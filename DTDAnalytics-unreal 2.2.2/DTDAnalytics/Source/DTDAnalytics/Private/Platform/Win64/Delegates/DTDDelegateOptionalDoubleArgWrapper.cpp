// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateOptionalDoubleArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

DTDDelegateOptionalDoubleArgWrapper::DTDDelegateOptionalDoubleArgWrapper(const FDTDGetterOptionalFloatDelegate* del)
{
	this->del = del;
}

DTDDelegateOptionalDoubleArgWrapper::~DTDDelegateOptionalDoubleArgWrapper()
{
	delete del;
}

void DTDDelegateOptionalDoubleArgWrapper::Call(bool success, double arg) const
{
	del->ExecuteIfBound(success, static_cast<float>(arg));
}

#endif
