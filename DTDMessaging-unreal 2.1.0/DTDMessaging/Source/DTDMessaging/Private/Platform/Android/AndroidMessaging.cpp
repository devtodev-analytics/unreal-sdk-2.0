#include "AndroidMessaging.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidJava.h"
#include "Android/AndroidApplication.h"

#include "AndroidDelegates.h"
#include "Runtime/Launch/Resources/Version.h"

AndroidMessaging::AndroidMessaging()
{

#if ENGINE_MAJOR_VERSION >= 5
	enganePath = "com/epicgames/unreal";
#else
	enganePath = "com/epicgames/ue4";
#endif
	
	// Set push listener
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsMessaging = FAndroidApplication::FindJavaClass("com/devtodev/push/unrealwrapper/DTDMessagingUnreal");

	jclass jclsPushListenerUnreal = FAndroidApplication::FindJavaClass(TCHAR_TO_ANSI(*(enganePath + "/GameActivity$DevToDevPushListenerUnreal")));
    jmethodID jmidPushListenerUnrealInit = Env->GetMethodID(jclsPushListenerUnreal, "<init>", TCHAR_TO_ANSI(*("(L" + enganePath + "/GameActivity;)V")));

    jobject joPushListenerUnrealProxy = Env->NewObject(jclsPushListenerUnreal, jmidPushListenerUnrealInit, FJavaWrapper::GameActivityThis);
	jmethodID jmidSetOnMessageCallback = Env->GetStaticMethodID(jclsMessaging, "setPushListener", "(Lcom/devtodev/push/unrealwrapper/DTDPushListenerUnreal;)V");
    Env->CallStaticVoidMethod(jclsMessaging, jmidSetOnMessageCallback, joPushListenerUnrealProxy);
    Env->DeleteLocalRef(joPushListenerUnrealProxy);
}

AndroidMessaging::~AndroidMessaging()
{

}

void AndroidMessaging::Initialize()
{
	// Initialize
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsMessaging = FAndroidApplication::FindJavaClass("com/devtodev/push/unrealwrapper/DTDMessagingUnreal");
	jmethodID jmidInitialize = Env->GetStaticMethodID(jclsMessaging, "initialize", "(Landroid/content/Context;)V");
	jobject joActivity = FAndroidApplication::GetGameActivityThis();
	Env->CallStaticVoidMethod(jclsMessaging, jmidInitialize, joActivity);
}

void AndroidMessaging::GetAvailability(const FDTDMessagingBoolParamsDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jcls_Messaging = FAndroidApplication::FindJavaClass("com/devtodev/push/unrealwrapper/DTDMessagingUnreal");
    jmethodID jmid_GetToken = Env->GetStaticMethodID(jcls_Messaging, "getPushState", "()Z");
	bool available = Env->CallStaticBooleanMethod(jcls_Messaging, jmid_GetToken);
	onResult->ExecuteIfBound(available);
	delete onResult;
}

void AndroidMessaging::SetAvailability(bool value)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jcls_Messaging = FAndroidApplication::FindJavaClass("com/devtodev/push/unrealwrapper/DTDMessagingUnreal");
	jmethodID jmid_PushIsAllowed = Env->GetStaticMethodID(jcls_Messaging, "pushIsAllowed", "(Z)V");
	Env->CallStaticVoidMethod(jcls_Messaging, jmid_PushIsAllowed, value);
}

void AndroidMessaging::GetToken(const FDTDMessagingStringParamsDelegate* onResult)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jcls_Messaging = FAndroidApplication::FindJavaClass("com/devtodev/push/unrealwrapper/DTDMessagingUnreal");
    jmethodID jmid_GetToken = Env->GetStaticMethodID(jcls_Messaging, "getToken", "()Ljava/lang/String;");
	jstring js_Token = static_cast<jstring>(Env->CallStaticObjectMethod(jcls_Messaging, jmid_GetToken));
	const char* utf_Token = Env->GetStringUTFChars(js_Token, nullptr);
	FString u_Token(UTF8_TO_TCHAR(utf_Token));
	Env->ReleaseStringUTFChars(js_Token, utf_Token);
	Env->DeleteLocalRef(js_Token);
	onResult->ExecuteIfBound(u_Token);
	delete onResult;
}

void AndroidMessaging::SetTokenListener(const FDTDMessagingStringParamsDelegate* listener)
{
	Devtodev_SetTokenListener(listener);
}

void AndroidMessaging::SetTokenErrorListener(const FDTDMessagingStringParamsDelegate* listener)
{
	Devtodev_SetTokenErrorListener(listener);
}

void AndroidMessaging::SetNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener)
{
	Devtodev_SetNotificationReceiveListener(listener);
}

void AndroidMessaging::SetInvisibleNotificationReceiveListener(const FDTDMessagingNotificationParamsDelegate* listener)
{
	Devtodev_SetInvisibleNotificationReceiveListener(listener);
}

void AndroidMessaging::SetNotificationActionListener(const FDTDMessagingNotificationActionParamsDelegate* listener)
{
	Devtodev_SetNotificationActionListener(listener);
}
