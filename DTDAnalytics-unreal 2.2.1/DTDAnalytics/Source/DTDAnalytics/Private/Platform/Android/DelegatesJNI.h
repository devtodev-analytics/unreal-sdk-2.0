// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"

extern "C"
{
    void Devtodev_SetLogsListener(const FDTDLogsListenerDelegate* listener);
    void Devtodev_SetRemoteConfigOnReceivedListener(const FDTDRemoteConfigReceiveResultDelegate* listener);
    void Devtodev_SetRemoteConfigOnPrepareToChangeListener(const FDTDRemoteConfigPrepareToChangeDelegate* listener);
    void Devtodev_SetRemoteConfigOnChangedListener(const FDTDRemoteConfigChangeResultDelegate* listener);
    
    //ue4 
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevRemoteConfigListener_OnReceived(JNIEnv*, jobject, jint);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevRemoteConfigListener_OnPrepareToChange(JNIEnv*, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevRemoteConfigListener_OnChanged(JNIEnv*, jobject, jint, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevOnMessageCallback_callback(JNIEnv*, jobject, jint jLogLevel, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterVoidCallback_CallbackHandler(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterStringCallback_CallbackHandler(JNIEnv*, jobject, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterBoolCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterIntCallback_CallbackHandler(JNIEnv*, jobject, jobject, jint);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterLongCallback_CallbackHandler(JNIEnv*, jobject, jobject, jlong);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPersistGetterStringCallback_CallbackHandler(JNIEnv*, jobject, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevPersistGetterLongCallback_CallbackHandler(JNIEnv*, jobject, jobject, jlong);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalStringCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalBoolCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean, jboolean);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalFloatCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean, jfloat);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevGetterOptionalLongCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean, jlong);

    //ue5 
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevRemoteConfigListener_OnReceived(JNIEnv*, jobject, jint);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevRemoteConfigListener_OnPrepareToChange(JNIEnv*, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevRemoteConfigListener_OnChanged(JNIEnv*, jobject, jint, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevOnMessageCallback_callback(JNIEnv*, jobject, jint jLogLevel, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterVoidCallback_CallbackHandler(JNIEnv*, jobject, jobject);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterStringCallback_CallbackHandler(JNIEnv*, jobject, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterBoolCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterIntCallback_CallbackHandler(JNIEnv*, jobject, jobject, jint);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterLongCallback_CallbackHandler(JNIEnv*, jobject, jobject, jlong);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPersistGetterStringCallback_CallbackHandler(JNIEnv*, jobject, jobject, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevPersistGetterLongCallback_CallbackHandler(JNIEnv*, jobject, jobject, jlong);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterOptionalStringCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean, jstring);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterOptionalBoolCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean, jboolean);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterOptionalFloatCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean, jfloat);
    JNIEXPORT void JNICALL Java_com_epicgames_unreal_GameActivity_00024DevToDevGetterOptionalLongCallback_CallbackHandler(JNIEnv*, jobject, jobject, jboolean, jlong);

    void DevToDevRemoteConfigListener_OnReceived(JNIEnv *env, jobject jObj, jint jResult);
    void DevToDevRemoteConfigListener_OnPrepareToChange(JNIEnv *env, jobject jObj);
    void DevToDevRemoteConfigListener_OnChanged(JNIEnv *env, jobject jObj, jint jResult, jstring jError);
    void DevToDevOnMessageCallback_callback(JNIEnv *env, jobject obj, jint jLogLevel, jstring jMessage);
    void DevToDevGetterVoidCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer);
    void DevToDevGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result);
    void DevToDevGetterBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean result);
    void DevToDevGetterIntCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jint result);
    void DevToDevGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result);
    void DevToDevPersistGetterStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jstring result);
    void DevToDevPersistGetterLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jlong result);
    void DevToDevGetterOptionalStringCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jstring result);
    void DevToDevGetterOptionalBoolCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jboolean result);
    void DevToDevGetterOptionalFloatCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jfloat result);
    void DevToDevGetterOptionalLongCallback_CallbackHandler(JNIEnv* env, jobject obj, jobject pointer, jboolean success, jlong result);
}