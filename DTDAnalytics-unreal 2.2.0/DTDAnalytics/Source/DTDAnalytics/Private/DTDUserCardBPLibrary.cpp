// Copyright (c) devtodev. All rights reserved.


#include "DTDUserCardBPLibrary.h"

#include "Async/TaskGraphInterfaces.h"

#include "Platform/PlatformHub.h"

void UDTDUserCardBPLibrary::TryGetString(const FString& key, const FUserCardDynamicGetterOptionalStringDelegate& onResult)
{
	FDTDGetterOptionalStringDelegate* onResultDelegate = new FDTDGetterOptionalStringDelegate();
	onResultDelegate->BindLambda([=](bool success, const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(success, key, result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->TryGetString(key, onResultDelegate);
}

void UDTDUserCardBPLibrary::TryGetBool(const FString& key, const FUserCardDynamicGetterOptionalBoolDelegate& onResult)
{
	FDTDGetterOptionalBoolDelegate* onResultDelegate = new FDTDGetterOptionalBoolDelegate();
	onResultDelegate->BindLambda([=](bool success, bool result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(success, key, result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->TryGetBool(key, onResultDelegate);
}

void UDTDUserCardBPLibrary::TryGetFloat(const FString& key, const FUserCardDynamicGetterOptionalFloatDelegate& onResult)
{
	FDTDGetterOptionalFloatDelegate* onResultDelegate = new FDTDGetterOptionalFloatDelegate();
	onResultDelegate->BindLambda([=](bool success, float result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(success, key, result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->TryGetFloat(key, onResultDelegate);
}

void UDTDUserCardBPLibrary::TryGetLong(const FString& key, const FUserCardDynamicGetterOptionalLongDelegate& onResult)
{
	FDTDGetterOptionalLongDelegate* onResultDelegate = new FDTDGetterOptionalLongDelegate();
	onResultDelegate->BindLambda([=](bool success, int64 result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(success, key, result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->TryGetLong(key, onResultDelegate);
}

void UDTDUserCardBPLibrary::SetCheater(bool cheater)
{
	PlatformHub::GetInstance().GetAnalytics()->SetCheater(cheater);
}

void UDTDUserCardBPLibrary::SetTester(bool tester)
{
	PlatformHub::GetInstance().GetAnalytics()->SetTester(tester);
}

void UDTDUserCardBPLibrary::SetString(const FString& key, const FString& value)
{
	PlatformHub::GetInstance().GetAnalytics()->SetString(key, value);
}

void UDTDUserCardBPLibrary::SetBool(const FString& key, bool value)
{
	PlatformHub::GetInstance().GetAnalytics()->SetBool(key, value);
}

void UDTDUserCardBPLibrary::SetLong(const FString& key, int64 value)
{
	PlatformHub::GetInstance().GetAnalytics()->SetInt(key, value);
}

void UDTDUserCardBPLibrary::SetFloat(const FString& key, float value)
{
	PlatformHub::GetInstance().GetAnalytics()->SetFloat(key, value);
}

void UDTDUserCardBPLibrary::Unset(const FString& key)
{
	PlatformHub::GetInstance().GetAnalytics()->Unset(key);
}

void UDTDUserCardBPLibrary::UnsetArray(const TArray<FString>& keys)
{
	PlatformHub::GetInstance().GetAnalytics()->UnsetArray(keys);
}

void UDTDUserCardBPLibrary::IncrementLong(const FString& key, int64 value)
{
	PlatformHub::GetInstance().GetAnalytics()->IncrementInt(key, value);
}

void UDTDUserCardBPLibrary::IncrementFloat(const FString& key, float value)
{
	PlatformHub::GetInstance().GetAnalytics()->IncrementFloat(key, value);
}

void UDTDUserCardBPLibrary::ClearUser()
{
	PlatformHub::GetInstance().GetAnalytics()->ClearUser();
}


//
// Methods to interact from C++ code.
//

void UDTDUserCardBPLibrary::TryGetString(const FString& key, const FDTDGetterOptionalStringWithKeyDelegate& onResult)
{
	FDTDGetterOptionalStringDelegate* onResultDelegate = new FDTDGetterOptionalStringDelegate();
	onResultDelegate->BindLambda([=](bool success, const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(success, key, result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->TryGetString(key, onResultDelegate);
}

void UDTDUserCardBPLibrary::TryGetBool(const FString& key, const FDTDGetterOptionalBoolWithKeyDelegate& onResult)
{
	FDTDGetterOptionalBoolDelegate* onResultDelegate = new FDTDGetterOptionalBoolDelegate();
	onResultDelegate->BindLambda([=](bool success, bool result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(success, key, result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->TryGetBool(key, onResultDelegate);
}

void UDTDUserCardBPLibrary::TryGetFloat(const FString& key, const FDTDGetterOptionalFloatWithKeyDelegate& onResult)
{
	FDTDGetterOptionalFloatDelegate* onResultDelegate = new FDTDGetterOptionalFloatDelegate();
	onResultDelegate->BindLambda([=](bool success, float result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(success, key, result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->TryGetFloat(key, onResultDelegate);
}

void UDTDUserCardBPLibrary::TryGetLong(const FString& key, const FDTDGetterOptionalLongWithKeyDelegate& onResult)
{
	FDTDGetterOptionalLongDelegate* onResultDelegate = new FDTDGetterOptionalLongDelegate();
	onResultDelegate->BindLambda([=](bool success, int64 result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(success, key, result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->TryGetLong(key, onResultDelegate);
}
