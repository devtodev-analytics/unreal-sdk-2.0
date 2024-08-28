// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDReferralProperty.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDReferralProperty : uint8
{
	Source = 0		UMETA(DisplayName = "Source"),
	Medium = 1		UMETA(DisplayName = "Medium"),
	Content = 2		UMETA(DisplayName = "Content"),
	Campaign = 3	UMETA(DisplayName = "Campaign"),
	Term = 4		UMETA(DisplayName = "Term")
};