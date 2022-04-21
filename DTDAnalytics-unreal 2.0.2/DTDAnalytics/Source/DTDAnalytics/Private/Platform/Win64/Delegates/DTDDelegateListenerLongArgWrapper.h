// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "../../../../../../ThirdParty/Windows/Headers/DTDCallbackLongArg.h"

class DTDDelegateListenerLongArgWrapper : public DevToDevAnalyticsUnrealWindows::DTDCallbackLongArg
{
public:
	explicit DTDDelegateListenerLongArgWrapper(const FDTDLongListenerDelegate* del);
	virtual ~DTDDelegateListenerLongArgWrapper() override;
	virtual void Call(__int64 arg) const override;
private:
	const FDTDLongListenerDelegate* del;
};

