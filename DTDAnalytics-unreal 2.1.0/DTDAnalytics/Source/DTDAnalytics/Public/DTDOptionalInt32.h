// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDOptionalInt32.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDOptionalInt32
{
	GENERATED_USTRUCT_BODY()

public:
    FDTDOptionalInt32() {}

    FDTDOptionalInt32(int32 value) : HasValue(true), Value(value) {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Parameters")
	bool HasValue = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Parameters")
	int32 Value = 0;
};
