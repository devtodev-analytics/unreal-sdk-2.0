// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackOptionalStringArg.h"

class DTDDelegateOptionalStringArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackOptionalStringArg
{
public:
	explicit DTDDelegateOptionalStringArgWrapper(const FDTDGetterOptionalStringDelegate* del);
	virtual ~DTDDelegateOptionalStringArgWrapper() override;
	virtual void Call(bool success, const DevToDevAnalyticsUnrealWindows::DTDString& str) const override;
private:
	const FDTDGetterOptionalStringDelegate* del;
};
