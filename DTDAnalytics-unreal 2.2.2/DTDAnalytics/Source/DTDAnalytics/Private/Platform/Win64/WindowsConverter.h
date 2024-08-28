#pragma once
#include "DTDAccrualType.h"
#include "DTDAnalyticsConfiguration.h"
#include "DTDCustomEventParams.h"
#include "DTDFinishProgressionEventParams.h"
#include "DTDGender.h"
#include "DTDLogLevel.h"
#include "DTDReferralProperty.h"
#include "DTDSocialNetwork.h"
#include "DTDStartProgressionEventParams.h"
#include "DTDRemoteConfigSource.h"

#include "../../../../../ThirdParty/Windows/Headers/DTDString.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDLogLevel.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDGender.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDAnalyticsConfiguration.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDCustomEventParameters.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDAccrualType.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDDictionaryInt.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDReferralProperty.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDDictionaryReferralProperty.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDStartProgressionEventParameters.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDFinishProgressionEventParameters.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDArrayString.h"
#include "../../../../../ThirdParty/Windows/Headers/Logger.h"
#include "../../../../../ThirdParty/Windows/Headers/DTDRemoteConfigSource.h"

class WindowsConverter
{
public:
	static char* ToCStr(const std::string& str);
	static std::string ToStdStr(const FString& str);
	static FString Convert(const DevToDevAnalyticsUnrealWindows::DTDString& str);
	static DevToDevAnalyticsUnrealWindows::DTDString Convert(const FString& str);
	static FString Convert(const char* c_str);
	static FString Convert(std::wstring str);
	static DevToDevAnalyticsUnrealWindows::DTDLogLevel Convert(EDTDLogLevel logLevel);
	static EDTDGender Convert(DevToDevAnalyticsUnrealWindows::DTDGender gender);
	static EDTDLogLevel Convert(DevToDevAnalyticsUnrealWindows::DTDLogLevel logLevel);
	static DevToDevAnalyticsUnrealWindows::DTDGender Convert(EDTDGender gender);
	static DevToDevAnalyticsUnrealWindows::DTDAccrualType Convert(EDTDAccrualType accrualType);
	static DevToDevAnalyticsUnrealWindows::DTDReferralProperty Convert(EDTDReferralProperty referralProperty);
	static DevToDevAnalyticsUnrealWindows::DTDTrackingStatus Convert(EDTDTrackingStatus trackingStatus);
	static DevToDevAnalyticsUnrealWindows::DTDAnalyticsConfiguration Convert(const FDTDAnalyticsConfiguration& config);
	static DevToDevAnalyticsUnrealWindows::DTDCustomEventParameters Convert(const FDTDCustomEventParams& params);
	static DevToDevAnalyticsUnrealWindows::DTDDictionaryInt Convert(const TMap<FString, int32>& map);
	static DevToDevAnalyticsUnrealWindows::DTDDictionaryLong Convert(const TMap<FString, int64>& map);
	static DevToDevAnalyticsUnrealWindows::DTDDictionaryReferralProperty Convert(const TMap<EDTDReferralProperty, FString>& referrer);
	static DevToDevAnalyticsUnrealWindows::DTDStartProgressionEventParameters Convert(const FDTDStartProgressionEventParams& params);
	static DevToDevAnalyticsUnrealWindows::DTDFinishProgressionEventParameters Convert(const FDTDFinishProgressionEventParams& params);
	static DevToDevAnalyticsUnrealWindows::DTDArrayString Convert(const TArray<FString>& keys);
	static TArray<FString> Convert(const DevToDevAnalyticsUnrealWindows::DTDArrayString& keys);
	static DevToDevAnalyticsUnrealWindows::DTDDictionaryString Convert(const TMap<FString, FString>& map);
	static DevToDevAnalyticsUnrealWindows::DTDDictionaryDouble Convert(const TMap<FString, float>& map);
	static DevToDevAnalyticsUnrealWindows::DTDDictionaryBool Convert(const TMap<FString, bool>& map);
	static EDTDRemoteConfigSource Convert(DevToDevAnalyticsUnrealWindows::DTDRemoteConfigSource source);	
};
