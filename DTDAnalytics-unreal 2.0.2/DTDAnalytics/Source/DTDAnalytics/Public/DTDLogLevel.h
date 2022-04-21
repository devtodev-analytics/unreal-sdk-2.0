// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDLogLevel.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDLogLevel : uint8
{
	Unknown = 0 UMETA(DisplayName = "Unknown"),
	No = 1		UMETA(DisplayName = "No"),
	Error = 2	UMETA(DisplayName = "Error"),
	Warning = 3	UMETA(DisplayName = "Warning"),
	Info = 4	UMETA(DisplayName = "Info"),
	Debug = 5	UMETA(DisplayName = "Debug"),
};
