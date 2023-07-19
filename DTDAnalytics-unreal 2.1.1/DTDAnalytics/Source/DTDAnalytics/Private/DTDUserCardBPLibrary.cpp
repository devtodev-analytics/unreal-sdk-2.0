// Copyright (c) devtodev. All rights reserved.


#include "DTDUserCardBPLibrary.h"

#include "Async/TaskGraphInterfaces.h"

#include "Platform/PlatformHub.h"

void UDTDUserCardBPLibrary::GetName(const FUserCardDynamicGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetName(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetEmail(const FUserCardDynamicGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetEmail(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetPhone(const FUserCardDynamicGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetPhone(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetPhoto(const FUserCardDynamicGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetPhoto(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetGender(const FUserCardDynamicGetterGenderDelegate& onResult)
{
	FDTDGetterGenderDelegate* onResultDelegate = new FDTDGetterGenderDelegate();
	onResultDelegate->BindLambda([=](EDTDGender result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetGender(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetAge(const FUserCardDynamicGetterLongDelegate& onResult)
{
	FDTDGetterLongDelegate* onResultDelegate = new FDTDGetterLongDelegate();
	onResultDelegate->BindLambda([=](int64 result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetAge(onResultDelegate);
}

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

void UDTDUserCardBPLibrary::SetName(const FString& name)
{
	PlatformHub::GetInstance().GetAnalytics()->SetName(name);
}

void UDTDUserCardBPLibrary::SetEmail(const FString& email)
{
	PlatformHub::GetInstance().GetAnalytics()->SetEmail(email);
}

void UDTDUserCardBPLibrary::SetPhone(const FString& phone)
{
	PlatformHub::GetInstance().GetAnalytics()->SetPhone(phone);
}

void UDTDUserCardBPLibrary::SetPhoto(const FString& photo)
{
	PlatformHub::GetInstance().GetAnalytics()->SetPhoto(photo);
}

void UDTDUserCardBPLibrary::SetGender(EDTDGender gender)
{
	PlatformHub::GetInstance().GetAnalytics()->SetGender(gender);
}

void UDTDUserCardBPLibrary::SetAge(int64 age)
{
	PlatformHub::GetInstance().GetAnalytics()->SetAge(age);
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


void UDTDUserCardBPLibrary::GetName(const FDTDGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetName(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetEmail(const FDTDGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetEmail(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetPhone(const FDTDGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetPhone(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetPhoto(const FDTDGetterStringDelegate& onResult)
{
	FDTDGetterStringDelegate* onResultDelegate = new FDTDGetterStringDelegate();
	onResultDelegate->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetPhoto(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetGender(const FDTDGetterGenderDelegate& onResult)
{
	FDTDGetterGenderDelegate* onResultDelegate = new FDTDGetterGenderDelegate();
	onResultDelegate->BindLambda([=](EDTDGender result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetGender(onResultDelegate);
}

void UDTDUserCardBPLibrary::GetAge(const FDTDGetterLongDelegate& onResult)
{
	FDTDGetterLongDelegate* onResultDelegate = new FDTDGetterLongDelegate();
	onResultDelegate->BindLambda([=](int64 result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	PlatformHub::GetInstance().GetAnalytics()->GetAge(onResultDelegate);
}

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
