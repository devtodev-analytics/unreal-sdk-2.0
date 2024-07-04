// Copyright (c) devtodev. All rights reserved.

#include "DTDLogs.h"

#include "DTDLogCategory.h"

void DTDLogs::MethodAvailableOnlyForWindowsPlatformWarning(const FString& methodName)
{
    UE_LOG(LogDTD, Warning, TEXT("The [%s] method is available only for Windows platform"), *methodName);
}

void DTDLogs::CallStubbedMethodInfo(const FString& methodName)
{
    UE_LOG(LogDTD, Display, TEXT("The [%s] stubbed method"), *methodName);
}
