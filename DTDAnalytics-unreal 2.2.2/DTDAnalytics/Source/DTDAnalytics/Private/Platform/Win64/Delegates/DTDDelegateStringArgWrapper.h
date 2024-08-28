// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackStringArg.h"

class DTDDelegateStringArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackStringArg
{
public:
	explicit DTDDelegateStringArgWrapper(const FDTDGetterStringDelegate* del);
	virtual ~DTDDelegateStringArgWrapper() override;
	virtual void Call(const DevToDevAnalyticsUnrealWindows::DTDString& str) const override;
private:
	const FDTDGetterStringDelegate* del;
};
