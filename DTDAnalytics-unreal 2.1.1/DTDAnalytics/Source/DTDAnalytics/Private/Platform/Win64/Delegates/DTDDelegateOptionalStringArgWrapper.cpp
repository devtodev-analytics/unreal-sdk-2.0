// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateOptionalStringArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

#include "../WindowsConverter.h"

DTDDelegateOptionalStringArgWrapper::DTDDelegateOptionalStringArgWrapper(const FDTDGetterOptionalStringDelegate* del)
{
	this->del = del;
}

DTDDelegateOptionalStringArgWrapper::~DTDDelegateOptionalStringArgWrapper()
{
	delete del;
}

void DTDDelegateOptionalStringArgWrapper::Call(bool success, const DevToDevAnalyticsUnrealWindows::DTDString& str) const
{
	del->ExecuteIfBound(success, WindowsConverter::Convert(str));
}

#endif
