// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"

#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackIntArg.h"

class DTDDelegateIntArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackIntArg
{
public:
	explicit DTDDelegateIntArgWrapper(const FDTDGetterIntDelegate* del);
	virtual ~DTDDelegateIntArgWrapper() override;
	virtual void Call(__int32 arg) const override;
private:
	const FDTDGetterIntDelegate* del;
};
