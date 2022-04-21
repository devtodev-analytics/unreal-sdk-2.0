// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateLongArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

#include "../WindowsConverter.h"

DTDDelegateLongArgWrapper::DTDDelegateLongArgWrapper(const FDTDGetterLongDelegate* del)
{
	this->del = del;
}

DTDDelegateLongArgWrapper::~DTDDelegateLongArgWrapper()
{
	delete del;
}


void DTDDelegateLongArgWrapper::Call(__int64 arg) const
{
	del->ExecuteIfBound(arg);
}

#endif