// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDTrackingStatus.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDTrackingStatus : uint8
{
	Unknown = 0	UMETA(DisplayName = "Unknown"),
	Enable = 1	UMETA(DisplayName = "Enable"),
	Disable = 2	UMETA(DisplayName = "Disable")
};
