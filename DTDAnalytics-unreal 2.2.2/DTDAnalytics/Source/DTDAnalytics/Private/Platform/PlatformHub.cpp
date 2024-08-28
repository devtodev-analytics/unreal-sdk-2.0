// Copyright (c) devtodev. All rights reserved.


#include "PlatformHub.h"

#if PLATFORM_ANDROID
#include "Platform/Android/AndroidAnalytics.h"
#elif PLATFORM_IOS	
#include "Platform/IOS/IOSAnalytics.h"
#elif PLATFORM_WINDOWS
#include "Platform/Win64/WindowsAnalytics.h"
#elif PLATFORM_MAC
#include "Platform/Mac/MacAnalytics.h"
#else
#include "Platform/Stubbed/StubbedAnalytics.h"
#endif

PlatformHub& PlatformHub::GetInstance()
{
	static PlatformHub instance;
	return instance;
}

PlatformAnalytics* PlatformHub::GetAnalytics()
{
	return analytics;
}

PlatformHub::PlatformHub()
{
#if PLATFORM_ANDROID
	analytics = new AndroidAnalytics();
#elif PLATFORM_IOS	
	analytics = new IOSAnalytics();
#elif PLATFORM_WINDOWS
	analytics = new WindowsAnalytics();
#elif PLATFORM_MAC
	analytics = new MacAnalytics();
#else
	analytics = new StubbedAnalytics();
#endif
}

PlatformHub::~PlatformHub()
{
	delete analytics;
}
