// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateBoolArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

#include "../WindowsConverter.h"

DTDDelegateBoolArgWrapper::DTDDelegateBoolArgWrapper(const FDTDGetterBoolDelegate* del)
{
	this->del = del;
}

DTDDelegateBoolArgWrapper::~DTDDelegateBoolArgWrapper()
{
	delete del;
}

void DTDDelegateBoolArgWrapper::Call(bool arg) const
{
	del->ExecuteIfBound(arg);
}

#endif