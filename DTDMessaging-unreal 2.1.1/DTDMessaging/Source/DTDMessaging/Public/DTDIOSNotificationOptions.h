// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDIOSNotificationOptions.generated.h"

UENUM(Blueprintable, BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EDTDIOSNotificationOptions : uint8
{
    None                    = 0,
    Badge                   = 1 << 0,
    Sound                   = 1 << 1,
    Alert                   = 1 << 2,
    CarPlay                 = 1 << 3,
    CriticalAlert           = 1 << 4,
    AppNotificationSettings = 1 << 5,
    Provisional             = 1 << 6
};

ENUM_CLASS_FLAGS(EDTDIOSNotificationOptions);
