// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDAnalytics/DTDAnalytics-Swift.h"
#include "DTDDelegates.h"

@interface MacIdentifiersListener : NSObject<DTDIdentifiersListener>
{
    const FDTDLongListenerDelegate* onResult;    
}

-(id)initWithDelegate:(const FDTDLongListenerDelegate*)delegate;
@end