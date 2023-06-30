// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "Android/AndroidJNI.h"
#include "Android/AndroidJava.h"
#include "Android/AndroidApplication.h"

#include "DTDLogLevel.h"
#include "DTDAnalyticsConfiguration.h"
#include "DTDCustomEventParams.h"
#include "DTDReferralProperty.h"
#include "DTDAccrualType.h"
#include "DTDSocialNetwork.h"
#include "DTDGender.h"
#include "DTDStartProgressionEventParams.h"
#include "DTDFinishProgressionEventParams.h"
#include "DTDDelegates.h"
#include "DTDAccrualType.h"
#include "DTDSocialNetwork.h"
#include "DTDGender.h"


class ConverterJNI
{
public:
	static jobject ConvertToJArrayList(const TArray<FString>& stringArray);
	static jobject ConvertToJObject(const FDTDAnalyticsConfiguration& config);
	static jobject ConvertToJObject(FDTDStartProgressionEventParams value);
	static jobject ConvertToJObject(FDTDFinishProgressionEventParams value);
	static jobject ConvertToReferral(EDTDReferralProperty value);
	static jobject ConvertToJTrackingStatus(EDTDTrackingStatus value);
	static jobject ConvertToJMap(const TMap<EDTDReferralProperty, FString>& map);
	static jobject ConvertToJMap(const TMap<FString, int64>& map);
	static jobject ConvertToJMap(const TMap<FString, int32>& map);
	static jobject ConvertToJavaLogLevel(EDTDLogLevel logLevel);
	static jobject ConvertToJavaAccrualType(EDTDAccrualType value);
	static jobject ConvertToJavaSocialNetwork(EDTDSocialNetwork value);
	static jobject ConvertToJGender(EDTDGender value);
	static jobject ConvertToJavaSocialNetwork(const FString& value);
	static jobjectArray ConvertToJStringArray(const TArray<FString>& stringArray);
	static jbooleanArray ConvertToJBooleanArray(const TArray<bool>& boolArray);
	static jintArray ConvertToJIntArray(const TArray<int>& intArray);
	static jbyteArray ConvertToJByteArray(const TArray<uint8>& byteArray);
	static jlongArray ConvertToJLongArray(const TArray<long>& longArray);
	static jfloatArray ConvertToJFloatArray(const TArray<float>& floatArray);
	static TArray<uint8> ConvertToByteArray(jbyteArray javaArray);
	static TArray<float> ConvertToFloatArray(jfloatArray javaArray);
	static TArray<int> ConvertToIntArray(jintArray javaArray);
	static TArray<long> ConvertToLongArray(jlongArray javaArray);
	static TArray<FString> ConvertToStringArray(jobjectArray javaStringArray);
	static jlong ConvertToJLong(long l);
	static jstring ConvertToJString(const FString& string);
	static jstring ConvertToJString(const char* str);
	static FString ConvertToFString(jstring javaString);
};
