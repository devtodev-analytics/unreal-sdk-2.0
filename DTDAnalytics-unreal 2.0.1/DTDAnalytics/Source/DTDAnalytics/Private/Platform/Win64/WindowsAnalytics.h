// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Platform/PlatformAnalytics.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

class WindowsAnalytics : public PlatformAnalytics
{
public:
	WindowsAnalytics();
	~WindowsAnalytics();
	void SetTestProxyUrl(const FString& url) override;
	void SetTestCustomUrl(const FString& url) override;
	void TestLogs() override;
	void TestString(const FString& value) override;
	void SetLoggerMessageListener(const FDTDLogsListenerDelegate* listener) override;
	void SetIdentifiersListener(const FDTDLongListenerDelegate* listener) override;
	void GetDeviceId(const FDTDGetterStringDelegate* onResult) override;
	void GetSdkVersion(const FDTDGetterStringDelegate* onResult) override;
	void GetApplicationVersion(const FDTDGetterStringDelegate* onResult) override;
	void SetApplicationVersion(const FString& value) override;
	void GetTrackingAvailability(const FDTDGetterBoolDelegate* onResult) override;
	void GetUserId(const FDTDGetterStringDelegate* onResult) override;
	void GetCurrentLevel(const FDTDGetterIntDelegate* onResult) override;
	void Initialize(const FString& appKey) override;
	void InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config) override;
	void Deinitialize() override;
	void StartActivity() override;
	void StopActivity() override;
	void SetUserId(const FString& userId) override;
	void ReplaceUserId(const FString& fromUserId, const FString& toUserId) override;
	void CustomEvent(const FString& eventName) override;
	void CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params) override;
	void SetCurrentLevel(int32 level) override;
	void SetTrackingAvailability(bool value) override;
	void CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType) override;
	void VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency) override;
	void VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources) override;
	void LevelUp(int32 level) override;
	void LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance) override;
	void CurrentBalance(const TMap<FString, int64>& balance) override;
	void Referrer(const TMap<EDTDReferralProperty, FString>& utmData) override;
	void Tutorial(int32 step) override;
	void StartProgressionEvent(const FString& eventName) override;
	void StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params) override;
	void FinishProgressionEvent(const FString& eventName) override;
	void FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params) override;
	void RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode) override;
	void SocialNetworkConnect(EDTDSocialNetwork socialNetwork) override;
	void SocialNetworkConnectCustom(const FString& socialNetwork) override;
	void SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason) override;
	void SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason) override;
	void AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit) override;
	void SendBufferedEvents() override;
	void SetLogLevel(EDTDLogLevel logLevel) override;
	void GetName(const FDTDGetterStringDelegate* onResult) override;
	void GetEmail(const FDTDGetterStringDelegate* onResult) override;
	void GetPhone(const FDTDGetterStringDelegate* onResult) override;
	void GetPhoto(const FDTDGetterStringDelegate* onResult) override;
	void GetGender(const FDTDGetterGenderDelegate* onResult) override;
	void GetAge(const FDTDGetterLongDelegate* onResult) override;
	void GetCheater(const FDTDGetterBoolDelegate* onResult) override;
	void TryGetString(const FString& key, const FDTDGetterOptionalStringDelegate* onResult) override;
	void TryGetBool(const FString& key, const FDTDGetterOptionalBoolDelegate* onResult) override;
	void TryGetFloat(const FString& key, const FDTDGetterOptionalFloatDelegate* onResult) override;
	void TryGetLong(const FString& key, const FDTDGetterOptionalLongDelegate* onResult) override;
	void SetName(const FString& name) override;
	void SetEmail(const FString& email) override;
	void SetPhone(const FString& phone) override;
	void SetPhoto(const FString& photo) override;
	void SetGender(EDTDGender gender) override;
	void SetAge(int64 age) override;
	void SetCheater(bool cheater) override;
	void SetString(const FString& key, const FString& value) override;
	void SetBool(const FString& key, bool value) override;
	void SetInt(const FString& key, int64 value) override;
	void SetFloat(const FString& key, float value) override;
	void Unset(const FString& key) override;
	void UnsetArray(const TArray<FString>& keys) override;
	void IncrementInt(const FString& key, int64 value) override;
	void IncrementFloat(const FString& key, float value) override;
	void ClearUser() override;
private:
	const FDTDLogsListenerDelegate* logsListener = nullptr;
};

#endif
