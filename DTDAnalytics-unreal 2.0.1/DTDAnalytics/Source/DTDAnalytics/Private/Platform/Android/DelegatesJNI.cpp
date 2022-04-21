// Copyright (c) devtodev. All rights reserved.

#include "DelegatesJNI.h"

#include "CoreMinimal.h"

#include "DTDDelegates.h"
#include "DTDLogLevel.h"
#include "Constants/SDKConstants.h"
#include "Logging/DTDLogCategory.h"

static const FDTDLogsListenerDelegate* devtodevLogsListener = nullptr;

void Devtodev_SetLogsListener(const FDTDLogsListenerDelegate* listener)
{
	if (devtodevLogsListener != nullptr)
	{
        delete devtodevLogsListener;
	}

    devtodevLogsListener = listener;
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevOnMessageCallback_callback(JNIEnv *env, jobject obj, jint jLogLevel, jstring jMessage)
{
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

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
	const char* utfString = env->GetStringUTFChars(result, nullptr);
	const FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
    FDTDGetterStringDelegate* onResult = (FDTDGetterStringDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(fResult);
    delete onResult;
}


JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result)
{
    FDTDGetterBoolDelegate* onResult = (FDTDGetterBoolDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
    delete onResult;
}


JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterIntCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jint result)
{
    FDTDGetterIntDelegate* onResult = (FDTDGetterIntDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
    delete onResult;
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result)
{
    FDTDGetterLongDelegate* onResult = (FDTDGetterLongDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
    delete onResult;
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPersistGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
	const char* utfString = env->GetStringUTFChars(result, nullptr);
	FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
    FDTDGetterStringDelegate* onResult = (FDTDGetterStringDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(fResult);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPersistGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result)
{
    FDTDGetterLongDelegate* onResult = (FDTDGetterLongDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jstring result)
{
	const char* utfString = env->GetStringUTFChars(result, nullptr);
	FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
    FDTDGetterOptionalStringDelegate* onResult = (FDTDGetterOptionalStringDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(success, fResult);
    delete onResult;
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jboolean result)
{
    FDTDGetterOptionalBoolDelegate* onResult = (FDTDGetterOptionalBoolDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(success, result);
    delete onResult;
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalFloatCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jfloat result)
{
    FDTDGetterOptionalFloatDelegate* onResult = (FDTDGetterOptionalFloatDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(success, result);
    delete onResult;
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jlong result)
{
    FDTDGetterOptionalLongDelegate* onResult = (FDTDGetterOptionalLongDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(success, result);
    delete onResult;
}
