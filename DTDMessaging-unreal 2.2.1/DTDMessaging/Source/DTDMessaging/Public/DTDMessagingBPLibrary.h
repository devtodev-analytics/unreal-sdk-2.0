// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "DTDNotification.h"
#include "DTDNotificationAction.h"
#include "DTDIOSNotificationOptions.h"
#include "DTDMessagingDelegates.h"

#include "DTDMessagingBPLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FDTDMessagingDynamicBoolParamsDelegate, bool, value);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDTDMessagingDynamicStringParamsDelegate, const FString&, value);
DECLARE_DYNAMIC_DELEGATE_OneParam(FDTDMessagingDynamicNotificationParamsDelegate, const FDTDNotification&, notification);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FDTDMessagingDynamicNotificationActionParamsDelegate, const FDTDNotification&, notification, const FDTDNotificationAction&, notificationAction);

UCLASS()
class UDTDMessagingBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Initialize", Keywords = "initialize"), Category = "DTD|Messaging")
	static void Initialize();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAvailability", Keywords = "get availability"), Category = "DTD|Messaging")
	static void GetAvailability(const FDTDMessagingDynamicBoolParamsDelegate& onResult);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetAvailability", Keywords = "set availability"), Category = "DTD|Messaging")
	static void SetAvailability(bool value);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetToken", Keywords = "get token"), Category = "DTD|Messaging")
	static void GetToken(const FDTDMessagingDynamicStringParamsDelegate& onResult);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetTokenListener", Keywords = "set token listener"), Category = "DTD|Messaging")
	static void SetTokenListener(const FDTDMessagingDynamicStringParamsDelegate& listener);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetTokenErrorListener", Keywords = "set token error listener"), Category = "DTD|Messaging")
	static void SetTokenErrorListener(const FDTDMessagingDynamicStringParamsDelegate& listener);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetNotificationReceiveListener", Keywords = "set notification receive listener"), Category = "DTD|Messaging")
	static void SetNotificationReceiveListener(const FDTDMessagingDynamicNotificationParamsDelegate& listener);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetInvisibleNotificationReceiveListener", Keywords = "set invisible notification receive listener"), Category = "DTD|Messaging")
	static void SetInvisibleNotificationReceiveListener(const FDTDMessagingDynamicNotificationParamsDelegate& listener);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetNotificationActionListener", Keywords = "set notification action listener"), Category = "DTD|Messaging")
	static void SetNotificationActionListener(const FDTDMessagingDynamicNotificationActionParamsDelegate& listener);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IOSSetNotificationOptions", Keywords = "ios set notification options"), Category = "DTD|Messaging")
	static void IOSSetNotificationOptions(
		UPARAM(meta = (Bitmask, BitmaskEnum = EDTDIOSNotificationOptions))
		int32 options
	);

	//
	// Methods to interact from C++ code.
	//

	void GetAvailability(const FDTDMessagingBoolParamsDelegate& onResult);
    void GetToken(const FDTDMessagingStringParamsDelegate& onResult);
    void SetTokenListener(const FDTDMessagingStringParamsDelegate& listener);
    void SetTokenErrorListener(const FDTDMessagingStringParamsDelegate& listener);
    void SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate& listener);
    void SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate& listener);
    void SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate& listener);
};
