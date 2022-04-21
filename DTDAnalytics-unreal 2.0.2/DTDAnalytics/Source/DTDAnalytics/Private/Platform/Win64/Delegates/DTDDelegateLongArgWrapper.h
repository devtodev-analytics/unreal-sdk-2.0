// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackLongArg.h"

class DTDDelegateLongArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackLongArg
{
public:
	explicit DTDDelegateLongArgWrapper(const FDTDGetterLongDelegate* del);
	virtual ~DTDDelegateLongArgWrapper() override;
	virtual void Call(__int64 arg) const override;
private:
	const FDTDGetterLongDelegate* del;
};

