// Copyright (c) devtodev. All rights reserved.

#include "WindowsAnalytics.h"

#if PLATFORM_WINDOWS && PLATFORM_32BITS

#include "Logging/DTDLogCategory.h"

WindowsAnalytics::WindowsAnalytics()
{
	WarnAboutNotSupportedArchitecture();
}

WindowsAnalytics::~WindowsAnalytics()
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetTestProxyUrl(const FString& url)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetTestCustomUrl(const FString& url)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::TestLogs()
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::TestString(const FString& value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetLoggerMessageListener(const FDTDLogsListenerDelegate* listener)
{
	if (listener != nullptr)
	{
		delete listener;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetIdentifiersListener(const FDTDLongListenerDelegate* listener)
{
	if (listener != nullptr)
	{
		delete listener;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetDeviceId(const FDTDGetterStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetSdkVersion(const FDTDGetterStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetApplicationVersion(const FDTDGetterStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetApplicationVersion(const FString& value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetTrackingAvailability(const FDTDGetterBoolDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetUserId(const FDTDGetterStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetCurrentLevel(const FDTDGetterIntDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::Initialize(const FString& appKey)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::Deinitialize()
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::StartActivity()
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::StopActivity()
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetUserId(const FString& userId)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::ReplaceUserId(const FString& fromUserId, const FString& toUserId)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::CustomEvent(const FString& eventName)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetCurrentLevel(int32 level)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetTrackingAvailability(bool value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::LevelUp(int32 level)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::CurrentBalance(const TMap<FString, int64>& balance)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::Referrer(const TMap<EDTDReferralProperty, FString>& utmData)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::Tutorial(int32 step)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::StartProgressionEvent(const FString& eventName)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::FinishProgressionEvent(const FString& eventName)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SocialNetworkConnect(EDTDSocialNetwork socialNetwork)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SocialNetworkConnectCustom(const FString& socialNetwork)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SendBufferedEvents()
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetLogLevel(EDTDLogLevel logLevel)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetName(const FDTDGetterStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetEmail(const FDTDGetterStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetPhone(const FDTDGetterStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetPhoto(const FDTDGetterStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetGender(const FDTDGetterGenderDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetAge(const FDTDGetterLongDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::GetCheater(const FDTDGetterBoolDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::TryGetString(const FString& key, const FDTDGetterOptionalStringDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::TryGetBool(const FString& key, const FDTDGetterOptionalBoolDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::TryGetFloat(const FString& key, const FDTDGetterOptionalFloatDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::TryGetLong(const FString& key, const FDTDGetterOptionalLongDelegate* onResult)
{
	if (onResult != nullptr)
	{
		delete onResult;
	}

	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetName(const FString& name)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetEmail(const FString& email)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetPhone(const FString& phone)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetPhoto(const FString& photo)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetGender(EDTDGender gender)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetAge(int64 age)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetCheater(bool cheater)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetString(const FString& key, const FString& value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetBool(const FString& key, bool value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetInt(const FString& key, int64 value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::SetFloat(const FString& key, float value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::Unset(const FString& key)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::UnsetArray(const TArray<FString>& keys)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::IncrementInt(const FString& key, int64 value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::IncrementFloat(const FString& key, float value)
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::ClearUser()
{
	WarnAboutNotSupportedArchitecture();
}

void WindowsAnalytics::WarnAboutNotSupportedArchitecture()
{
	UE_LOG(LogDTD, Warning, TEXT("The 32 bits target architecture not supported for Windows platform"));
}

#endif