// Copyright (c) devtodev. All rights reserved.

#include "MacIdentifiersListener.h"
#include "MacConverter.h"

@implementation MacIdentifiersListener
-(id)initWithDelegate:(const FDTDLongListenerDelegate*)delegate {
	onResult = delegate;
    return self;
}

- (void)didReceiveDevtodevIdWith:(int64_t)devtodevId {
	int64 u_devtodevId = static_cast<int64>(devtodevId);
	onResult->ExecuteIfBound(u_devtodevId);
}
@end