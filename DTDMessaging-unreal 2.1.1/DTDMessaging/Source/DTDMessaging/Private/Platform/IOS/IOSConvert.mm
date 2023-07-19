// Copyright (c) devtodev. All rights reserved.

#include "IOSConvert.h"

bool IOSConvert::ToCpp(BOOL value)
{
	return value ? true : false;
}

BOOL IOSConvert::ToObjC(bool value)
{
    return value ? YES : NO;
}

FString IOSConvert::ToCpp(const NSString* value)
{
	const char* cString = [value cStringUsingEncoding:NSUTF8StringEncoding];
	return FString(UTF8_TO_TCHAR(cString));
}

NSString* IOSConvert::ToObjC(const FString& value)
{
    return [NSString stringWithUTF8String:TCHAR_TO_UTF8(*value)];
}

TMap<FString, FString> IOSConvert::ToCpp(const NSDictionary<NSString*, NSString*>* dict)
{
    TMap<FString, FString> u_Dict;
    @autoreleasepool {
        for (NSString* key in dict)
        {
            NSString* value = dict[key];
            if ([value isKindOfClass:[NSDictionary class]] || [value isKindOfClass:[NSMutableDictionary class]]) {
                NSDictionary<NSString*, NSString*>* innerDict = (id)value;
                TMap<FString, FString> innerMap = IOSConvert::ToCpp(innerDict);
                u_Dict.Append(innerMap);
            } else if ([value isKindOfClass:[NSString class]]) {
                u_Dict.Add(IOSConvert::ToCpp(key), IOSConvert::ToCpp(value));
            } else {
                u_Dict.Add(IOSConvert::ToCpp(key), IOSConvert::ToCpp([value description]));
            }
        }
    }
    return u_Dict;
}

EDTDNotificationActionType IOSConvert::ToCpp(DTDActionType value)
{
	switch (value)
	{
	case DTDActionTypeApp:
		return EDTDNotificationActionType::App;
	case DTDActionTypeUrl:
		return EDTDNotificationActionType::Url;
	case DTDActionTypeShare:
		return EDTDNotificationActionType::Share;
	case DTDActionTypeDeeplink:
		return EDTDNotificationActionType::DeepLink;

	default:
		return EDTDNotificationActionType::App;
	}
}
