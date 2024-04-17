// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "Testing/DTDTestingDelegates.h"

class DTDTestingPlatformIOS
{
public:
    static void RequestTrackingAuthorization(const FDTDTestingGetterStringDelegate& onResult);
};
