#include "IOSMessaging.h"

#include <UserNotifications/UserNotifications.h>
#include <DTDMessagingUnreal/DTDMessagingUnreal-Swift.h>

#include "IOSConvert.h"

const FDTDMessagingStringParamsDelegate* devtodev_TokenListener = nullptr;
const FDTDMessagingStringParamsDelegate* devtodev_TokenErrorListener = nullptr;
const FDTDMessagingNotificationParamsDelegate* devtodev_NotificationReceiveListener = nullptr;
const FDTDMessagingNotificationParamsDelegate* devtodev_InvisibleNotificationReceiveListener = nullptr;
const FDTDMessagingNotificationActionParamsDelegate* devtodev_NotificationActionListener = nullptr;

@interface IOSMessagingListener : NSObject<DTDMessagingDelegate>
@end

@implementation IOSMessagingListener
- (void)didRegisterForRemoteNotificationsWith:(NSData*)deviceToken {
    NSString* deviceTokenStr = [[NSString alloc] initWithData:deviceToken encoding:NSUTF8StringEncoding];
    if (devtodev_TokenListener != nullptr) {
        devtodev_TokenListener->ExecuteIfBound(IOSConvert::ToCpp(deviceTokenStr));
    }
}

- (void)didFailToRegisterForRemoteNotificationsWith:(NSError*)error {
    if (devtodev_TokenErrorListener != nullptr) {
        devtodev_TokenErrorListener->ExecuteIfBound(IOSConvert::ToCpp(error.localizedDescription));
    }
}

- (void)didReceiveInvisibleNotificationWith:(DTDMessage*)message {
    if (devtodev_InvisibleNotificationReceiveListener != nullptr) {
        FDTDNotification notification;
        notification.ActionString = IOSConvert::ToCpp(message.actionString);
        notification.Data = IOSConvert::ToCpp(message.payload);
        notification.ActionType = IOSConvert::ToCpp(message.actionType);

        devtodev_InvisibleNotificationReceiveListener->ExecuteIfBound(notification);
    }
}

- (void)didReceiveForegroundNotificationWith:(DTDMessage*)message {
    if (devtodev_NotificationReceiveListener != nullptr) {
        FDTDNotification notification;
        notification.ActionString = IOSConvert::ToCpp(message.actionString);
        notification.Data = IOSConvert::ToCpp(message.payload);
        notification.ActionType = IOSConvert::ToCpp(message.actionType);

        devtodev_NotificationReceiveListener->ExecuteIfBound(notification);
    }
}

- (void)didOpenRemoteNotificationWith:(DTDMessage*)message and:(DTDActionButton*)buttonClicked {
    if (devtodev_NotificationActionListener != nullptr)
    {
        FDTDNotification notification;
        notification.ActionString = IOSConvert::ToCpp(message.actionString);
        notification.Data = IOSConvert::ToCpp(message.payload);
        notification.ActionType = IOSConvert::ToCpp(message.actionType);

        FDTDNotificationAction action;
        if (buttonClicked) {
            notification.ActionType = IOSConvert::ToCpp(buttonClicked.actionType);
            action.ActionString = IOSConvert::ToCpp(buttonClicked.actionString);
            action.ButtonId = IOSConvert::ToCpp(buttonClicked.buttonId);
            action.ButtonText = IOSConvert::ToCpp(buttonClicked.text);
            action.IsBackground = false;
        }

        devtodev_NotificationActionListener->ExecuteIfBound(notification, action);
    }
}
@end

IOSMessaging::IOSMessaging()
{
    [::DTDMessaging setDelegate:[[IOSMessagingListener alloc] init]];
}

IOSMessaging::~IOSMessaging()
{

}

void IOSMessaging::Initialize()
{
    [::DTDMessaging startPushService];
}

void IOSMessaging::GetAvailability(const FDTDMessagingBoolParamsDelegate* onResult)
{
    BOOL objc_Allowed = [::DTDMessaging pushNotificationsAllowed];
    bool u_Allowed = IOSConvert::ToCpp(objc_Allowed);
    onResult->ExecuteIfBound(u_Allowed);
    delete onResult;
}

void IOSMessaging::SetAvailability(bool value)
{
    [::DTDMessaging setPushNotificationsAllowed:IOSConvert::ToObjC(value)];
}

void IOSMessaging::GetToken(const FDTDMessagingStringParamsDelegate* onResult)
{
    NSString* objc_Token = [::DTDMessaging apnsTokenString];
    FString u_Token = IOSConvert::ToCpp(objc_Token);
    onResult->ExecuteIfBound(u_Token);
    delete onResult;
}

void IOSMessaging::SetTokenListener(const FDTDMessagingStringParamsDelegate* listener)
{
    if (devtodev_TokenListener != nullptr)
    {
        delete devtodev_TokenListener;
    }

    devtodev_TokenListener = listener;
}

void IOSMessaging::SetTokenErrorListener(const FDTDMessagingStringParamsDelegate* listener)
{
    if (devtodev_TokenErrorListener != nullptr)
    {
        delete devtodev_TokenErrorListener;
    }

    devtodev_TokenErrorListener = listener;
}

void IOSMessaging::SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener)
{
    if (devtodev_NotificationReceiveListener != nullptr)
    {
        delete devtodev_NotificationReceiveListener;
    }

    devtodev_NotificationReceiveListener = listener;
}

void IOSMessaging::SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener)
{
    if (devtodev_InvisibleNotificationReceiveListener != nullptr)
    {
        delete devtodev_InvisibleNotificationReceiveListener;
    }

    devtodev_InvisibleNotificationReceiveListener = listener;
}

void IOSMessaging::SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate* listener)
{
    if (devtodev_NotificationActionListener != nullptr)
    {
        delete devtodev_NotificationActionListener;
    }

    devtodev_NotificationActionListener = listener;
}

void IOSMessaging::SetNotificationOptions(int32 options)
{
    [::DTDMessaging setPushNotificationsOptions:[[DTDNotificationOptions alloc] initWithRawValue:options]];
}
