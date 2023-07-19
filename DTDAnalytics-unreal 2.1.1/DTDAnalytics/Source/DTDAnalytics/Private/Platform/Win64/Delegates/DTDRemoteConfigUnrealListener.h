// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "../../../../../../ThirdParty/Windows/Headers/DTDRemoteConfigListener.h"

#include "DTDDelegates.h"
#include "DTDRemoteConfigChangeResult.h"
#include "DTDRemoteConfigReceiveResult.h"

class DTDRemoteConfigUnrealListener : public DevToDevAnalyticsUnrealWindows::DTDRemoteConfigListener
{
public:
	explicit DTDRemoteConfigUnrealListener(
		const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChangeDelegate,
		const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChangeDelegate,
		const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceiveDelegate);
	virtual ~DTDRemoteConfigUnrealListener() override;
	virtual void OnReceived(DevToDevAnalyticsUnrealWindows::DTDRemoteConfigReceiveResult result) const override;
	virtual void OnPrepareToChange() const override;
	virtual void OnChanged(DevToDevAnalyticsUnrealWindows::DTDRemoteConfigChangeResult result, 
		const DevToDevAnalyticsUnrealWindows::DTDString& error) const override;

private:
	const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChangeDelegate;
	const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChangeDelegate;
	const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceiveDelegate;
};
