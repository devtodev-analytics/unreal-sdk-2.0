// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Async/Async.h"
#include "HAL/ThreadManager.h"
#include "DTDTestingBPLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FTestingDynamicGetterStringDelegate, const FString&, result);
DECLARE_DYNAMIC_DELEGATE(FTestingDynamicVoidAsyncDelegate);


UCLASS()
class DTDANALYTICS_API UDTDTestingBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetTestProxyUrl", Keywords = "set test proxy url"), Category = "DTD|Testing")
	static void SetTestProxyUrl(const FString& url);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetTestCustomUrl", Keywords = "set test custom url"), Category = "DTD|Testing")
	static void SetTestCustomUrl(const FString& url);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TestLogs", Keywords = "test logs"), Category = "DTD|Testing")
	static void TestLogs();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TestString", Keywords = "test string"), Category = "DTD|Testing")
	static void TestString(const FString& value);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetLoggerMessageListener", Keywords = "set logger message listener"), Category = "DTD|Testing")
	static void SetLoggerMessageListener(const FTestingDynamicGetterStringDelegate& listener);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetProjectVersion", Keywords = "get project version"), Category = "DTD|Testing")
	static void GetProjectVersion(const FTestingDynamicGetterStringDelegate& onResult);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "RequestTrackingAuthorization", Keywords = "request tracking authorization"), Category = "DTD|Testing")
	static void RequestTrackingAuthorization(const FTestingDynamicGetterStringDelegate& onResult);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Deinitialize", Keywords = "deinitialize"), Category = "DTD|Testing")
	static void Deinitialize();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "RunAsyncFunction", Keywords = "RunAsyncFunction"), Category = "DTD|Testing")
	static void RunAsyncFunction(const FString& functionName, const FTestingDynamicVoidAsyncDelegate& function, const FTestingDynamicVoidAsyncDelegate& result);
};


