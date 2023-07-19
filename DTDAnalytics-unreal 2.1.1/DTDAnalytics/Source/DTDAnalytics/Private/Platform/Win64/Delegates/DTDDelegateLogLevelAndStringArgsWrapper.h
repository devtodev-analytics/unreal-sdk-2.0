// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackLogLevelAndStringArgs.h"

class DTDDelegateLogLevelAndStringArgsWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackLogLevelAndStringArgs
{
public:
	explicit DTDDelegateLogLevelAndStringArgsWrapper(const FDTDLogsListenerDelegate* del);
	virtual ~DTDDelegateLogLevelAndStringArgsWrapper() override;
	virtual void Call(DevToDevAnalyticsUnrealWindows::DTDLogLevel logLevel, const DevToDevAnalyticsUnrealWindows::DTDString& str) const override;
private:
	const FDTDLogsListenerDelegate* del;
};
