// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDNotificationActionType.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDNotificationActionType : uint8
{
    App = 0,
    Url = 1,
    Share = 2,
    DeepLink = 3
};
