// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDLogLevel.h"
#include "DTDAnalyticsConfiguration.h"
#include "DTDCustomEventParams.h"
#include "DTDReferralProperty.h"
#include "DTDAccrualType.h"
#include "DTDSocialNetwork.h"
#include "DTDGender.h"
#include "DTDStartProgressionEventParams.h"
#include "DTDFinishProgressionEventParams.h"
#include "DTDDelegates.h"
#include "DTDAccrualType.h"
#include "DTDSocialNetwork.h"
#include "DTDGender.h"
#include "DTDRemoteConfigValue.h"
#include "DTDRemoteConfigDefaults.h"


class PlatformAnalytics
{
public:
	virtual ~PlatformAnalytics() { }
	virtual void SetTestProxyUrl(const FString& url) = 0;
	virtual void SetTestCustomUrl(const FString& url) = 0;
	virtual void TestLogs() = 0;
	virtual void TestString(const FString& value) = 0;
	virtual void SetLoggerMessageListener(const FDTDLogsListenerDelegate* listener) = 0;

	virtual void CoppaControlEnable() = 0;
	virtual void SetInitializationCompleteCallback(const FDTDAnalyticsInitializationCompleteDelegate* callback) = 0;
	virtual void SetIdentifiersListener(const FDTDLongListenerDelegate* listener) = 0;
	virtual void GetDeviceId(const FDTDGetterStringDelegate* onResult) = 0;
	virtual void GetSdkVersion(const FDTDGetterStringDelegate* onResult) = 0;
	virtual void GetApplicationVersion(const FDTDGetterStringDelegate* onResult) = 0;
	virtual void SetApplicationVersion(const FString& value) = 0;
	virtual void GetTrackingAvailability(const FDTDGetterBoolDelegate* onResult) = 0;
	virtual void GetUserId(const FDTDGetterStringDelegate* onResult) = 0;
	virtual void GetCurrentLevel(const FDTDGetterIntDelegate* onResult) = 0;
	virtual void Initialize(const FString& appKey) = 0;
	virtual void InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config) = 0;
	virtual void Deinitialize() = 0;
	virtual void StartActivity() = 0;
	virtual void StopActivity() = 0;
	virtual void SetUserId(const FString& userId) = 0;
	virtual void ReplaceUserId(const FString& fromUserId, const FString& toUserId) = 0;
	virtual void CustomEvent(const FString& eventName) = 0;
	virtual void CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params) = 0;
	virtual void SetCurrentLevel(int32 level) = 0;
	virtual void SetTrackingAvailability(bool value) = 0;
	virtual void CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType) = 0;
	virtual void VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency) = 0;
	virtual void VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources) = 0;
	virtual void LevelUp(int32 level) = 0;
	virtual void LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance) = 0;
	virtual void CurrentBalance(const TMap<FString, int64>& balance) = 0;
	virtual void Referrer(const TMap<EDTDReferralProperty, FString>& utmData) = 0;
	virtual void Tutorial(int32 step) = 0;
	virtual void StartProgressionEvent(const FString& eventName) = 0;
	virtual void StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params) = 0;
	virtual void FinishProgressionEvent(const FString& eventName) = 0;
	virtual void FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params) = 0;
	virtual void RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode) = 0;
	virtual void SocialNetworkConnect(EDTDSocialNetwork socialNetwork) = 0;
	virtual void SocialNetworkConnectCustom(const FString& socialNetwork) = 0;
	virtual void SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason) = 0;
	virtual void SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason) = 0;
	virtual void AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit) = 0;
	virtual void SendBufferedEvents() = 0;
	virtual void SetLogLevel(EDTDLogLevel logLevel) = 0;
	virtual void GetName(const FDTDGetterStringDelegate* onResult) = 0;
	virtual void GetEmail(const FDTDGetterStringDelegate* onResult) = 0;
	virtual void GetPhone(const FDTDGetterStringDelegate* onResult) = 0;
	virtual void GetPhoto(const FDTDGetterStringDelegate* onResult) = 0;
	virtual void GetGender(const FDTDGetterGenderDelegate* onResult) = 0;
	virtual void GetAge(const FDTDGetterLongDelegate* onResult) = 0;
	virtual void TryGetString(const FString& key, const FDTDGetterOptionalStringDelegate* onResult) = 0;
	virtual void TryGetBool(const FString& key, const FDTDGetterOptionalBoolDelegate* onResult) = 0;
	virtual void TryGetFloat(const FString& key, const FDTDGetterOptionalFloatDelegate* onResult) = 0;
	virtual void TryGetLong(const FString& key, const FDTDGetterOptionalLongDelegate* onResult) = 0;
	virtual void SetName(const FString& name) = 0;
	virtual void SetEmail(const FString& email) = 0;
	virtual void SetPhone(const FString& phone) = 0;
	virtual void SetPhoto(const FString& photo) = 0;
	virtual void SetGender(EDTDGender gender) = 0;
	virtual void SetAge(int64 age) = 0;
	virtual void SetCheater(bool cheater) = 0;
	virtual void SetTester(bool tester) = 0;
	virtual void SetString(const FString& key, const FString& value) = 0;
	virtual void SetBool(const FString& key, bool value) = 0;
	virtual void SetInt(const FString& key, int64 value) = 0;
	virtual void SetFloat(const FString& key, float value) = 0;
	virtual void Unset(const FString& key) = 0;
	virtual void UnsetArray(const TArray<FString>& keys) = 0;
	virtual void IncrementInt(const FString& key, int64 value) = 0;
	virtual void IncrementFloat(const FString& key, float value) = 0;
	virtual void ClearUser() = 0;

	// AB Tests
	virtual void InitializeWithAbTest(const FString& appKey,
		const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChange, 
		const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChange,
		const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceive) = 0;

	virtual void InitializeWithConfigWithAbTest(const FString& appKey,
		const FDTDAnalyticsConfiguration& config, 
		const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChange,
		const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChange,
		const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceive) = 0;
	virtual float GetRemoteConfigWaiting() = 0;
	virtual void SetRemoteConfigWaiting(float value) = 0;
	virtual float GetGroupDefinitionWaiting() = 0;
	virtual void SetGroupDefinitionWaiting(float value) = 0;
	virtual void SetDefaults(const FDTDRemoteConfigDefaults& defaults) = 0;
    virtual void ApplyConfig() = 0;
	virtual void ResetConfig() = 0;
    virtual TMap<FString, FDTDRemoteConfigValue> GetConfig() = 0;
	virtual FDTDRemoteConfigValue GetRemoteConfigValue(const FString& key) = 0;
	virtual bool HasKey(const FString& key) = 0;
	virtual void CacheTestExperiment() = 0;
};
