// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDOptionalString.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDOptionalString
{
	GENERATED_USTRUCT_BODY()

public:
    FDTDOptionalString() {}

	FDTDOptionalString(FString value) : HasValue(true), Value(value) {}

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Parameters")
	bool HasValue = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Parameters")
	FString Value = "";
};
