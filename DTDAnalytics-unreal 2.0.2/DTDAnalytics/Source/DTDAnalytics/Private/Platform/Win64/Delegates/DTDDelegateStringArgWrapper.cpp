// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateStringArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

#include "../WindowsConverter.h"

DTDDelegateStringArgWrapper::DTDDelegateStringArgWrapper(const FDTDGetterStringDelegate* del)
{
	this->del = del;
}

DTDDelegateStringArgWrapper::~DTDDelegateStringArgWrapper()
{
	delete del;
}

void DTDDelegateStringArgWrapper::Call(const DevToDevAnalyticsUnrealWindows::DTDString& str) const
{
	del->ExecuteIfBound(WindowsConverter::Convert(str));
}

#endif