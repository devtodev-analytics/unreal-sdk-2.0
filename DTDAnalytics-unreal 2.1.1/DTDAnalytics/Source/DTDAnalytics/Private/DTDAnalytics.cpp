// Copyright (c) devtodev. All rights reserved.

#include "DTDAnalytics.h"

#include "Platform/PlatformHub.h"

#define LOCTEXT_NAMESPACE "FDTDAnalyticsModule"

void FDTDAnalyticsModule::StartupModule()
{
#if WITH_EDITOR
	PieHandle = FEditorDelegates::EndPIE.AddLambda([this](const bool bBegan)
	{
		PlatformHub::GetInstance().GetAnalytics()->Deinitialize();
	});
#endif
}

void FDTDAnalyticsModule::ShutdownModule()
{
#if WITH_EDITOR
	FEditorDelegates::EndPIE.Remove(PieHandle);
	PieHandle.Reset();
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDTDAnalyticsModule, DTDAnalytics)