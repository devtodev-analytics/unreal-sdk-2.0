// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DTDMessagingBPLibrary.h"
#include "DTDMessaging.h"

#include "CoreGlobals.h"
#include "Async/TaskGraphInterfaces.h"

#include "Platform/MessagingHub.h"
#include "DTDMessagingDelegates.h"

#if PLATFORM_IOS
#include "Platform/IOS/IOSMessaging.h"
#endif

UDTDMessagingBPLibrary::UDTDMessagingBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UDTDMessagingBPLibrary::Initialize()
{
	MessagingHub::GetMessaging().Initialize();
}

void UDTDMessagingBPLibrary::GetAvailability(const FDTDMessagingDynamicBoolParamsDelegate& onResult)
{
	FDTDMessagingBoolParamsDelegate* del = new FDTDMessagingBoolParamsDelegate();
	del->BindLambda([=](bool result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().GetAvailability(del);
}

void UDTDMessagingBPLibrary::SetAvailability(bool value)
{
	MessagingHub::GetMessaging().SetAvailability(value);
}

void UDTDMessagingBPLibrary::GetToken(const FDTDMessagingDynamicStringParamsDelegate& onResult)
{
	FDTDMessagingStringParamsDelegate* del = new FDTDMessagingStringParamsDelegate();
	del->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().GetToken(del);
}

void UDTDMessagingBPLibrary::SetTokenListener(const FDTDMessagingDynamicStringParamsDelegate& listener)
{
	FDTDMessagingStringParamsDelegate* del = new FDTDMessagingStringParamsDelegate();
	del->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetTokenListener(del);
}

void UDTDMessagingBPLibrary::SetTokenErrorListener(const FDTDMessagingDynamicStringParamsDelegate& listener)
{
	FDTDMessagingStringParamsDelegate* del = new FDTDMessagingStringParamsDelegate();
	del->BindLambda([=](const FString& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{	
			listener.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetTokenErrorListener(del);
}

void UDTDMessagingBPLibrary::SetNotificationReceiveListener(const FDTDMessagingDynamicNotificationParamsDelegate& listener)
{
	FDTDMessagingNotificationParamsDelegate* del = new FDTDMessagingNotificationParamsDelegate();
	del->BindLambda([=](const FDTDNotification& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			for (auto& Elem : result.Data)
			{
				UE_LOG(LogTemp, Warning, TEXT("K:%s V:%s"), *Elem.Key, *Elem.Value);
			}

			listener.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetNotificationReceiveListener(del);
}

void UDTDMessagingBPLibrary::SetInvisibleNotificationReceiveListener(const FDTDMessagingDynamicNotificationParamsDelegate& listener)
{
	FDTDMessagingNotificationParamsDelegate* del = new FDTDMessagingNotificationParamsDelegate();
	del->BindLambda([=](const FDTDNotification& result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetInvisibleNotificationReceiveListener(del);
}

void UDTDMessagingBPLibrary::SetNotificationActionListener(const FDTDMessagingDynamicNotificationActionParamsDelegate& listener)
{
	FDTDMessagingNotificationActionParamsDelegate* del = new FDTDMessagingNotificationActionParamsDelegate();
	del->BindLambda([=](const FDTDNotification& notification, const FDTDNotificationAction& notificationAction)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(notification, notificationAction);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetNotificationActionListener(del);
}

void UDTDMessagingBPLibrary::IOSSetNotificationOptions(int32 options)
{
#if PLATFORM_IOS
	PlatformMessaging& platformMessaging = MessagingHub::GetMessaging();
	IOSMessaging& iosMessaging = static_cast<IOSMessaging&>(platformMessaging);
	iosMessaging.SetNotificationOptions(options);
#endif
}

void UDTDMessagingBPLibrary::GetAvailability(const FDTDMessagingBoolParamsDelegate& onResult)
{
	FDTDMessagingBoolParamsDelegate* del = new FDTDMessagingBoolParamsDelegate();
	del->BindLambda([=](bool result)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(result);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().GetAvailability(del);
}

void UDTDMessagingBPLibrary::GetToken(const FDTDMessagingStringParamsDelegate& onResult)
{
	FDTDMessagingStringParamsDelegate* del = new FDTDMessagingStringParamsDelegate();
	del->BindLambda([=](const FString& token)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			onResult.ExecuteIfBound(token);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().GetToken(del);
}

void UDTDMessagingBPLibrary::SetTokenListener(const FDTDMessagingStringParamsDelegate& listener)
{
	FDTDMessagingStringParamsDelegate* del = new FDTDMessagingStringParamsDelegate();
	del->BindLambda([=](const FString& token)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(token);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetTokenListener(del);
}

void UDTDMessagingBPLibrary::SetTokenErrorListener(const FDTDMessagingStringParamsDelegate& listener)
{
	FDTDMessagingStringParamsDelegate* del = new FDTDMessagingStringParamsDelegate();
	del->BindLambda([=](const FString& error)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(error);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetTokenErrorListener(del);
}

void UDTDMessagingBPLibrary::SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate& listener)
{
	FDTDMessagingNotificationParamsDelegate* del = new FDTDMessagingNotificationParamsDelegate();
	del->BindLambda([=](const FDTDNotification& notification)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(notification);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetNotificationReceiveListener(del);
}

void UDTDMessagingBPLibrary::SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate& listener)
{
	FDTDMessagingNotificationParamsDelegate* del = new FDTDMessagingNotificationParamsDelegate();
	del->BindLambda([=](const FDTDNotification& notification)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(notification);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetInvisibleNotificationReceiveListener(del);
}

void UDTDMessagingBPLibrary::SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate& listener)
{
	FDTDMessagingNotificationActionParamsDelegate* del = new FDTDMessagingNotificationActionParamsDelegate();
	del->BindLambda([=](const FDTDNotification& notification, const FDTDNotificationAction& notificationAction)
	{
		FGraphEventRef Task = FFunctionGraphTask::CreateAndDispatchWhenReady([=]()
		{
			listener.ExecuteIfBound(notification, notificationAction);
		}, TStatId(), nullptr, ENamedThreads::GameThread);
	});
	MessagingHub::GetMessaging().SetNotificationActionListener(del);
}
