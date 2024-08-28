// Copyright (c) devtodev. All rights reserved.

#include "AndroidAnalytics.h"

#include "Async/TaskGraphInterfaces.h"

#include "Platform/Android/DelegatesJNI.h"
#include "Platform/Android/ConverterJNI.h"
#include "Platform/Android/HelperJNI.h"

#include "Constants/SDKConstants.h"
#include "Logging/DTDLogCategory.h"
#include "Logging/DTDLogs.h"

#include "AndroidDefinitions.h"
#include "Json.h"
#include "Runtime/Launch/Resources/Version.h"

AndroidAnalytics::AndroidAnalytics()
{

#if ENGINE_MAJOR_VERSION >= 5
	enganePath = "com/epicgames/unreal";
#else
	enganePath = "com/epicgames/ue4";
#endif
	// Set SDK version.
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setSDKVersion", SDKConstants::Version);

	// // Set logs listener.
	// JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	// jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	// jclass jclsOnMessageCallback = FAndroidApplication::FindJavaClass("com/epicgames/ue4/GameActivity$DevToDevOnMessageCallback");
	// jmethodID jmidSetOnMessageCallback = Env->GetStaticMethodID(jclsAnalytics, "setLoggerMessageClosure", "(Lcom/devtodev/analytics/unrealwrapper/IGetterIntAndString;)V");
	// jmethodID jmidOnMessageCallbackCallbackInit = Env->GetMethodID(jclsOnMessageCallback, "<init>", "(Lcom/epicgames/ue4/GameActivity;)V");
	// jobject joOnMessageCallbackProxy = Env->NewObject(jclsOnMessageCallback, jmidOnMessageCallbackCallbackInit, FJavaWrapper::GameActivityThis);
	// Env->CallStaticVoidMethod(jclsAnalytics, jmidSetOnMessageCallback, joOnMessageCallbackProxy);
	// Env->DeleteLocalRef(joOnMessageCallbackProxy);
}

AndroidAnalytics::~AndroidAnalytics()
{
}

void AndroidAnalytics::SetTestProxyUrl(const FString &url)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setTestProxyUrl", url);
}

void AndroidAnalytics::SetTestCustomUrl(const FString &url)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setTestCustomUrl", url);
}

void AndroidAnalytics::TestLogs()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "testLogs");
}

void AndroidAnalytics::TestString(const FString &value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "testString", value);
}

void AndroidAnalytics::SetLoggerMessageListener(const FDTDLogsListenerDelegate *listener)
{
	Devtodev_SetLogsListener(listener);
}

void AndroidAnalytics::CoppaControlEnable()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "coppaControlEnable");
}

void AndroidAnalytics::SetInitializationCompleteCallback(const FDTDAnalyticsInitializationCompleteDelegate *listener)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

	jclass jclsGetterVoidCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterVoidCallback")));
	jmethodID jmidPersistGetterLongCallbackInit = Env->GetMethodID(jclsGetterVoidCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)listener, sizeof(FDTDAnalyticsInitializationCompleteDelegate));
	jobject joPersistGetterVoidCallbackProxy = Env->NewObject(jclsGetterVoidCallback, jmidPersistGetterLongCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "setInitializationCompleteCallback", "(Lcom/devtodev/analytics/unrealwrapper/IGetterVoid;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joPersistGetterVoidCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joPersistGetterVoidCallbackProxy);
}

void AndroidAnalytics::SetIdentifiersListener(const FDTDLongListenerDelegate *listener)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

	jclass jclsGetterLongCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevPersistGetterLongCallback")));
	jmethodID jmidPersistGetterLongCallbackInit = Env->GetMethodID(jclsGetterLongCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));
	
	jobject joPointer = Env->NewDirectByteBuffer((void *)listener, sizeof(FDTDLongListenerDelegate));
	jobject joPersistGetterLongCallbackProxy = Env->NewObject(jclsGetterLongCallback, jmidPersistGetterLongCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "setIdentifiersListener", "(Lcom/devtodev/analytics/unrealwrapper/IGetterLong;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joPersistGetterLongCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joPersistGetterLongCallbackProxy);
}

void AndroidAnalytics::GetDeviceId(const FDTDGetterStringDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterStringCallback")));
	jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jmethodID jmidGetDeviceId = Env->GetStaticMethodID(jclsAnalytics, "getDeviceId", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetDeviceId, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetSdkVersion(const FDTDGetterStringDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterStringCallback")));
	jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jmethodID jmidGetSdkVersion = Env->GetStaticMethodID(jclsAnalytics, "getSdkVersion", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetSdkVersion, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetApplicationVersion(const FDTDGetterStringDelegate *onResult)
{
	delete onResult;

	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("GetApplicationVersion");
}

void AndroidAnalytics::SetApplicationVersion(const FString &value)
{
	// Not supported.
	DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning("SetApplicationVersion");
}

void AndroidAnalytics::GetTrackingAvailability(const FDTDGetterBoolDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

	jclass jclsGetterBoolCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterBoolCallback")));
	jmethodID jmidGetterBoolCallbackInit = Env->GetMethodID(jclsGetterBoolCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterBoolDelegate));
	jobject joGetterBoolCallbackProxy = Env->NewObject(jclsGetterBoolCallback, jmidGetterBoolCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jmethodID jmidGetTrackingAvailability = Env->GetStaticMethodID(jclsAnalytics, "getTrackingAvailability", "(Lcom/devtodev/analytics/unrealwrapper/IGetterBool;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetTrackingAvailability, joGetterBoolCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterBoolCallbackProxy);
}

void AndroidAnalytics::GetUserId(const FDTDGetterStringDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

	jclass jclsGetterStringCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterStringCallback")));
	jmethodID jmidGetterStringCallbackInit = Env->GetMethodID(jclsGetterStringCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterStringDelegate));
	jobject joGetterStringCallbackProxy = Env->NewObject(jclsGetterStringCallback, jmidGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jmethodID jmidGetUserId = Env->GetStaticMethodID(jclsAnalytics, "getUserId", "(Lcom/devtodev/analytics/unrealwrapper/IGetterString;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetUserId, joGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterStringCallbackProxy);
}

void AndroidAnalytics::GetCurrentLevel(const FDTDGetterIntDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

	jclass jclsGetterIntCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterIntCallback")));
	jmethodID jmidGetterIntCallbackInit = Env->GetMethodID(jclsGetterIntCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterIntDelegate));
	jobject joGetterIntCallbackProxy = Env->NewObject(jclsGetterIntCallback, jmidGetterIntCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jmethodID jmidGetCurrentLevel = Env->GetStaticMethodID(jclsAnalytics, "getCurrentLevel", "(Lcom/devtodev/analytics/unrealwrapper/IGetterInt;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidGetCurrentLevel, joGetterIntCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joGetterIntCallbackProxy);
}

void AndroidAnalytics::Initialize(const FString &appKey)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidInitialize = Env->GetStaticMethodID(jclsAnalytics, "initialize", "(Ljava/lang/String;Landroid/content/Context;)V");
	jstring jsAppKey = Env->NewStringUTF(TCHAR_TO_UTF8(*appKey));
	jobject joActivity = FAndroidApplication::GetGameActivityThis();
	Env->CallStaticVoidMethod(jclsAnalytics, jmidInitialize, jsAppKey, joActivity);
	Env->DeleteLocalRef(jsAppKey);
}

void AndroidAnalytics::InitializeWithConfig(const FString &appKey, const FDTDAnalyticsConfiguration &config)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
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

void AndroidAnalytics::SetUserId(const FString &userId)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "setUserId", userId);
}

void AndroidAnalytics::ReplaceUserId(const FString &fromUserId, const FString &toUserId)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "replaceUserId", fromUserId, toUserId);
}

void AndroidAnalytics::CustomEvent(const FString &eventName)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "customEvent", eventName);
}

void AndroidAnalytics::CustomEventWithParams(const FString &eventName, const FDTDCustomEventParams &params)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();

	// Create params.
	jclass jclsCustomEventParameters = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/analytics/DTDCustomEventParameters");
	jmethodID jmidCustomEventParametersInit = Env->GetMethodID(jclsCustomEventParameters, "<init>", "()V");
	jobject joCustomEventParameters = Env->NewObject(jclsCustomEventParameters, jmidCustomEventParametersInit);

	// String params.
	for (const TPair<FString, FString> &pair : params.StringParameters)
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
	for (const TPair<FString, bool> &pair : params.BoolParameters)
	{
		jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
		// TODO: Oprimize.
		jmethodID jmidAdd = Env->GetMethodID(jclsCustomEventParameters, "add", "(Ljava/lang/String;Z)V");
		Env->CallVoidMethod(joCustomEventParameters, jmidAdd, jsKey, pair.Value);
		Env->DeleteLocalRef(jsKey);
	}

	// Long marameters.
	for (const TPair<FString, int64> &pair : params.IntParameters)
	{
		jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
		// TODO: Oprimize.
		jmethodID jmidAdd = Env->GetMethodID(jclsCustomEventParameters, "add", "(Ljava/lang/String;J)V");
		Env->CallVoidMethod(joCustomEventParameters, jmidAdd, jsKey, pair.Value);
		Env->DeleteLocalRef(jsKey);
	}

	// Double marameters.
	for (const TPair<FString, float> &pair : params.FloatParameters)
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

void AndroidAnalytics::CurrencyAccrual(const FString &currencyName, int32 currencyAmount, const FString &source, EDTDAccrualType accrualType)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
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

void AndroidAnalytics::VirtualCurrencyPayment(const FString &purchaseId, const FString &purchaseType, int32 purchaseAmount, int32 purchasePrice, const FString &purchaseCurrency)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
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

void AndroidAnalytics::VirtualCurrencyPaymentWithResources(const FString &purchaseId, const FString &purchaseType, int32 purchaseAmount, const TMap<FString, int32> &resources)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
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

void AndroidAnalytics::LevelUpWithBalance(int32 level, const TMap<FString, int64> &balance)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidLevelUp = Env->GetStaticMethodID(jclsAnalytics, "levelUp", "(ILjava/util/Map;)V");
	jobject joBalance = ConverterJNI::ConvertToJMap(balance);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidLevelUp, level, joBalance);
	Env->DeleteLocalRef(joBalance);
}

void AndroidAnalytics::CurrentBalance(const TMap<FString, int64> &balance)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidCurrentBalance = Env->GetStaticMethodID(jclsAnalytics, "currentBalance", "(Ljava/util/Map;)V");
	jobject joBalance = ConverterJNI::ConvertToJMap(balance);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidCurrentBalance, joBalance);
	Env->DeleteLocalRef(joBalance);
}

void AndroidAnalytics::Referrer(const TMap<EDTDReferralProperty, FString> &utmData)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
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

void AndroidAnalytics::StartProgressionEvent(const FString &eventName)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "startProgressionEvent", eventName);
}

void AndroidAnalytics::StartProgressionEventWithParams(const FString &eventName, const FDTDStartProgressionEventParams &params)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidStartProgressionEvent = Env->GetStaticMethodID(jclsAnalytics, "startProgressionEvent", "(Ljava/lang/String;Lcom/devtodev/analytics/external/analytics/DTDStartProgressionEventParameters;)V");
	jstring jsEventName = Env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
	jobject joParams = ConverterJNI::ConvertToJObject(params);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidStartProgressionEvent, jsEventName, joParams);
	Env->DeleteLocalRef(jsEventName);
	Env->DeleteLocalRef(joParams);
}

void AndroidAnalytics::FinishProgressionEvent(const FString &eventName)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "finishProgressionEvent", eventName);
}

void AndroidAnalytics::FinishProgressionEventWithParams(const FString &eventName, const FDTDFinishProgressionEventParams &params)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidFinishProgressionEvent = Env->GetStaticMethodID(jclsAnalytics, "finishProgressionEvent", "(Ljava/lang/String;Lcom/devtodev/analytics/external/analytics/DTDFinishProgressionEventParameters;)V");
	jstring jsEventName = Env->NewStringUTF(TCHAR_TO_UTF8(*eventName));
	jobject joParams = ConverterJNI::ConvertToJObject(params);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidFinishProgressionEvent, jsEventName, joParams);
	Env->DeleteLocalRef(jsEventName);
	Env->DeleteLocalRef(joParams);
}

void AndroidAnalytics::RealCurrencyPayment(const FString &orderId, float price, const FString &productId, const FString &currencyCode)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal", "realCurrencyPayment", orderId, (double)price, productId, currencyCode);
}

void AndroidAnalytics::SocialNetworkConnect(EDTDSocialNetwork socialNetwork)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "socialNetworkConnect", "(Lcom/devtodev/analytics/external/analytics/DTDSocialNetwork;)V");
	jobject joSocialNetwork = ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joSocialNetwork);
	Env->DeleteLocalRef(joSocialNetwork);
}

void AndroidAnalytics::SocialNetworkConnectCustom(const FString &socialNetwork)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "socialNetworkConnect", "(Lcom/devtodev/analytics/external/analytics/DTDSocialNetwork;)V");
	jobject joSocialNetwork = ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joSocialNetwork);
	Env->DeleteLocalRef(joSocialNetwork);
}

void AndroidAnalytics::SocialNetworkPost(EDTDSocialNetwork socialNetwork, const FString &reason)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "socialNetworkPost", "(Lcom/devtodev/analytics/external/analytics/DTDSocialNetwork;Ljava/lang/String;)V");
	jobject joSocialNetwork = ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
	jstring jsReason = Env->NewStringUTF(TCHAR_TO_UTF8(*reason));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joSocialNetwork, jsReason);
	Env->DeleteLocalRef(joSocialNetwork);
	Env->DeleteLocalRef(jsReason);
}

void AndroidAnalytics::SocialNetworkPostCustom(const FString &socialNetwork, const FString &reason)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, "socialNetworkPost", "(Lcom/devtodev/analytics/external/analytics/DTDSocialNetwork;Ljava/lang/String;)V");
	jobject joSocialNetwork = ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
	jstring jsReason = Env->NewStringUTF(TCHAR_TO_UTF8(*reason));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joSocialNetwork, jsReason);
	Env->DeleteLocalRef(joSocialNetwork);
	Env->DeleteLocalRef(jsReason);
}

void AndroidAnalytics::AdImpression(const FString &socialNetwork, float revenue, const FString &placement, const FString &unit)
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
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");
	jmethodID jmidSetLogLevel = Env->GetStaticMethodID(jclsAnalytics, "setLogLevel", "(Lcom/devtodev/analytics/external/DTDLogLevel;)V");
	jobject joLogLevel = ConverterJNI::ConvertToJavaLogLevel(logLevel);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidSetLogLevel, joLogLevel);
	Env->DeleteLocalRef(joLogLevel);
}

void AndroidAnalytics::TryGetString(const FString &key, const FDTDGetterOptionalStringDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");

	jclass jclsOptionalGetterStringCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterOptionalStringCallback")));
	jmethodID jmidOptionalGetterStringCallbackInit = Env->GetMethodID(jclsOptionalGetterStringCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterOptionalStringDelegate));
	jobject joOptionslGetterStringCallbackProxy = Env->NewObject(jclsOptionalGetterStringCallback, jmidOptionalGetterStringCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
	jmethodID jmidValue = Env->GetStaticMethodID(jclsAnalytics, "getValue", "(Ljava/lang/String;Lcom/devtodev/analytics/unrealwrapper/IGetterObject;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidValue, jsKey, joOptionslGetterStringCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joOptionslGetterStringCallbackProxy);
	Env->DeleteLocalRef(jsKey);
}

void AndroidAnalytics::TryGetBool(const FString &key, const FDTDGetterOptionalBoolDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");

	jclass jclsOptionalGetterBoolCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterOptionalBoolCallback")));
	jmethodID jmidOptionalGetterBoolCallbackInit = Env->GetMethodID(jclsOptionalGetterBoolCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterOptionalBoolDelegate));
	jobject joOptionalGetterBoolCallbackProxy = Env->NewObject(jclsOptionalGetterBoolCallback, jmidOptionalGetterBoolCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
	jmethodID jmidValue = Env->GetStaticMethodID(jclsAnalytics, "getValue", "(Ljava/lang/String;Lcom/devtodev/analytics/unrealwrapper/IGetterObject;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidValue, jsKey, joOptionalGetterBoolCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joOptionalGetterBoolCallbackProxy);
	Env->DeleteLocalRef(jsKey);
}

void AndroidAnalytics::TryGetFloat(const FString &key, const FDTDGetterOptionalFloatDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jclass jclsOptionalGetterFloatCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterOptionalFloatCallback")));
	jmethodID jmidOptionalGetterFloatCallbackInit = Env->GetMethodID(jclsOptionalGetterFloatCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));
	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterOptionalFloatDelegate));
	jobject joOptionalGetterFloatCallbackProxy = Env->NewObject(jclsOptionalGetterFloatCallback, jmidOptionalGetterFloatCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
	jmethodID jmidValue = Env->GetStaticMethodID(jclsAnalytics, "getValue", "(Ljava/lang/String;Lcom/devtodev/analytics/unrealwrapper/IGetterObject;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidValue, jsKey, joOptionalGetterFloatCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joOptionalGetterFloatCallbackProxy);
	Env->DeleteLocalRef(jsKey);
}

void AndroidAnalytics::TryGetLong(const FString &key, const FDTDGetterOptionalLongDelegate *onResult)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");

	jclass jclsOptionalGetterLongCallback = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevGetterOptionalLongCallback")));
	jmethodID jmidOptionalGetterLongCallbackInit = Env->GetMethodID(jclsOptionalGetterLongCallback, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;Ljava/lang/Object;)V")));

	jobject joPointer = Env->NewDirectByteBuffer((void *)onResult, sizeof(FDTDGetterLongDelegate));
	jobject joOptionalGetterLongCallbackProxy = Env->NewObject(jclsOptionalGetterLongCallback, jmidOptionalGetterLongCallbackInit, FJavaWrapper::GameActivityThis, joPointer);
	jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*key));
	jmethodID jmidValue = Env->GetStaticMethodID(jclsAnalytics, "getValue", "(Ljava/lang/String;Lcom/devtodev/analytics/unrealwrapper/IGetterObject;)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidValue, jsKey, joOptionalGetterLongCallbackProxy);
	Env->DeleteLocalRef(joPointer);
	Env->DeleteLocalRef(joOptionalGetterLongCallbackProxy);
	Env->DeleteLocalRef(jsKey);
}

void AndroidAnalytics::SetCheater(bool cheater)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setCheater", cheater);
}

void AndroidAnalytics::SetTester(bool tester)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "setTester", tester);
}

void AndroidAnalytics::SetString(const FString &key, const FString &value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "set", key, value);
}

void AndroidAnalytics::SetBool(const FString &key, bool value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "set", key, value);
}

void AndroidAnalytics::SetInt(const FString &key, int64 value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "set", key, value);
}

void AndroidAnalytics::SetFloat(const FString &key, float value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "set", key, (double)value);
}

void AndroidAnalytics::Unset(const FString &key)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "unset", key);
}

void AndroidAnalytics::UnsetArray(const TArray<FString> &keys)
{
	JNIEnv *Env = FAndroidApplication::GetJavaEnv();
	jclass jclsUserCard = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal");
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsUserCard, "unset", "(Ljava/util/ArrayList;)V");
	jobject joKeys = ConverterJNI::ConvertToJArrayList(keys);
	Env->CallStaticVoidMethod(jclsUserCard, jmidMethod, joKeys);
	Env->DeleteLocalRef(joKeys);
}

void AndroidAnalytics::IncrementInt(const FString &key, int64 value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "increment", key, value);
}

void AndroidAnalytics::IncrementFloat(const FString &key, float value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "increment", key, (double)value);
}

void AndroidAnalytics::ClearUser()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDUserCardUnreal", "clearUser");
}

// AB Tests
void AndroidAnalytics::InitializeWithAbTest(const FString &appKey,
											const FDTDRemoteConfigChangeResultDelegate *onRemoteConfigChange,
											const FDTDRemoteConfigPrepareToChangeDelegate *onRemoteConfigPrepareToChange,
											const FDTDRemoteConfigReceiveResultDelegate *onRemoteConfigReceive)
{
	// Set native delegates to be called from java
    Devtodev_SetRemoteConfigOnReceivedListener(onRemoteConfigReceive);
    Devtodev_SetRemoteConfigOnPrepareToChangeListener(onRemoteConfigPrepareToChange);
    Devtodev_SetRemoteConfigOnChangedListener(onRemoteConfigChange);

	// Set java listener
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

    jclass jclsListener = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevRemoteConfigListener")));
    jmethodID jmidListenerInit = env->GetMethodID(jclsListener, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;)V")));

    jobject joListener = env->NewObject(jclsListener, jmidListenerInit, FJavaWrapper::GameActivityThis);
    jmethodID jmidSetListener = env->GetStaticMethodID(jclsAnalytics, "setAbTestListener", "(Lcom/devtodev/analytics/unrealwrapper/DTDRemoteConfigListenerUnreal;)V");
    env->CallStaticVoidMethod(jclsAnalytics, jmidSetListener, joListener);
    env->DeleteLocalRef(joListener);

	// init analytic with ab test
	jmethodID jmidInitialize = env->GetStaticMethodID(jclsAnalytics, "initializeWithAbTest", "(Ljava/lang/String;Landroid/content/Context;)V");
	jstring jsAppKey = env->NewStringUTF(TCHAR_TO_UTF8(*appKey));
	jobject joActivity = FAndroidApplication::GetGameActivityThis();
	env->CallStaticVoidMethod(jclsAnalytics, jmidInitialize, jsAppKey, joActivity);
	env->DeleteLocalRef(jsAppKey);
}

void AndroidAnalytics::InitializeWithConfigWithAbTest(const FString &appKey,
													  const FDTDAnalyticsConfiguration &config,
													  const FDTDRemoteConfigChangeResultDelegate *onRemoteConfigChange,
													  const FDTDRemoteConfigPrepareToChangeDelegate *onRemoteConfigPrepareToChange,
													  const FDTDRemoteConfigReceiveResultDelegate *onRemoteConfigReceive)
{
	// Set native delegates to be called from java
    Devtodev_SetRemoteConfigOnReceivedListener(onRemoteConfigReceive);
    Devtodev_SetRemoteConfigOnPrepareToChangeListener(onRemoteConfigPrepareToChange);
    Devtodev_SetRemoteConfigOnChangedListener(onRemoteConfigChange);

	// Set java listener
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDAnalyticsUnreal");

    jclass jclsListener = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevRemoteConfigListener")));
    jmethodID jmidListenerInit = env->GetMethodID(jclsListener, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;)V")));

    jobject joListener = env->NewObject(jclsListener, jmidListenerInit, FJavaWrapper::GameActivityThis);
    jmethodID jmidSetListener = env->GetStaticMethodID(jclsAnalytics, "setAbTestListener", "(Lcom/devtodev/analytics/unrealwrapper/DTDRemoteConfigListenerUnreal;)V");
    env->CallStaticVoidMethod(jclsAnalytics, jmidSetListener, joListener);
    env->DeleteLocalRef(joListener);

	// init analytic with ab test
	jmethodID jmidInitialize = env->GetStaticMethodID(jclsAnalytics, "initializeWithAbTest", "(Ljava/lang/String;Lcom/devtodev/analytics/external/analytics/DTDAnalyticsConfiguration;Landroid/content/Context;)V");
	jstring jsAppKey = env->NewStringUTF(TCHAR_TO_UTF8(*appKey));
	jobject joActivity = FAndroidApplication::GetGameActivityThis();
	jobject joConfig = ConverterJNI::ConvertToJObject(config);
	env->CallStaticVoidMethod(jclsAnalytics, jmidInitialize, jsAppKey, joConfig, joActivity);
	env->DeleteLocalRef(jsAppKey);
	env->DeleteLocalRef(joConfig);
}

float AndroidAnalytics::GetRemoteConfigWaiting()
{
	JNIEnv *env = FAndroidApplication::GetJavaEnv();
	jclass jclsRemoteConfig = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal");
	IF_NULL_RETURN_SMTH(jclsRemoteConfig, 0.0f)
	jmethodID jmidMethod = env->GetStaticMethodID(jclsRemoteConfig, "getRemoteConfigWaiting", "()D");
	IF_NULL_RETURN_SMTH(jmidMethod, 0.0f)
	jdouble result = env->CallStaticDoubleMethod(jclsRemoteConfig, jmidMethod);
	return static_cast<float>(result);
}

void AndroidAnalytics::SetRemoteConfigWaiting(float value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal", "setRemoteConfigWaiting", static_cast<double>(value));
}

float AndroidAnalytics::GetGroupDefinitionWaiting()
{
	JNIEnv *env = FAndroidApplication::GetJavaEnv();
	jclass jclsRemoteConfig = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal");
	IF_NULL_RETURN_SMTH(jclsRemoteConfig, 0.0f)
	jmethodID jmidMethod = env->GetStaticMethodID(jclsRemoteConfig, "getGroupDefinitionWaiting", "()D");
	IF_NULL_RETURN_SMTH(jmidMethod, 0.0f)
	jdouble result = env->CallStaticDoubleMethod(jclsRemoteConfig, jmidMethod);
	return static_cast<float>(result);
}

void AndroidAnalytics::SetGroupDefinitionWaiting(float value)
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal", "setGroupDefinitionWaiting", static_cast<double>(value));
}

void AndroidAnalytics::SetDefaults(const FDTDRemoteConfigDefaults &defaults)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	for (const TPair<FString, FString>& pair : defaults.StringDefaults)
	{
		JsonObject->SetStringField(pair.Key, pair.Value);
	}

	for (const TPair<FString, int32>& pair : defaults.IntegerDefaults)
	{
		JsonObject->SetNumberField(pair.Key, pair.Value);
	}

	for (const TPair<FString, int64>& pair : defaults.LongDefaults)
	{
		JsonObject->SetNumberField(pair.Key, pair.Value);
	}

	for (const TPair<FString, float>& pair : defaults.FloatDefaults)
	{
		JsonObject->SetNumberField(pair.Key, pair.Value);
	}

	for (const TPair<FString, bool>& pair : defaults.BoolDefaults)
	{
		JsonObject->SetBoolField(pair.Key, pair.Value);
	}

	FString jsonString;
    TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&jsonString);
    FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal", "setDefaults", jsonString);	
	UpdateLocalConfig();
}

void AndroidAnalytics::ApplyConfig()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal", "applyConfig");
	UpdateLocalConfig();
}

void AndroidAnalytics::ResetConfig()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal", "resetConfig");
	UpdateLocalConfig();
}

TMap<FString, FDTDRemoteConfigValue> AndroidAnalytics::GetConfig()
{
	return localConfig;
}

FDTDRemoteConfigValue AndroidAnalytics::GetRemoteConfigValue(const FString &key)
{
	if (localConfig.Contains(key))
	{
		return localConfig[key];
	}

	FDTDRemoteConfigValue value;
	value.Source = EDTDRemoteConfigSource::Empty;
	return value;
}

bool AndroidAnalytics::HasKey(const FString &key)
{
	return localConfig.Contains(key);
}

void AndroidAnalytics::CacheTestExperiment()
{
	HelperJNI::CallStaticMethod("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal", "cacheTestExperiment");
}

void AndroidAnalytics::UpdateLocalConfig()
{
	localConfig.Reset();
	JNIEnv *env = FAndroidApplication::GetJavaEnv();
	jclass jclsRemoteConfig = FAndroidApplication::FindJavaClass("com/devtodev/analytics/unrealwrapper/DTDRemoteConfigUnreal");
	IF_NULL_RETURN(jclsRemoteConfig)
	jmethodID jmidMethod = env->GetStaticMethodID(jclsRemoteConfig, "getConfig", "()Ljava/lang/String;");
	IF_NULL_RETURN(jmidMethod)

	jobject result = env->CallStaticObjectMethod(jclsRemoteConfig, jmidMethod);
	FString str = ConverterJNI::ConvertToFString((jstring)result);

	TSharedPtr<FJsonObject> JsonParsed;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(str);
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		for (auto currJsonValue = JsonParsed->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
		{
			FString key = (*currJsonValue).Key;
			TSharedPtr<FJsonValue> jsonValue = (*currJsonValue).Value;

			TSharedPtr<FJsonObject> jsonObject = jsonValue->AsObject();
			int source = jsonObject->GetIntegerField(TEXT("source"));

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
			if (jsonObject->TryGetStringField(TEXT("value"), strValue)){
				configValue.StringValue = strValue;
			}

			int32 int32Value;
			if (jsonObject->TryGetNumberField(TEXT("value"), int32Value)){
				configValue.IntegerValue = int32Value;
			}

			int64 longValue;
			if (jsonObject->TryGetNumberField(TEXT("value"), longValue)){
				configValue.LongValue = longValue;
			}

			double floatValue;
			if (jsonObject->TryGetNumberField(TEXT("value"), floatValue)){
				configValue.FloatValue = (float)floatValue;
			}

			bool boolValue;
			if (jsonObject->TryGetBoolField(TEXT("value"), boolValue)){
				configValue.BoolValue = boolValue; 
			}

			localConfig.Add(key, configValue);
		}
	}
}
