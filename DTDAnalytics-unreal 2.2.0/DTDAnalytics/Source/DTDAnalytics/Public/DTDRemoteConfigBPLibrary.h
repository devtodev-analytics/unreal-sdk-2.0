// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "DTDRemoteConfigDefaults.h"
#include "DTDRemoteConfigValue.h"

#include "DTDRemoteConfigBPLibrary.generated.h"

UCLASS()
class DTDANALYTICS_API UDTDRemoteConfigBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetDefaults", Keywords = "set defaults"), Category = "DTD|RemoteConfig")
	static void SetDefaults(const FDTDRemoteConfigDefaults& defaults);

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetRemoteConfigWaiting", Keywords = "get remote config waiting"), Category = "DTD|RemoteConfig")
	static float GetRemoteConfigWaiting();

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetRemoteConfigWaiting", Keywords = "set remote config waiting"), Category = "DTD|RemoteConfig")
	static void SetRemoteConfigWaiting(float value);

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetGroupDefinitionWaiting", Keywords = "get group definition waiting"), Category = "DTD|RemoteConfig")
	static float GetGroupDefinitionWaiting();

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetGroupDefinitionWaiting", Keywords = "set group definition waiting"), Category = "DTD|RemoteConfig")
	static void SetGroupDefinitionWaiting(float value);

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "ApplyConfig", Keywords = "apply config"), Category = "DTD|RemoteConfig")
    static void ApplyConfig();

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "ResetConfig", Keywords = "reset config"), Category = "DTD|RemoteConfig")
	static void ResetConfig();

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetConfig", Keywords = "config"), Category = "DTD|RemoteConfig")
    static TMap<FString, FDTDRemoteConfigValue> GetConfig();

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetRemoteConfigValue", Keywords = "Get remote config value"), Category = "DTD|RemoteConfig")
    static FDTDRemoteConfigValue GetRemoteConfigValue(const FString& key);

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "HasKey", Keywords = "Remote config has key"), Category = "DTD|RemoteConfig")
    static bool HasKey(const FString& key);

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "CacheTestExperiment", Keywords = "Cache test experiment"), Category = "DTD|RemoteConfig")
    static void CacheTestExperiment();
};