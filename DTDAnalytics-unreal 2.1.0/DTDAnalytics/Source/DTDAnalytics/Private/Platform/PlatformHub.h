// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlatformAnalytics.h"

class PlatformHub
{
public:
	static PlatformHub& GetInstance();
	PlatformAnalytics* GetAnalytics();

private:
	PlatformHub();
	~PlatformHub();

	PlatformAnalytics* analytics;
};
