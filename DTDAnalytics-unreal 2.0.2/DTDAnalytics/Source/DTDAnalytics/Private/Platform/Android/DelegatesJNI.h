// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "DTDDelegates.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"

extern "C"
{
    void Devtodev_SetLogsListener(const FDTDLogsListenerDelegate* listener);
    JNIEXPORT void JNICALL Java_com_epicgames_ue4_GameActivity_00024DevToDevOnMessageCallback_callback(JNIEnv*, jobject, jint jLogLevel, jstring);
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
}
