// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateGenderArgWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

#include "../WindowsConverter.h"

DTDDelegateGenderArgWrapper::DTDDelegateGenderArgWrapper(const FDTDGetterGenderDelegate* del)
{
	this->del = del;
}

DTDDelegateGenderArgWrapper::~DTDDelegateGenderArgWrapper()
{
	delete del;
}

void DTDDelegateGenderArgWrapper::Call(DevToDevAnalyticsUnrealWindows::DTDGender gender) const
{
	del->ExecuteIfBound(WindowsConverter::Convert(gender));
}

#endif
