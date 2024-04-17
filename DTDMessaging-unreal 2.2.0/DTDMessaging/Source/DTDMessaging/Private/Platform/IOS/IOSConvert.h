// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include <UserNotifications/UserNotifications.h>
#include <DTDMessagingUnreal/DTDMessagingUnreal-Swift.h>
#include "DTDNotificationActionType.h"

class IOSConvert
{
public:
    static bool ToCpp(BOOL value);
    static BOOL ToObjC(bool value);
    static FString ToCpp(const NSString* value);
    static NSString* ToObjC(const FString& value);
    static TMap<FString, FString> ToCpp(const NSDictionary<NSString*, NSString*>* dic);
    static EDTDNotificationActionType ToCpp(DTDActionType value);
};