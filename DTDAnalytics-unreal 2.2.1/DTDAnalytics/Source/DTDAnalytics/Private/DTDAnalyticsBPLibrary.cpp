// Copyright (c) devtodev. All rights reserved.

#include "DTDAnalyticsBPLibrary.h"

#include "CoreGlobals.h"
#include "Async/TaskGraphInterfaces.h"

#include "Platform//PlatformHub.h"

UDTDAnalyticsBPLibrary::UDTDAnalyticsBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


void UDTDAnalyticsBPLibrary::CoppaControlEnable()
{
	PlatformHub::GetInstance().GetAnalytics()->CoppaControlEnable();
}
	
void UDTDAnalyticsBPLibrary::SetInitializationCompleteCallback(const FDTDAnalyticsInitializationCompleteDynamicDelegate& callback)
{
	FDTDAnalyticsInitializationCompleteDelegate* callbackDelegate = new FDTDAnalyticsInitializationCompleteDelegate();
	callbackDelegate->BindLambda([=]()
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			callback.ExecuteIfBound();
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->SetInitializationCompleteCallback(callbackDelegate);
}

void UDTDAnalyticsBPLibrary::SetIdentifiersListener(const FAnalyticsDynamicGetterLongDelegate& listener)
{
	FDTDLongListenerDelegate* listenerDelegate = new FDTDLongListenerDelegate();
	listenerDelegate->BindLambda([=](int64 result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->SetIdentifiersListener(listenerDelegate);
}

void UDTDAnalyticsBPLibrary::GetDeviceId(const FAnalyticsDynamicGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetDeviceId(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetSdkVersion(const FAnalyticsDynamicGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetSdkVersion(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetApplicationVersion(const FAnalyticsDynamicGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetApplicationVersion(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::SetApplicationVersion(const FString& appKey)
{
	PlatformHub::GetInstance().GetAnalytics()->SetApplicationVersion(appKey);
}

void UDTDAnalyticsBPLibrary::GetTrackingAvailability(const FAnalyticsDynamicGetterBoolDelegate& onResult)
{
	FDTDGetterBoolDelegate* onResultDelegate = new FDTDGetterBoolDelegate();
	onResultDelegate->BindLambda([=](bool result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetTrackingAvailability(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetUserId(const FAnalyticsDynamicGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetUserId(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetCurrentLevel(const FAnalyticsDynamicGetterIntDelegate& onResult)
{
	FDTDGetterIntDelegate* onResultDelegate = new FDTDGetterIntDelegate();
	onResultDelegate->BindLambda([=](int32 result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetCurrentLevel(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::Initialize(const FString& appKey)
{
	PlatformHub::GetInstance().GetAnalytics()->Initialize(appKey);
}

void UDTDAnalyticsBPLibrary::InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config)
{
	PlatformHub::GetInstance().GetAnalytics()->InitializeWithConfig(appKey, config);
}

void UDTDAnalyticsBPLibrary::InitializeWithAbTest(const FString& appKey, 
		const FDTDRemoteConfigChangeResultDynamicDelegate& onRemoteConfigChange,
        const FDTDRemoteConfigPrepareToChangeDynamicDelegate& onRemoteConfigPrepareToChange,
        const FDTDRemoteConfigReceiveResultDynamicDelegate& onRemoteConfigReceive) 
{
	// FDTDRemoteConfigChangeResultDelegate
	const auto onRemoteConfigChangeInternal = new FDTDRemoteConfigChangeResultDelegate();
	onRemoteConfigChangeInternal->BindLambda([=](EDTDRemoteConfigChangeResult result, const FString& error)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigChange.ExecuteIfBound(result, error);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// FDTDRemoteConfigPrepareToChangeDelegate
	const auto onRemoteConfigPrepareToChangeInternal = new FDTDRemoteConfigPrepareToChangeDelegate();
	onRemoteConfigPrepareToChangeInternal->BindLambda([=]()
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigPrepareToChange.ExecuteIfBound();
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// FDTDRemoteConfigReceiveResultDelegate
	const auto onRemoteConfigReceiveInternal = new FDTDRemoteConfigReceiveResultDelegate();
	onRemoteConfigReceiveInternal->BindLambda([=](EDTDRemoteConfigReceiveResult result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigReceive.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// Initialize AB
	PlatformHub::GetInstance().GetAnalytics()->InitializeWithAbTest(appKey, 
		onRemoteConfigChangeInternal, 
		onRemoteConfigPrepareToChangeInternal, 
		onRemoteConfigReceiveInternal);
}

void UDTDAnalyticsBPLibrary::InitializeWithConfigWithAbTest(const FString& appKey, 
		const FDTDAnalyticsConfiguration& config,
		const FDTDRemoteConfigChangeResultDynamicDelegate& onRemoteConfigChange,
        const FDTDRemoteConfigPrepareToChangeDynamicDelegate& onRemoteConfigPrepareToChange,
        const FDTDRemoteConfigReceiveResultDynamicDelegate& onRemoteConfigReceive) 
{
	// FDTDRemoteConfigChangeResultDelegate
	const auto onRemoteConfigChangeInternal = new FDTDRemoteConfigChangeResultDelegate();
	onRemoteConfigChangeInternal->BindLambda([=](EDTDRemoteConfigChangeResult result, const FString& error)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigChange.ExecuteIfBound(result, error);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// FDTDRemoteConfigPrepareToChangeDelegate
	const auto onRemoteConfigPrepareToChangeInternal = new FDTDRemoteConfigPrepareToChangeDelegate();
	onRemoteConfigPrepareToChangeInternal->BindLambda([=]()
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigPrepareToChange.ExecuteIfBound();
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// FDTDRemoteConfigReceiveResultDelegate
	const auto onRemoteConfigReceiveInternal = new FDTDRemoteConfigReceiveResultDelegate();
	onRemoteConfigReceiveInternal->BindLambda([=](EDTDRemoteConfigReceiveResult result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigReceive.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// Initialize AB
	PlatformHub::GetInstance().GetAnalytics()->InitializeWithConfigWithAbTest(appKey, 
		config,
		onRemoteConfigChangeInternal, 
		onRemoteConfigPrepareToChangeInternal, 
		onRemoteConfigReceiveInternal);
}

void UDTDAnalyticsBPLibrary::StartActivity()
{
	PlatformHub::GetInstance().GetAnalytics()->StartActivity();
}

void UDTDAnalyticsBPLibrary::StopActivity()
{
	PlatformHub::GetInstance().GetAnalytics()->StopActivity();
}

void UDTDAnalyticsBPLibrary::SetUserId(const FString& userId)
{
	PlatformHub::GetInstance().GetAnalytics()->SetUserId(userId);
}

void UDTDAnalyticsBPLibrary::ReplaceUserId(const FString& fromUserId, const FString& toUserId)
{
	PlatformHub::GetInstance().GetAnalytics()->ReplaceUserId(fromUserId, toUserId);
}

void UDTDAnalyticsBPLibrary::CustomEvent(const FString& eventName)
{
	PlatformHub::GetInstance().GetAnalytics()->CustomEvent(eventName);
}

void UDTDAnalyticsBPLibrary::CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params)
{
	PlatformHub::GetInstance().GetAnalytics()->CustomEventWithParams(eventName, params);
}

void UDTDAnalyticsBPLibrary::SetCurrentLevel(int32 level)
{
	PlatformHub::GetInstance().GetAnalytics()->SetCurrentLevel(level);
}

void UDTDAnalyticsBPLibrary::SetTrackingAvailability(bool value)
{
	PlatformHub::GetInstance().GetAnalytics()->SetTrackingAvailability(value);
}

void UDTDAnalyticsBPLibrary::CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType)
{
	PlatformHub::GetInstance().GetAnalytics()->CurrencyAccrual(currencyName, currencyAmount, source, accrualType);
}

void UDTDAnalyticsBPLibrary::VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency)
{
	PlatformHub::GetInstance().GetAnalytics()->VirtualCurrencyPayment(purchaseId, purchaseType, purchaseAmount, purchasePrice, purchaseCurrency);
}

void UDTDAnalyticsBPLibrary::VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources)
{
	PlatformHub::GetInstance().GetAnalytics()->VirtualCurrencyPaymentWithResources(purchaseId, purchaseType, purchaseAmount, resources);
}

void UDTDAnalyticsBPLibrary::LevelUp(int32 level)
{
	PlatformHub::GetInstance().GetAnalytics()->LevelUp(level);
}

void UDTDAnalyticsBPLibrary::LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance)
{
	PlatformHub::GetInstance().GetAnalytics()->LevelUpWithBalance(level, balance);
}

void UDTDAnalyticsBPLibrary::CurrentBalance(const TMap<FString, int64>& balance)
{
	PlatformHub::GetInstance().GetAnalytics()->CurrentBalance(balance);
}

void UDTDAnalyticsBPLibrary::Referrer(const TMap<EDTDReferralProperty, FString>& utmData)
{
	PlatformHub::GetInstance().GetAnalytics()->Referrer(utmData);
}

void UDTDAnalyticsBPLibrary::Tutorial(int32 step)
{
	PlatformHub::GetInstance().GetAnalytics()->Tutorial(step);
}

void UDTDAnalyticsBPLibrary::StartProgressionEvent(const FString& eventName)
{
	PlatformHub::GetInstance().GetAnalytics()->StartProgressionEvent(eventName);
}

void UDTDAnalyticsBPLibrary::StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params)
{
	PlatformHub::GetInstance().GetAnalytics()->StartProgressionEventWithParams(eventName, params);
}

void UDTDAnalyticsBPLibrary::FinishProgressionEvent(const FString& eventName)
{
	PlatformHub::GetInstance().GetAnalytics()->FinishProgressionEvent(eventName);
}

void UDTDAnalyticsBPLibrary::FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params)
{
	PlatformHub::GetInstance().GetAnalytics()->FinishProgressionEventWithParams(eventName, params);
}

void UDTDAnalyticsBPLibrary::RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode)
{
	PlatformHub::GetInstance().GetAnalytics()->RealCurrencyPayment(orderId, price, productId, currencyCode);
}

void UDTDAnalyticsBPLibrary::SocialNetworkConnect(EDTDSocialNetwork socialNetwork)
{
	PlatformHub::GetInstance().GetAnalytics()->SocialNetworkConnect(socialNetwork);
}

void UDTDAnalyticsBPLibrary::SocialNetworkConnectCustom(const FString& socialNetwork)
{
	PlatformHub::GetInstance().GetAnalytics()->SocialNetworkConnectCustom(socialNetwork);
}

void UDTDAnalyticsBPLibrary::SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason)
{
	PlatformHub::GetInstance().GetAnalytics()->SocialNetworkPost(socialNetwork, reason);
}

void UDTDAnalyticsBPLibrary::SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason)
{
	PlatformHub::GetInstance().GetAnalytics()->SocialNetworkPostCustom(socialNetwork, reason);
}

void UDTDAnalyticsBPLibrary::AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit)
{
	PlatformHub::GetInstance().GetAnalytics()->AdImpression(socialNetwork, revenue, placement, unit);
}

void UDTDAnalyticsBPLibrary::SendBufferedEvents()
{
	PlatformHub::GetInstance().GetAnalytics()->SendBufferedEvents();	
}

void UDTDAnalyticsBPLibrary::SetLogLevel(EDTDLogLevel logLevel)
{
	PlatformHub::GetInstance().GetAnalytics()->SetLogLevel(logLevel);
}

//
// Methods to interact from C++ code.
//

void UDTDAnalyticsBPLibrary::SetIdentifiersListener(const FDTDLongListenerDelegate& listener)
{
	FDTDLongListenerDelegate* listenerDelegate = new FDTDLongListenerDelegate();
	listenerDelegate->BindLambda([=](int64 result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->SetIdentifiersListener(listenerDelegate);
}

void UDTDAnalyticsBPLibrary::GetDeviceId(const FDTDGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetDeviceId(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetSdkVersion(const FDTDGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetSdkVersion(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetApplicationVersion(const FDTDGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetApplicationVersion(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetTrackingAvailability(const FDTDGetterBoolDelegate& onResult)
{
	FDTDGetterBoolDelegate* onResultDelegate = new FDTDGetterBoolDelegate();
	onResultDelegate->BindLambda([=](bool result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetTrackingAvailability(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetUserId(const FDTDGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetUserId(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::GetCurrentLevel(const FDTDGetterIntDelegate& onResult)
{
	FDTDGetterIntDelegate* onResultDelegate = new FDTDGetterIntDelegate();
	onResultDelegate->BindLambda([=](int32 result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetCurrentLevel(onResultDelegate);
}


void UDTDAnalyticsBPLibrary::InitializeWithAbTest(const FString& appKey,
		const FDTDRemoteConfigChangeResultDelegate& onRemoteConfigChange,
        const FDTDRemoteConfigPrepareToChangeDelegate& onRemoteConfigPrepareToChange,
        const FDTDRemoteConfigReceiveResultDelegate& onRemoteConfigReceive) 
{
	// FDTDRemoteConfigChangeResultDelegate
	const auto onRemoteConfigChangeInternal = new FDTDRemoteConfigChangeResultDelegate();
	onRemoteConfigChangeInternal->BindLambda([=](EDTDRemoteConfigChangeResult result, const FString& error)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigChange.ExecuteIfBound(result, error);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// FDTDRemoteConfigPrepareToChangeDelegate
	const auto onRemoteConfigPrepareToChangeInternal = new FDTDRemoteConfigPrepareToChangeDelegate();
	onRemoteConfigPrepareToChangeInternal->BindLambda([=]()
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigPrepareToChange.ExecuteIfBound();
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// FDTDRemoteConfigReceiveResultDelegate
	const auto onRemoteConfigReceiveInternal = new FDTDRemoteConfigReceiveResultDelegate();
	onRemoteConfigReceiveInternal->BindLambda([=](EDTDRemoteConfigReceiveResult result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigReceive.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// Initialize AB
	PlatformHub::GetInstance().GetAnalytics()->InitializeWithAbTest(appKey, 
		onRemoteConfigChangeInternal, 
		onRemoteConfigPrepareToChangeInternal, 
		onRemoteConfigReceiveInternal);
}

void UDTDAnalyticsBPLibrary::InitializeWithConfigWithAbTest(const FString& appKey, 
	const FDTDAnalyticsConfiguration& config,
	const FDTDRemoteConfigChangeResultDelegate& onRemoteConfigChange,
    const FDTDRemoteConfigPrepareToChangeDelegate& onRemoteConfigPrepareToChange,
    const FDTDRemoteConfigReceiveResultDelegate& onRemoteConfigReceive) 
{
	// FDTDRemoteConfigChangeResultDelegate
	const auto onRemoteConfigChangeInternal = new FDTDRemoteConfigChangeResultDelegate();
	onRemoteConfigChangeInternal->BindLambda([=](EDTDRemoteConfigChangeResult result, const FString& error)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigChange.ExecuteIfBound(result, error);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// FDTDRemoteConfigPrepareToChangeDelegate
	const auto onRemoteConfigPrepareToChangeInternal = new FDTDRemoteConfigPrepareToChangeDelegate();
	onRemoteConfigPrepareToChangeInternal->BindLambda([=]()
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigPrepareToChange.ExecuteIfBound();
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// FDTDRemoteConfigReceiveResultDelegate
	const auto onRemoteConfigReceiveInternal = new FDTDRemoteConfigReceiveResultDelegate();
	onRemoteConfigReceiveInternal->BindLambda([=](EDTDRemoteConfigReceiveResult result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onRemoteConfigReceive.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});

	// Initialize AB
	PlatformHub::GetInstance().GetAnalytics()->InitializeWithConfigWithAbTest(appKey, 
		config,
		onRemoteConfigChangeInternal, 
		onRemoteConfigPrepareToChangeInternal, 
		onRemoteConfigReceiveInternal);
}
