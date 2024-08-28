// Copyright (c) devtodev. All rights reserved.

#include "DTDDelegateLogLevelAndStringArgsWrapper.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

#include "../WindowsConverter.h"

DTDDelegateLogLevelAndStringArgsWrapper::DTDDelegateLogLevelAndStringArgsWrapper(const FDTDLogsListenerDelegate* del)
{
	this->del = del;
}

DTDDelegateLogLevelAndStringArgsWrapper::~DTDDelegateLogLevelAndStringArgsWrapper()
{
	delete del;
}

void DTDDelegateLogLevelAndStringArgsWrapper::Call(DevToDevAnalyticsUnrealWindows::DTDLogLevel logLevel, const DevToDevAnalyticsUnrealWindows::DTDString& str) const
{
	del->ExecuteIfBound(WindowsConverter::Convert(logLevel), WindowsConverter::Convert(str));
}

#endif