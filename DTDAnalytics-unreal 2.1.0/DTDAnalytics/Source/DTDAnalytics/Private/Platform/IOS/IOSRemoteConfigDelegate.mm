// Copyright (c) devtodev. All rights reserved.

#include "IOSRemoteConfigDelegate.h"
#include "IOSConverter.h"

@implementation IOSRemoteConfigDelegate

+ (IOSRemoteConfigDelegate *) shared {
    static IOSRemoteConfigDelegate *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[IOSRemoteConfigDelegate alloc] init];
    });

    return sharedInstance;
}

- (void)subscribeConfigChange:(const FDTDRemoteConfigChangeResultDelegate*) onRemoteConfigChangeDelegate
	withConfigPrepareToChange:(const FDTDRemoteConfigPrepareToChangeDelegate *) onRemoteConfigPrepareToChangeDelegate
	withConfigReceive:(const FDTDRemoteConfigReceiveResultDelegate *) onRemoteConfigReceiveDelegate
{
	onRemoteConfigChange = onRemoteConfigChangeDelegate;
	onRemoteConfigPrepareToChange = onRemoteConfigPrepareToChangeDelegate;
	onRemoteConfigReceive = onRemoteConfigReceiveDelegate;
}

- (void)onChangedResult:(enum DTDRemoteConfigChangeResult)result error:(NSError * _Nullable)error {
	NSString *exception = [error localizedDescription];
    FString u_Error = IOSConverter::FromUtf8String([exception UTF8String]);

	EDTDRemoteConfigChangeResult u_Result;
    switch (result) {
        case DTDRemoteConfigChangeResultSuccess:
			u_Result = EDTDRemoteConfigChangeResult::Success;
            break;
        case DTDRemoteConfigChangeResultFailure:
			u_Result = EDTDRemoteConfigChangeResult::Failure;
            break;
        default:
            break;
    }

	onRemoteConfigChange->ExecuteIfBound(u_Result, u_Error);
}

- (void)onPrepareToChange {
	onRemoteConfigPrepareToChange->ExecuteIfBound();
}

- (void)onReceivedResult:(enum DTDRemoteConfigReceiveResult)result {
	EDTDRemoteConfigReceiveResult u_Result;
    switch (result) {
        case DTDRemoteConfigReceiveResultSuccess:
			u_Result = EDTDRemoteConfigReceiveResult::Success;
            break;
        case DTDRemoteConfigReceiveResultFailure:
			u_Result = EDTDRemoteConfigReceiveResult::Failure;
            break;
        default:
            break;
    }
	onRemoteConfigReceive->ExecuteIfBound(u_Result);
}

@end
