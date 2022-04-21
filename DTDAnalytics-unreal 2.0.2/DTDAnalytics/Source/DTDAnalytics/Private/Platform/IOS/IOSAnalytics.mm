// Copyright (c) devtodev. All rights reserved.

#include "IOSAnalytics.h"

#include "DTDAnalytics/DTDAnalytics-Swift.h"

#include "Misc/DateTime.h"

#include "IOSConverter.h"
#include "Constants/SDKConstants.h"
#include "Logging/DTDLogs.h"

// TODO: Rewrite it. Make week property probably.
@interface IOSIdentifiersListener : NSObject<DTDIdentifiersListener>
{
    const FDTDLongListenerDelegate* onResult;    
}
-(id)initWithDelegate:(const FDTDLongListenerDelegate*)delegate;
@end

@implementation IOSIdentifiersListener
-(id)initWithDelegate:(const FDTDLongListenerDelegate*)delegate {
	onResult = delegate;
    return self;
}

- (void)didReceiveDevtodevIdWith:(int64_t)devtodevId {
	int64 u_devtodevId = static_cast<int64>(devtodevId);
	onResult->ExecuteIfBound(u_devtodevId);
}
@end

IOSAnalytics::IOSAnalytics()
{
	[::DTDEngineWrapper setSDKVersionWithVersion:IOSConverter::Convert(SDKConstants::Version)];
	[::DTDEngineWrapper setEngineLoggerMessageClosure:^(DTDLogLevel logLevel, NSString* message) {
		const auto u_logLevel = IOSConverter::Convert(logLevel);
		const auto u_message = IOSConverter::Convert(message);
#if !UE_BUILD_SHIPPING
		const auto u_now = FDateTime::Now().ToString(TEXT("%Y/%m/%d %H:%M:%S:%s"));
#else 
		const auto u_now = FDateTime::Now().ToString(TEXT("%Y/%m/%d %H:%M:%S"));
#endif
		TArray<FStringFormatArg> formattingArgs; 
		formattingArgs.Add(FStringFormatArg(u_now));
		formattingArgs.Add(FStringFormatArg(SDKConstants::Version));
		formattingArgs.Add(FStringFormatArg(u_message));
		const auto formattedMessage = FString::Format(TEXT("{0} [DevToDev {1}] {2}"), formattingArgs);
		switch (u_logLevel)
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
        	logsListener->ExecuteIfBound(u_logLevel, formattedMessage);
		}
    }];
}

IOSAnalytics::~IOSAnalytics()
{
	if (logsListener != nullptr)
	{
		delete logsListener;
	}
}

void IOSAnalytics::SetTestProxyUrl(const FString& url)
{
	[::DTDAnalytics setTestProxyUrlWithUrl:IOSConverter::Convert(url)];
}

void IOSAnalytics::SetTestCustomUrl(const FString& url)
{
	[::DTDAnalytics setTestCustomUrlWithUrl:IOSConverter::Convert(url)];
}

void IOSAnalytics::TestLogs()
{
	[::DTDAnalytics testLogs];
}

void IOSAnalytics::TestString(const FString& value)
{
	[::DTDEngineWrapper testStringWithValue:IOSConverter::Convert(value)];
}

void IOSAnalytics::SetLoggerMessageListener(const FDTDLogsListenerDelegate* listener)
{
    if (logsListener != nullptr)
    {
        delete logsListener;
    }

    logsListener = listener;
}

void IOSAnalytics::SetIdentifiersListener(const FDTDLongListenerDelegate* listener)
{
	[::DTDAnalytics setIdentifiersListenerWithListener:[[IOSIdentifiersListener alloc] initWithDelegate:listener]];
}

void IOSAnalytics::GetDeviceId(const FDTDGetterStringDelegate* onResult)
{
	[::DTDAnalytics deviceIdHandler:^(NSString* value) {
        onResult->ExecuteIfBound(IOSConverter::Convert(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetSdkVersion(const FDTDGetterStringDelegate* onResult)
{
	[::DTDAnalytics sdkVersionHandler:^(NSString* value) {
        onResult->ExecuteIfBound(IOSConverter::Convert(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetApplicationVersion(const FDTDGetterStringDelegate* onResult)
{
	delete onResult;

	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("GetApplicationVersion");
}

void IOSAnalytics::SetApplicationVersion(const FString& value)
{
	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("SetApplicationVersion");
}

void IOSAnalytics::GetTrackingAvailability(const FDTDGetterBoolDelegate* onResult)
{
	[::DTDAnalytics trackingAvailabilityHandler:^(BOOL value) {
        onResult->ExecuteIfBound(IOSConverter::ConvertToCpp(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetUserId(const FDTDGetterStringDelegate* onResult)
{
	[::DTDAnalytics userIdHandler:^(NSString* value) {
        onResult->ExecuteIfBound(IOSConverter::Convert(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetCurrentLevel(const FDTDGetterIntDelegate* onResult)
{
	[::DTDAnalytics currentLevelHandler:^(NSInteger value) {
        onResult->ExecuteIfBound(IOSConverter::ConvertToInt32(value));
		delete onResult;
    }];
}

void IOSAnalytics::Initialize(const FString& appKey)
{
	[::DTDAnalytics applicationKey:IOSConverter::Convert(appKey)];
}

void IOSAnalytics::InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config)
{
	const auto oco_config = IOSConverter::Convert(config);
	const auto ocs_appKey = IOSConverter::Convert(appKey);
	[::DTDAnalytics applicationKey:ocs_appKey configuration:oco_config];
	[oco_config release];
}

void IOSAnalytics::Deinitialize()
{
	// Not supported.
}

void IOSAnalytics::StartActivity()
{
	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("StartActivity");
}

void IOSAnalytics::StopActivity()
{
	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("StopActivity");
}

void IOSAnalytics::SetUserId(const FString& userId)
{
	[::DTDAnalytics userId:IOSConverter::Convert(userId)];
}

void IOSAnalytics::ReplaceUserId(const FString& fromUserId, const FString& toUserId)
{
	[::DTDAnalytics replaceFromUserId:IOSConverter::Convert(fromUserId) toUserId:IOSConverter::Convert(toUserId)];
}

void IOSAnalytics::CustomEvent(const FString& eventName)
{
	[::DTDAnalytics customEvent:IOSConverter::Convert(eventName)];
}

void IOSAnalytics::CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params)
{
	const auto ocs_eventName = IOSConverter::Convert(eventName);
	const auto oco_params = IOSConverter::Convert(params);
	[::DTDAnalytics customEvent:ocs_eventName withParameters:oco_params];
	[oco_params release];
}

void IOSAnalytics::SetCurrentLevel(int32 level)
{
	[::DTDAnalytics currentLevel:IOSConverter::Convert(level)];
}

void IOSAnalytics::SetTrackingAvailability(bool value)
{
	[::DTDAnalytics trackingAvailability:IOSConverter::ConvertToObjC(value)];
}

void IOSAnalytics::CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType)
{
	[::DTDAnalytics currencyName:IOSConverter::Convert(currencyName) currencyAmount:IOSConverter::Convert(currencyAmount) source:IOSConverter::Convert(source) accrualType:IOSConverter::Convert(accrualType)];
}

void IOSAnalytics::VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency)
{
	[::DTDAnalytics virtualCurrencyPaymentWithPurchaseId:IOSConverter::Convert(purchaseId) purchaseType:IOSConverter::Convert(purchaseType) purchaseAmount:IOSConverter::Convert(purchaseAmount) purchasePrice:IOSConverter::Convert(purchasePrice) purchaseCurrency:IOSConverter::Convert(purchaseCurrency)];
}

void IOSAnalytics::VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources)
{
	const auto ocs_purchaseId = IOSConverter::Convert(purchaseId);
	const auto ocs_purchaseType = IOSConverter::Convert(purchaseType);
	const auto ocp_purchaseAmount = IOSConverter::Convert(purchaseAmount);
	const auto oco_resources = IOSConverter::Convert(resources);
	[::DTDAnalytics virtualCurrencyPaymentWithPurchaseId:ocs_purchaseId purchaseType:ocs_purchaseType purchaseAmount:ocp_purchaseAmount resources:oco_resources];
	[oco_resources release];
}

void IOSAnalytics::LevelUp(int32 level)
{
	[::DTDAnalytics levelUp:IOSConverter::Convert(level)];
}

void IOSAnalytics::LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance)
{
	const auto ocp_level = IOSConverter::Convert(level);
	const auto oco_balance = IOSConverter::Convert(balance);
	[::DTDAnalytics levelUp:ocp_level withBalances:oco_balance];
	[oco_balance release];
}

void IOSAnalytics::CurrentBalance(const TMap<FString, int64>& balance)
{
	const auto oco_balance = IOSConverter::Convert(balance);
	[::DTDAnalytics currentBalanceWithBalance:oco_balance];
	[oco_balance release];
}

void IOSAnalytics::Referrer(const TMap<EDTDReferralProperty, FString>& utmData)
{
	const auto oco_utmData = IOSConverter::Convert(utmData);
	[::DTDAnalytics referrer:oco_utmData];
	[oco_utmData release];
}

void IOSAnalytics::Tutorial(int32 step)
{
	[::DTDAnalytics tutorialStep:IOSConverter::Convert(step)];
}

void IOSAnalytics::StartProgressionEvent(const FString& eventName)
{
	[::DTDAnalytics startProgressionEvent:IOSConverter::Convert(eventName)];
}

void IOSAnalytics::StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params)
{
	const auto ocs_eventName = IOSConverter::Convert(eventName);
	const auto oco_params = IOSConverter::Convert(params);
	[::DTDAnalytics startProgressionEvent:ocs_eventName withParameters:oco_params];
	[oco_params release];
}

void IOSAnalytics::FinishProgressionEvent(const FString& eventName)
{
	[::DTDAnalytics finishProgressionEvent:IOSConverter::Convert(eventName)];
}

void IOSAnalytics::FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params)
{
	const auto ocs_eventName = IOSConverter::Convert(eventName);
	const auto oco_params = IOSConverter::Convert(params);
	[::DTDAnalytics finishProgressionEvent:ocs_eventName withParameters:oco_params];
	[oco_params release];
}

void IOSAnalytics::RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode)
{
	[::DTDAnalytics realCurrencyPaymentWithOrderId:IOSConverter::Convert(orderId) price:(double)price productId:IOSConverter::Convert(productId) currencyCode:IOSConverter::Convert(currencyCode)];
}

void IOSAnalytics::SocialNetworkConnect(EDTDSocialNetwork socialNetwork)
{
	const auto oco_socialNetwork = IOSConverter::Convert(socialNetwork);
	[::DTDAnalytics socialNetworkConnect:oco_socialNetwork];
	[oco_socialNetwork release];
}

void IOSAnalytics::SocialNetworkConnectCustom(const FString& socialNetwork)
{
	[::DTDAnalytics socialNetworkConnect:IOSConverter::ConvertToSocialNetwork(socialNetwork)];
}

void IOSAnalytics::SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason)
{
	const auto oco_socialNetwork = IOSConverter::Convert(socialNetwork);
	const auto ocs_reason = IOSConverter::Convert(reason);
	[::DTDAnalytics socialNetworkPost:oco_socialNetwork withReason:ocs_reason];
	[oco_socialNetwork release];
}

void IOSAnalytics::SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason)
{
	[::DTDAnalytics socialNetworkPost:IOSConverter::ConvertToSocialNetwork(socialNetwork) withReason:IOSConverter::Convert(reason)];
}

void IOSAnalytics::AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit)
{
	const auto ocs_socialNetwork = IOSConverter::Convert(socialNetwork);
	const auto ocp_revenue = static_cast<double>(revenue);
	const auto ocs_placement = IOSConverter::Convert(placement);
	const auto ocs_unit = IOSConverter::Convert(unit);
	[::DTDAnalytics adImpressionWithNetwork:ocs_socialNetwork revenue:ocp_revenue placement:ocs_placement unit:ocs_unit];
}

void IOSAnalytics::SendBufferedEvents()
{
	[::DTDAnalytics sendBufferedEvents];
}

void IOSAnalytics::SetLogLevel(EDTDLogLevel logLevel)
{
	[::DTDAnalytics setLogLevel:IOSConverter::Convert(logLevel)];
}

void IOSAnalytics::GetName(const FDTDGetterStringDelegate* onResult)
{
	[::DTDUserCard getNameHandler:^(NSString* value) {
        onResult->ExecuteIfBound(IOSConverter::Convert(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetEmail(const FDTDGetterStringDelegate* onResult)
{
	[::DTDUserCard getEmailHandler:^(NSString* value) {
        onResult->ExecuteIfBound(IOSConverter::Convert(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetPhone(const FDTDGetterStringDelegate* onResult)
{
	[::DTDUserCard getPhoneHandler:^(NSString* value) {
        onResult->ExecuteIfBound(IOSConverter::Convert(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetPhoto(const FDTDGetterStringDelegate* onResult)
{
	[::DTDUserCard getPhotoHandler:^(NSString* value) {
        onResult->ExecuteIfBound(IOSConverter::Convert(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetGender(const FDTDGetterGenderDelegate* onResult)
{
	[::DTDUserCard getGenderHandler:^(Gender value) {
        onResult->ExecuteIfBound(IOSConverter::Convert(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetAge(const FDTDGetterLongDelegate* onResult)
{
	[::DTDUserCard getAgeHandler:^(NSInteger value) {
        onResult->ExecuteIfBound(IOSConverter::ConvertToInt64(value));
		delete onResult;
    }];
}

void IOSAnalytics::GetCheater(const FDTDGetterBoolDelegate* onResult)
{
	[::DTDUserCard getCheaterHandler:^(BOOL value) {
        onResult->ExecuteIfBound(IOSConverter::ConvertToCpp(value));
		delete onResult;
    }];
}

void IOSAnalytics::TryGetString(const FString& key, const FDTDGetterOptionalStringDelegate* onResult)
{
	[::DTDUserCard getValueWithKey:IOSConverter::Convert(key) :^(id value) {
        if (value && [value respondsToSelector:@selector(UTF8String)])
        {
			onResult->ExecuteIfBound(true, IOSConverter::FromUtf8String([value UTF8String]));
        }
		else
		{
			onResult->ExecuteIfBound(false, "");
		}
        
		delete onResult;
    }];
}

void IOSAnalytics::TryGetBool(const FString& key, const FDTDGetterOptionalBoolDelegate* onResult)
{
	[::DTDUserCard getValueWithKey:IOSConverter::Convert(key) :^(id value) {
        if (value && [value respondsToSelector:@selector(boolValue)])
        {
			onResult->ExecuteIfBound(true, IOSConverter::ConvertToCpp([value boolValue]));
        }
		else
		{
			onResult->ExecuteIfBound(false, false);
		}
        
		delete onResult;
    }];
}

void IOSAnalytics::TryGetFloat(const FString& key, const FDTDGetterOptionalFloatDelegate* onResult)
{
	[::DTDUserCard getValueWithKey:IOSConverter::Convert(key) :^(id value) {
        if (value && [value respondsToSelector:@selector(doubleValue)])
        {
			onResult->ExecuteIfBound(true, (float)[value doubleValue]);
        }
		else
		{
			onResult->ExecuteIfBound(false, 0);
		}
        
		delete onResult;
    }];
}

void IOSAnalytics::TryGetLong(const FString& key, const FDTDGetterOptionalLongDelegate* onResult)
{
	[::DTDUserCard getValueWithKey:IOSConverter::Convert(key) :^(id value) {
        if (value && [value respondsToSelector:@selector(longValue)])
        {
			onResult->ExecuteIfBound(true, IOSConverter::ConvertToInt64([value longValue]));
        }
		else
		{
			onResult->ExecuteIfBound(false, 0);
		}
        
		delete onResult;
    }];
}

void IOSAnalytics::SetName(const FString& name)
{
	[::DTDUserCard setName:IOSConverter::Convert(name)];
}

void IOSAnalytics::SetEmail(const FString& email)
{
	[::DTDUserCard setEmail:IOSConverter::Convert(email)];
}

void IOSAnalytics::SetPhone(const FString& phone)
{
	[::DTDUserCard setPhone:IOSConverter::Convert(phone)];
}

void IOSAnalytics::SetPhoto(const FString& photo)
{
	[::DTDUserCard setPhoto:IOSConverter::Convert(photo)];
}

void IOSAnalytics::SetGender(EDTDGender gender)
{
	[::DTDUserCard setGender:IOSConverter::Convert(gender)];
}

void IOSAnalytics::SetAge(int64 age)
{
	[::DTDUserCard setAge:IOSConverter::Convert(age)];
}

void IOSAnalytics::SetCheater(bool cheater)
{
	[::DTDUserCard setCheater:IOSConverter::ConvertToObjC(cheater)];
}

void IOSAnalytics::SetString(const FString& key, const FString& value)
{
	[::DTDUserCard setString:IOSConverter::Convert(key) value:IOSConverter::Convert(value)];
}

void IOSAnalytics::SetBool(const FString& key, bool value)
{
	[::DTDUserCard setBool:IOSConverter::Convert(key) value:IOSConverter::ConvertToObjC(value)];
}

void IOSAnalytics::SetInt(const FString& key, int64 value)
{
	[::DTDUserCard setInt:IOSConverter::Convert(key) value:IOSConverter::Convert(value)];
}

void IOSAnalytics::SetFloat(const FString& key, float value)
{
	[::DTDUserCard setDouble:IOSConverter::Convert(key) value:(double)value];
}

void IOSAnalytics::Unset(const FString& key)
{
	[::DTDUserCard unsetProperty:IOSConverter::Convert(key)];
}

void IOSAnalytics::UnsetArray(const TArray<FString>& keys)
{
	const auto oco_keys = IOSConverter::Convert(keys);
	[::DTDUserCard unset:oco_keys];
	[oco_keys release];
}

void IOSAnalytics::IncrementInt(const FString& key, int64 value)
{
	[::DTDUserCard increment:IOSConverter::Convert(key) byInt:IOSConverter::Convert(value)];
}

void IOSAnalytics::IncrementFloat(const FString& key, float value)
{
	[::DTDUserCard increment:IOSConverter::Convert(key) byDouble:(double)value];
}

void IOSAnalytics::ClearUser()
{
	[::DTDUserCard clearUser];
}
