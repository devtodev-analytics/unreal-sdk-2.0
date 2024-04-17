// Copyright (c) devtodev. All rights reserved.

#include "DTDTestingBPLibrary.h"

#include "CoreGlobals.h"
#include "Async/TaskGraphInterfaces.h"

// Analytics module.
#include "Platform/PlatformHub.h"

// Testing module.
#include "DTDTestingDelegates.h"

// Log category.
#include "Logging/DTDLogCategory.h"

// Apple platforms.
#if PLATFORM_IOS
#include "Platform/IOS/DTDTestingPlatformIOS.h"
#endif

void UDTDTestingBPLibrary::SetTestProxyUrl(const FString& url)
{
	PlatformHub::GetInstance().GetAnalytics()->SetTestProxyUrl(url);
}

void UDTDTestingBPLibrary::SetTestCustomUrl(const FString& url)
{
	PlatformHub::GetInstance().GetAnalytics()->SetTestCustomUrl(url);
}

void UDTDTestingBPLibrary::TestLogs()
{
	PlatformHub::GetInstance().GetAnalytics()->TestLogs();
}

void UDTDTestingBPLibrary::TestString(const FString& value)
{
	PlatformHub::GetInstance().GetAnalytics()->TestString(value);
}

void UDTDTestingBPLibrary::SetLoggerMessageListener(const FTestingDynamicGetterStringDelegate& listener)
{
	FDTDLogsListenerDelegate* listenerDelegate = new FDTDLogsListenerDelegate();
	listenerDelegate->BindLambda([=](EDTDLogLevel logLevel, const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(result);
		}, TStatId(), NULL, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->SetLoggerMessageListener(listenerDelegate);
}

void UDTDTestingBPLibrary::GetProjectVersion(const FTestingDynamicGetterStringDelegate& onResult)
{
	FString projectVersion;
	GConfig->GetString(
    	TEXT("/Script/EngineSettings.GeneralProjectSettings"),
    	TEXT("ProjectVersion"),
    	projectVersion,
    	GGameIni);
	onResult.ExecuteIfBound(projectVersion);
}

void UDTDTestingBPLibrary::RequestTrackingAuthorization(const FTestingDynamicGetterStringDelegate& onResult)
{
#if PLATFORM_IOS
	FDTDTestingGetterStringDelegate* internalOnResult = new FDTDTestingGetterStringDelegate();
	internalOnResult->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
			delete internalOnResult;
		}, TStatId(), NULL, ENamedThreads::GameThread);
	});
	DTDTestingPlatformIOS::RequestTrackingAuthorization(*internalOnResult);
#else
	onResult.ExecuteIfBound("Not supported for current platform!");
#endif
}

void UDTDTestingBPLibrary::Deinitialize()
{
	PlatformHub::GetInstance().GetAnalytics()->Deinitialize();
}

void UDTDTestingBPLibrary::RunAsyncFunction(const FString& functionName, const FTestingDynamicVoidAsyncDelegate& function, const FTestingDynamicVoidAsyncDelegate& result)
{
	AsyncTask(ENamedThreads::AnyThread, [functionName, function, result]()
	{
		uint32 ThreadId = FPlatformTLS::GetCurrentThreadId();
		FString ThreadName = FThreadManager::Get().GetThreadName(ThreadId);
		UE_LOG(LogTemp, Error, TEXT("run functionName = %s in thread = %s"), *functionName, *ThreadName);
		function.ExecuteIfBound();

		AsyncTask(ENamedThreads::GameThread, [functionName, function, result]()
		{
			uint32 ThreadId = FPlatformTLS::GetCurrentThreadId();
			FString ThreadName = FThreadManager::Get().GetThreadName(ThreadId);
			UE_LOG(LogTemp, Error, TEXT("finish functionName = %s in thread = %s"), *functionName, *ThreadName);
			result.ExecuteIfBound();		
		});
	});
}