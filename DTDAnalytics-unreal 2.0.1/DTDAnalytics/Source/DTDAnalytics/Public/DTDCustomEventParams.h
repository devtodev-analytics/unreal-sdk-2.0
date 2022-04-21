// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDCustomEventParams.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDCustomEventParams
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	TMap<FString, FString> StringParameters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	TMap<FString, int64> IntParameters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	TMap<FString, float> FloatParameters;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	TMap<FString, bool> BoolParameters;
};
