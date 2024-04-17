// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDRemoteConfigSource.h"

#include "DTDRemoteConfigValue.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDRemoteConfigValue
{
	GENERATED_USTRUCT_BODY()
public:
	FDTDRemoteConfigValue() {}

	FDTDRemoteConfigValue(FString value) : StringValue(value) {}
	FDTDRemoteConfigValue(float value) : FloatValue(value) {}
	FDTDRemoteConfigValue(int32 value) : IntegerValue(value) {}
	FDTDRemoteConfigValue(int64 value) : LongValue(value) {}
	FDTDRemoteConfigValue(bool value) : BoolValue(value) {}

	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "DTD|RemoteConfigValue")
	EDTDRemoteConfigSource Source = EDTDRemoteConfigSource::Empty;

	UPROPERTY(EditAnywhere, AdvancedDisplay,BlueprintReadWrite, Category = "DTD|RemoteConfigValue")
	FString StringValue = "";

	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "DTD|RemoteConfigValue")
	float FloatValue = 0.0f;

	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "DTD|RemoteConfigValue")
	int32 IntegerValue = 0;

	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "DTD|RemoteConfigValue")
	int64 LongValue = 0;

	UPROPERTY(EditAnywhere, AdvancedDisplay, BlueprintReadWrite, Category = "DTD|RemoteConfigValue")
	bool BoolValue = false;
};