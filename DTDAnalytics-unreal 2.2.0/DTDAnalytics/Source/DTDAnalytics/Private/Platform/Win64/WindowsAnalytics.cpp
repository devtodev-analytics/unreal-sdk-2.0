// Copyright (c) devtodev. All rights reserved.

#include "WindowsAnalytics.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

// TODO: Need to remove?
#include <iostream>

#include "Misc/DateTime.h"

#include "../../../../../ThirdParty/Windows/Headers/DTDAnalytics.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDUserCard.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDRemoteConfig.h"
#include "../../../../../ThirdParty/Windows/Headers/Logger.h"
#include "WindowsConverter.h"
#include "Constants/SDKConstants.h"
#include "SocialNetwork/DTDSocialNetworkKeys.h"
#include "Delegates/DTDDelegateBoolArgWrapper.h"
#include "Delegates/DTDDelegateVoidArgWrapper.h"
#include "Delegates/DTDDelegateGenderArgWrapper.h"
#include "Delegates/DTDDelegateIntArgWrapper.h"
#include "Delegates/DTDDelegateLongArgWrapper.h"
#include "Delegates/DTDDelegateListenerLongArgWrapper.h"
#include "Delegates/DTDDelegateOptionalBoolArgWrapper.h"
#include "Delegates/DTDDelegateOptionalDoubleArgWrapper.h"
#include "Delegates/DTDDelegateOptionalLongArgWrapper.h"
#include "Delegates/DTDDelegateOptionalStringArgWrapper.h"
#include "Delegates/DTDDelegateStringArgWrapper.h"
#include "Delegates/DTDDelegateLogLevelAndStringArgsWrapper.h"
#include "Delegates/DTDRemoteConfigUnrealListener.h"
#include "Json.h"

WindowsAnalytics::WindowsAnalytics()
{
	// Initialized wrapper first.
	::DevToDevAnalyticsUnrealWindows::DTDAnalytics::InitializeWrapper();

	// Override SDK version.
	const auto m_version = WindowsConverter::Convert(SDKConstants::Version);
	::DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetSdkVersion(m_version);

	// Setup logging.
	auto logsUnrealListener = new FDTDLogsListenerDelegate();
	logsUnrealListener->BindLambda([this] (EDTDLogLevel logLevel, const FString& message)
	{
#if !UE_BUILD_SHIPPING
		const auto u_now = FDateTime::Now().ToString(TEXT("%Y/%m/%d %H:%M:%S:%s"));
#else 
		const auto u_now = FDateTime::Now().ToString(TEXT("%Y/%m/%d %H:%M:%S"));
#endif
		TArray<FStringFormatArg> formattingArgs; 
		formattingArgs.Add(FStringFormatArg(u_now));
		formattingArgs.Add(FStringFormatArg(SDKConstants::Version));
		formattingArgs.Add(FStringFormatArg(message));
		const FString formattedMessage = FString::Format(TEXT("{0} [DevToDev {1}] {2}"), formattingArgs);
		switch (logLevel)
		{
		case EDTDLogLevel::Error:
			UE_LOG(LogTemp, Error, TEXT("%s"), *formattedMessage);
			break;
		case EDTDLogLevel::Warning:
			UE_LOG(LogTemp, Warning, TEXT("%s"), *formattedMessage);
			break;
		case EDTDLogLevel::Info:
		case EDTDLogLevel::Debug:
			UE_LOG(LogTemp, Display, TEXT("%s"), *formattedMessage);
			break;
		default:
			break;
		}

		if (logsListener != nullptr)
		{
			logsListener->ExecuteIfBound(logLevel, formattedMessage);
		}
	});
	const auto logsNetHandler = new DTDDelegateLogLevelAndStringArgsWrapper(logsUnrealListener);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::OnLoggerMessage(logsNetHandler);
}

WindowsAnalytics::~WindowsAnalytics()
{
	if (logsListener != nullptr)
	{
		delete logsListener;
	}
}

void WindowsAnalytics::SetTestProxyUrl(const FString& url)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetTestProxyUrl(WindowsConverter::Convert(url));
}

void WindowsAnalytics::SetTestCustomUrl(const FString& url)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetTestCustomUrl(WindowsConverter::Convert(url));
}

void WindowsAnalytics::TestLogs()
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::TestLogs();
}

void WindowsAnalytics::TestString(const FString& value)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::TestString(WindowsConverter::Convert(value));
}

void WindowsAnalytics::SetLoggerMessageListener(const FDTDLogsListenerDelegate* listener)
{
	if (logsListener != nullptr)
	{
		delete logsListener;
	}

	logsListener = listener;
}

void WindowsAnalytics::SetIdentifiersListener(const FDTDLongListenerDelegate* listener)
{
	const auto delWrapper = new DTDDelegateListenerLongArgWrapper(listener);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetIdentifiersListener(delWrapper);
}

void WindowsAnalytics::CoppaControlEnable()
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CoppaControlEnable();
}

void WindowsAnalytics::SetInitializationCompleteCallback(const FDTDAnalyticsInitializationCompleteDelegate* callback)
{
	const auto delWrapper = new DTDDelegateVoidArgWrapper(callback);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetInitializationCompleteCallback(delWrapper);
}

void WindowsAnalytics::GetDeviceId(const FDTDGetterStringDelegate* onResult)
{
	 const auto delWrapper = new DTDDelegateStringArgWrapper(onResult);
	 DevToDevAnalyticsUnrealWindows::DTDAnalytics::GetDeviceId(delWrapper);
}

void WindowsAnalytics::GetSdkVersion(const FDTDGetterStringDelegate* onResult)
{
	 const auto delWrapper = new DTDDelegateStringArgWrapper(onResult);
	 DevToDevAnalyticsUnrealWindows::DTDAnalytics::GetSdkVersion(delWrapper);
}

void WindowsAnalytics::GetApplicationVersion(const FDTDGetterStringDelegate* onResult)
{
	 const auto delWrapper = new DTDDelegateStringArgWrapper(onResult);
	 DevToDevAnalyticsUnrealWindows::DTDAnalytics::GetApplicationVersion(delWrapper);
}

void WindowsAnalytics::SetApplicationVersion(const FString& value)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetApplicationVersion(WindowsConverter::Convert(value));
}

void WindowsAnalytics::GetTrackingAvailability(const FDTDGetterBoolDelegate* onResult)
{
	const auto delWrapper = new DTDDelegateBoolArgWrapper(onResult);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::GetTrackingAvailability(delWrapper);
}

void WindowsAnalytics::GetUserId(const FDTDGetterStringDelegate* onResult)
{
	 const auto delWrapper = new DTDDelegateStringArgWrapper(onResult);
	 DevToDevAnalyticsUnrealWindows::DTDAnalytics::GetUserId(delWrapper);
}

void WindowsAnalytics::GetCurrentLevel(const FDTDGetterIntDelegate* onResult)
{
	const auto delWrapper = new DTDDelegateIntArgWrapper(onResult);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::GetCurrentLevel(delWrapper);
}

void WindowsAnalytics::Initialize(const FString& appKey)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::Initialize(WindowsConverter::Convert(appKey));
}

void WindowsAnalytics::InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::InitializeWithConfig(WindowsConverter::Convert(appKey), WindowsConverter::Convert(config));
}

void WindowsAnalytics::Deinitialize()
{
	localConfig.Empty();
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::Deinitialize();
}

void WindowsAnalytics::StartActivity()
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::StartActivity();
}

void WindowsAnalytics::StopActivity()
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::StopActivity();
}

void WindowsAnalytics::SetUserId(const FString& userId)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetUserId(WindowsConverter::Convert(userId));
}

void WindowsAnalytics::ReplaceUserId(const FString& fromUserId, const FString& toUserId)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::ReplaceUserId(WindowsConverter::Convert(fromUserId), WindowsConverter::Convert(toUserId));
}

void WindowsAnalytics::CustomEvent(const FString& eventName)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CustomEvent(WindowsConverter::Convert(eventName));
}

void WindowsAnalytics::CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CustomEventWithParams(WindowsConverter::Convert(eventName), WindowsConverter::Convert(params));
}

void WindowsAnalytics::SetCurrentLevel(int32 level)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetCurrentLevel(level);
}

void WindowsAnalytics::SetTrackingAvailability(bool value)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetTrackingAvailability(value);
}

void WindowsAnalytics::CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CurrencyAccrual(WindowsConverter::Convert(currencyName), currencyAmount, WindowsConverter::Convert(source), WindowsConverter::Convert(accrualType));
}

void WindowsAnalytics::VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::VirtualCurrencyPayment(
		WindowsConverter::Convert(purchaseId), 
		WindowsConverter::Convert(purchaseType), 
		purchaseAmount, purchasePrice, 
		WindowsConverter::Convert(purchaseCurrency));
}

void WindowsAnalytics::VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::VirtualCurrencyPaymentWithMultipleCurrency(WindowsConverter::Convert(purchaseId), WindowsConverter::Convert(purchaseType), purchaseAmount, WindowsConverter::Convert(resources));
}

void WindowsAnalytics::LevelUp(int32 level)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::LevelUp(level);
}

void WindowsAnalytics::LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::LevelUpWithResources(level, WindowsConverter::Convert(balance));
}

void WindowsAnalytics::CurrentBalance(const TMap<FString, int64>& balance)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CurrentBalance(WindowsConverter::Convert(balance));
}

void WindowsAnalytics::Referrer(const TMap<EDTDReferralProperty, FString>& utmData)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::Referrer(WindowsConverter::Convert(utmData));
}

void WindowsAnalytics::Tutorial(int32 step)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::Tutorial(step);
}

void WindowsAnalytics::StartProgressionEvent(const FString& eventName)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::StartProgressionEvent(WindowsConverter::Convert(eventName));
}

void WindowsAnalytics::StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::StartProgressionEventWithParams(WindowsConverter::Convert(eventName), WindowsConverter::Convert(params));
}

void WindowsAnalytics::FinishProgressionEvent(const FString& eventName)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::FinishProgressionEvent(WindowsConverter::Convert(eventName));
}

void WindowsAnalytics::FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::FinishProgressionEventWithParams(WindowsConverter::Convert(eventName), WindowsConverter::Convert(params));
}

void WindowsAnalytics::RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::RealCurrencyPayment(
		WindowsConverter::Convert(orderId),
		price,
		WindowsConverter::Convert(productId),
		WindowsConverter::Convert(currencyCode));
}

void WindowsAnalytics::SocialNetworkConnect(EDTDSocialNetwork socialNetwork)
{
	const auto socialNetworkKey = DTDSocialNetworkKeys::GetKey(socialNetwork);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CustomSocialNetworkConnect(WindowsConverter::Convert(socialNetworkKey));
}

void WindowsAnalytics::SocialNetworkConnectCustom(const FString& socialNetwork)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CustomSocialNetworkConnect(WindowsConverter::Convert(socialNetwork));
}

void WindowsAnalytics::SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason)
{
	const auto socialNetworkKey = DTDSocialNetworkKeys::GetKey(socialNetwork);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CustomSocialNetworkPost(WindowsConverter::Convert(socialNetworkKey), WindowsConverter::Convert(reason));
}

void WindowsAnalytics::SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::CustomSocialNetworkPost(WindowsConverter::Convert(socialNetwork), WindowsConverter::Convert(reason));
}

void WindowsAnalytics::AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::AdImpression(
		WindowsConverter::Convert(socialNetwork), 
		revenue, 
		WindowsConverter::Convert(placement), 
		WindowsConverter::Convert(unit));
}

void WindowsAnalytics::SendBufferedEvents()
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SendBufferedEvents();
}

void WindowsAnalytics::SetLogLevel(EDTDLogLevel logLevel)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::SetLogLevel(WindowsConverter::Convert(logLevel));
}

void WindowsAnalytics::TryGetString(const FString& key, const FDTDGetterOptionalStringDelegate* onResult)
{
	const auto delWrapper = new DTDDelegateOptionalStringArgWrapper(onResult);
	DevToDevAnalyticsUnrealWindows::DTDUserCard::TryGetString(WindowsConverter::Convert(key), delWrapper);
}

void WindowsAnalytics::TryGetBool(const FString& key, const FDTDGetterOptionalBoolDelegate* onResult)
{
	const auto delWrapper = new DTDDelegateOptionalBoolArgWrapper(onResult);
	DevToDevAnalyticsUnrealWindows::DTDUserCard::TryGetBool(WindowsConverter::Convert(key), delWrapper);
}

void WindowsAnalytics::TryGetFloat(const FString& key, const FDTDGetterOptionalFloatDelegate* onResult)
{
	const auto delWrapper = new DTDDelegateOptionalDoubleArgWrapper(onResult);
	DevToDevAnalyticsUnrealWindows::DTDUserCard::TryGetDouble(WindowsConverter::Convert(key), delWrapper);
}

void WindowsAnalytics::TryGetLong(const FString& key, const FDTDGetterOptionalLongDelegate* onResult)
{
	const auto delWrapper = new DTDDelegateOptionalLongArgWrapper(onResult);
	DevToDevAnalyticsUnrealWindows::DTDUserCard::TryGetLong(WindowsConverter::Convert(key), delWrapper);
}

void WindowsAnalytics::SetCheater(bool cheater)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::SetCheater(cheater);
}

void WindowsAnalytics::SetTester(bool tester)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::SetTester(tester);
}

void WindowsAnalytics::SetString(const FString& key, const FString& value)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::SetString(WindowsConverter::Convert(key), WindowsConverter::Convert(value));
}

void WindowsAnalytics::SetBool(const FString& key, bool value)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::SetBool(WindowsConverter::Convert(key), value);
}

void WindowsAnalytics::SetInt(const FString& key, int64 value)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::SetLong(WindowsConverter::Convert(key), value);
}

void WindowsAnalytics::SetFloat(const FString& key, float value)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::SetDouble(WindowsConverter::Convert(key), value);
}

void WindowsAnalytics::Unset(const FString& key)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::Unset(WindowsConverter::Convert(key));
}

void WindowsAnalytics::UnsetArray(const TArray<FString>& keys)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::UnsetArray(WindowsConverter::Convert(keys));
}

void WindowsAnalytics::IncrementInt(const FString& key, int64 value)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::IncrementLong(WindowsConverter::Convert(key), value);
}

void WindowsAnalytics::IncrementFloat(const FString& key, float value)
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::IncrementDouble(WindowsConverter::Convert(key), value);
}

void WindowsAnalytics::ClearUser()
{
	DevToDevAnalyticsUnrealWindows::DTDUserCard::ClearUser();
}

// AB Tests

void WindowsAnalytics::InitializeWithConfigWithAbTest(const FString& appKey,
		const FDTDAnalyticsConfiguration& config, 
		const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChange, 
		const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChange,
		const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceive)
{
    const auto listener = new DTDRemoteConfigUnrealListener(onRemoteConfigChange, onRemoteConfigPrepareToChange, onRemoteConfigReceive);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::InitializeWithConfigWithAbTests(WindowsConverter::Convert(appKey),
	WindowsConverter::Convert(config),
	listener);
}

void WindowsAnalytics::InitializeWithAbTest(const FString& appKey,
		const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChange, 
		const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChange,
		const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceive)
{
    const auto listener = new DTDRemoteConfigUnrealListener(onRemoteConfigChange, onRemoteConfigPrepareToChange, onRemoteConfigReceive);
	DevToDevAnalyticsUnrealWindows::DTDAnalytics::InitializeWithAbTests(WindowsConverter::Convert(appKey),listener);
}

float WindowsAnalytics::GetRemoteConfigWaiting()
{
	return DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::GetRemoteConfigWaiting();
}

void WindowsAnalytics::SetRemoteConfigWaiting(float value)
{
	DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::SetRemoteConfigWaiting((double)value);
}

float WindowsAnalytics::GetGroupDefinitionWaiting()
{
	return DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::GetGroupDefinitionWaiting();
}

void WindowsAnalytics::SetGroupDefinitionWaiting(float value)
{
	DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::SetGroupDefinitionWaiting((double)value);
}

void WindowsAnalytics::SetDefaults(const FDTDRemoteConfigDefaults &defaults)
{
	const auto intDefaults = WindowsConverter::Convert(defaults.IntegerDefaults);
	const auto longDefaults = WindowsConverter::Convert(defaults.LongDefaults);
	const auto floatDefaults = WindowsConverter::Convert(defaults.FloatDefaults);
	const auto boolDefaults = WindowsConverter::Convert(defaults.BoolDefaults);
	const auto stringDefaults = WindowsConverter::Convert(defaults.StringDefaults);
	// TODO Double defaults for UE5
	DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::SetDefaults(
		intDefaults,
	 	longDefaults,
	  	floatDefaults,
	    boolDefaults,
		stringDefaults);
	UpdateLocalConfig();
}

void WindowsAnalytics::ApplyConfig()
{
	DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::ApplyConfig();
	UpdateLocalConfig();
}

void WindowsAnalytics::ResetConfig()
{
	DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::ResetConfig();
	UpdateLocalConfig();
}

TMap<FString, FDTDRemoteConfigValue> WindowsAnalytics::GetConfig()
{
    return localConfig;
}

FDTDRemoteConfigValue WindowsAnalytics::GetRemoteConfigValue(const FString &key)
{
    if (localConfig.Contains(key)) 
	{
		return localConfig[key];
	} 
	else 
	{
		FDTDRemoteConfigValue value;
		value.Source = EDTDRemoteConfigSource::Empty;
		return value;
	}
}

bool WindowsAnalytics::HasKey(const FString &key)
{
    return localConfig.Contains(key);
}

void WindowsAnalytics::CacheTestExperiment()
{
	DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::CacheTestExperiment();
}

void WindowsAnalytics::UpdateLocalConfig()
{
	DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::GetConfigJson();
	localConfig.Reset();
	FString str = WindowsConverter::Convert(DevToDevAnalyticsUnrealWindows::DTDRemoteConfig::GetConfigJson());
	TSharedPtr<FJsonObject> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(str);
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		for (auto currJsonValue = JsonParsed->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
		{
			FString key = (*currJsonValue).Key;
			TSharedPtr<FJsonValue> jsonValue = (*currJsonValue).Value;

			TSharedPtr<FJsonObject> jsonObject = jsonValue->AsObject();
			int source = jsonObject->GetIntegerField("source");

			FDTDRemoteConfigValue configValue;
			if(source == 0)
			{
				configValue.Source = EDTDRemoteConfigSource::Empty;
			} 
			if(source == 1)
			{
				configValue.Source = EDTDRemoteConfigSource::Remote;
			} 
			if(source == 2)
			{
				configValue.Source = EDTDRemoteConfigSource::Default;
			}

			FString strValue;
			if (jsonObject->TryGetStringField("StringValue", strValue)){
				configValue.StringValue = strValue;
			}

			int32 int32Value;
			if (jsonObject->TryGetNumberField("Int32Value", int32Value)){
				configValue.IntegerValue = int32Value;
			}

			int64 longValue;
			if (jsonObject->TryGetNumberField("Int64Value", longValue)){
				configValue.LongValue = longValue;
			}

			double floatValue;
			if (jsonObject->TryGetNumberField("FloatValue", floatValue)){
				configValue.FloatValue = (float)floatValue;
			}

			bool boolValue;
			if (jsonObject->TryGetBoolField("BoolValue", boolValue)){
				configValue.BoolValue = boolValue; 
			}

			localConfig.Add(key, configValue);
		}
	}
}


#endif


