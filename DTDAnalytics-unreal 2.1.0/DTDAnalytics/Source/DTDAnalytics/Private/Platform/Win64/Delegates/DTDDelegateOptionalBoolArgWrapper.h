// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackOptionalBoolArg.h"

class DTDDelegateOptionalBoolArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackOptionalBoolArg
{
public:
	explicit DTDDelegateOptionalBoolArgWrapper(const FDTDGetterOptionalBoolDelegate* del);
	virtual ~DTDDelegateOptionalBoolArgWrapper() override;
	virtual void Call(bool success, bool arg) const override;
private:
	const FDTDGetterOptionalBoolDelegate* del;
};

