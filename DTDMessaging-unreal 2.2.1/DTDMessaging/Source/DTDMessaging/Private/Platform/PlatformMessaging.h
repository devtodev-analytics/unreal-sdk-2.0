// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDMessagingDelegates.h"

class PlatformMessaging
{
public:
    PlatformMessaging() = default;
    virtual ~PlatformMessaging() = default;
    virtual void Initialize() = 0;
    virtual void GetAvailability(const FDTDMessagingBoolParamsDelegate* onResult) = 0;
    virtual void SetAvailability(bool value) = 0;
    virtual void GetToken(const FDTDMessagingStringParamsDelegate* onResult) = 0;
    virtual void SetTokenListener(const FDTDMessagingStringParamsDelegate* listener) = 0;
    virtual void SetTokenErrorListener(const FDTDMessagingStringParamsDelegate* listener) = 0;
    virtual void SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener) = 0;
    virtual void SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener) = 0;
    virtual void SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate* listener) = 0;
};