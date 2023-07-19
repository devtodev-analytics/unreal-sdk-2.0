// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateOptionalLongArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

DTDDelegateOptionalLongArgWrapper::DTDDelegateOptionalLongArgWrapper(const FDTDGetterOptionalLongDelegate* del)
{
	this->del = del;
}

DTDDelegateOptionalLongArgWrapper::~DTDDelegateOptionalLongArgWrapper()
{
	delete del;
}

void DTDDelegateOptionalLongArgWrapper::Call(bool success, __int64 arg) const
{
	del->ExecuteIfBound(success, arg);
}

#endif
