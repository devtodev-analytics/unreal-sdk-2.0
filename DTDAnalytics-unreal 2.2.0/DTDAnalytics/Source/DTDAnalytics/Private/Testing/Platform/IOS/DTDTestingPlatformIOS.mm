// Copyright (c) devtodev. All rights reserved.

#include "DTDTestingPlatformIOS.h"

#if PLATFORM_IOS

#import <AppTrackingTransparency/AppTrackingTransparency.h>

void DTDTestingPlatformIOS::RequestTrackingAuthorization(const FDTDTestingGetterStringDelegate& onResult)
{
    if (@available(iOS 14, *)) {
        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
            FString result;
            switch (status) {
                case ATTrackingManagerAuthorizationStatusAuthorized:
            result = "ATTrackingManagerAuthorizationStatusAuthorized";
            break;
                case ATTrackingManagerAuthorizationStatusDenied:
                    result = "ATTrackingManagerAuthorizationStatusDenied";
                    break;
                case ATTrackingManagerAuthorizationStatusNotDetermined:
                    result = "ATTrackingManagerAuthorizationStatusNotDetermined";
                    break;
                case ATTrackingManagerAuthorizationStatusRestricted:
                    result = "ATTrackingManagerAuthorizationStatusRestricted";
                    break;
                default:
                    result = "ERROR_UNKNOWN_STATUS";
            }
            onResult.ExecuteIfBound(result);
        }];
    } else {
        onResult.ExecuteIfBound("ERROR_IOS_VERSION_IS_BELOW_14");
    }
}

#endif
