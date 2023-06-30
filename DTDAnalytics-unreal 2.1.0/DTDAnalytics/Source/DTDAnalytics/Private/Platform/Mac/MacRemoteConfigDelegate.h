// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDAnalytics/DTDAnalytics-Swift.h"
#include "DTDDelegates.h"

@interface MacRemoteConfigDelegate : NSObject <DTDRemoteConfigListener>
{
	const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChange;
	const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChange;
	const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceive;
}

+ (MacRemoteConfigDelegate *) shared;
- (void) subscribeConfigChange:(const FDTDRemoteConfigChangeResultDelegate*) onRemoteConfigChangeDelegate
	withConfigPrepareToChange:(const FDTDRemoteConfigPrepareToChangeDelegate *) onRemoteConfigPrepareToChangeDelegate
	withConfigReceive:(const FDTDRemoteConfigReceiveResultDelegate *) onRemoteConfigReceiveDelegate;
@end
