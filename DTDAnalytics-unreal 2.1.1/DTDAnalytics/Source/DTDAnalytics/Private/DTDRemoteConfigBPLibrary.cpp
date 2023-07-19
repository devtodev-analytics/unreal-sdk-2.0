// Copyright (c) devtodev. All rights reserved.

#include "DTDRemoteConfigBPLibrary.h"

#include "Async/TaskGraphInterfaces.h"

#include "Platform/PlatformHub.h"

float UDTDRemoteConfigBPLibrary::GetRemoteConfigWaiting()
{
	return PlatformHub::GetInstance().GetAnalytics()->GetRemoteConfigWaiting();
}

void UDTDRemoteConfigBPLibrary::SetRemoteConfigWaiting(float value)
{
	PlatformHub::GetInstance().GetAnalytics()->SetRemoteConfigWaiting(value);
}

float UDTDRemoteConfigBPLibrary::GetGroupDefinitionWaiting()
{
	return PlatformHub::GetInstance().GetAnalytics()->GetGroupDefinitionWaiting();
}

void UDTDRemoteConfigBPLibrary::SetGroupDefinitionWaiting(float value)
{
	PlatformHub::GetInstance().GetAnalytics()->SetGroupDefinitionWaiting(value);
}

void UDTDRemoteConfigBPLibrary::SetDefaults(const FDTDRemoteConfigDefaults& defaults) 
{
	PlatformHub::GetInstance().GetAnalytics()->SetDefaults(defaults);
}

void UDTDRemoteConfigBPLibrary::ApplyConfig()
{
	PlatformHub::GetInstance().GetAnalytics()->ApplyConfig();
}

void UDTDRemoteConfigBPLibrary::ResetConfig()
{
	PlatformHub::GetInstance().GetAnalytics()->ResetConfig();
}

TMap<FString, FDTDRemoteConfigValue> UDTDRemoteConfigBPLibrary::GetConfig()
{
	return PlatformHub::GetInstance().GetAnalytics()->GetConfig();
}

FDTDRemoteConfigValue UDTDRemoteConfigBPLibrary::GetRemoteConfigValue(const FString& key) {
	return PlatformHub::GetInstance().GetAnalytics()->GetRemoteConfigValue(key);
}

bool UDTDRemoteConfigBPLibrary::HasKey(const FString& key) {
	return PlatformHub::GetInstance().GetAnalytics()->HasKey(key);
}

void UDTDRemoteConfigBPLibrary::CacheTestExperiment() {
	PlatformHub::GetInstance().GetAnalytics()->CacheTestExperiment();
}