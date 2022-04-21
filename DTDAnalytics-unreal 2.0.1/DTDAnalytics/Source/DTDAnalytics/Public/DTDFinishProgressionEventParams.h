// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDFinishProgressionEventParams.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDFinishProgressionEventParams
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	bool SuccessfulCompletion = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	int32 Duration = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	TMap<FString, int64> Spent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	TMap<FString, int64> Earned;
};
