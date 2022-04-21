// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "Modules/ModuleManager.h"

#if WITH_EDITOR
#include "Editor.h"
#endif

class FDTDAnalyticsModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	FDelegateHandle PieHandle;
};
