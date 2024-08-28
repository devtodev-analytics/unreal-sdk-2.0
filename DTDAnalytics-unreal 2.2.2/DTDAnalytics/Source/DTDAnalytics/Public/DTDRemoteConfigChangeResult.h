// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDRemoteConfigChangeResult.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDRemoteConfigChangeResult : uint8
{
	Failure = 0	UMETA(DisplayName = "Failure"),
	Success = 1	UMETA(DisplayName = "Success")
};
