// Copyright (c) devtodev. All rights reserved.


#include "MessagingHub.h"

#if PLATFORM_ANDROID
#include "Platform/Android/AndroidMessaging.h"
#elif PLATFORM_IOS	
#include "Platform/IOS/IOSMessaging.h"
#else
#include "Platform/Stub/StubMessaging.h"
#endif

PlatformMessaging& MessagingHub::GetMessaging()
{
	static MessagingHub instance;
	return *(instance.m_Messaging);
}

MessagingHub::MessagingHub()
{
#if PLATFORM_ANDROID
	m_Messaging = new AndroidMessaging();
#elif PLATFORM_IOS	
	m_Messaging = new IOSMessaging();
#else
	m_Messaging = new StubMessaging();
#endif
}

MessagingHub::~MessagingHub()
{
	delete m_Messaging;
}
