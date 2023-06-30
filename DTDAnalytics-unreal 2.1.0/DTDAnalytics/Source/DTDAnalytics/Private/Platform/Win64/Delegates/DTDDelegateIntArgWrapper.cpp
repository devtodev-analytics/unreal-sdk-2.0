// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateIntArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

DTDDelegateIntArgWrapper::DTDDelegateIntArgWrapper(const FDTDGetterIntDelegate* del)
{
	this->del = del;
}

DTDDelegateIntArgWrapper::~DTDDelegateIntArgWrapper()
{
	delete del;
}

void DTDDelegateIntArgWrapper::Call(__int32 arg) const
{
	del->ExecuteIfBound(arg);
}

#endif
