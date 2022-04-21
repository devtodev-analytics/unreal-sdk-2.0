// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateListenerLongArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

#include "../WindowsConverter.h"

DTDDelegateListenerLongArgWrapper::DTDDelegateListenerLongArgWrapper(const FDTDLongListenerDelegate* del)
{
	this->del = del;
}

DTDDelegateListenerLongArgWrapper::~DTDDelegateListenerLongArgWrapper()
{
	delete del;
}


void DTDDelegateListenerLongArgWrapper::Call(__int64 arg) const
{
	del->ExecuteIfBound(arg);
}

#endif