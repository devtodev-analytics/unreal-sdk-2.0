// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDLogLevel.h"
#include "DTDTrackingStatus.h"
#include "DTDOptionalInt32.h"
#include "DTDOptionalString.h"

#include "DTDAnalyticsConfiguration.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDAnalyticsConfiguration
{
	GENERATED_USTRUCT_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	EDTDLogLevel LogLevel = EDTDLogLevel::Unknown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	FDTDOptionalInt32 CurrentLevel = FDTDOptionalInt32();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	FDTDOptionalString UserId = FDTDOptionalString();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	FDTDOptionalString ApplicationVersion = FDTDOptionalString();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Analytics")
	EDTDTrackingStatus TrackingAvailability = EDTDTrackingStatus::Unknown;
};
