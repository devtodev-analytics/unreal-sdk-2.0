#pragma once

#include "CoreMinimal.h"
#include "DTDRemoteConfigSource.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDRemoteConfigSource : uint8
{
	Empty = 0       UMETA(DisplayName = "Empty"),
	Remote = 1      UMETA(DisplayName = "Remote"),
    Default = 2     UMETA(DisplayName = "Default")
};