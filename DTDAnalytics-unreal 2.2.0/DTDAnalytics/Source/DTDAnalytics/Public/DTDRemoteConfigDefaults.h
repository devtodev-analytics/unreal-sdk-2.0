// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDRemoteConfigDefaults.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDRemoteConfigDefaults
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|RemoteConfig")
	TMap<FString, FString> StringDefaults;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|RemoteConfig")
	TMap<FString, int32> IntegerDefaults;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|RemoteConfig")
	TMap<FString, int64> LongDefaults;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|RemoteConfig")
	TMap<FString, float> FloatDefaults;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|RemoteConfig")
	TMap<FString, bool> BoolDefaults;
};
