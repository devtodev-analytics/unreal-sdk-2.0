// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDNotificationActionType.h"

#include "DTDNotificationAction.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FDTDNotificationAction
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	EDTDNotificationActionType ActionType = EDTDNotificationActionType::App;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	FString ActionString = "";
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	FString ButtonId = "";
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	FString ButtonText = "";
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	FString ButtonIcon = "";
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DTD|Messaging")
	bool IsBackground = false;
};
