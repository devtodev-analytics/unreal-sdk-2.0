// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#include "DTDGender.h"

class HelperJNI
{
public:
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, bool argument);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, int32 argument);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, int64 argument);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, double argument);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& argument);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, int64 arg2);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, double arg2);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, double arg2, const FString& arg3, const FString& arg4);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, EDTDGender arg1);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, const FString& arg2);
    static void CallStaticMethod(const ANSICHAR* className, const ANSICHAR* methodName, const FString& arg1, bool arg2);
};
