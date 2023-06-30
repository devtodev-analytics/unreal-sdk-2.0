// Copyright (c) devtodev. All rights reserved.

#include "StubbedAnalytics.h"

#include "DTDLogLevel.h"

#include "Logging/DTDLogs.h"

StubbedAnalytics::StubbedAnalytics()
{
	DTDLogs::CallStubbedMethodInfo("StubbedAnalytics");
}

StubbedAnalytics::~StubbedAnalytics()
{
	DTDLogs::CallStubbedMethodInfo("~StubbedAnalytics");
}

void StubbedAnalytics::SetTestProxyUrl(const FString& url)
{
	DTDLogs::CallStubbedMethodInfo("SetTestProxyUrl");
}

void StubbedAnalytics::SetTestCustomUrl(const FString& url)
{
	DTDLogs::CallStubbedMethodInfo("SetTestCustomUrl");
}

void StubbedAnalytics::TestLogs()
{
	DTDLogs::CallStubbedMethodInfo("TestLogs");
}

void StubbedAnalytics::TestString(const FString& value)
{
	DTDLogs::CallStubbedMethodInfo("TestString");
}

void StubbedAnalytics::SetLoggerMessageListener(const FDTDLogsListenerDelegate* listener)
{
	DTDLogs::CallStubbedMethodInfo("SetLoggerMessageListener");
	listener->ExecuteIfBound(EDTDLogLevel::Warning, TEXT("STUBBED_LOG_MESSAGE"));
	delete listener;
}

void StubbedAnalytics::CoppaControlEnable()
{
	DTDLogs::CallStubbedMethodInfo("CoppaControlEnable");
}

void StubbedAnalytics::SetInitializationCompleteCallback(const FDTDAnalyticsInitializationCompleteDelegate* callback)
{
	DTDLogs::CallStubbedMethodInfo("STUBBED_InitializationComplete");
	callback->ExecuteIfBound();
	delete callback;
}

void StubbedAnalytics::SetIdentifiersListener(const FDTDLongListenerDelegate* listener)
{
	DTDLogs::CallStubbedMethodInfo("SetIdentifiersListener");
	listener->ExecuteIfBound(777);
	delete listener;
}

void StubbedAnalytics::GetDeviceId(const FDTDGetterStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetDeviceId");
	onResult->ExecuteIfBound(TEXT("STUBBED_DEVICE_ID"));
	delete onResult;
}

void StubbedAnalytics::GetSdkVersion(const FDTDGetterStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetSdkVersion");
	onResult->ExecuteIfBound(TEXT("STUBBED_SDK_VERSION"));
	delete onResult;
}

void StubbedAnalytics::GetApplicationVersion(const FDTDGetterStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetApplicationVersion");
	onResult->ExecuteIfBound(TEXT("STUBBED_APPLICATION_VERSION"));
	delete onResult;
}

void StubbedAnalytics::SetApplicationVersion(const FString& value)
{
	DTDLogs::CallStubbedMethodInfo("SetApplicationVersion");
}

void StubbedAnalytics::GetTrackingAvailability(const FDTDGetterBoolDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetTrackingAvailability");
	onResult->ExecuteIfBound(true);
	delete onResult;
}

void StubbedAnalytics::GetUserId(const FDTDGetterStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetUserId");
	onResult->ExecuteIfBound(TEXT("STUBBED_USER_ID"));
	delete onResult;
}

void StubbedAnalytics::GetCurrentLevel(const FDTDGetterIntDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetCurrentLevel");
	onResult->ExecuteIfBound(777);
	delete onResult;
}

void StubbedAnalytics::Initialize(const FString& appKey)
{
	DTDLogs::CallStubbedMethodInfo("Initialize");
}

void StubbedAnalytics::InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config)
{
	DTDLogs::CallStubbedMethodInfo("InitializeWithConfig");
}

void StubbedAnalytics::Deinitialize()
{
	DTDLogs::CallStubbedMethodInfo("Deinitialize");
}

void StubbedAnalytics::StartActivity()
{
	DTDLogs::CallStubbedMethodInfo("StartActivity");
}

void StubbedAnalytics::StopActivity()
{
	DTDLogs::CallStubbedMethodInfo("StopActivity");
}

void StubbedAnalytics::SetUserId(const FString& userId)
{
	DTDLogs::CallStubbedMethodInfo("SetUserId");
}

void StubbedAnalytics::ReplaceUserId(const FString& fromUserId, const FString& toUserId)
{
	DTDLogs::CallStubbedMethodInfo("ReplaceUserId");
}

void StubbedAnalytics::CustomEvent(const FString& eventName)
{
	DTDLogs::CallStubbedMethodInfo("CustomEvent");
}

void StubbedAnalytics::CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params)
{
	DTDLogs::CallStubbedMethodInfo("CustomEventWithParams");
}

void StubbedAnalytics::SetCurrentLevel(int32 level)
{
	DTDLogs::CallStubbedMethodInfo("SetCurrentLevel");
}

void StubbedAnalytics::SetTrackingAvailability(bool value)
{
	DTDLogs::CallStubbedMethodInfo("SetTrackingAvailability");
}

void StubbedAnalytics::CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType)
{
	DTDLogs::CallStubbedMethodInfo("CurrencyAccrual");
}

void StubbedAnalytics::VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency)
{
	DTDLogs::CallStubbedMethodInfo("VirtualCurrencyPayment");
}

void StubbedAnalytics::VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources)
{
	DTDLogs::CallStubbedMethodInfo("VirtualCurrencyPaymentWithResources");
}

void StubbedAnalytics::LevelUp(int32 level)
{
	DTDLogs::CallStubbedMethodInfo("LevelUp");
}

void StubbedAnalytics::LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance)
{
	DTDLogs::CallStubbedMethodInfo("LevelUpWithBalance");
}

void StubbedAnalytics::CurrentBalance(const TMap<FString, int64>& balance)
{
	DTDLogs::CallStubbedMethodInfo("CurrentBalance");
}

void StubbedAnalytics::Referrer(const TMap<EDTDReferralProperty, FString>& utmData)
{
	DTDLogs::CallStubbedMethodInfo("Referrer");
}

void StubbedAnalytics::Tutorial(int32 step)
{
	DTDLogs::CallStubbedMethodInfo("Tutorial");
}

void StubbedAnalytics::StartProgressionEvent(const FString& eventName)
{
	DTDLogs::CallStubbedMethodInfo("StartProgressionEvent");
}

void StubbedAnalytics::StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params)
{
	DTDLogs::CallStubbedMethodInfo("StartProgressionEventWithParams");
}

void StubbedAnalytics::FinishProgressionEvent(const FString& eventName)
{
	DTDLogs::CallStubbedMethodInfo("FinishProgressionEvent");
}

void StubbedAnalytics::FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params)
{
	DTDLogs::CallStubbedMethodInfo("FinishProgressionEventWithParams");
}

void StubbedAnalytics::RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode)
{
	DTDLogs::CallStubbedMethodInfo("RealCurrencyPayment");
}

void StubbedAnalytics::SocialNetworkConnect(EDTDSocialNetwork socialNetwork)
{
	DTDLogs::CallStubbedMethodInfo("SocialNetworkConnect");
}

void StubbedAnalytics::SocialNetworkConnectCustom(const FString& socialNetwork)
{
	DTDLogs::CallStubbedMethodInfo("SocialNetworkConnectCustom");
}

void StubbedAnalytics::SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason)
{
	DTDLogs::CallStubbedMethodInfo("SocialNetworkPost");
}

void StubbedAnalytics::SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason)
{
	DTDLogs::CallStubbedMethodInfo("SocialNetworkPostCustom");
}

void StubbedAnalytics::AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit)
{
	DTDLogs::CallStubbedMethodInfo("AdImpression");
}

void StubbedAnalytics::SendBufferedEvents()
{
	DTDLogs::CallStubbedMethodInfo("SendBufferedEvents");
}

void StubbedAnalytics::SetLogLevel(EDTDLogLevel logLevel)
{
	DTDLogs::CallStubbedMethodInfo("SetLogLevel");
}

void StubbedAnalytics::GetName(const FDTDGetterStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetName");
	onResult->ExecuteIfBound(TEXT("STUBBED_NAME"));
	delete onResult;
}

void StubbedAnalytics::GetEmail(const FDTDGetterStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetEmail");
	onResult->ExecuteIfBound(TEXT("STUBBED_EMAIL"));
	delete onResult;
}

void StubbedAnalytics::GetPhone(const FDTDGetterStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetPhone");
	onResult->ExecuteIfBound(TEXT("STUBBED_PHONE"));
	delete onResult;
}

void StubbedAnalytics::GetPhoto(const FDTDGetterStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetPhoto");
	onResult->ExecuteIfBound(TEXT("STUBBED_PHOTO"));
	delete onResult;
}

void StubbedAnalytics::GetGender(const FDTDGetterGenderDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetGender");
	onResult->ExecuteIfBound(EDTDGender::Male);
	delete onResult;
}

void StubbedAnalytics::GetAge(const FDTDGetterLongDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("GetAge");
	onResult->ExecuteIfBound(888);
	delete onResult;
}

void StubbedAnalytics::TryGetString(const FString& key, const FDTDGetterOptionalStringDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("TryGetString");
	onResult->ExecuteIfBound(true, TEXT("STUBBED_TRY_STRING"));
	delete onResult;
}

void StubbedAnalytics::TryGetBool(const FString& key, const FDTDGetterOptionalBoolDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("TryGetBool");
	onResult->ExecuteIfBound(true, true);
	delete onResult;
}

void StubbedAnalytics::TryGetFloat(const FString& key, const FDTDGetterOptionalFloatDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("TryGetFloat");
	onResult->ExecuteIfBound(true, 4.44f);
	delete onResult;
}

void StubbedAnalytics::TryGetLong(const FString& key, const FDTDGetterOptionalLongDelegate* onResult)
{
	DTDLogs::CallStubbedMethodInfo("TryGetLong");
	onResult->ExecuteIfBound(true, 444);
	delete onResult;
}

void StubbedAnalytics::SetName(const FString& name)
{
	DTDLogs::CallStubbedMethodInfo("SetName");
}

void StubbedAnalytics::SetEmail(const FString& email)
{
	DTDLogs::CallStubbedMethodInfo("SetEmail");
}

void StubbedAnalytics::SetPhone(const FString& phone)
{
	DTDLogs::CallStubbedMethodInfo("SetPhone");
}

void StubbedAnalytics::SetPhoto(const FString& photo)
{
	DTDLogs::CallStubbedMethodInfo("SetPhoto");
}

void StubbedAnalytics::SetGender(EDTDGender gender)
{
	DTDLogs::CallStubbedMethodInfo("SetGender");
}

void StubbedAnalytics::SetAge(int64 age)
{
	DTDLogs::CallStubbedMethodInfo("SetAge");
}

void StubbedAnalytics::SetCheater(bool cheater)
{
	DTDLogs::CallStubbedMethodInfo("SetCheater");
}

void StubbedAnalytics::SetTester(bool tester)
{
	DTDLogs::CallStubbedMethodInfo("SetTester");
}

void StubbedAnalytics::SetString(const FString& key, const FString& value)
{
	DTDLogs::CallStubbedMethodInfo("SetString");
}

void StubbedAnalytics::SetBool(const FString& key, bool value)
{
	DTDLogs::CallStubbedMethodInfo("SetBool");
}

void StubbedAnalytics::SetInt(const FString& key, int64 value)
{
	DTDLogs::CallStubbedMethodInfo("SetInt");
}

void StubbedAnalytics::SetFloat(const FString& key, float value)
{
	DTDLogs::CallStubbedMethodInfo("SetFloat");
}

void StubbedAnalytics::Unset(const FString& key)
{
	DTDLogs::CallStubbedMethodInfo("Unset");
}

void StubbedAnalytics::UnsetArray(const TArray<FString>& keys)
{
	DTDLogs::CallStubbedMethodInfo("UnsetArray");
}

void StubbedAnalytics::IncrementInt(const FString& key, int64 value)
{
	DTDLogs::CallStubbedMethodInfo("IncrementInt");
}

void StubbedAnalytics::IncrementFloat(const FString& key, float value)
{
	DTDLogs::CallStubbedMethodInfo("IncrementFloat");
}

void StubbedAnalytics::ClearUser()
{
	DTDLogs::CallStubbedMethodInfo("ClearUser");
}

// AB Tests
void StubbedAnalytics::InitializeWithAbTest(const FString& appKey,
	const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChange, 
	const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChange,
	const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceive)
{
	DTDLogs::CallStubbedMethodInfo("InitializeWithAbTest");
	if (onRemoteConfigChange != nullptr)
	{
		delete onRemoteConfigChange;
	}

	if (onRemoteConfigPrepareToChange != nullptr)
	{
		delete onRemoteConfigPrepareToChange;
	}
	
	if (onRemoteConfigReceive != nullptr)
	{
		delete onRemoteConfigReceive;
	}
}

void StubbedAnalytics::InitializeWithConfigWithAbTest(const FString& appKey,
		const FDTDAnalyticsConfiguration& config, 
		const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChange, 
		const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChange,
		const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceive)
{
	DTDLogs::CallStubbedMethodInfo("InitializeWithConfigWithAbTest");
	if (onRemoteConfigChange != nullptr)
	{
		delete onRemoteConfigChange;
	}

	if (onRemoteConfigPrepareToChange != nullptr)
	{
		delete onRemoteConfigPrepareToChange;
	}
	
	if (onRemoteConfigReceive != nullptr)
	{
		delete onRemoteConfigReceive;
	}
}

float StubbedAnalytics::GetRemoteConfigWaiting()
{
	DTDLogs::CallStubbedMethodInfo("GetRemoteConfigWaiting");
	return 0;
}

void StubbedAnalytics::SetRemoteConfigWaiting(float value)
{
	DTDLogs::CallStubbedMethodInfo("SetRemoteConfigWaiting");
}

float StubbedAnalytics::GetGroupDefinitionWaiting()
{
	DTDLogs::CallStubbedMethodInfo("GetGroupDefinitionWaiting");
	return 0;
}

void StubbedAnalytics::SetGroupDefinitionWaiting(float value)
{
	DTDLogs::CallStubbedMethodInfo("SetGroupDefinitionWaiting");
}

void StubbedAnalytics::SetDefaults(const FDTDRemoteConfigDefaults& defaults)
{
	DTDLogs::CallStubbedMethodInfo("SetDefaults");
}

void StubbedAnalytics::ApplyConfig()
{
	DTDLogs::CallStubbedMethodInfo("ApplyConfig");
}

void StubbedAnalytics::ResetConfig()
{
	DTDLogs::CallStubbedMethodInfo("ResetConfig");
}

TMap<FString, FDTDRemoteConfigValue> StubbedAnalytics::GetConfig() {
	DTDLogs::CallStubbedMethodInfo("GetConfig");
    return localConfig;
}

FDTDRemoteConfigValue StubbedAnalytics::GetRemoteConfigValue(const FString& key) {
	DTDLogs::CallStubbedMethodInfo("GetRemoteConfigValue");
	return localConfig[key];
}

bool StubbedAnalytics::HasKey(const FString& key) {
	DTDLogs::CallStubbedMethodInfo("HasKey");
	return false;
}

void StubbedAnalytics::CacheTestExperiment() {
	DTDLogs::CallStubbedMethodInfo("CacheTestExperiment");
}
