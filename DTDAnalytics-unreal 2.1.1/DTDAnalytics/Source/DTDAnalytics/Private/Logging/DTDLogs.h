// Copyright (c) devtodev. All rights reserved.

#pragma once 

#include "CoreMinimal.h"

class DTDLogs
{
public:
	static void MethodAvailableOnlyForWindowsPlatformWarning(const FString& methodName);
	static void CallStubbedMethodInfo(const FString& methodName);
};
