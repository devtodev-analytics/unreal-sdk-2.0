// Copyright (c) devtodev. All rights reserved.

#include "DelegatesJNI.h"

#include "CoreMinimal.h"

#include "DTDDelegates.h"
#include "DTDLogLevel.h"

#include "Constants/SDKConstants.h"
#include "Logging/DTDLogCategory.h"

#include "DTDRemoteConfigChangeResult.h"
#include "DTDRemoteConfigReceiveResult.h"

#include "ConverterJNI.h"


static const FDTDLogsListenerDelegate* devtodevLogsListener = nullptr;
void Devtodev_SetLogsListener(const FDTDLogsListenerDelegate* listener)
{
	if (devtodevLogsListener)
	{
        delete devtodevLogsListener;
	}

    devtodevLogsListener = listener;
}

static const FDTDRemoteConfigReceiveResultDelegate* devtodevRemoteConfigOnReceivedListener = nullptr;
void Devtodev_SetRemoteConfigOnReceivedListener(const FDTDRemoteConfigReceiveResultDelegate* listener)
{
	if (devtodevRemoteConfigOnReceivedListener)
	{
        delete devtodevRemoteConfigOnReceivedListener;
	}

    devtodevRemoteConfigOnReceivedListener = listener;
}

static const FDTDRemoteConfigPrepareToChangeDelegate* devtodevRemoteConfigOnPrepareToChangeListener = nullptr;
void Devtodev_SetRemoteConfigOnPrepareToChangeListener(const FDTDRemoteConfigPrepareToChangeDelegate* listener)
{
	if (devtodevRemoteConfigOnPrepareToChangeListener)
	{
        delete devtodevRemoteConfigOnPrepareToChangeListener;
	}

    devtodevRemoteConfigOnPrepareToChangeListener = listener;
}

static const FDTDRemoteConfigChangeResultDelegate* devtodevRemoteConfigOnChangedListener = nullptr;
void Devtodev_SetRemoteConfigOnChangedListener(const FDTDRemoteConfigChangeResultDelegate* listener)
{
	if (devtodevRemoteConfigOnChangedListener)
	{
        delete devtodevRemoteConfigOnChangedListener;
	}

    devtodevRemoteConfigOnChangedListener = listener;
}

//ue 4
JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevRemoteConfigListener_OnReceived(JNIEnv *env, jobject jObj, jint jResult)
{
    DevToDevRemoteConfigListener_OnReceived(env, jObj, jResult);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevRemoteConfigListener_OnPrepareToChange(JNIEnv *env, jobject jObj)
{
    DevToDevRemoteConfigListener_OnPrepareToChange(env, jObj);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevRemoteConfigListener_OnChanged(JNIEnv *env, jobject jObj, jint jResult, jstring jError)
{
    DevToDevRemoteConfigListener_OnChanged(env, jObj, jResult, jError);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevOnMessageCallback_callback(JNIEnv *env, jobject obj, jint jLogLevel, jstring jMessage)
{
    DevToDevOnMessageCallback_callback(env, obj, jLogLevel, jMessage);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterVoidCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer)
{
    DevToDevGetterVoidCallback_CallbackHandler(env, obj, pointer);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
    DevToDevGetterStringCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result)
{
    DevToDevGetterBoolCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterIntCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jint result)
{
    DevToDevGetterIntCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result)
{
    DevToDevGetterLongCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPersistGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
	DevToDevPersistGetterStringCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPersistGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result)
{
    DevToDevPersistGetterLongCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jstring result)
{
	DevToDevGetterOptionalStringCallback_CallbackHandler(env, obj, pointer, success, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jboolean result)
{
    DevToDevGetterOptionalBoolCallback_CallbackHandler(env, obj, pointer, success, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalFloatCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jfloat result)
{
    DevToDevGetterOptionalFloatCallback_CallbackHandler(env, obj, pointer, success, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jlong result)
{
    DevToDevGetterOptionalLongCallback_CallbackHandler(env, obj, pointer, success, result);
}

//ue 5 
JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevRemoteConfigListener_OnReceived(JNIEnv *env, jobject jObj, jint jResult)
{
    DevToDevRemoteConfigListener_OnReceived(env, jObj, jResult);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevRemoteConfigListener_OnPrepareToChange(JNIEnv *env, jobject jObj)
{
    DevToDevRemoteConfigListener_OnPrepareToChange(env, jObj);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevRemoteConfigListener_OnChanged(JNIEnv *env, jobject jObj, jint jResult, jstring jError)
{
    DevToDevRemoteConfigListener_OnChanged(env, jObj, jResult, jError);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevOnMessageCallback_callback(JNIEnv *env, jobject obj, jint jLogLevel, jstring jMessage)
{
    DevToDevOnMessageCallback_callback(env, obj, jLogLevel, jMessage);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterVoidCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer)
{
    DevToDevGetterVoidCallback_CallbackHandler(env, obj, pointer);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
	DevToDevGetterStringCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result)
{
    DevToDevGetterBoolCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterIntCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jint result)
{
    DevToDevGetterIntCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result)
{
    DevToDevGetterLongCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPersistGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
	DevToDevPersistGetterStringCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPersistGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result)
{
    DevToDevPersistGetterLongCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterOptionalStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jstring result)
{
    DevToDevGetterOptionalStringCallback_CallbackHandler(env, obj, pointer, success, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterOptionalBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jboolean result)
{
    DevToDevGetterOptionalBoolCallback_CallbackHandler(env, obj, pointer, success, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterOptionalFloatCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jfloat result)
{
    DevToDevGetterOptionalFloatCallback_CallbackHandler(env, obj, pointer, success, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterOptionalLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jlong result)
{
    DevToDevGetterOptionalLongCallback_CallbackHandler(env, obj, pointer, success, result);
}

// ==== 
void DevToDevRemoteConfigListener_OnReceived(JNIEnv *env, jobject jObj, jint jResult){
    const int32 result = static_cast<int32>(jResult);
    EDTDRemoteConfigReceiveResult u_Result;
    switch (result)
    {
    case 0:
        u_Result = EDTDRemoteConfigReceiveResult::Failure;
        break;
    case 1:
        u_Result = EDTDRemoteConfigReceiveResult::Success;
        break;
    default:
        break;
    }

    if (devtodevRemoteConfigOnReceivedListener)
	{
        devtodevRemoteConfigOnReceivedListener->ExecuteIfBound(u_Result);
	}
}

void DevToDevRemoteConfigListener_OnPrepareToChange(JNIEnv *env, jobject jObj){
    if (devtodevRemoteConfigOnPrepareToChangeListener)
	{
        devtodevRemoteConfigOnPrepareToChangeListener->ExecuteIfBound();
	}
}

void DevToDevRemoteConfigListener_OnChanged(JNIEnv *env, jobject jObj, jint jResult, jstring jError){
    const int32 result = static_cast<int32>(jResult);
    FString u_Error;
    if (!(env->IsSameObject(jError, nullptr)))
    {
        u_Error = ConverterJNI::ConvertToFString(jError);
    }

    EDTDRemoteConfigChangeResult u_Result;
    switch (result)
    {
    case 0:
        u_Result = EDTDRemoteConfigChangeResult::Failure;
        break;
    case 1:
        u_Result = EDTDRemoteConfigChangeResult::Success;
        break;
    default:
        break;
    }

    if (devtodevRemoteConfigOnChangedListener)
	{
        devtodevRemoteConfigOnChangedListener->ExecuteIfBound(u_Result, u_Error);
	}
}

void DevToDevOnMessageCallback_callback(JNIEnv *env, jobject obj, jint jLogLevel, jstring jMessage){
    if (env->IsSameObject(jMessage, NULL))
    {
        return;
    }

    // Convert message from java data type.
    const char *messageCStr = env->GetStringUTFChars(jMessage, NULL);
    const FString u_message = FString(UTF8_TO_TCHAR(messageCStr));
    env->ReleaseStringUTFChars(jMessage, messageCStr);

    // Current date time string.
#if !UE_BUILD_SHIPPING
	const auto u_now = FDateTime::Now().ToString(TEXT("%Y/%m/%d %H:%M:%S:%s"));
#else 
	const auto u_now = FDateTime::Now().ToString(TEXT("%Y/%m/%d %H:%M:%S"));
#endif

    // Build formatted log message.
	TArray<FStringFormatArg> formattingArgs; 
	formattingArgs.Add(FStringFormatArg(u_now));
	formattingArgs.Add(FStringFormatArg(SDKConstants::Version));
	formattingArgs.Add(FStringFormatArg(u_message));
	const auto formattedMessage = FString::Format(TEXT("{0} [DevToDev {1}] {2}"), formattingArgs);

    // Log to unreal engine logger by log level.
    int logLevel = static_cast<int>(jLogLevel);
    EDTDLogLevel uLogLevel = EDTDLogLevel::Unknown;
    switch (logLevel)
    {
    case 0: // Unknown.
        uLogLevel = EDTDLogLevel::Unknown;
        break;
    case 1: // No.
        uLogLevel = EDTDLogLevel::No;
        break;
    case 2: // Error.
        uLogLevel = EDTDLogLevel::Error;
        UE_LOG(LogTemp, Error, TEXT("%s"), *formattedMessage);
        break;
    case 3: // Warning.
        uLogLevel = EDTDLogLevel::Warning;
        UE_LOG(LogTemp, Warning, TEXT("%s"), *formattedMessage);
        break;
    case 4: // Info.
        uLogLevel = EDTDLogLevel::Info;
        UE_LOG(LogTemp, Display, TEXT("%s"), *formattedMessage);
        break;
    case 5: // Debug.
        uLogLevel = EDTDLogLevel::Debug;
        UE_LOG(LogTemp, Display, TEXT("%s"), *formattedMessage);
        break;
    default:
        break;
    }

	if (devtodevLogsListener != nullptr)
	{
        devtodevLogsListener->ExecuteIfBound(uLogLevel, formattedMessage);
	}
}

void DevToDevGetterVoidCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer)
{
    FDTDAnalyticsInitializationCompleteDelegate* onResult = (FDTDAnalyticsInitializationCompleteDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound();
}

void DevToDevGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
    const char* utfString = env->GetStringUTFChars(result, nullptr);
	const FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
    FDTDGetterStringDelegate* onResult = (FDTDGetterStringDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(fResult);
    delete onResult;
}

void DevToDevGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result)
{
    FDTDGetterBoolDelegate* onResult = (FDTDGetterBoolDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
    delete onResult;
}

void DevToDevGetterIntCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jint result)
{
    FDTDGetterIntDelegate* onResult = (FDTDGetterIntDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
    delete onResult;
}

void DevToDevGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result)
{
    FDTDGetterLongDelegate* onResult = (FDTDGetterLongDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
    delete onResult;
}

void DevToDevPersistGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
    const char* utfString = env->GetStringUTFChars(result, nullptr);
	FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
    FDTDGetterStringDelegate* onResult = (FDTDGetterStringDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(fResult);
}

void DevToDevPersistGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result)
{
    FDTDGetterLongDelegate* onResult = (FDTDGetterLongDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
}

void DevToDevGetterOptionalStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jstring result)
{
	const char* utfString = env->GetStringUTFChars(result, nullptr);
	FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
    FDTDGetterOptionalStringDelegate* onResult = (FDTDGetterOptionalStringDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(success, fResult);
    delete onResult;
}

void DevToDevGetterOptionalBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jboolean result)
{
    FDTDGetterOptionalBoolDelegate* onResult = (FDTDGetterOptionalBoolDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(success, result);
    delete onResult;
}

void DevToDevGetterOptionalFloatCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jfloat result)
{
    FDTDGetterOptionalFloatDelegate* onResult = (FDTDGetterOptionalFloatDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(success, result);
    delete onResult;
}

void DevToDevGetterOptionalLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jlong result){
    FDTDGetterOptionalLongDelegate* onResult = (FDTDGetterOptionalLongDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(success, result);
    delete onResult;
}