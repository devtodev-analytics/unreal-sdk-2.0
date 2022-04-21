// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackOptionalLongArg.h"

class DTDDelegateOptionalLongArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackOptionalLongArg
{
public:
	explicit DTDDelegateOptionalLongArgWrapper(const FDTDGetterOptionalLongDelegate* del);
	virtual ~DTDDelegateOptionalLongArgWrapper() override;
	virtual void Call(bool success, __int64 arg) const override;
private:
	const FDTDGetterOptionalLongDelegate* del;
};
