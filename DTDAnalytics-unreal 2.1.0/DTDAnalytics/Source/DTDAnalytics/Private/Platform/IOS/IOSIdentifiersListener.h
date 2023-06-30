// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include <DTDAnalyticsUnreal/DTDAnalyticsUnreal-Swift.h>
#include "DTDDelegates.h"

@interface IOSIdentifiersListener : NSObject<DTDIdentifiersListener>
{
    const FDTDLongListenerDelegate* onResult;    
}

-(id)initWithDelegate:(const FDTDLongListenerDelegate*)delegate;
@end