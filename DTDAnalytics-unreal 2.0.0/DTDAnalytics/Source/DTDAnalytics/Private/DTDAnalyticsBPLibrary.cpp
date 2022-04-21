// Copyright (c) devtodev. All rights reserved.

#include "DTDAnalyticsBPLibrary.h"

#include "CoreGlobals.h"
#include "Async/TaskGraphInterfaces.h"

#include "Platform//PlatformHub.h"

UDTDAnalyticsBPLibrary::UDTDAnalyticsBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
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
	PlatformHub::GetInstance().GetAnalytycs()->SetIdentifiersListener(listenerDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetDeviceId(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetSdkVersion(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetApplicationVersion(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::SetApplicationVersion(const FString& appKey)
{
	PlatformHub::GetInstance().GetAnalytycs()->SetApplicationVersion(appKey);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetTrackingAvailability(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetUserId(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetCurrentLevel(onResultDelegate);
}

void UDTDAnalyticsBPLibrary::Initialize(const FString& appKey)
{
	PlatformHub::GetInstance().GetAnalytycs()->Initialize(appKey);
}

void UDTDAnalyticsBPLibrary::InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config)
{
	PlatformHub::GetInstance().GetAnalytycs()->InitializeWithConfig(appKey, config);
}

void UDTDAnalyticsBPLibrary::StartActivity()
{
	PlatformHub::GetInstance().GetAnalytycs()->StartActivity();
}

void UDTDAnalyticsBPLibrary::StopActivity()
{
	PlatformHub::GetInstance().GetAnalytycs()->StopActivity();
}

void UDTDAnalyticsBPLibrary::SetUserId(const FString& userId)
{
	PlatformHub::GetInstance().GetAnalytycs()->SetUserId(userId);
}

void UDTDAnalyticsBPLibrary::ReplaceUserId(const FString& fromUserId, const FString& toUserId)
{
	PlatformHub::GetInstance().GetAnalytycs()->ReplaceUserId(fromUserId, toUserId);
}

void UDTDAnalyticsBPLibrary::CustomEvent(const FString& eventName)
{
	PlatformHub::GetInstance().GetAnalytycs()->CustomEvent(eventName);
}

void UDTDAnalyticsBPLibrary::CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params)
{
	PlatformHub::GetInstance().GetAnalytycs()->CustomEventWithParams(eventName, params);
}

void UDTDAnalyticsBPLibrary::SetCurrentLevel(int32 level)
{
	PlatformHub::GetInstance().GetAnalytycs()->SetCurrentLevel(level);
}

void UDTDAnalyticsBPLibrary::SetTrackingAvailability(bool value)
{
	PlatformHub::GetInstance().GetAnalytycs()->SetTrackingAvailability(value);
}

void UDTDAnalyticsBPLibrary::CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType)
{
	PlatformHub::GetInstance().GetAnalytycs()->CurrencyAccrual(currencyName, currencyAmount, source, accrualType);
}

void UDTDAnalyticsBPLibrary::VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency)
{
	PlatformHub::GetInstance().GetAnalytycs()->VirtualCurrencyPayment(purchaseId, purchaseType, purchaseAmount, purchasePrice, purchaseCurrency);
}

void UDTDAnalyticsBPLibrary::VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources)
{
	PlatformHub::GetInstance().GetAnalytycs()->VirtualCurrencyPaymentWithResources(purchaseId, purchaseType, purchaseAmount, resources);
}

void UDTDAnalyticsBPLibrary::LevelUp(int32 level)
{
	PlatformHub::GetInstance().GetAnalytycs()->LevelUp(level);
}

void UDTDAnalyticsBPLibrary::LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance)
{
	PlatformHub::GetInstance().GetAnalytycs()->LevelUpWithBalance(level, balance);
}

void UDTDAnalyticsBPLibrary::CurrentBalance(const TMap<FString, int64>& balance)
{
	PlatformHub::GetInstance().GetAnalytycs()->CurrentBalance(balance);
}

void UDTDAnalyticsBPLibrary::Referrer(const TMap<EDTDReferralProperty, FString>& utmData)
{
	PlatformHub::GetInstance().GetAnalytycs()->Referrer(utmData);
}

void UDTDAnalyticsBPLibrary::Tutorial(int32 step)
{
	PlatformHub::GetInstance().GetAnalytycs()->Tutorial(step);
}

void UDTDAnalyticsBPLibrary::StartProgressionEvent(const FString& eventName)
{
	PlatformHub::GetInstance().GetAnalytycs()->StartProgressionEvent(eventName);
}

void UDTDAnalyticsBPLibrary::StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params)
{
	PlatformHub::GetInstance().GetAnalytycs()->StartProgressionEventWithParams(eventName, params);
}

void UDTDAnalyticsBPLibrary::FinishProgressionEvent(const FString& eventName)
{
	PlatformHub::GetInstance().GetAnalytycs()->FinishProgressionEvent(eventName);
}

void UDTDAnalyticsBPLibrary::FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params)
{
	PlatformHub::GetInstance().GetAnalytycs()->FinishProgressionEventWithParams(eventName, params);
}

void UDTDAnalyticsBPLibrary::RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode)
{
	PlatformHub::GetInstance().GetAnalytycs()->RealCurrencyPayment(orderId, price, productId, currencyCode);
}

void UDTDAnalyticsBPLibrary::SocialNetworkConnect(EDTDSocialNetwork socialNetwork)
{
	PlatformHub::GetInstance().GetAnalytycs()->SocialNetworkConnect(socialNetwork);
}

void UDTDAnalyticsBPLibrary::SocialNetworkConnectCustom(const FString& socialNetwork)
{
	PlatformHub::GetInstance().GetAnalytycs()->SocialNetworkConnectCustom(socialNetwork);
}

void UDTDAnalyticsBPLibrary::SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason)
{
	PlatformHub::GetInstance().GetAnalytycs()->SocialNetworkPost(socialNetwork, reason);
}

void UDTDAnalyticsBPLibrary::SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason)
{
	PlatformHub::GetInstance().GetAnalytycs()->SocialNetworkPostCustom(socialNetwork, reason);
}

void UDTDAnalyticsBPLibrary::AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit)
{
	PlatformHub::GetInstance().GetAnalytycs()->AdImpression(socialNetwork, revenue, placement, unit);
}

void UDTDAnalyticsBPLibrary::SendBufferedEvents()
{
	PlatformHub::GetInstance().GetAnalytycs()->SendBufferedEvents();	
}

void UDTDAnalyticsBPLibrary::SetLogLevel(EDTDLogLevel logLevel)
{
	PlatformHub::GetInstance().GetAnalytycs()->SetLogLevel(logLevel);
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
	PlatformHub::GetInstance().GetAnalytycs()->SetIdentifiersListener(listenerDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetDeviceId(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetSdkVersion(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetApplicationVersion(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetTrackingAvailability(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetUserId(onResultDelegate);
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
	PlatformHub::GetInstance().GetAnalytycs()->GetCurrentLevel(onResultDelegate);
}
