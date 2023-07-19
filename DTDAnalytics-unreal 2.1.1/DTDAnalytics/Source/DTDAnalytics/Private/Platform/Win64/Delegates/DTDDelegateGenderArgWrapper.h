// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"

#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackGenderArg.h"

class DTDDelegateGenderArgWrapper : public ::DevToDevAnalyticsUnrealWindows::DTDCallbackGenderArg
{
public:
	explicit DTDDelegateGenderArgWrapper(const FDTDGetterGenderDelegate* del);
	virtual ~DTDDelegateGenderArgWrapper() override;
	virtual void Call(DevToDevAnalyticsUnrealWindows::DTDGender gender) const override;
private:
	const FDTDGetterGenderDelegate* del;
};

