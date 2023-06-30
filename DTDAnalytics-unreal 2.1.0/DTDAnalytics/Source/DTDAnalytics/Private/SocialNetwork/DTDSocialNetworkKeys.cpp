// Copyright (c) devtodev. All rights reserved.

#include "DTDSocialNetworkKeys.h"

FString DTDSocialNetworkKeys::GetKey(EDTDSocialNetwork socialNetwork)
{
	switch (socialNetwork)
	{
	case EDTDSocialNetwork::Facebook:
		return "fb";
	case EDTDSocialNetwork::Vkontakte:
		return "vk";
	case EDTDSocialNetwork::Twitter:
		return "tw";
	case EDTDSocialNetwork::Googleplus:
		return "gp";
	case EDTDSocialNetwork::Whatsapp:
		return "wp";
	case EDTDSocialNetwork::Viber:
		return "vb";
	case EDTDSocialNetwork::Evernote:
		return "en";
	case EDTDSocialNetwork::Googlemail:
		return "gm";
	case EDTDSocialNetwork::Linkedin:
		return "in";
	case EDTDSocialNetwork::Pinterest:
		return "pi";
	case EDTDSocialNetwork::Reddit:
		return "rt";
	case EDTDSocialNetwork::Renren:
		return "rr";
	case EDTDSocialNetwork::Tumblr:
		return "tb";
	case EDTDSocialNetwork::Qzone:
		return "qq";
	default:
		return "Unknown";
	}
}