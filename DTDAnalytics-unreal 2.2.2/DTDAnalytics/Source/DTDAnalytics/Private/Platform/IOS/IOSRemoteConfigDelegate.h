// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include <DTDAnalyticsUnreal/DTDAnalyticsUnreal-Swift.h>
#include "DTDDelegates.h"

@interface IOSRemoteConfigDelegate : NSObject <DTDRemoteConfigListener>
{
	const FDTDRemoteConfigChangeResultDelegate* onRemoteConfigChange;
	const FDTDRemoteConfigPrepareToChangeDelegate* onRemoteConfigPrepareToChange;
	const FDTDRemoteConfigReceiveResultDelegate* onRemoteConfigReceive;
}

+ (IOSRemoteConfigDelegate *) shared;
- (void) subscribeConfigChange:(const FDTDRemoteConfigChangeResultDelegate*) onRemoteConfigChangeDelegate
	withConfigPrepareToChange:(const FDTDRemoteConfigPrepareToChangeDelegate *) onRemoteConfigPrepareToChangeDelegate
	withConfigReceive:(const FDTDRemoteConfigReceiveResultDelegate *) onRemoteConfigReceiveDelegate;
@end
