// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDNotification.h"
#include "DTDNotificationAction.h"

DECLARE_DELEGATE_OneParam(FDTDMessagingBoolParamsDelegate, bool);
DECLARE_DELEGATE_OneParam(FDTDMessagingStringParamsDelegate, const FString&);
DECLARE_DELEGATE_OneParam(FDTDMessagingNotificationParamsDelegate, const FDTDNotification&);
DECLARE_DELEGATE_TwoParams(FDTDMessagingNotificationActionParamsDelegate, const FDTDNotification&, const FDTDNotificationAction&);
