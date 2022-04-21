// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"

#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackBoolArg.h"

class DTDDelegateBoolArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackBoolArg
{
public:
	explicit DTDDelegateBoolArgWrapper(const FDTDGetterBoolDelegate* del);
	virtual ~DTDDelegateBoolArgWrapper() override;
	virtual void Call(bool arg) const override;
private:
	const FDTDGetterBoolDelegate* del;
};

