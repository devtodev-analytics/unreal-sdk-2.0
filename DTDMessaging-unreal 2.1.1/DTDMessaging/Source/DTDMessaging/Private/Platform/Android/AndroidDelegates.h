// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"

#include "DTDMessagingDelegates.h"

extern "C"
{
    void Devtodev_SetTokenListener(const FDTDMessagingStringParamsDelegate* listener);
    void Devtodev_SetTokenErrorListener(const FDTDMessagingStringParamsDelegate* listener);
    void Devtodev_SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener);
    void Devtodev_SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener);
    void Devtodev_SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate* listener);
    
    // ue4
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushGetterStringCallback_CallbackHandler(JNIEnv*, jobject, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushGetterBoolCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushListenerUnreal_RegistrationSuccessful(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushListenerUnreal_RegistrationFailed(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushListenerUnreal_NotificationReceived(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPushListenerUnreal_NotificationOpened(JNIEnv*, jobject, jobject, jobject);

    // ue5
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushGetterStringCallback_CallbackHandler(JNIEnv*, jobject, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushGetterBoolCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushListenerUnreal_RegistrationSuccessful(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushListenerUnreal_RegistrationFailed(JNIEnv*, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushListenerUnreal_NotificationReceived(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPushListenerUnreal_NotificationOpened(JNIEnv*, jobject, jobject, jobject);

    void DevToDevPushGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result);
    void DevToDevPushGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result);
    void DevToDevPushListenerUnreal_RegistrationSuccessful(JNIEnv* env, jobject obj, jstring result);
    void DevToDevPushListenerUnreal_RegistrationFailed(JNIEnv* env, jobject obj, jstring result);
    void DevToDevPushListenerUnreal_NotificationReceived(JNIEnv* env, jobject obj, jobject pushData);
    void DevToDevPushListenerUnreal_NotificationOpened(JNIEnv* env, jobject obj, jobject pushData, jobject actionButton);
}