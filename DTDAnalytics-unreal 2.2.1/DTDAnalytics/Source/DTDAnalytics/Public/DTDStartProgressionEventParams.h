// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDOptionalInt32.h"
#include "DTDOptionalString.h"

#include "DTDStartProgressionEventParams.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDStartProgressionEventParams
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	FDTDOptionalInt32 Difficulty = FDTDOptionalInt32();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	FDTDOptionalString Source = FDTDOptionalString();
};
