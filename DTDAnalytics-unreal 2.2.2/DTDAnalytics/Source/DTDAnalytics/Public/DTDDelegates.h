// Copyright (c) devtodev. All rights reserved.

#pragma once

#include "CoreMinimal.h"

#include "DTDGender.h"
#include "DTDLogLevel.h"
#include "DTDRemoteConfigChangeResult.h"
#include "DTDRemoteConfigReceiveResult.h"

// Initialization complite
DECLARE_DELEGATE(FDTDAnalyticsInitializationCompleteDelegate);

// Listeners.
DECLARE_DELEGATE_OneParam(FDTDLongListenerDelegate, int64);
DECLARE_DELEGATE_TwoParams(FDTDLogsListenerDelegate, EDTDLogLevel, const FString&);

// Common getters.
DECLARE_DELEGATE_OneParam(FDTDGetterStringDelegate, const FString&);
DECLARE_DELEGATE_OneParam(FDTDGetterBoolDelegate, bool);
DECLARE_DELEGATE_OneParam(FDTDGetterIntDelegate, int32);
DECLARE_DELEGATE_OneParam(FDTDGetterLongDelegate, int64);
DECLARE_DELEGATE_OneParam(FDTDGetterGenderDelegate, EDTDGender);

// Gettters for optional parameters.
DECLARE_DELEGATE_TwoParams(FDTDGetterOptionalStringDelegate, bool, const FString&);
DECLARE_DELEGATE_TwoParams(FDTDGetterOptionalBoolDelegate, bool, bool);
DECLARE_DELEGATE_TwoParams(FDTDGetterOptionalFloatDelegate, bool, float);
DECLARE_DELEGATE_TwoParams(FDTDGetterOptionalLongDelegate, bool, int64);

// Gettters for optional parameters with their key.
DECLARE_DELEGATE_ThreeParams(FDTDGetterOptionalStringWithKeyDelegate, bool, const FString&, const FString&);
DECLARE_DELEGATE_ThreeParams(FDTDGetterOptionalBoolWithKeyDelegate, bool, const FString&, bool);
DECLARE_DELEGATE_ThreeParams(FDTDGetterOptionalFloatWithKeyDelegate, bool, const FString&, float);
DECLARE_DELEGATE_ThreeParams(FDTDGetterOptionalLongWithKeyDelegate, bool, const FString&, int64);

// Remote config listener
DECLARE_DELEGATE(FDTDRemoteConfigPrepareToChangeDelegate);
DECLARE_DELEGATE_OneParam(FDTDRemoteConfigReceiveResultDelegate, EDTDRemoteConfigReceiveResult);
DECLARE_DELEGATE_TwoParams(FDTDRemoteConfigChangeResultDelegate, EDTDRemoteConfigChangeResult, const FString&);
