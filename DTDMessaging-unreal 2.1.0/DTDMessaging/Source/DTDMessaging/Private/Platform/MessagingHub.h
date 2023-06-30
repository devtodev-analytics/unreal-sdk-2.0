// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "PlatformMessaging.h"

class MessagingHub
{
public:
	static PlatformMessaging& GetMessaging();
private:
	MessagingHub();
	~MessagingHub();
	PlatformMessaging* m_Messaging;
};
