// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "DTDLogLevel.h"
#include "DTDAnalyticsConfiguration.h"
#include "DTDCustomEventParams.h"
#include "DTDReferralProperty.h"
#include "DTDAccrualType.h"
#include "DTDGender.h"
#include "DTDSocialNetwork.h"
#include "DTDStartProgressionEventParams.h"
#include "DTDFinishProgressionEventParams.h"
#include "DTDDelegates.h"
#include "DTDRemoteConfigChangeResult.h"
#include "DTDRemoteConfigReceiveResult.h"

#include "DTDAnalyticsBPLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE(FDTDAnalyticsInitializationCompleteDynamicDelegate);

DECLARE_DYNAMIC_DELEGATE_OneParam(FAnalyticsDynamicGetterStringDelegate, const FString&, result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAnalyticsDynamicGetterBoolDelegate, bool, result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAnalyticsDynamicGetterIntDelegate, int32, result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAnalyticsDynamicGetterLongDelegate, int64, result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FAnalyticsDynamicGetterGenderDelegate, EDTDGender, result);

DECLARE_DYNAMIC_DELEGATE(FDTDRemoteConfigPrepareToChangeDynamicDelegate);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDTDRemoteConfigReceiveResultDynamicDelegate, EDTDRemoteConfigReceiveResult, result);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTDRemoteConfigChangeResultDynamicDelegate, EDTDRemoteConfigChangeResult, result, const FString&, error);

UCLASS()
class DTDANALYTICS_API UDTDAnalyticsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CoppaControlEnable", Keywords = "coppa control enable"), Category = "DTD|Analytics")
	static void CoppaControlEnable();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetInitializationCompleteCallback", Keywords = "set initialization complete callback"), Category = "DTD|Analytics")
	static void SetInitializationCompleteCallback(const FDTDAnalyticsInitializationCompleteDynamicDelegate& callback);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetIdentifiersListener", Keywords = "set identifiers listener"), Category = "DTD|Analytics")
	static void SetIdentifiersListener(const FAnalyticsDynamicGetterLongDelegate& listener);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetDeviceId", Keywords = "get device id"), Category = "DTD|Analytics")
	static void GetDeviceId(const FAnalyticsDynamicGetterStringDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetSdkVersion", Keywords = "get sdk version"), Category = "DTD|Analytics")
	static void GetSdkVersion(const FAnalyticsDynamicGetterStringDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetApplicationVersion", Keywords = "get application version"), Category = "DTD|Analytics")
	static void GetApplicationVersion(const FAnalyticsDynamicGetterStringDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetApplicationVersion", Keywords = "set application version"), Category = "DTD|Analytics")
	static void SetApplicationVersion(const FString& appKey);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetTrackingAvailability", Keywords = "get tracking availability"), Category = "DTD|Analytics")
	static void GetTrackingAvailability(const FAnalyticsDynamicGetterBoolDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetUserId", Keywords = "get user id"), Category = "DTD|Analytics")
	static void GetUserId(const FAnalyticsDynamicGetterStringDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetCurrentLevel", Keywords = "get current level"), Category = "DTD|Analytics")
	static void GetCurrentLevel(const FAnalyticsDynamicGetterIntDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Initialize", Keywords = "initialize"), Category = "DTD|Analytics")
	static void Initialize(const FString& appKey);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InitializeWithConfig", Keywords = "initialize with config"), Category = "DTD|Analytics")
	static void InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InitializeWithAbTest", Keywords = "initialize with ab-tests"), Category = "DTD|Analytics")
	static void InitializeWithAbTest(const FString& appKey,
		const FDTDRemoteConfigChangeResultDynamicDelegate& onRemoteConfigChange,
        const FDTDRemoteConfigPrepareToChangeDynamicDelegate& onRemoteConfigPrepareToChange,
        const FDTDRemoteConfigReceiveResultDynamicDelegate& onRemoteConfigReceive);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InitializeWithConfigWithAbTest", Keywords = "initialize with config with ab-tests"), Category = "DTD|Analytics")
	static void InitializeWithConfigWithAbTest(const FString& appKey, 
		const FDTDAnalyticsConfiguration& config,
		const FDTDRemoteConfigChangeResultDynamicDelegate& onRemoteConfigChange,
        const FDTDRemoteConfigPrepareToChangeDynamicDelegate& onRemoteConfigPrepareToChange,
        const FDTDRemoteConfigReceiveResultDynamicDelegate& onRemoteConfigReceive);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StartActivity", Keywords = "start activity"), Category = "DTD|Analytics")
	static void StartActivity();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopActivity", Keywords = "stop activity"), Category = "DTD|Analytics")
	static void StopActivity();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetUserId", Keywords = "set user id"), Category = "DTD|Analytics")
	static void SetUserId(const FString& userId);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ReplaceUserId", Keywords = "replace user id"), Category = "DTD|Analytics")
	static void ReplaceUserId(const FString& fromUserId, const FString& toUserId);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CustomEvent", Keywords = "custom event"), Category = "DTD|Analytics")
	static void CustomEvent(const FString& eventName);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CustomEventWithParams", Keywords = "custom event with params"), Category = "DTD|Analytics")
	static void CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetCurrentLevel", Keywords = "set current level"), Category = "DTD|Analytics")
	static void SetCurrentLevel(int32 level);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetTrackingAvailability", Keywords = "set tracking availability"), Category = "DTD|Analytics")
	static void SetTrackingAvailability(bool value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CurrencyAccrual", Keywords = "currency accrual"), Category = "DTD|Analytics")
	static void CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "VirtualCurrencyPayment", Keywords = "virtual currency payment"), Category = "DTD|Analytics")
	static void VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "VirtualCurrencyPaymentWithResources", Keywords = "virtual currency payment with resources"), Category = "DTD|Analytics")
	static void VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LevelUp", Keywords = "level up"), Category = "DTD|Analytics")
	static void LevelUp(int32 level);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LevelUpWithBalance", Keywords = "level up with balance"), Category = "DTD|Analytics")
	static void LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CurrentBalance", Keywords = "current balance"), Category = "DTD|Analytics")
	static void CurrentBalance(const TMap<FString, int64>& balance);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Referrer", Keywords = "referrer"), Category = "DTD|Analytics")
	static void Referrer(const TMap<EDTDReferralProperty, FString>& utmData);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Tutorial", Keywords = "tutorial"), Category = "DTD|Analytics")
	static void Tutorial(int32 step);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StartProgressionEvent", Keywords = "start progression event"), Category = "DTD|Analytics")
	static void StartProgressionEvent(const FString& eventName);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StartProgressionEventWithParams", Keywords = "start progression event with params"), Category = "DTD|Analytics")
	static void StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FinishProgressionEvent", Keywords = "finish progression event"), Category = "DTD|Analytics")
	static void FinishProgressionEvent(const FString& eventName);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FinishProgressionEventWithParams", Keywords = "finish progression event with params"), Category = "DTD|Analytics")
	static void FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "RealCurrencyPayment", Keywords = "real currency payment"), Category = "DTD|Analytics")
	static void RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SocialNetworkConnect", Keywords = "social network connect"), Category = "DTD|Analytics")
	static void SocialNetworkConnect(EDTDSocialNetwork socialNetwork);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SocialNetworkConnectCustom", Keywords = "social network connect custom"), Category = "DTD|Analytics")
	static void SocialNetworkConnectCustom(const FString& socialNetwork);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SocialNetworkPost", Keywords = "social network post"), Category = "DTD|Analytics")
	static void SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SocialNetworkPostCustom", Keywords = "social network post custom"), Category = "DTD|Analytics")
	static void SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AdImpression", Keywords = "ad impression"), Category = "DTD|Analytics")
	static void AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SendBufferedEvents", Keywords = "send buffered events"), Category = "DTD|Analytics")
	static void SendBufferedEvents();
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetLogLevel", Keywords = "set log level"), Category = "DTD|Analytics")
	static void SetLogLevel(EDTDLogLevel logLevel);

	//
	// Methods to interact from C++ code.
	//

	static void SetIdentifiersListener(const FDTDLongListenerDelegate& listener);
	static void GetDeviceId(const FDTDGetterStringDelegate& onResult);
	static void GetSdkVersion(const FDTDGetterStringDelegate& onResult);
	static void GetApplicationVersion(const FDTDGetterStringDelegate& onResult);
	static void GetTrackingAvailability(const FDTDGetterBoolDelegate& onResult);
	static void GetUserId(const FDTDGetterStringDelegate& onResult);
	static void GetCurrentLevel(const FDTDGetterIntDelegate& onResult);
	static void InitializeWithAbTest(const FString& appKey,
		const FDTDRemoteConfigChangeResultDelegate& onRemoteConfigChange,
        const FDTDRemoteConfigPrepareToChangeDelegate& onRemoteConfigPrepareToChange,
        const FDTDRemoteConfigReceiveResultDelegate& onRemoteConfigReceive);

	static void InitializeWithConfigWithAbTest(const FString& appKey, 
		const FDTDAnalyticsConfiguration& config,
		const FDTDRemoteConfigChangeResultDelegate& onRemoteConfigChange,
        const FDTDRemoteConfigPrepareToChangeDelegate& onRemoteConfigPrepareToChange,
        const FDTDRemoteConfigReceiveResultDelegate& onRemoteConfigReceive);
};
