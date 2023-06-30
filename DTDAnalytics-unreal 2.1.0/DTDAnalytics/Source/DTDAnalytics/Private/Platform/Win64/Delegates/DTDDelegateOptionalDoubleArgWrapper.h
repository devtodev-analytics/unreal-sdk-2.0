// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackOptionalDoubleArg.h"

class DTDDelegateOptionalDoubleArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackOptionalDoubleArg
{
public:
	explicit DTDDelegateOptionalDoubleArgWrapper(const FDTDGetterOptionalFloatDelegate* del);
	virtual ~DTDDelegateOptionalDoubleArgWrapper() override;
	virtual void Call(bool success, double arg) const override;
private:
	const FDTDGetterOptionalFloatDelegate* del;
};

