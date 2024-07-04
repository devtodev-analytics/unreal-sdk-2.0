#include "StubMessaging.h"

StubMessaging::StubMessaging()
{
}

StubMessaging::~StubMessaging()
{
}

void StubMessaging::Initialize()
{
    StubMethodWarning("Messaging::Initialize");
}

void StubMessaging::GetAvailability(const FDTDMessagingBoolParamsDelegate* onResult)
{
    StubMethodWarning("Messaging::GetAvailability");
    delete onResult;
}

void StubMessaging::SetAvailability(bool value)
{
    StubMethodWarning("Messaging::SetAvailability");
}

void StubMessaging::GetToken(const FDTDMessagingStringParamsDelegate* onResult)
{
    StubMethodWarning("Messaging::GetToken");
    delete onResult;
}

void StubMessaging::SetTokenListener(const FDTDMessagingStringParamsDelegate* listener)
{
    StubMethodWarning("Messaging::SetTokenListener");
    delete listener;
}

void StubMessaging::SetTokenErrorListener(const FDTDMessagingStringParamsDelegate* listener)
{
    StubMethodWarning("Messaging::SetTokenErrorListener");
    delete listener;
}

void StubMessaging::SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener)
{
    StubMethodWarning("Messaging::SetNotificationReceiveListener");
    delete listener;
}

void StubMessaging::SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener)
{
    StubMethodWarning("Messaging::SetInvisibleNotificationReceiveListener");
    delete listener;
}

void StubMessaging::SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate* listener)
{
    StubMethodWarning("Messaging::SetNotificationActionListener");
    delete listener;
}

void StubMessaging::StubMethodWarning(const FString& methodName)
{
    UE_LOG(LogTemp, Warning, TEXT("The [%s] stub method has been called"), *methodName);
}