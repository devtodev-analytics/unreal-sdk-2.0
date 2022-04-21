// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDAnalytics/DTDAnalytics-Swift.h"

#include "DTDLogLevel.h"
#include "DTDAnalyticsConfiguration.h"
#include "DTDCustomEventParams.h"
#include "DTDGender.h"
#include "DTDReferralProperty.h"
#include "DTDStartProgressionEventParams.h"
#include "DTDFinishProgressionEventParams.h"
#include "DTDDelegates.h"
#include "DTDAccrualType.h"
#include "DTDSocialNetwork.h"
#include "DTDGender.h"

class MacConverter
{
public:
    static FString Convert(const NSString* value);
    static FString FromUtf8String(const char* cString);
    static bool ConvertToCpp(BOOL value);
    static int32 ConvertToInt32(NSInteger value);
    static int64 ConvertToInt64(NSInteger value);
    static EDTDGender Convert(Gender value);
    static NSString* Convert(const FString& value);
    static BOOL ConvertToObjC(bool value);
    static NSInteger Convert(int32 value);
    static NSNumber* ConvertToPointer(int32 value);
    static NSInteger Convert(int64 value);
    static NSNumber* ConvertToPointer(int64 value);
    static NSNumber* Convert(float value);
    static NSNumber* Convert(double value);
    static NSDictionary<NSString*, NSNumber*>* Convert(const TMap<FString, int32>& dic);
    static NSDictionary<NSString*, NSNumber*>* Convert(const TMap<FString, int64>& dic);
    static NSArray<NSString*>* Convert(const TArray<FString>& array);
    static DTDLogLevel Convert(EDTDLogLevel value);
	static EDTDLogLevel Convert(DTDLogLevel value);
    static Gender Convert(EDTDGender value);
    static DTDTrackingStatus Convert(EDTDTrackingStatus value);
    static DTDAccrualType Convert(EDTDAccrualType value);
    static DTDReferralProperty* Convert(EDTDReferralProperty referral);
    static NSDictionary<DTDReferralProperty*, NSString*>* Convert(const TMap<EDTDReferralProperty, FString>& referrer);
    static DTDAnalyticsConfiguration* Convert(const FDTDAnalyticsConfiguration& config);
    static DTDCustomEventParameters* Convert(const FDTDCustomEventParams& params);
    static DTDStartProgressionEventParameters* Convert(const FDTDStartProgressionEventParams& params);
    static DTDFinishProgressionEventParameters* Convert(const FDTDFinishProgressionEventParams& params);
    static DTDSocialNetwork* Convert(EDTDSocialNetwork socialNetwork);
    static DTDSocialNetwork* ConvertToSocialNetwork(const FString& socialNetworkName);
};
