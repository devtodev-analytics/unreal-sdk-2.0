// Copyright (c) devtodev. All rights reserved.

#include "AndroidAnalytics.h"

#include "Async/TaskGraphInterfaces.h"

#include "Platform/Android/DelegatesJNI.h"
#include "Platform/Android/ConverterJNI.h"
#include "Platform/Android/HelperJNI.h"

#include "Constants/SDKConstants.h"
#include "Logging/DTDLogCategory.h"
#include "Logging/DTDLogs.h"

AndroidAnalytics::AndroidAnalytics()
{
	// Set SDK version.
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setSDKVersion", SDKConstants::Version);

	// Set logs listener.
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
    jclass jclsOnMessageCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevOnMessageCallback");
    jmethodID jmidSetOnMessageCallback = Env->GetStaticMethodID(jclsAnalytics, "setLoggerMessageClosure", "(Lcom/devtodev/analytics/unrealwrapper/IGetterIntAndString;)V");
    jmethodID jmidOnMessageCallbackCallbackInit = Env->GetMethodID(jclsOnMessageCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;)V");
    jobject joOnMessageCallbackProxy = Env->NewObject(jclsOnMessageCallback, jmidOnMessageCallbackCallbackInit, FJavaWrapper::GameActivityThis);
    Env->CallStaticVoidMethod(jclsAnalytics, jmidSetOnMessageCallback, joOnMessageCallbackProxy);
    Env->DeleteLocalRef(joOnMessageCallbackProxy);
}

AndroidAnalytics::~AndroidAnalytics()
{
	
}

void AndroidAnalytics::SetTestProxyUrl(const FString& url)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setTestProxyUrl", url);
}

void AndroidAnalytics::SetTestCustomUrl(const FString& url)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setTestCustomUrl", url);
}

void AndroidAnalytics::TestLogs()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "testLogs");
}

void AndroidAnalytics::TestString(const FString& value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "testString", value);
}

void AndroidAnalytics::SetLoggerMessageListener(const FDTDLogsListenerDelegate* listener)
{
	Devtodev_SetLogsListener(listener);
}

void AndroidAnalytics::SetIdentifiersListener(const FDTDLongListenerDelegate* listener)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jclass jclsGetterLongCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevPersistGetterLongCallback");
    jmethodID jmidPersistGetterLongCallbackInit = Env->GetMethodID(jclsGetterLongCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)listener, sizeof(FDTDLongListenerDelegate));
	jobject joPersistGetterLongCallbackProxy = Env->NewObject(jclsGetterLongCallback, jmidPersistGetterLongCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "setIdentifiersListener", "(Lcom/devtodev/analytics/unrealwrapper/IGetterLong;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joPersistGetterLongCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joPersistGetterLongCallbackProxy);
}

void AndroidAnalytics::GetDeviceId(const FDTDGetterStringDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterStringCallback");
    jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetDeviceId = Env->GetStaticMethodID(jclsAnalytics, "getDeviceId", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetDeviceId, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetSdkVersion(const FDTDGetterStringDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterStringCallback");
    jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetSdkVersion = Env->GetStaticMethodID(jclsAnalytics, "getSdkVersion", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetSdkVersion, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetApplicationVersion(const FDTDGetterStringDelegate* onResult)
{
	delete onResult;

	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("GetApplicationVersion");
}

void AndroidAnalytics::SetApplicationVersion(const FString& value)
{
	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("SetApplicationVersion");
}

void AndroidAnalytics::GetTrackingAvailability(const FDTDGetterBoolDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jclass jclsGetterBoolCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterBoolCallback");
    jmethodID jmidGetterBoolCallbackInit = Env->GetMethodID(jclsGetterBoolCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterBoolDelegate));
	jobject joGetterBoolCallbackProxy = Env->NewObject(jclsGetterBoolCallback, jmidGetterBoolCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetTrackingAvailability = Env->GetStaticMethodID(jclsAnalytics, "getTrackingAvailability", "(Lcom/devtodev/analytics/unrealwrapper/IGetterBool;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetTrackingAvailability, joGetterBoolCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterBoolCallbackProxy);
}

void AndroidAnalytics::GetUserId(const FDTDGetterStringDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterStringCallback");
    jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetUserId = Env->GetStaticMethodID(jclsAnalytics, "getUserId", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetUserId, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetCurrentLevel(const FDTDGetterIntDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jclass jclsGetterIntCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterIntCallback");
    jmethodID jmidGetterIntCallbackInit = Env->GetMethodID(jclsGetterIntCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterIntDelegate));
	jobject joGetterIntCallbackProxy = Env->NewObject(jclsGetterIntCallback, jmidGetterIntCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetCurrentLevel = Env->GetStaticMethodID(jclsAnalytics, "getCurrentLevel", "(Lcom/devtodev/analytics/unrealwrapper/IGetterInt;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetCurrentLevel, joGetterIntCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterIntCallbackProxy);
}

void AndroidAnalytics::Initialize(const FString& appKey)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidInitialize = Env->GetStaticMethodID(jclsAnalytics, "initialize", "(Ljava/lang/String;Landroid/content/Context;)V");
	jstring jsAppKey = Env->NewStringUTF(TCHAR_TO_UTF8(*appKey));
	jobject joActivity = FAndroidApplication::GetGameActivityThis();
	Env->CallStaticVoidMethod(jclsAnalytics, jmidInitialize, jsAppKey, joActivity);
	Env->DeleteLocalRef(jsAppKey);
}

void AndroidAnalytics::InitializeWithConfig(const FString& appKey, const FDTDAnalyticsConfiguration& config)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidInitialize = Env->GetStaticMethodID(jclsAnalytics, "initialize", "(Ljava/lang/String;Lcom/devtodev/analytics/external/analytics/DTDAnalyticsConfiguration;Landroid/content/Context;)V");
	jobject joActivity = FAndroidApplication::GetGameActivityThis();
	jstring jsAppKey = Env->NewStringUTF(TCHAR_TO_UTF8(*appKey));
	jobject joConfig = ConverterJNI::ConvertToJObject(config);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidInitialize, jsAppKey, joConfig, joActivity);
	Env->DeleteLocalRef(jsAppKey);
	Env->DeleteLocalRef(joConfig);
}

void AndroidAnalytics::Deinitialize()
{
	// Not supported.
}

void AndroidAnalytics::StartActivity()
{
	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("StartActivity");
}

void AndroidAnalytics::StopActivity()
{
	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("StopActivity");
}

void AndroidAnalytics::SetUserId(const FString& userId)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setUserId", userId);
}

void AndroidAnalytics::ReplaceUserId(const FString& fromUserId, const FString& toUserId)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "replaceUserId", fromUserId, toUserId);
}

void AndroidAnalytics::CustomEvent(const FString& eventName)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "customEvent", eventName);
}

void AndroidAnalytics::CustomEventWithParams(const FString& eventName, const FDTDCustomEventParams& params)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	// Create params.
	jclass jclsCustomEventParameters = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/analytics/DTDCustomEventParameters");
	jmethodID jmidCustomEventParametersInit = Env->GetMethodID(jclsCustomEventParameters, "<init>", "()V");
    jobject joCustomEventParameters = Env->NewObject(jclsCustomEventParameters, jmidCustomEventParametersInit);

	// String params.
	for (const TPair<FString, FString>& pair : params.StringParameters)
	{
		jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
		jstring jsValue = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value));
		// TODO: Oprimize.
		jmethodID jmidAdd = Env->GetMethodID(jclsCustomEventParameters, "add", "(Ljava/lang/String;Ljava/lang/String;)V");
		Env->CallVoidMethod(joCustomEventParameters, jmidAdd, jsKey, jsValue);
		Env->DeleteLocalRef(jsKey);
		Env->DeleteLocalRef(jsValue);
	}

	// Bool params.
	for (const TPair<FString, bool>& pair : params.BoolParameters)
	{
		jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
		// TODO: Oprimize.
		jmethodID jmidAdd = Env->GetMethodID(jclsCustomEventParameters, "add", "(Ljava/lang/String;Z)V");
		Env->CallVoidMethod(joCustomEventParameters, jmidAdd, jsKey, pair.Value);
		Env->DeleteLocalRef(jsKey);
	}

	// Long marameters.
	for (const TPair<FString, int64>& pair : params.IntParameters)
	{
		jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
		// TODO: Oprimize.
		jmethodID jmidAdd = Env->GetMethodID(jclsCustomEventParameters, "add", "(Ljava/lang/String;J)V");
		Env->CallVoidMethod(joCustomEventParameters, jmidAdd, jsKey, pair.Value);
		Env->DeleteLocalRef(jsKey);
	}

	// Double marameters.
	for (const TPair<FString, float>& pair : params.FloatParameters)
	{
		jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
		// TODO: Oprimize.
		jmethodID jmidAdd = Env->GetMethodID(jclsCustomEventParameters, "add", "(Ljava/lang/String;D)V");
		Env->CallVoidMethod(joCustomEventParameters, jmidAdd, jsKey, (double)pair.Value);
		Env->DeleteLocalRef(jsKey);
	}
	
	// Call.
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidCustomEvent = Env->GetStaticMethodID(jclsAnalytics, "customEvent", "(Ljava/lang/String;Lcom/devtodev/analytics/external/analytics/DTDCustomEventParameters;)V");
	jstring jsEventName = Env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidCustomEvent, jsEventName, joCustomEventParameters);
	Env->DeleteLocalRef(jsEventName);
}

void AndroidAnalytics::SetCurrentLevel(int32 level)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setCurrentLevel", level);
}

void AndroidAnalytics::SetTrackingAvailability(bool value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setTrackingAvailability", value);
}

void AndroidAnalytics::CurrencyAccrual(const FString& currencyName, int32 currencyAmount, const FString& source, EDTDAccrualType accrualType)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "currencyAccrual", "(Ljava/lang/String;ILjava/lang/String;Lcom/devtodev/analytics/external/analytics/DTDAccrualType;)V");
	jstring jsCurrencyName = Env->NewStringUTF(TCHAR_TO_UTF8(*currencyName));
	jstring jsSource = Env->NewStringUTF(TCHAR_TO_UTF8(*source));
	jobject joAccrualType = ConverterJNI::ConvertToJavaAccrualType(accrualType);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, jsCurrencyName, currencyAmount, jsSource, joAccrualType);
	Env->DeleteLocalRef(jsCurrencyName);
	Env->DeleteLocalRef(jsSource);
	Env->DeleteLocalRef(joAccrualType);
}

void AndroidAnalytics::VirtualCurrencyPayment(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString& purchaseCurrency)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "virtualCurrencyPayment", "(Ljava/lang/String;Ljava/lang/String;IILjava/lang/String;)V");
	jstring jsPurchaseId = Env->NewStringUTF(TCHAR_TO_UTF8(*purchaseId));
	jstring jsPurchaseType = Env->NewStringUTF(TCHAR_TO_UTF8(*purchaseType));
	jstring jsPurchaseCurrency = Env->NewStringUTF(TCHAR_TO_UTF8(*purchaseCurrency));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, jsPurchaseId, jsPurchaseType, purchaseAmount, purchasePrice, jsPurchaseCurrency);
	Env->DeleteLocalRef(jsPurchaseId);
	Env->DeleteLocalRef(jsPurchaseType);
	Env->DeleteLocalRef(jsPurchaseCurrency);
}

void AndroidAnalytics::VirtualCurrencyPaymentWithResources(const FString& purchaseId, const FString& purchaseType, int32 purchaseAmount, const TMap<FString, int32>& resources)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidVirtualCurrencyPayment = Env->GetStaticMethodID(jclsAnalytics, "virtualCurrencyPayment", "(Ljava/lang/String;Ljava/lang/String;ILjava/util/Map;)V");
	jstring jsPurchaseId = Env->NewStringUTF(TCHAR_TO_UTF8(*purchaseId));
	jstring jsPurchaseType = Env->NewStringUTF(TCHAR_TO_UTF8(*purchaseType));
    jobject joHashResources = ConverterJNI::ConvertToJMap(resources);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidVirtualCurrencyPayment, jsPurchaseId, jsPurchaseType, purchaseAmount, joHashResources);
	Env->DeleteLocalRef(jsPurchaseId);
	Env->DeleteLocalRef(jsPurchaseType);
	Env->DeleteLocalRef(joHashResources);
}

void AndroidAnalytics::LevelUp(int32 level)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "levelUp", level);
}

void AndroidAnalytics::LevelUpWithBalance(int32 level, const TMap<FString, int64>& balance)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidLevelUp = Env->GetStaticMethodID(jclsAnalytics, "levelUp", "(ILjava/util/Map;)V");
    jobject joBalance = ConverterJNI::ConvertToJMap(balance);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidLevelUp, level, joBalance);
	Env->DeleteLocalRef(joBalance);
}

void AndroidAnalytics::CurrentBalance(const TMap<FString, int64>& balance)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidCurrentBalance = Env->GetStaticMethodID(jclsAnalytics, "currentBalance", "(Ljava/util/Map;)V");
    jobject joBalance = ConverterJNI::ConvertToJMap(balance);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidCurrentBalance, joBalance);
	Env->DeleteLocalRef(joBalance);
}

void AndroidAnalytics::Referrer(const TMap<EDTDReferralProperty, FString>& utmData)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidReferrer = Env->GetStaticMethodID(jclsAnalytics, "referrer", "(Ljava/util/Map;)V");
    jobject joUtmData = ConverterJNI::ConvertToJMap(utmData);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidReferrer, joUtmData);
	Env->DeleteLocalRef(joUtmData);
}

void AndroidAnalytics::Tutorial(int32 step)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "tutorial", step);
}

void AndroidAnalytics::StartProgressionEvent(const FString& eventName)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "startProgressionEvent", eventName);
}

void AndroidAnalytics::StartProgressionEventWithParams(const FString& eventName, const FDTDStartProgressionEventParams& params)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidStartProgressionEvent = Env->GetStaticMethodID(jclsAnalytics, "startProgressionEvent", "(Ljava/lang/String;Lcom/devtodev/analytics/external/analytics/DTDStartProgressionEventParameters;)V");
	jstring jsEventName = Env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
    jobject joParams = ConverterJNI::ConvertToJObject(params);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidStartProgressionEvent, jsEventName, joParams);
	Env->DeleteLocalRef(jsEventName);
	Env->DeleteLocalRef(joParams);
}

void AndroidAnalytics::FinishProgressionEvent(const FString& eventName)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "finishProgressionEvent", eventName);
}

void AndroidAnalytics::FinishProgressionEventWithParams(const FString& eventName, const FDTDFinishProgressionEventParams& params)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidFinishProgressionEvent = Env->GetStaticMethodID(jclsAnalytics, "finishProgressionEvent", "(Ljava/lang/String;Lcom/devtodev/analytics/external/analytics/DTDFinishProgressionEventParameters;)V");
	jstring jsEventName = Env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
    jobject joParams = ConverterJNI::ConvertToJObject(params);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidFinishProgressionEvent, jsEventName, joParams);
	Env->DeleteLocalRef(jsEventName);
	Env->DeleteLocalRef(joParams);
}

void AndroidAnalytics::RealCurrencyPayment(const FString& orderId, float price, const FString& productId, const FString& currencyCode)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "realCurrencyPayment", orderId, (double)price, productId, currencyCode);
}

void AndroidAnalytics::SocialNetworkConnect(EDTDSocialNetwork socialNetwork)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "socialNetworkConnect", "(Lcom/devtodev/analytics/external/analytics/DTDSocialNetwork;)V");
	jobject joSocialNetwork = ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joSocialNetwork);
	Env->DeleteLocalRef(joSocialNetwork);
}

void AndroidAnalytics::SocialNetworkConnectCustom(const FString& socialNetwork)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "socialNetworkConnect", "(Lcom/devtodev/analytics/external/analytics/DTDSocialNetwork;)V");
	jobject joSocialNetwork = ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joSocialNetwork);
	Env->DeleteLocalRef(joSocialNetwork);
}

void AndroidAnalytics::SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString& reason)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "socialNetworkPost", "(Lcom/devtodev/analytics/external/analytics/DTDSocialNetwork;Ljava/lang/String;)V");
	jobject joSocialNetwork = ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
	jstring jsReason = Env->NewStringUTF(TCHAR_TO_UTF8(*reason));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joSocialNetwork, jsReason);
	Env->DeleteLocalRef(joSocialNetwork);
	Env->DeleteLocalRef(jsReason);
}

void AndroidAnalytics::SocialNetworkPostCustom(const FString& socialNetwork, const FString& reason)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "socialNetworkPost", "(Lcom/devtodev/analytics/external/analytics/DTDSocialNetwork;Ljava/lang/String;)V");
	jobject joSocialNetwork = ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
	jstring jsReason = Env->NewStringUTF(TCHAR_TO_UTF8(*reason));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joSocialNetwork, jsReason);
	Env->DeleteLocalRef(joSocialNetwork);
	Env->DeleteLocalRef(jsReason);
}

void AndroidAnalytics::AdImpression(const FString& socialNetwork, float revenue, const FString& placement, const FString& unit)
{
	HelperJNI::CallStaticMethod(
		"com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", 
		"adImpression", 
		socialNetwork, 
		static_cast<double>(revenue), 
		placement, 
		unit);
}

void AndroidAnalytics::SendBufferedEvents()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "sendBufferedEvents");
}

void AndroidAnalytics::SetLogLevel(EDTDLogLevel logLevel)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidSetLogLevel = Env->GetStaticMethodID(jclsAnalytics, "setLogLevel", "(Lcom/devtodev/analytics/external/DTDLogLevel;)V");
	jobject joLogLevel = ConverterJNI::ConvertToJavaLogLevel(logLevel);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidSetLogLevel, joLogLevel);
	Env->DeleteLocalRef(joLogLevel);
}

void AndroidAnalytics::GetName(const FDTDGetterStringDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterStringCallback");
    jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetName = Env->GetStaticMethodID(jclsAnalytics, "getName", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetName, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetEmail(const FDTDGetterStringDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterStringCallback");
    jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetEmail = Env->GetStaticMethodID(jclsAnalytics, "getEmail", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetEmail, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetPhone(const FDTDGetterStringDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterStringCallback");
    jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetPhone = Env->GetStaticMethodID(jclsAnalytics, "getPhone", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetPhone, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetPhoto(const FDTDGetterStringDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterStringCallback");
    jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetPhoto = Env->GetStaticMethodID(jclsAnalytics, "getPhoto", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetPhoto, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetGender(const FDTDGetterGenderDelegate* onResult)
{
	FDTDGetterLongDelegate* onLongResultDelegate = new FDTDGetterLongDelegate();
	onLongResultDelegate->BindLambda([onResult](int64 result)
	{
		EDTDGender gender;
		switch (result)
		{
		case 0:
			gender = EDTDGender::Unknown;
			break;
		case 1:
			gender = EDTDGender::Male;
			break;
		case 2:
			gender = EDTDGender::Female;
			break;
		default:
			gender = EDTDGender::Unknown;
		}
		onResult->ExecuteIfBound(gender);
		delete onResult;
	});
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsGetterLongCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterLongCallback");
	jmethodID jmidGetterLongCallbackInit = Env->GetMethodID(jclsGetterLongCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onLongResultDelegate, sizeof(FDTDGetterLongDelegate));
	jobject joGetterLongCallbackProxy = Env->NewObject(jclsGetterLongCallback, jmidGetterLongCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jmethodID jmidGetGender = Env->GetStaticMethodID(jclsAnalytics, "getGender", "(Lcom/devtodev/analytics/unrealwrapper/IGetterLong;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetGender, joGetterLongCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterLongCallbackProxy);
}

void AndroidAnalytics::GetAge(const FDTDGetterLongDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsGetterLongCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterLongCallback");
    jmethodID jmidGetterLongCallbackInit = Env->GetMethodID(jclsGetterLongCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterLongDelegate));
	jobject joGetterLongCallbackProxy = Env->NewObject(jclsGetterLongCallback, jmidGetterLongCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetAge = Env->GetStaticMethodID(jclsAnalytics, "getAge", "(Lcom/devtodev/analytics/unrealwrapper/IGetterLong;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetAge, joGetterLongCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterLongCallbackProxy);
}

void AndroidAnalytics::GetCheater(const FDTDGetterBoolDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsGetterBoolCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterBoolCallback");
    jmethodID jmidGetterBoolCallbackInit = Env->GetMethodID(jclsGetterBoolCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterBoolDelegate));
	jobject joGetterBoolCallbackProxy = Env->NewObject(jclsGetterBoolCallback, jmidGetterBoolCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
    jmethodID jmidGetCheater = Env->GetStaticMethodID(jclsAnalytics, "getCheater", "(Lcom/devtodev/analytics/unrealwrapper/IGetterBool;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetCheater, joGetterBoolCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterBoolCallbackProxy);
}

void AndroidAnalytics::TryGetString(const FString& key, const FDTDGetterOptionalStringDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsOptionalGetterStringCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterOptionalStringCallback");
    jmethodID jmidOptionalGetterStringCallbackInit = Env->GetMethodID(jclsOptionalGetterStringCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterOptionalStringDelegate));
	jobject joOptionslGetterStringCallbackProxy = Env->NewObject(jclsOptionalGetterStringCallback, jmidOptionalGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
    jmethodID jmidValue = Env->GetStaticMethodID(jclsAnalytics, "getValue", "(Ljava/lang/String;Lcom/devtodev/analytics/unrealwrapper/IGetterObject;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidValue, jsKey, joOptionslGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joOptionslGetterStringCallbackProxy);
	Env->DeleteLocalRef(jsKey);
}

void AndroidAnalytics::TryGetBool(const FString& key, const FDTDGetterOptionalBoolDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsOptionalGetterBoolCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterOptionalBoolCallback");
    jmethodID jmidOptionalGetterBoolCallbackInit = Env->GetMethodID(jclsOptionalGetterBoolCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterOptionalBoolDelegate));
	jobject joOptionalGetterBoolCallbackProxy = Env->NewObject(jclsOptionalGetterBoolCallback, jmidOptionalGetterBoolCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
    jmethodID jmidValue = Env->GetStaticMethodID(jclsAnalytics, "getValue", "(Ljava/lang/String;Lcom/devtodev/analytics/unrealwrapper/IGetterObject;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidValue, jsKey, joOptionalGetterBoolCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joOptionalGetterBoolCallbackProxy);
	Env->DeleteLocalRef(jsKey);
}

void AndroidAnalytics::TryGetFloat(const FString& key, const FDTDGetterOptionalFloatDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsOptionalGetterFloatCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterOptionalFloatCallback");
    jmethodID jmidOptionalGetterFloatCallbackInit = Env->GetMethodID(jclsOptionalGetterFloatCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterOptionalFloatDelegate));
	jobject joOptionalGetterFloatCallbackProxy = Env->NewObject(jclsOptionalGetterFloatCallback, jmidOptionalGetterFloatCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
    jmethodID jmidValue = Env->GetStaticMethodID(jclsAnalytics, "getValue", "(Ljava/lang/String;Lcom/devtodev/analytics/unrealwrapper/IGetterObject;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidValue, jsKey, joOptionalGetterFloatCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joOptionalGetterFloatCallbackProxy);
	Env->DeleteLocalRef(jsKey);
}

void AndroidAnalytics::TryGetLong(const FString& key, const FDTDGetterOptionalLongDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsOptionalGetterLongCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevGetterOptionalLongCallback");
    jmethodID jmidOptionalGetterLongCallbackInit = Env->GetMethodID(jclsOptionalGetterLongCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;Ljava/lang/Object;)V");
	jobject joPointer = Env->NewDirectByteBuffer((void*)onResult, sizeof(FDTDGetterLongDelegate));
	jobject joOptionalGetterLongCallbackProxy = Env->NewObject(jclsOptionalGetterLongCallback, jmidOptionalGetterLongCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
    jmethodID jmidValue = Env->GetStaticMethodID(jclsAnalytics, "getValue", "(Ljava/lang/String;Lcom/devtodev/analytics/unrealwrapper/IGetterObject;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidValue, jsKey, joOptionalGetterLongCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joOptionalGetterLongCallbackProxy);
	Env->DeleteLocalRef(jsKey);
}

void AndroidAnalytics::SetName(const FString& name)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setName", name);
}

void AndroidAnalytics::SetEmail(const FString& email)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setEmail", email);
}

void AndroidAnalytics::SetPhone(const FString& phone)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setPhone", phone);
}

void AndroidAnalytics::SetPhoto(const FString& photo)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setPhoto", photo);
}

void AndroidAnalytics::SetGender(EDTDGender gender)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setGender", gender);
}

void AndroidAnalytics::SetAge(int64 age)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setAge", age);
}

void AndroidAnalytics::SetCheater(bool cheater)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setCheater", cheater);
}

void AndroidAnalytics::SetString(const FString& key, const FString& value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "set", key, value);
}

void AndroidAnalytics::SetBool(const FString& key, bool value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "set", key, value);
}

void AndroidAnalytics::SetInt(const FString& key, int64 value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "set", key, value);
}

void AndroidAnalytics::SetFloat(const FString& key, float value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "set", key, (double)value);
}

void AndroidAnalytics::Unset(const FString& key)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "unset", key);
}

void AndroidAnalytics::UnsetArray(const TArray<FString>& keys)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsUserCard = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsUserCard, "unset", "(Ljava/util/ArrayList;)V");
	jobject joKeys = ConverterJNI::ConvertToJArrayList(keys);
	Env->CallStaticVoidMethod(jclsUserCard, jmidMethod, joKeys);
	Env->DeleteLocalRef(joKeys);
}

void AndroidAnalytics::IncrementInt(const FString& key, int64 value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "increment", key, value);
}

void AndroidAnalytics::IncrementFloat(const FString& key, float value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "increment", key, (double)value);
}

void AndroidAnalytics::ClearUser()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "clearUser");
}
