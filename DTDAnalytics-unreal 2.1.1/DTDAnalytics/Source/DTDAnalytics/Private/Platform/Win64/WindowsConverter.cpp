#include "WindowsConverter.h"

#if PLATFORM_WINDOWS && PLATFORM_64BITS

FString WindowsConverter::Convert(const DevToDevAnalyticsUnrealWindows::DTDString& str)
{
	const wchar_t* data = str.GetData();
	return FString(data);
}

DevToDevAnalyticsUnrealWindows::DTDString WindowsConverter::Convert(const FString& str)
{
	return DevToDevAnalyticsUnrealWindows::DTDString(*str);
}

FString WindowsConverter::Convert(std::wstring str)
{
	const DevToDevAnalyticsUnrealWindows::DTDString dStr(str.c_str());
	FString fStr = Convert(dStr);
    return fStr;
}

DevToDevAnalyticsUnrealWindows::DTDLogLevel WindowsConverter::Convert(EDTDLogLevel logLevel)
{
	switch (logLevel)
	{
	case EDTDLogLevel::Unknown:
		return DevToDevAnalyticsUnrealWindows::DTDLogLevel::DTDLogLevelUnknown;
	case EDTDLogLevel::No:
		return DevToDevAnalyticsUnrealWindows::DTDLogLevel::DTDLogLevelNo;
	case EDTDLogLevel::Error:
		return DevToDevAnalyticsUnrealWindows::DTDLogLevel::DTDLogLevelError;
	case EDTDLogLevel::Warning:
		return DevToDevAnalyticsUnrealWindows::DTDLogLevel::DTDLogLevelWarning;
	case EDTDLogLevel::Info:
		return DevToDevAnalyticsUnrealWindows::DTDLogLevel::DTDLogLevelInfo;
	case EDTDLogLevel::Debug:
		return DevToDevAnalyticsUnrealWindows::DTDLogLevel::DTDLogLevelDebug;
	default:
		return DevToDevAnalyticsUnrealWindows::DTDLogLevel::DTDLogLevelUnknown;
	}
}

EDTDGender WindowsConverter::Convert(DevToDevAnalyticsUnrealWindows::DTDGender gender)
{
	switch (gender)
	{
	case DevToDevAnalyticsUnrealWindows::DTDGenderUnknown:
		return EDTDGender::Unknown;
	case DevToDevAnalyticsUnrealWindows::DTDGenderMale:
		return EDTDGender::Male;
	case DevToDevAnalyticsUnrealWindows::DTDGenderFemale:
		return EDTDGender::Female;
	default:
		return EDTDGender::Unknown;
	}
}

EDTDLogLevel WindowsConverter::Convert(DevToDevAnalyticsUnrealWindows::DTDLogLevel logLevel)
{
	switch (logLevel)
	{
		case DevToDevAnalyticsUnrealWindows::DTDLogLevelUnknown:
			return EDTDLogLevel::Unknown;
		case DevToDevAnalyticsUnrealWindows::DTDLogLevelNo:
			return EDTDLogLevel::No;
		case DevToDevAnalyticsUnrealWindows::DTDLogLevelError:
			return EDTDLogLevel::Error;
		case DevToDevAnalyticsUnrealWindows::DTDLogLevelWarning:
			return EDTDLogLevel::Warning;
		case DevToDevAnalyticsUnrealWindows::DTDLogLevelInfo:
			return EDTDLogLevel::Info;
		case DevToDevAnalyticsUnrealWindows::DTDLogLevelDebug:
			return EDTDLogLevel::Debug;
		default:
			return EDTDLogLevel::Unknown;
	}
}

DevToDevAnalyticsUnrealWindows::DTDGender WindowsConverter::Convert(EDTDGender gender)
{
	switch (gender)
	{
	case EDTDGender::Unknown:
		return DevToDevAnalyticsUnrealWindows::DTDGender::DTDGenderUnknown;
	case EDTDGender::Male:
		return DevToDevAnalyticsUnrealWindows::DTDGender::DTDGenderMale;
	case EDTDGender::Female:
		return DevToDevAnalyticsUnrealWindows::DTDGender::DTDGenderFemale;
	default:
		return DevToDevAnalyticsUnrealWindows::DTDGender::DTDGenderUnknown;
	}
}

DevToDevAnalyticsUnrealWindows::DTDAccrualType WindowsConverter::Convert(EDTDAccrualType accrualType)
{
	switch (accrualType)
	{
	case EDTDAccrualType::Earned:
		return DevToDevAnalyticsUnrealWindows::DTDAccrualType::DTDAccrualTypeEarned;
	case EDTDAccrualType::Bought:
		return DevToDevAnalyticsUnrealWindows::DTDAccrualType::DTDAccrualTypeBought;
	default:
		return DevToDevAnalyticsUnrealWindows::DTDAccrualType::DTDAccrualTypeEarned;
	}
}

DevToDevAnalyticsUnrealWindows::DTDReferralProperty WindowsConverter::Convert(EDTDReferralProperty referralProperty)
{
	switch (referralProperty)
	{
	case EDTDReferralProperty::Source:
		return DevToDevAnalyticsUnrealWindows::DTDReferralProperty::DTDReferralPropertySource;
	case EDTDReferralProperty::Medium:
		return DevToDevAnalyticsUnrealWindows::DTDReferralProperty::DTDReferralPropertyMedium;
	case EDTDReferralProperty::Content:
		return DevToDevAnalyticsUnrealWindows::DTDReferralProperty::DTDReferralPropertyContent;
	case EDTDReferralProperty::Campaign:
		return DevToDevAnalyticsUnrealWindows::DTDReferralProperty::DTDReferralPropertyCampaign;
	case EDTDReferralProperty::Term:
		return DevToDevAnalyticsUnrealWindows::DTDReferralProperty::DTDReferralPropertyTerm;
	default:
		return DevToDevAnalyticsUnrealWindows::DTDReferralProperty::DTDReferralPropertySource;
	}
}

DevToDevAnalyticsUnrealWindows::DTDTrackingStatus WindowsConverter::Convert(EDTDTrackingStatus trackingStatus)
{
	switch (trackingStatus)
	{
	case EDTDTrackingStatus::Unknown:
		return DevToDevAnalyticsUnrealWindows::DTDTrackingStatus::DTDTrackingStatusUnknown;
	case EDTDTrackingStatus::Enable:
		return DevToDevAnalyticsUnrealWindows::DTDTrackingStatus::DTDTrackingStatusEnable;
	case EDTDTrackingStatus::Disable:
		return DevToDevAnalyticsUnrealWindows::DTDTrackingStatus::DTDTrackingStatusDisable;
	default:
		return DevToDevAnalyticsUnrealWindows::DTDTrackingStatus::DTDTrackingStatusUnknown;
	}
}

DevToDevAnalyticsUnrealWindows::DTDAnalyticsConfiguration WindowsConverter::Convert(
	const FDTDAnalyticsConfiguration& config)
{
	DevToDevAnalyticsUnrealWindows::DTDAnalyticsConfiguration cliConfig;
	cliConfig.LogLevel = Convert(config.LogLevel);

	cliConfig.ApplyCurrentLevel = config.CurrentLevel.HasValue;
	cliConfig.CurrentLevel = config.CurrentLevel.Value;

	cliConfig.ApplyUserId = config.UserId.HasValue;
	cliConfig.UserId = Convert(config.UserId.Value);

	cliConfig.ApplyApplicationVersion = config.ApplicationVersion.HasValue;
	cliConfig.ApplicationVersion = Convert(config.ApplicationVersion.Value);

	cliConfig.TrackingAvailability = Convert(config.TrackingAvailability);
	return cliConfig;
}

DevToDevAnalyticsUnrealWindows::DTDCustomEventParameters WindowsConverter::Convert(const FDTDCustomEventParams& params)
{
	DevToDevAnalyticsUnrealWindows::DTDCustomEventParameters cliParams;
	cliParams.StringParameters = Convert(params.StringParameters);
	cliParams.LongParameters = Convert(params.IntParameters);
	cliParams.DoubleParameters = Convert(params.FloatParameters);
	cliParams.BoolParameters = Convert(params.BoolParameters);
	return cliParams;
}

DevToDevAnalyticsUnrealWindows::DTDDictionaryInt WindowsConverter::Convert(const TMap<FString, int32>& map)
{
	DevToDevAnalyticsUnrealWindows::DTDDictionaryInt cliMap;
	for (auto keyValuePair : map)
	{
		const auto key = Convert(keyValuePair.Key);
		cliMap.Add(key, keyValuePair.Value);
	}

	return cliMap;
}

DevToDevAnalyticsUnrealWindows::DTDDictionaryLong WindowsConverter::Convert(const TMap<FString, int64>& map)
{
	DevToDevAnalyticsUnrealWindows::DTDDictionaryLong cliMap;
	for (auto keyValuePair : map)
	{
		const auto key = Convert(keyValuePair.Key);
		cliMap.Add(key, keyValuePair.Value);
	}

	return cliMap;
}

DevToDevAnalyticsUnrealWindows::DTDDictionaryReferralProperty WindowsConverter::Convert(
	const TMap<EDTDReferralProperty, FString>& referrer)
{
	DevToDevAnalyticsUnrealWindows::DTDDictionaryReferralProperty cliMap;
	for (auto keyValuePair : referrer)
	{
		const auto key = Convert(keyValuePair.Key);
		const auto value = Convert(keyValuePair.Value);
		cliMap.Add(key, value);
	}

	return cliMap;
}

DevToDevAnalyticsUnrealWindows::DTDStartProgressionEventParameters WindowsConverter::Convert(
	const FDTDStartProgressionEventParams& params)
{
	DevToDevAnalyticsUnrealWindows::DTDStartProgressionEventParameters cliParams;

	cliParams.ApplyDifficulty = params.Difficulty.HasValue;
	cliParams.Difficulty = params.Difficulty.Value;

	cliParams.ApplySource = params.Source.HasValue;
	cliParams.Source = Convert(params.Source.Value);
	
	return cliParams;
}

DevToDevAnalyticsUnrealWindows::DTDFinishProgressionEventParameters WindowsConverter::Convert(
	const FDTDFinishProgressionEventParams& params)
{
	DevToDevAnalyticsUnrealWindows::DTDFinishProgressionEventParameters cliParams;
	cliParams.SuccessfulCompletion = params.SuccessfulCompletion;
	cliParams.Duration = params.Duration;
	cliParams.Spent = Convert(params.Spent);
	cliParams.Earned = Convert(params.Earned);
	return cliParams;
}

DevToDevAnalyticsUnrealWindows::DTDArrayString WindowsConverter::Convert(const TArray<FString>& keys)
{
	DevToDevAnalyticsUnrealWindows::DTDArrayString cliKeys;
	for (auto key : keys)
	{
		const auto cliKey = Convert(key);
		cliKeys.Add(cliKey);
	}

	return cliKeys;
}

TArray<FString> WindowsConverter::Convert(const DevToDevAnalyticsUnrealWindows::DTDArrayString& keys)
{
    TArray<FString> unrealArray;

	std::vector<std::wstring> vec = keys.GetVector();
	
	for(auto key: vec)
	{
		auto converted = FString(key.c_str());
		unrealArray.Add(converted);
	}

	return unrealArray;
}

DevToDevAnalyticsUnrealWindows::DTDDictionaryString WindowsConverter::Convert(const TMap<FString, FString>& map)
{
	DevToDevAnalyticsUnrealWindows::DTDDictionaryString cliMap;
	for (auto keyValuePair : map)
	{
		const auto key = Convert(keyValuePair.Key);
		const auto value = Convert(keyValuePair.Value);
		cliMap.Add(key, value);
	}

	return cliMap;
}

DevToDevAnalyticsUnrealWindows::DTDDictionaryDouble WindowsConverter::Convert(const TMap<FString, float>& map)
{
	DevToDevAnalyticsUnrealWindows::DTDDictionaryDouble cliMap;
	for (auto keyValuePair : map)
	{
		const auto key = Convert(keyValuePair.Key);
		cliMap.Add(key, keyValuePair.Value);
	}

	return cliMap;
}

DevToDevAnalyticsUnrealWindows::DTDDictionaryBool WindowsConverter::Convert(const TMap<FString, bool>& map)
{
	DevToDevAnalyticsUnrealWindows::DTDDictionaryBool cliMap;
	for (auto keyValuePair : map)
	{
		const auto key = Convert(keyValuePair.Key);
		cliMap.Add(key, keyValuePair.Value);
	}

	return cliMap;
}

EDTDRemoteConfigSource WindowsConverter::Convert(DevToDevAnalyticsUnrealWindows::DTDRemoteConfigSource source)
{
	switch (source)
	{
	case DevToDevAnalyticsUnrealWindows::DTDRemoteConfigSource::DTDRemoteConfigSourceEmpty:
		return EDTDRemoteConfigSource::Empty;
	case DevToDevAnalyticsUnrealWindows::DTDRemoteConfigSource::DTDRemoteConfigSourceRemote:
		return EDTDRemoteConfigSource::Remote;
	case DevToDevAnalyticsUnrealWindows::DTDRemoteConfigSource::DTDRemoteConfigSourceDefault:
		return EDTDRemoteConfigSource::Default;
	default:
		return EDTDRemoteConfigSource::Empty;
	}
}

#endif