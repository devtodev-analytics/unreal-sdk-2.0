// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateOptionalBoolArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

DTDDelegateOptionalBoolArgWrapper::DTDDelegateOptionalBoolArgWrapper(const FDTDGetterOptionalBoolDelegate* del)
{
	this->del = del;
}

DTDDelegateOptionalBoolArgWrapper::~DTDDelegateOptionalBoolArgWrapper()
{
	delete del;
}

void DTDDelegateOptionalBoolArgWrapper::Call(bool success, bool arg) const
{
	del->ExecuteIfBound(success, arg);
}

#endif
