#pragma once

#include "DTDAccrualType.h"
#include "DTDAnalyticsConfiguration.h"
#include "DTDCallbackBoolArg.h"
#include "DTDCallbackIntArg.h"
#include "DTDCallbackLogLevelAndStringArgs.h"
#include "DTDCallbackLongArg.h"
#include "DTDCallbackVoidArg.h"
#include "DTDCallbackStringArg.h"
#include "DTDCustomEventParameters.h"
#include "DTDString.h"
#include "DTDDefines.h"
#include "DTDDictionaryInt.h"
#include "DTDDictionaryReferralProperty.h"
#include "DTDFinishProgressionEventParameters.h"
#include "DTDStartProgressionEventParameters.h"
#include "DTDRemoteConfigListener.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDAnalytics
	{
	public:
		static void InitializeWrapper();
		static void SetSdkVersion(const DTDString& version);
		static void OnLoggerMessage(const DTDCallbackLogLevelAndStringArgs* del);
		static void SetTestProxyUrl(const DTDString& url);
		static void SetTestCustomUrl(const DTDString& url);
		static void TestLogs();
		static void TestString(const DTDString& value);
		static void CoppaControlEnable();
		static void SetInitializationCompleteCallback(const DTDCallbackVoidArg* del);
		static void SetIdentifiersListener(const DTDCallbackLongArg* del);
		static void GetDeviceId(const DTDCallbackStringArg* del);
		static void GetSdkVersion(const DTDCallbackStringArg* del);
		static void GetApplicationVersion(const DTDCallbackStringArg* del);
		static void SetApplicationVersion(const DTDString& version);
		static void GetTrackingAvailability(const DTDCallbackBoolArg* del);
		static void GetUserId(const DTDCallbackStringArg* del);
		static void GetCurrentLevel(const DTDCallbackIntArg* del);
		static void Initialize(const DTDString& appKey);
		static void InitializeWithConfig(const DTDString& appKey, const DTDAnalyticsConfiguration& config);
		static void InitializeWithConfigWithAbTests(const DTDString& appKey, const DTDAnalyticsConfiguration& config, const DTDRemoteConfigListener* listener);
		static void InitializeWithAbTests(const DTDString& appKey, const DTDRemoteConfigListener* listener);
		static void Deinitialize();
		static void StartActivity();
		static void StopActivity();
		static void SetUserId(const DTDString& userId);
		static void ReplaceUserId(const DTDString& fromUserId, const DTDString& toUserId);
		static void CustomEvent(const DTDString& eventName);
		static void CustomEventWithParams(const DTDString& eventName, const DTDCustomEventParameters& params);
		static void SetCurrentLevel(__int32 level);
		static void SetTrackingAvailability(bool trackingValue);
		static void CurrencyAccrual(const DTDString& currencyName, __int32 currencyAmount, const DTDString& source, DTDAccrualType accrualType);
		static void VirtualCurrencyPayment(const DTDString& purchaseId, const DTDString& purchaseType, __int32 purchaseAmount, __int32 purchasePrice, const DTDString& purchaseCurrency);
		static void VirtualCurrencyPaymentWithMultipleCurrency(const DTDString& purchaseId, const DTDString& purchaseType, __int32 purchaseAmount, const DTDDictionaryInt& map);
		static void LevelUp(__int32 level);
		static void LevelUpWithResources(__int32 level, const DTDDictionaryLong& resources);
		static void CurrentBalance(const DTDDictionaryLong& balance);
		static void Referrer(const DTDDictionaryReferralProperty& referrer);
		static void Tutorial(__int32 step);
		static void StartProgressionEvent(const DTDString& eventName);
		static void StartProgressionEventWithParams(const DTDString& eventName, const DTDStartProgressionEventParameters& params);
		static void FinishProgressionEvent(const DTDString& eventName);
		static void FinishProgressionEventWithParams(const DTDString& eventName, const DTDFinishProgressionEventParameters& params);
		static void RealCurrencyPayment(const DTDString& orderId, double price, const DTDString& productId, const DTDString& currencyCode);
		static void CustomSocialNetworkConnect(const DTDString& socialNetwork);
		static void CustomSocialNetworkPost(const DTDString& socialNetwork, const DTDString& reason);
		static void AdImpression(const DTDString& socialNetwork, double revenue, const DTDString& placement, const DTDString& unit);
		static void SendBufferedEvents();
		static void SetLogLevel(DTDLogLevel logLevel);
	};
}
