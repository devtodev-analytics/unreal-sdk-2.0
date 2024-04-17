// Copyright (c) devtodev. All rights reserved.

#include "AndroidDelegates.h"

#include "CoreMinimal.h"

static const FDTDMessagingStringParamsDelegate* devtodevTokenListener = nullptr;
static const FDTDMessagingStringParamsDelegate* devtodevTokenErrorListener = nullptr;
static const FDTDMessagingNotificationParamsDelegate* devtodevNotificationReceiveListener = nullptr;
static const FDTDMessagingNotificationParamsDelegate* devtodevInvisibleNotificationReceiveListener = nullptr;
static const FDTDMessagingNotificationActionParamsDelegate* devtodevNotificationActionListener = nullptr;

static TMap<FString, FString> ToUnrealMap(JNIEnv* env, jobject hashMap)
{
	TMap<FString, FString> u_Map;
	jclass jcls_pushData = env->GetObjectClass(hashMap);
	jmethodID jmid_entrySet = env->GetMethodID(jcls_pushData, "entrySet", "()Ljava/util/Set;");

	jclass jcls_entrySet = env->FindClass("java/util/Set");
	jmethodID jmid_iterator = env->GetMethodID(jcls_entrySet, "iterator", "()Ljava/util/Iterator;");

	jclass jcls_iterator = env->FindClass("java/util/Iterator");
	jmethodID jmid_hasNext = env->GetMethodID(jcls_iterator, "hasNext", "()Z");
	jmethodID jmid_next = env->GetMethodID(jcls_iterator, "next", "()Ljava/lang/Object;");

	jclass jcls_entry = env->FindClass("java/util/Map$Entry");
	jmethodID jmid_getKey = env->GetMethodID(jcls_entry, "getKey", "()Ljava/lang/Object;");
	jmethodID jmid_getValue = env->GetMethodID(jcls_entry, "getValue", "()Ljava/lang/Object;");

	jclass jcls_string = env->FindClass("java/lang/String");
	jmethodID jmid_toString = env->GetMethodID(jcls_string, "toString", "()Ljava/lang/String;");

	jobject jo_entrySet = env->CallObjectMethod(hashMap, jmid_entrySet);
	jobject jo_iterator = env->CallObjectMethod(jo_entrySet, jmid_iterator);

	bool hasNext = (bool) env->CallBooleanMethod(jo_iterator, jmid_hasNext);

	while(hasNext) 
	{
		jobject entry = env->CallObjectMethod(jo_iterator, jmid_next);
		jobject key = env->CallObjectMethod(entry, jmid_getKey);
		jobject value = env->CallObjectMethod(entry, jmid_getValue);
		jstring jstrKey = (jstring) env->CallObjectMethod(key, jmid_toString);
		jstring jstrValue = (jstring) env->CallObjectMethod(value, jmid_toString);
		const char *c_strKey = env->GetStringUTFChars(jstrKey, nullptr);
		const char *c_strValue = env->GetStringUTFChars(jstrValue, nullptr);

		u_Map.Add(FString(UTF8_TO_TCHAR(c_strKey)), FString(UTF8_TO_TCHAR(c_strValue)));

		env->ReleaseStringUTFChars(jstrKey, c_strKey);
		env->ReleaseStringUTFChars(jstrValue, c_strValue);
		hasNext = (bool) env->CallBooleanMethod(jo_iterator, jmid_hasNext);
	}

	return u_Map;
}

static FDTDNotification ToNotification(const TMap<FString, FString>& pushData)
{
	FDTDNotification u_Notification;

	// ActionType, ActionString
	const FString URL_KEY = "_u";
	const FString SHARE_KEY = "_s";
	const FString DEEPLINK_KEY = "_d";
	if (pushData.Contains(URL_KEY))
	{
		u_Notification.ActionType = EDTDNotificationActionType::Url;
		u_Notification.ActionString = pushData[URL_KEY];
	}
	else if (pushData.Contains(SHARE_KEY))
	{
		u_Notification.ActionType = EDTDNotificationActionType::Share;
		u_Notification.ActionString = pushData[SHARE_KEY];
	}
	else if (pushData.Contains(DEEPLINK_KEY))
	{
		u_Notification.ActionType = EDTDNotificationActionType::DeepLink;
		u_Notification.ActionString = pushData[DEEPLINK_KEY];
	}
	else
	{
		u_Notification.ActionType = EDTDNotificationActionType::App;
		u_Notification.ActionString = "";
	}

	u_Notification.Data = pushData;
	return u_Notification;
}

static FDTDNotificationAction ToNotificationAction(const TMap<FString, FString>& actionButton)
{
	FDTDNotificationAction u_NotificationAction;

	// ActionType, ActionString
	const FString URL_KEY = "_u";
	const FString SHARE_KEY = "_s";
	const FString DEEPLINK_KEY = "_d";
	if (actionButton.Contains(URL_KEY))
	{
		u_NotificationAction.ActionType = EDTDNotificationActionType::Url;
		u_NotificationAction.ActionString = actionButton[URL_KEY];
	}
	else if (actionButton.Contains(SHARE_KEY))
	{
		u_NotificationAction.ActionType = EDTDNotificationActionType::Share;
		u_NotificationAction.ActionString = actionButton[SHARE_KEY];
	}
	else if (actionButton.Contains(DEEPLINK_KEY))
	{
		u_NotificationAction.ActionType = EDTDNotificationActionType::DeepLink;
		u_NotificationAction.ActionString = actionButton[DEEPLINK_KEY];
	}
	else
	{
		u_NotificationAction.ActionType = EDTDNotificationActionType::App;
		u_NotificationAction.ActionString = "";
	}

	// IsBackground
	const FString ACTIVATION_MODE_KEY = "activationMode";
	const FString ACTIVATION_MODE_BACKGROUND = "background";
	if (actionButton.Contains(ACTIVATION_MODE_KEY))
	{
		u_NotificationAction.IsBackground = actionButton[ACTIVATION_MODE_KEY] == ACTIVATION_MODE_BACKGROUND;
	}

	// ButtonId
	const FString BUTTON_ID_KEY = "id";
	if (actionButton.Contains(BUTTON_ID_KEY))
	{
		u_NotificationAction.ButtonId = actionButton[BUTTON_ID_KEY];
	}

	// ButtonText
	const FString TEXT_KEY = "text";
	if (actionButton.Contains(TEXT_KEY))
	{
		u_NotificationAction.ButtonText = actionButton[TEXT_KEY];
	}

	// ButtonIcon
	const FString ICON_KEY = "icon";
	if (actionButton.Contains(ICON_KEY))
	{
		u_NotificationAction.ButtonIcon = actionButton[ICON_KEY];
	}

	return u_NotificationAction;
}

void Devtodev_SetTokenListener(const FDTDMessagingStringParamsDelegate* listener)
{
	if (devtodevTokenListener != nullptr)
	{
        delete devtodevTokenListener;
	}

    devtodevTokenListener = listener;
}

void Devtodev_SetTokenErrorListener(const FDTDMessagingStringParamsDelegate* listener)
{
	if (devtodevTokenErrorListener != nullptr)
	{
        delete devtodevTokenErrorListener;
	}

    devtodevTokenErrorListener = listener;
}

void Devtodev_SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener)
{
	if (devtodevNotificationReceiveListener != nullptr)
	{
        delete devtodevNotificationReceiveListener;
	}

    devtodevNotificationReceiveListener = listener;
}

void Devtodev_SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener)
{
	if (devtodevInvisibleNotificationReceiveListener != nullptr)
	{
        delete devtodevInvisibleNotificationReceiveListener;
	}

    devtodevInvisibleNotificationReceiveListener = listener;
}

void Devtodev_SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate* listener)
{
	if (devtodevNotificationActionListener != nullptr)
	{
        delete devtodevNotificationActionListener;
	}

    devtodevNotificationActionListener = listener;
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
	DevToDevPushGetterStringCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result)
{
	DevToDevPushGetterBoolCallback_CallbackHandler(env,  obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushListenerUnreal_RegistrationSuccessful(JNIEnv* env, jobject obj, jstring result)
{
	DevToDevPushListenerUnreal_RegistrationSuccessful(env, obj, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushListenerUnreal_RegistrationFailed(JNIEnv* env, jobject obj, jstring result)
{
	DevToDevPushListenerUnreal_RegistrationFailed(env, obj, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushListenerUnreal_NotificationReceived(JNIEnv* env, jobject obj, jobject pushData)
{
	DevToDevPushListenerUnreal_NotificationReceived(env, obj, pushData);
}

JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushListenerUnreal_NotificationOpened(JNIEnv* env, jobject obj, jobject pushData, jobject actionButton)
{
	DevToDevPushListenerUnreal_NotificationOpened(env, obj, pushData, actionButton);
}

// ue 5
JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
	DevToDevPushGetterStringCallback_CallbackHandler(env, obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result)
{
	DevToDevPushGetterBoolCallback_CallbackHandler(env,  obj, pointer, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushListenerUnreal_RegistrationSuccessful(JNIEnv* env, jobject obj, jstring result)
{
	DevToDevPushListenerUnreal_RegistrationSuccessful(env, obj, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushListenerUnreal_RegistrationFailed(JNIEnv* env, jobject obj, jstring result)
{
	DevToDevPushListenerUnreal_RegistrationFailed(env, obj, result);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushListenerUnreal_NotificationReceived(JNIEnv* env, jobject obj, jobject pushData)
{
	DevToDevPushListenerUnreal_NotificationReceived(env, obj, pushData);
}

JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushListenerUnreal_NotificationOpened(JNIEnv* env, jobject obj, jobject pushData, jobject actionButton)
{
	DevToDevPushListenerUnreal_NotificationOpened(env, obj, pushData, actionButton);
}

void DevToDevPushGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result)
{
	const char* utfString = env->GetStringUTFChars(result, nullptr);
	const FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
    FDTDMessagingStringParamsDelegate* onResult = (FDTDMessagingStringParamsDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(fResult);
    delete onResult;
}

void DevToDevPushGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result)
{
    FDTDMessagingBoolParamsDelegate* onResult = (FDTDMessagingBoolParamsDelegate*)env->GetDirectBufferAddress(pointer);
	onResult->ExecuteIfBound(result);
    delete onResult;
}

void DevToDevPushListenerUnreal_RegistrationSuccessful(JNIEnv* env, jobject obj, jstring result)
{
	const char* utfString = env->GetStringUTFChars(result, nullptr);
	const FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
	if (devtodevTokenListener != nullptr)
	{
        devtodevTokenListener->ExecuteIfBound(fResult);
	}
}

void DevToDevPushListenerUnreal_RegistrationFailed(JNIEnv* env, jobject obj, jstring result)
{
	const char* utfString = env->GetStringUTFChars(result, nullptr);
	const FString fResult(UTF8_TO_TCHAR(utfString));
	env->ReleaseStringUTFChars(result, utfString);
	if (devtodevTokenErrorListener != nullptr)
	{
        devtodevTokenErrorListener->ExecuteIfBound(fResult);
	}
}

void DevToDevPushListenerUnreal_NotificationReceived(JNIEnv* env, jobject obj, jobject pushData)
{
	TMap<FString, FString> u_PushData = ToUnrealMap(env, pushData);
	FDTDNotification u_Notification = ToNotification(u_PushData);

	const FString HIDEN_KEY = "_h";
	const FString TRUE_VALUE = "true";
	if (u_PushData.Contains(HIDEN_KEY) && u_PushData[HIDEN_KEY] == TRUE_VALUE)
	{
		if (devtodevInvisibleNotificationReceiveListener != nullptr)
		{
    	    devtodevInvisibleNotificationReceiveListener->ExecuteIfBound(u_Notification);
		}
	}
	else
	{
		if (devtodevNotificationReceiveListener != nullptr)
		{
    	    devtodevNotificationReceiveListener->ExecuteIfBound(u_Notification);
		}
	}
}

void DevToDevPushListenerUnreal_NotificationOpened(JNIEnv* env, jobject obj, jobject pushData, jobject actionButton)
{
	TMap<FString, FString> u_PushData = ToUnrealMap(env, pushData);
	FDTDNotification u_Notification = ToNotification(u_PushData);

	TMap<FString, FString> u_ActionButton = ToUnrealMap(env, actionButton);
	FDTDNotificationAction u_NotificationAction = ToNotificationAction(u_ActionButton);

	if (devtodevNotificationActionListener != nullptr)
	{
        devtodevNotificationActionListener->ExecuteIfBound(u_Notification, u_NotificationAction);
	}
}