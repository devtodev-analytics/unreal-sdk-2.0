// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackVoidArg.h"

class DTDDelegateVoidArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackVoidArg
{
public:
	explicit DTDDelegateVoidArgWrapper(const FDTDAnalyticsInitializationCompleteDelegate* del);
	virtual ~DTDDelegateVoidArgWrapper() override;
	virtual void Call() const override;
private:
	const FDTDAnalyticsInitializationCompleteDelegate* del;
};
