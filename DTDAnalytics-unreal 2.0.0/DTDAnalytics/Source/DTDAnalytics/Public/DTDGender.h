// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDGender.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDGender : uint8
{
	Unknown = 0	UMETA(DisplayName = "Unknown"),
	Male = 1	UMETA(DisplayName = "Male"),
	Female = 2	UMETA(DisplayName = "Female")
};
