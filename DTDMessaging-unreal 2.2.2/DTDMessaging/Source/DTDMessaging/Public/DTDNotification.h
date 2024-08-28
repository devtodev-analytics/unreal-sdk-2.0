// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDNotificationActionType.h"

#include "DTDNotification.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDNotification
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	EDTDNotificationActionType ActionType = EDTDNotificationActionType::App;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	FString ActionString = "";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	TMap<FString, FString> Data = TMap<FString, FString>();
};
