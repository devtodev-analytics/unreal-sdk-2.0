// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDAccrualType.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDAccrualType : uint8
{
	Earned = 0	UMETA(DisplayName = "Earned"),
	Bought = 1	UMETA(DisplayName = "Bought")
};
