// Copyright (c) devtodev. All rights reserved.

#include "Platform/Android/ConverterJNI.h"

#include <string>

#include "SocialNetwork/DTDSocialNetworkKeys.h"

jobject ConverterJNI::ConvertToJArrayList(const TArray<FString>& stringArray)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsArrayList = Env->FindClass("java/util/ArrayList");
	jmethodID jmidArrayListInit = Env->GetMethodID(jclsArrayList, "<init>", "(I)V");
    jobject joArrayList = Env->NewObject(jclsArrayList, jmidArrayListInit, stringArray.Num());
	jmethodID jmidArrayListAdd = Env->GetMethodID(jclsArrayList, "add", "(Ljava/lang/Object;)Z");
	for (const FString& str : stringArray)
	{
		jstring jsStr = Env->NewStringUTF(TCHAR_TO_UTF8(*str));
		Env->CallBooleanMethod(joArrayList, jmidArrayListAdd, jsStr);
		Env->DeleteLocalRef(jsStr);
	}

	return joArrayList;
}

jobject ConverterJNI::ConvertToJObject(const FDTDAnalyticsConfiguration& config)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	// Create config.
	jclass jclsAnalyticsConfiguration = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/analytics/DTDAnalyticsConfiguration");
	jmethodID jmidAnalyticsConfigurationInit = Env->GetMethodID(jclsAnalyticsConfiguration, "<init>", "()V");
    jobject joAnalyticsConfiguration = Env->NewObject(jclsAnalyticsConfiguration, jmidAnalyticsConfigurationInit);

	// Set log level.
	jobject joLoglevel = ConverterJNI::ConvertToJavaLogLevel(config.LogLevel);
	jmethodID jmidSetLogLevel = Env->GetMethodID(jclsAnalyticsConfiguration, "setLogLevel", "(Lcom/devtodev/analytics/external/DTDLogLevel;)V");
	Env->CallVoidMethod(joAnalyticsConfiguration, jmidSetLogLevel, joLoglevel);
	Env->DeleteLocalRef(joLoglevel);

	// Set current level.
	if (config.CurrentLevel.HasValue)
	{
		jclass clsInteger = Env->FindClass("java/lang/Integer");
		jmethodID jmidIntegerInit = Env->GetMethodID(clsInteger, "<init>", "(I)V");
		jobject joCurrentLevel = Env->NewObject(clsInteger, jmidIntegerInit, config.CurrentLevel.Value);
		jmethodID jmidSetCurrentLevel = Env->GetMethodID(jclsAnalyticsConfiguration, "setCurrentLevel", "(Ljava/lang/Integer;)V");
		Env->CallVoidMethod(joAnalyticsConfiguration, jmidSetCurrentLevel, joCurrentLevel);
		Env->DeleteLocalRef(joCurrentLevel);
	}

	// Set user id.
	if (config.UserId.HasValue)
	{
		jstring jsUserId = Env->NewStringUTF(TCHAR_TO_UTF8(*(config.UserId.Value)));
		jmethodID jmidSetUserId = Env->GetMethodID(jclsAnalyticsConfiguration, "setUserId", "(Ljava/lang/String;)V");
		Env->CallVoidMethod(joAnalyticsConfiguration, jmidSetUserId, jsUserId);
		Env->DeleteLocalRef(jsUserId);
	}

	// Set tracking avaibility.
	jobject joTrackingAvailability = ConverterJNI::ConvertToJTrackingStatus(config.TrackingAvailability);
	jmethodID jmidSetTrackingAvailability = Env->GetMethodID(jclsAnalyticsConfiguration, "setTrackingAvailability", "(Lcom/devtodev/analytics/external/DTDTrackingStatus;)V");
	Env->CallVoidMethod(joAnalyticsConfiguration, jmidSetTrackingAvailability, joTrackingAvailability);
	Env->DeleteLocalRef(joTrackingAvailability);
	return joAnalyticsConfiguration;
}

jobject ConverterJNI::ConvertToJObject(FDTDStartProgressionEventParams value)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	// Create params.
	jclass jclsParams = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/analytics/DTDStartProgressionEventParameters");
	jmethodID jmidParamsInit = Env->GetMethodID(jclsParams, "<init>", "()V");
    jobject joParams = Env->NewObject(jclsParams, jmidParamsInit);

	// Set difficulty.
	if (value.Difficulty.HasValue)
	{
		jclass clsInteger = Env->FindClass("java/lang/Integer");
		jmethodID jmidIntegerInit = Env->GetMethodID(clsInteger, "<init>", "(I)V");
		jobject joDifficulty = Env->NewObject(clsInteger, jmidIntegerInit, value.Difficulty.Value);
		jmethodID jmidSetDifficulty = Env->GetMethodID(jclsParams, "setDifficulty", "(Ljava/lang/Integer;)V");
		Env->CallVoidMethod(joParams, jmidSetDifficulty, joDifficulty);
		Env->DeleteLocalRef(joDifficulty);
	}

	if (value.Source.HasValue)
	{
		// Set source.
		jstring jsSource = Env->NewStringUTF(TCHAR_TO_UTF8(*value.Source.Value));
		jmethodID jmidSetSource = Env->GetMethodID(jclsParams, "setSource", "(Ljava/lang/String;)V");
		Env->CallVoidMethod(joParams, jmidSetSource, jsSource);
		Env->DeleteLocalRef(jsSource);
	}

	return joParams;
}

jobject ConverterJNI::ConvertToJObject(FDTDFinishProgressionEventParams value)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	// Create params.
	jclass jclsParams = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/analytics/DTDFinishProgressionEventParameters");
	jmethodID jmidParamsInit = Env->GetMethodID(jclsParams, "<init>", "()V");
    jobject joParams = Env->NewObject(jclsParams, jmidParamsInit);

	// Set successfulCompletion.
	jmethodID jmidSetSuccessfulCompletion = Env->GetMethodID(jclsParams, "setSuccessfulCompletion", "(Z)V");
	Env->CallVoidMethod(joParams, jmidSetSuccessfulCompletion, value.SuccessfulCompletion);

	// Set duration.
	jmethodID jmidSetDuration = Env->GetMethodID(jclsParams, "setDuration", "(I)V");
	Env->CallVoidMethod(joParams, jmidSetDuration, value.Duration);

	// Set spent.
	jobject joSpent = ConverterJNI::ConvertToJMap(value.Spent);
	jmethodID jmidSetSpent = Env->GetMethodID(jclsParams, "setSpent", "(Ljava/util/Map;)V");
	Env->CallVoidMethod(joParams, jmidSetSpent, joSpent);
	Env->DeleteLocalRef(joSpent);

	// Set earned.
	jobject joEarned = ConverterJNI::ConvertToJMap(value.Earned);
	jmethodID jmidSetEarned = Env->GetMethodID(jclsParams, "setEarned", "(Ljava/util/Map;)V");
	Env->CallVoidMethod(joParams, jmidSetEarned, joEarned);
	Env->DeleteLocalRef(joEarned);

	return joParams;
}

jobject ConverterJNI::ConvertToReferral(EDTDReferralProperty value)
{
	const char* cValue;
	switch (value)
	{
	case EDTDReferralProperty::Source:
		cValue = "Source";
		break;
	case EDTDReferralProperty::Campaign:
		cValue = "Campaign";
		break;
	case EDTDReferralProperty::Content:
		cValue = "Content";
		break;
	case EDTDReferralProperty::Medium:
		cValue = "Medium";
		break;
	case EDTDReferralProperty::Term:
		cValue = "Term";
		break;
	default:
		cValue = "Source";
		break;
	}

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsValue = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/analytics/DTDReferralProperty");
	jfieldID jfidValue = Env->GetStaticFieldID(jclsValue, cValue, "Lcom/devtodev/analytics/external/analytics/DTDReferralProperty;");
	return Env->GetStaticObjectField(jclsValue, jfidValue);
}

jobject ConverterJNI::ConvertToJTrackingStatus(EDTDTrackingStatus value)
{
	const char* cValue;
	switch (value)
	{
	case EDTDTrackingStatus::Unknown:
		cValue = "Unknown";
		break;
	case EDTDTrackingStatus::Enable:
		cValue = "Enable";
		break;
	case EDTDTrackingStatus::Disable:
		cValue = "Disable";
		break;
	default:
		cValue = "Unknown";
		break;
	}

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsValue = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/DTDTrackingStatus");
	jfieldID jfidValue = Env->GetStaticFieldID(jclsValue, cValue, "Lcom/devtodev/analytics/external/DTDTrackingStatus;");
	return Env->GetStaticObjectField(jclsValue, jfidValue);
}

jobject ConverterJNI::ConvertToJMap(const TMap<EDTDReferralProperty, FString>& map)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsHashMap = Env->FindClass("java/util/HashMap");
	jmethodID jmidHashMapInit = Env->GetMethodID(jclsHashMap, "<init>", "(I)V");
    jobject joHashMap = Env->NewObject(jclsHashMap, jmidHashMapInit, map.Num());
	jmethodID jmidHashMapPut = Env->GetMethodID(jclsHashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	for (const TPair<EDTDReferralProperty, FString>& pair : map)
	{

		jobject joKey = ConverterJNI::ConvertToReferral(pair.Key);
		jstring jsValue = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Value));
		Env->CallObjectMethod(joHashMap, jmidHashMapPut, joKey, jsValue);
		Env->DeleteLocalRef(joKey);
		Env->DeleteLocalRef(jsValue);
	}

	return joHashMap;
}

jobject ConverterJNI::ConvertToJMap(const TMap<FString, int64>& map)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsHashMap = Env->FindClass("java/util/HashMap");
	jmethodID jmidHashMapInit = Env->GetMethodID(jclsHashMap, "<init>", "(I)V");
    jobject joHashMap = Env->NewObject(jclsHashMap, jmidHashMapInit, map.Num());
	jmethodID jmidHashMapPut = Env->GetMethodID(jclsHashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	jclass clsLong = Env->FindClass("java/lang/Long");
	jmethodID jmidLongInit = Env->GetMethodID(clsLong, "<init>", "(J)V");
	for (const TPair<FString, int64>& pair : map)
	{

		jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
		jobject joValue = Env->NewObject(clsLong, jmidLongInit, pair.Value);
		Env->CallObjectMethod(joHashMap, jmidHashMapPut, jsKey, joValue);
		Env->DeleteLocalRef(jsKey);
		Env->DeleteLocalRef(joValue);
	}

	return joHashMap;
}

jobject ConverterJNI::ConvertToJMap(const TMap<FString, int32>& map)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsHashMap = Env->FindClass("java/util/HashMap");
	jmethodID jmidHashMapInit = Env->GetMethodID(jclsHashMap, "<init>", "(I)V");
    jobject joHashMap = Env->NewObject(jclsHashMap, jmidHashMapInit, map.Num());
	jmethodID jmidHashMapPut = Env->GetMethodID(jclsHashMap, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	jclass clsLong = Env->FindClass("java/lang/Integer");
	jmethodID jmidLongInit = Env->GetMethodID(clsLong, "<init>", "(I)V");
	for (const TPair<FString, int32>& pair : map)
	{

		jstring jsKey = Env->NewStringUTF(TCHAR_TO_UTF8(*pair.Key));
		jobject joValue = Env->NewObject(clsLong, jmidLongInit, pair.Value);
		Env->CallObjectMethod(joHashMap, jmidHashMapPut, jsKey, joValue);
		Env->DeleteLocalRef(jsKey);
		Env->DeleteLocalRef(joValue);
	}

	return joHashMap;
}

jobject ConverterJNI::ConvertToJavaLogLevel(EDTDLogLevel logLevel)
{
	const char* cLogLevel;
	switch (logLevel)
	{
	case EDTDLogLevel::Unknown:
		cLogLevel = "Unknown";
	case EDTDLogLevel::Debug:
		cLogLevel = "Debug";
		break;
	case EDTDLogLevel::Error:
		cLogLevel = "Error";
		break;
	case EDTDLogLevel::Info:
		cLogLevel = "Info";
		break;
	case EDTDLogLevel::No:
		cLogLevel = "No";
		break;
	case EDTDLogLevel::Warning:
		cLogLevel = "Warning";
		break;
	default:
		cLogLevel = "No";
		break;
	}

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsLogLevel = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/DTDLogLevel");
	jfieldID jfidLogLevel = Env->GetStaticFieldID(jclsLogLevel, cLogLevel, "Lcom/devtodev/analytics/external/DTDLogLevel;");
	return Env->GetStaticObjectField(jclsLogLevel, jfidLogLevel);
}

jobject ConverterJNI::ConvertToJavaAccrualType(EDTDAccrualType value)
{
	const char* cValue;
	switch (value)
	{
	case EDTDAccrualType::Earned:
		cValue = "Earned";
		break;
	case EDTDAccrualType::Bought:
		cValue = "Bought";
		break;
	default:
		cValue = "Earned";
		break;
	}

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsAccrualType = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/analytics/DTDAccrualType");
	jfieldID jfidAccrualType = Env->GetStaticFieldID(jclsAccrualType, cValue, "Lcom/devtodev/analytics/external/analytics/DTDAccrualType;");
	return Env->GetStaticObjectField(jclsAccrualType, jfidAccrualType);
}

jobject ConverterJNI::ConvertToJavaSocialNetwork(EDTDSocialNetwork value)
{
	FString socialNetwork = DTDSocialNetworkKeys::GetKey(value);
	return ConverterJNI::ConvertToJavaSocialNetwork(socialNetwork);
}

jobject ConverterJNI::ConvertToJavaSocialNetwork(const FString& value)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsSocialNetwork = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/analytics/DTDSocialNetwork");
	jmethodID jmidSocialNetwork = Env->GetMethodID(jclsSocialNetwork, "<init>", "(Ljava/lang/String;)V");
	jstring jsValue = Env->NewStringUTF(TCHAR_TO_UTF8(*value));
	jobject joSocialNetwork = Env->NewObject(jclsSocialNetwork, jmidSocialNetwork, jsValue);
	Env->DeleteLocalRef(jsValue);
	return joSocialNetwork;
}

jobject ConverterJNI::ConvertToJGender(EDTDGender value)
{
	const char* cGender;
	switch (value)
	{
	case EDTDGender::Male:
		cGender = "Male";
		break;
	case EDTDGender::Female:
		cGender = "Female";
		break;
	case EDTDGender::Unknown:
		cGender = "Unknown";
		break;
	default:
		cGender = "Unknown";
		break;
	}

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jclass jclsGender = FAndroidApplication::FindJavaClass("com/devtodev/analytics/external/people/DTDGender");
	jfieldID jfidGender = Env->GetStaticFieldID(jclsGender, cGender, "Lcom/devtodev/analytics/external/people/DTDGender;");
	return Env->GetStaticObjectField(jclsGender, jfidGender);
}

jobjectArray ConverterJNI::ConvertToJStringArray(const TArray<FString>& stringArray)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jobjectArray javaStringArray = (jobjectArray)Env->NewObjectArray(stringArray.Num(), FJavaWrapper::JavaStringClass, nullptr);
	for (int i = 0; i < stringArray.Num(); i++) {
		Env->SetObjectArrayElement(javaStringArray, i, ConverterJNI::ConvertToJString(stringArray[i]));
	}
	return javaStringArray;
}

jbooleanArray ConverterJNI::ConvertToJBooleanArray(const TArray<bool>& boolArray)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jbooleanArray javaBooleanArray = (jbooleanArray)Env->NewBooleanArray(boolArray.Num());
	jboolean* javaBooleanArrayPtr = Env->GetBooleanArrayElements(javaBooleanArray, 0);
	for (int i = 0; i < boolArray.Num(); i++) {
		javaBooleanArrayPtr[i] = boolArray[i];
	}
	return javaBooleanArray;
}

jintArray ConverterJNI::ConvertToJIntArray(const TArray<int>& intArray)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jintArray javaIntArray = (jintArray)Env->NewIntArray(intArray.Num());
	jint* javaIntArrayPtr = (jint*)malloc(intArray.Num() * sizeof(jint));
	for (int i = 0; i < intArray.Num(); i++) {
		javaIntArrayPtr[i] = (jint)intArray[i];
	}
	Env->SetIntArrayRegion(javaIntArray, 0, intArray.Num(), javaIntArrayPtr);
	free(javaIntArrayPtr);
	return javaIntArray;
}

jbyteArray ConverterJNI::ConvertToJByteArray(const TArray<uint8>& byteArray)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jbyteArray javaByteArray = (jbyteArray)Env->NewByteArray(byteArray.Num());
	jbyte* javaByteArrayPtr = (jbyte*)malloc(byteArray.Num() * sizeof(jbyte));
	for (int i = 0; i < byteArray.Num(); i++) {
		javaByteArrayPtr[i] = byteArray[i];
	}
	Env->SetByteArrayRegion(javaByteArray, 0, byteArray.Num(), javaByteArrayPtr);
	free(javaByteArrayPtr);
	return javaByteArray;
}

jlongArray ConverterJNI::ConvertToJLongArray(const TArray<long>& longArray)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jlongArray javaLongArray = (jlongArray)Env->NewLongArray(longArray.Num());
	jlong* javaLongArrayPtr = (jlong*)malloc(longArray.Num() * sizeof(jlong));
	for (int i = 0; i < longArray.Num(); i++) {
		javaLongArrayPtr[i] = longArray[i];
	}
	Env->SetLongArrayRegion(javaLongArray, 0, longArray.Num(), javaLongArrayPtr);
	free(javaLongArrayPtr);
	return javaLongArray;
}

jfloatArray ConverterJNI::ConvertToJFloatArray(const TArray<float>& floatArray)
{
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloatArray javaFloatArray = (jfloatArray)Env->NewFloatArray(floatArray.Num());
	jfloat* javaFloatArrayPtr = (jfloat*)malloc(floatArray.Num() * sizeof(jfloat));
	for (int i = 0; i < floatArray.Num(); i++) {
		javaFloatArrayPtr[i] = floatArray[i];
	}
	Env->SetFloatArrayRegion(javaFloatArray, 0, floatArray.Num(), javaFloatArrayPtr);
	free(javaFloatArrayPtr);
	return javaFloatArray;
}

TArray<uint8> ConverterJNI::ConvertToByteArray(jbyteArray javaArray)
{
	TArray<uint8> byteArray;
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jbyte* javaByte = Env->GetByteArrayElements(javaArray, 0);
	int length = Env->GetArrayLength(javaArray);
	for (int i = 0; i < length; i++) {
		byteArray.Add(javaByte[i]);
	}
	return byteArray;
}

TArray<float> ConverterJNI::ConvertToFloatArray(jfloatArray javaArray)
{
	TArray<float> floatArray;
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jfloat* javaFloat = Env->GetFloatArrayElements(javaArray, 0);
	int length = Env->GetArrayLength(javaArray);
	for (int i = 0; i < length; i++)
	{
		floatArray.Add((float)javaFloat[i]);
	}
	return floatArray;
}

TArray<int> ConverterJNI::ConvertToIntArray(jintArray javaArray)
{
	TArray<int> numArray;
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jint* javaNum = Env->GetIntArrayElements(javaArray, 0);
	int length = Env->GetArrayLength(javaArray);
	for (int i = 0; i < length; i++)
	{
		numArray.Add((int)javaNum[i]);
	}
	return numArray;
}

TArray<long> ConverterJNI::ConvertToLongArray(jlongArray javaArray)
{
	TArray<long> longArray;
	JNIEnv* Env = FAndroidApplication::GetJavaEnv();
	jlong* javaLong = Env->GetLongArrayElements(javaArray, 0);
	int length = Env->GetArrayLength(javaArray);
	for (int i = 0; i < length; i++)
	{
		longArray.Add((long)javaLong[i]);
	}
	return longArray;
}

TArray<FString> ConverterJNI::ConvertToStringArray(jobjectArray javaStringArray)
{
	TArray<FString> stringArray;

	JNIEnv* Env = FAndroidApplication::GetJavaEnv();

	int length = Env->GetArrayLength(javaStringArray);

	for (int i = 0; i < length; i++)
	{
		jstring javaString = static_cast<jstring>(Env->GetObjectArrayElement(javaStringArray, i));

		stringArray.Add(ConverterJNI::ConvertToFString(javaString));
	}

	return stringArray;
}

jlong ConverterJNI::ConvertToJLong(long l)
{
	jlong jl = static_cast<jlong>(l);
	return jl;
}

jstring ConverterJNI::ConvertToJString(const FString& string)
{
	JNIEnv* JEnv = AndroidJavaEnv::GetJavaEnv();
	jstring local = JEnv->NewStringUTF(TCHAR_TO_UTF8(*string));
	jstring result = (jstring)JEnv->NewGlobalRef(local);
	JEnv->DeleteLocalRef(local);
	return result;
}

jstring ConverterJNI::ConvertToJString(const char* str)
{
	std::string sstr = str;
	FString string = sstr.c_str();
	JNIEnv* JEnv = AndroidJavaEnv::GetJavaEnv();
	jstring local = JEnv->NewStringUTF(TCHAR_TO_UTF8(*string));
	jstring result = (jstring)JEnv->NewGlobalRef(local);
	JEnv->DeleteLocalRef(local);
	return result;
}

FString ConverterJNI::ConvertToFString(jstring javaString)
{
	JNIEnv* Env = AndroidJavaEnv::GetJavaEnv();
	const char* UTFString = Env->GetStringUTFChars(javaString, nullptr);
	FString Result(UTF8_TO_TCHAR(UTFString));
	Env->ReleaseStringUTFChars(javaString, UTFString);
	Env->DeleteLocalRef(javaString);

	return Result;
}
