// Copyright (c) devtodev. All rights reserved.

#include "Platform/Android/HelperJNI.h"

#include "Platform/Android/ConverterJNI.h"

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "()V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod);
}


void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, bool argument)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(Z)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, argument);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, int32 argument)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(I)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, argument);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, int64 argument)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(J)V");
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, argument);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& argument)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(Ljava/lang/String;)V");
	jstring jsArgument = Env->NewStringUTF(TCHAR_TO_UTF8(*argument));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, jsArgument);
	Env->DeleteLocalRef(jsArgument);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, int64 arg2)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(Ljava/lang/String;J)V");
	jstring jsArg1 = Env->NewStringUTF(TCHAR_TO_UTF8(*arg1));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, jsArg1, arg2);
	Env->DeleteLocalRef(jsArg1);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, double arg2)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(Ljava/lang/String;D)V");
	jstring jsArg1 = Env->NewStringUTF(TCHAR_TO_UTF8(*arg1));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, jsArg1, arg2);
	Env->DeleteLocalRef(jsArg1);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, double arg2, const FString& arg3, const FString& arg4)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(Ljava/lang/String;DLjava/lang/String;Ljava/lang/String;)V");
	jstring jsArg1 = Env->NewStringUTF(TCHAR_TO_UTF8(*arg1));
	jstring jsArg3 = Env->NewStringUTF(TCHAR_TO_UTF8(*arg3));
	jstring jsArg4 = Env->NewStringUTF(TCHAR_TO_UTF8(*arg4));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, jsArg1, arg2, jsArg3, jsArg4);
	Env->DeleteLocalRef(jsArg1);
	Env->DeleteLocalRef(jsArg3);
	Env->DeleteLocalRef(jsArg4);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, EDTDGender arg1)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(Lcom/devtodev/analytics/external/people/DTDGender;)V");
	jobject joGender = ConverterJNI::ConvertToJGender(arg1);
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, joGender);
	Env->DeleteLocalRef(joGender);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, const FString& arg2)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(Ljava/lang/String;Ljava/lang/String;)V");
	jstring jsArg1 = Env->NewStringUTF(TCHAR_TO_UTF8(*arg1));
	jstring jsArg2 = Env->NewStringUTF(TCHAR_TO_UTF8(*arg2));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, jsArg1, jsArg2);
	Env->DeleteLocalRef(jsArg1);
	Env->DeleteLocalRef(jsArg2);
}

void HelperJNI::CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, bool arg2)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAnalytics = FAndroidApplication::FindJavaClass(className);
	jmethodID jmidMethod = Env->GetStaticMethodID(jclsAnalytics, methodName, "(Ljava/lang/String;Z)V");
	jstring jsArg1 = Env->NewStringUTF(TCHAR_TO_UTF8(*arg1));
	Env->CallStaticVoidMethod(jclsAnalytics, jmidMethod, jsArg1, arg2);
	Env->DeleteLocalRef(jsArg1);
}
