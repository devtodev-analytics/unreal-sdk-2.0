// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Platform/PlatformMessaging.h"
#include "DTDMessagingDelegates.h"

class StubMessaging : public PlatformMessaging
{
public:
    StubMessaging();
    virtual ~StubMessaging();
    virtual void Initialize() override;
    virtual void GetAvailability(const FDTDMessagingBoolParamsDelegate* onResult) override;
    virtual void SetAvailability(bool value) override;
    virtual void GetToken(const FDTDMessagingStringParamsDelegate* onResult) override;
    virtual void SetTokenListener(const FDTDMessagingStringParamsDelegate* listener) override;
    virtual void SetTokenErrorListener(const FDTDMessagingStringParamsDelegate* listener) override;
    virtual void SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener) override;
    virtual void SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener) override;
    virtual void SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate* listener) override;
private:
    void StubMethodWarning(const FString& methodName);
};