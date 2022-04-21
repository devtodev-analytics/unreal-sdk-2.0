// Copyright (c) devtodev. All rights reserved.

#include "MacConverter.h"

#include "SocialNetwork/DTDSocialNetworkKeys.h"

FString MacConverter::Convert(const NSString* value)
{
	const char* cString = [value cStringUsingEncoding:NSUTF8StringEncoding];
	return FString(UTF8_TO_TCHAR(cString));
}

FString MacConverter::FromUtf8String(const char* cString)
{
	return FString(UTF8_TO_TCHAR(cString));
}

bool MacConverter::ConvertToCpp(BOOL value)
{
	return value ? true : false;
}

int32 MacConverter::ConvertToInt32(NSInteger value)
{
	return (int32)value;
}

int64 MacConverter::ConvertToInt64(NSInteger value)
{
	return (int64)value;
}

EDTDGender MacConverter::Convert(Gender value)
{
	switch (value)
	{
	case GenderMale:
        return EDTDGender::Male;
	case GenderFemale:
        return EDTDGender::Female;
	case GenderUnknown:
    	return EDTDGender::Unknown;
	default:
    	return EDTDGender::Unknown;
	}
}

NSString* MacConverter::Convert(const FString& value)
{
    return [NSString stringWithUTF8String:TCHAR_TO_UTF8(*value)];
}

BOOL MacConverter::ConvertToObjC(bool value)
{
    return value ? YES : NO;
}

NSInteger MacConverter::Convert(int32 value)
{
    return NSInteger(value);
}

NSNumber* MacConverter::ConvertToPointer(int32 value)
{
    return [NSNumber numberWithInt:value];
}

NSInteger MacConverter::Convert(int64 value)
{
    return NSInteger(value);
}

NSNumber* MacConverter::ConvertToPointer(int64 value)
{
    return [NSNumber numberWithInt:value];
}

NSNumber* MacConverter::Convert(float value)
{
    return [NSNumber numberWithFloat:value];
}

NSNumber* MacConverter::Convert(double value)
{
    return [NSNumber numberWithDouble:value];
}

NSDictionary<NSString*, NSNumber*>* MacConverter::Convert(const TMap<FString, int32>& dic)
{
    NSMutableDictionary* objDic = [[NSMutableDictionary alloc] init];
    for (const TPair<FString, int32>& pair : dic)
	{
        [objDic setObject:ConvertToPointer(pair.Value) forKey:Convert(pair.Key)];
	}

    return objDic;
}

NSDictionary<NSString*, NSNumber*>* MacConverter::Convert(const TMap<FString, int64>& dic)
{
    NSMutableDictionary* objDic = [[NSMutableDictionary alloc] init];
    for (const TPair<FString, int64>& pair : dic)
	{
        [objDic setObject:ConvertToPointer(pair.Value) forKey:Convert(pair.Key)];
	}

    return objDic;
}

NSArray<NSString*>* MacConverter::Convert(const TArray<FString>& array)
{
    NSMutableArray* nsArray = [[NSMutableArray alloc] init];
    for (const FString& str : array)
	{
        [nsArray addObject:Convert(str)];
	}

    return nsArray;
}

DTDLogLevel MacConverter::Convert(EDTDLogLevel value)
{
	switch (value)
	{
	case EDTDLogLevel::Unknown:
		return DTDLogLevelUnknown;
	case EDTDLogLevel::No:
		return DTDLogLevelNo;
	case EDTDLogLevel::Error:
		return DTDLogLevelError;
	case EDTDLogLevel::Warning:
		return DTDLogLevelWarning;
	case EDTDLogLevel::Info:
		return DTDLogLevelInfo;
	case EDTDLogLevel::Debug:
		return DTDLogLevelDebug;
	default:
		return DTDLogLevelUnknown;
	}
}

EDTDLogLevel MacConverter::Convert(DTDLogLevel value)
{
	switch (value)
	{
	case DTDLogLevelUnknown:
		return EDTDLogLevel::Unknown;
	case DTDLogLevelNo:
		return EDTDLogLevel::No;
	case DTDLogLevelError:
		return EDTDLogLevel::Error;
	case DTDLogLevelWarning:
		return EDTDLogLevel::Warning;
	case DTDLogLevelInfo:
		return EDTDLogLevel::Info;
	case DTDLogLevelDebug:
		return EDTDLogLevel::Debug;
	default:
		return EDTDLogLevel::Unknown;
	}
}

Gender MacConverter::Convert(EDTDGender value)
{
	switch (value)
	{
	case EDTDGender::Male:
        return GenderMale;
	case EDTDGender::Female:
        return GenderFemale;
	case EDTDGender::Unknown:
    	return GenderUnknown;
	default:
		return GenderUnknown;
	}
}

DTDTrackingStatus MacConverter::Convert(EDTDTrackingStatus trackingStatus)
{
	switch (trackingStatus)
	{
	case EDTDTrackingStatus::Unknown:
        return DTDTrackingStatusUnknown;
	case EDTDTrackingStatus::Enable:
        return DTDTrackingStatusEnable;
	case EDTDTrackingStatus::Disable:
        return DTDTrackingStatusDisable;
	default:
        return DTDTrackingStatusUnknown;
	}
}

DTDAccrualType MacConverter::Convert(EDTDAccrualType accrualType)
{
    switch (accrualType)
	{
	case EDTDAccrualType::Earned:
        return DTDAccrualTypeEarned;
	case EDTDAccrualType::Bought:
        return DTDAccrualTypeBought;
	default:
        return DTDAccrualTypeEarned;
	}
}

DTDReferralProperty* MacConverter::Convert(EDTDReferralProperty referral)
{
	switch (referral)
	{
	case EDTDReferralProperty::Source:
        return [DTDReferralProperty source];
	case EDTDReferralProperty::Campaign:
        return [DTDReferralProperty campaign];
	case EDTDReferralProperty::Content:
        return [DTDReferralProperty content];
	case EDTDReferralProperty::Medium:
        return [DTDReferralProperty medium];
	case EDTDReferralProperty::Term:
        return [DTDReferralProperty term];
	default:
        return [DTDReferralProperty source];
	}
}

NSDictionary<DTDReferralProperty*, NSString*>* MacConverter::Convert(const TMap<EDTDReferralProperty, FString>& referrer)
{
    NSMutableDictionary* objReferrer = [[NSMutableDictionary alloc] init];
    for (const TPair<EDTDReferralProperty, FString>& pair : referrer)
	{
        [objReferrer setObject:Convert(pair.Value) forKey:Convert(pair.Key)];
	}

    return objReferrer;
}

DTDAnalyticsConfiguration* MacConverter::Convert(const FDTDAnalyticsConfiguration& config)
{
    DTDAnalyticsConfiguration *objConfig = [[DTDAnalyticsConfiguration alloc] init];
    [objConfig setLogLevel:Convert(config.LogLevel)];
	
    if (config.CurrentLevel.HasValue)
    {
        [objConfig setCurrentLevel:ConvertToPointer(config.CurrentLevel.Value)];
    }

    if (config.UserId.HasValue)
    {
        [objConfig setUserId:Convert(config.UserId.Value)];
    }

    [objConfig setTrackingAvailability:Convert(config.TrackingAvailability)];
    return objConfig;
}

DTDCustomEventParameters* MacConverter::Convert(const FDTDCustomEventParams& params)
{
    DTDCustomEventParameters *objParams = [[DTDCustomEventParameters alloc] init];
    for (const TPair<FString, FString>& pair : params.StringParameters)
	{
        [objParams addString:Convert(pair.Key) value:Convert(pair.Value)];
	}

    for (const TPair<FString, bool>& pair : params.BoolParameters)
	{
        [objParams addBool:Convert(pair.Key) value:Convert(pair.Value)];
	}

	for (const TPair<FString, int64>& pair : params.IntParameters)
	{
        [objParams addInt:Convert(pair.Key) value:Convert(pair.Value)];
	}
    
    for (const TPair<FString, float>& pair : params.FloatParameters)
	{
        [objParams addDouble:Convert(pair.Key) value:(double)pair.Value];
	}

    return objParams;
}

DTDStartProgressionEventParameters* MacConverter::Convert(const FDTDStartProgressionEventParams& params)
{
    DTDStartProgressionEventParameters *objParams = [[DTDStartProgressionEventParameters alloc] init];

	if (params.Source.HasValue)
	{
    	[objParams setSource:Convert(params.Source.Value)];
	}

	if (params.Difficulty.HasValue)
	{
    	[objParams setDifficultyWithDifficulty:Convert(params.Difficulty.Value)];
	}

    return objParams;
}

DTDFinishProgressionEventParameters* MacConverter::Convert(const FDTDFinishProgressionEventParams& params)
{
    DTDFinishProgressionEventParameters *objParams = [[DTDFinishProgressionEventParameters alloc] init];
    [objParams setSuccessfulCompletion:Convert(params.SuccessfulCompletion)];
    [objParams setDuration:Convert(params.Duration)];
    [objParams setSpent:Convert(params.Spent)];
    [objParams setEarned:Convert(params.Earned)];
    return objParams;
}

DTDSocialNetwork* MacConverter::Convert(EDTDSocialNetwork socialNetwork)
{
	FString socialNetworkName = DTDSocialNetworkKeys::GetKey(socialNetwork);
	return ConvertToSocialNetwork(socialNetworkName);
}

DTDSocialNetwork* MacConverter::ConvertToSocialNetwork(const FString& socialNetworkName)
{
    return [[DTDSocialNetwork alloc] initWithName:Convert(socialNetworkName)];
}
