// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DTDSocialNetwork.generated.h"

UENUM(Blueprintable, BlueprintType)
enum class EDTDSocialNetwork : uint8
{
	Facebook = 0	UMETA(DisplayName = "Facebook"),
	Vkontakte = 1	UMETA(DisplayName = "Vkontakte"),
	Twitter = 2		UMETA(DisplayName = "Twitter"),
	Googleplus = 3	UMETA(DisplayName = "Googleplus"),
	Whatsapp = 4	UMETA(DisplayName = "Whatsapp"),
	Viber = 5		UMETA(DisplayName = "Viber"),
	Evernote = 6	UMETA(DisplayName = "Evernote"),
	Googlemail = 7	UMETA(DisplayName = "Googlemail"),
	Linkedin = 8	UMETA(DisplayName = "Linkedin"),
	Pinterest = 9	UMETA(DisplayName = "Pinterest"),
	Reddit = 10		UMETA(DisplayName = "Reddit"),
	Renren = 11		UMETA(DisplayName = "Renren"),
	Tumblr = 12		UMETA(DisplayName = "Tumblr"),
	Qzone = 13		UMETA(DisplayName = "Qzone")
};
