// Copyright (c) devtodev. All rights reserved.

#include "DTDRemoteConfigUnrealListener.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

#include "../WindowsConverter.h"
#include "DTDRemoteConfigChangeResult.h"
#include "DTDRemoteConfigReceiveResult.h"

DTDRemoteConfigUnrealListener::DTDRemoteConfigUnrealListener(
	const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChangeDelegate,
	const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChangeDelegate,
	const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceiveDelegate)
{
	this->onRemoteConfigChangeDelegate = onRemoteConfigChangeDelegate;
	this->onRemoteConfigPrepareToChangeDelegate = onRemoteConfigPrepareToChangeDelegate;
	this->onRemoteConfigReceiveDelegate = onRemoteConfigReceiveDelegate;
}

DTDRemoteConfigUnrealListener::~DTDRemoteConfigUnrealListener()
{
	delete onRemoteConfigChangeDelegate;
	delete onRemoteConfigPrepareToChangeDelegate;
	delete onRemoteConfigReceiveDelegate;
}

void DTDRemoteConfigUnrealListener::OnReceived(DevToDevAnalyticsUnrealWindows::DTDRemoteConfigReceiveResult result) const 
{
	EDTDRemoteConfigReceiveResult u_Result;
	switch (result)
	{
	case DevToDevAnalyticsUnrealWindows::DTDRemoteConfigReceiveResult::DTDRemoteConfigReceiveResultFailure:
		u_Result = EDTDRemoteConfigReceiveResult::Failure;
		break;
	case DevToDevAnalyticsUnrealWindows::DTDRemoteConfigReceiveResult::DTDRemoteConfigReceiveResultSuccess:
		u_Result = EDTDRemoteConfigReceiveResult::Success;
		break;
	default:
		break;
	}

	onRemoteConfigReceiveDelegate->ExecuteIfBound(u_Result);
}

void DTDRemoteConfigUnrealListener::OnPrepareToChange() const
{
	onRemoteConfigPrepareToChangeDelegate->ExecuteIfBound();
}

void DTDRemoteConfigUnrealListener::OnChanged(DevToDevAnalyticsUnrealWindows::DTDRemoteConfigChangeResult result, 
	const DevToDevAnalyticsUnrealWindows::DTDString& error) const
{
	EDTDRemoteConfigChangeResult u_Result;
	switch (result)
	{
	case DevToDevAnalyticsUnrealWindows::DTDRemoteConfigChangeResult::DTDRemoteConfigChangeResultFailure:
		u_Result = EDTDRemoteConfigChangeResult::Failure;
		break;
	case DevToDevAnalyticsUnrealWindows::DTDRemoteConfigChangeResult::DTDRemoteConfigChangeResultSuccess:
		u_Result = EDTDRemoteConfigChangeResult::Success;
		break;
	default:
		break;
	}

	FString u_Error = WindowsConverter::Convert(error);
	onRemoteConfigChangeDelegate->ExecuteIfBound(u_Result, u_Error);
}

#endif