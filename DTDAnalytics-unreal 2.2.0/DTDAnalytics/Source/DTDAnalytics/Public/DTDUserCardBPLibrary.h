// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"

#include "DTDGender.h"
#include "DTDDelegates.h"

#include "DTDUserCardBPLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FUserCardDynamicGetterStringDelegate, const FString&, result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserCardDynamicGetterBoolDelegate, bool, result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserCardDynamicGetterIntDelegate, int32, result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserCardDynamicGetterLongDelegate, int64, result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FUserCardDynamicGetterGenderDelegate, EDTDGender, result);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FUserCardDynamicGetterOptionalStringDelegate, bool, success, const FString&, key, const FString&, result);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FUserCardDynamicGetterOptionalBoolDelegate, bool, success, const FString&, key, bool, result);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FUserCardDynamicGetterOptionalFloatDelegate, bool, success, const FString&, key, float, result);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FUserCardDynamicGetterOptionalLongDelegate, bool, success, const FString&, key, int64, result);

UCLASS()
class DTDANALYTICS_API UDTDUserCardBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TryGetString", Keywords = "try get string"), Category = "DTD|UserCard")
	static void TryGetString(const FString& key, const FUserCardDynamicGetterOptionalStringDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TryGetBool", Keywords = "try get bool"), Category = "DTD|UserCard")
	static void TryGetBool(const FString& key, const FUserCardDynamicGetterOptionalBoolDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TryGetFloat", Keywords = "try get float"), Category = "DTD|UserCard")
	static void TryGetFloat(const FString& key, const FUserCardDynamicGetterOptionalFloatDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TryGetLong", Keywords = "try get long"), Category = "DTD|UserCard")
	static void TryGetLong(const FString& key, const FUserCardDynamicGetterOptionalLongDelegate& onResult);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetCheater", Keywords = "set cheater"), Category = "DTD|UserCard")
	static void SetCheater(bool cheater);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetTester", Keywords = "set tester"), Category = "DTD|UserCard")
	static void SetTester(bool tester);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetString", Keywords = "set string"), Category = "DTD|UserCard")
	static void SetString(const FString& key, const FString& value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetBool", Keywords = "set bool"), Category = "DTD|UserCard")
	static void SetBool(const FString& key, bool value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetLong", Keywords = "set long"), Category = "DTD|UserCard")
	static void SetLong(const FString& key, int64 value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetFloat", Keywords = "set float"), Category = "DTD|UserCard")
	static void SetFloat(const FString& key, float value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Unset", Keywords = "unset"), Category = "DTD|UserCard")
	static void Unset(const FString& key);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UnsetArray", Keywords = "unset array"), Category = "DTD|UserCard")
	static void UnsetArray(const TArray<FString>& keys);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IncrementLong", Keywords = "increment long"), Category = "DTD|UserCard")
	static void IncrementLong(const FString& key, int64 value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IncrementFloat", Keywords = "increment float"), Category = "DTD|UserCard")
	static void IncrementFloat(const FString& key, float value);
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ClearUser", Keywords = "clear user"), Category = "DTD|UserCard")
	static void ClearUser();

	//
	// Methods to interact from C++ code.
	//
	static void TryGetString(const FString& key, const FDTDGetterOptionalStringWithKeyDelegate& onResult);
	static void TryGetBool(const FString& key, const FDTDGetterOptionalBoolWithKeyDelegate& onResult);
	static void TryGetFloat(const FString& key, const FDTDGetterOptionalFloatWithKeyDelegate& onResult);
	static void TryGetLong(const FString& key, const FDTDGetterOptionalLongWithKeyDelegate& onResult);
};
