#pragma once

#include "DTDString.h"
#include "DTDArrayString.h"
#include "DTDDefines.h"
#include "DTDRemoteConfigSource.h"
#include "DTDRemoteConfigListener.h"
#include "DTDDictionaryFloat.h"
#include "DTDDictionaryInt.h"
#include "DTDDictionaryBool.h"
#include "DTDDictionaryLong.h"
#include "DTDDictionaryDouble.h"
#include "DTDDictionaryString.h"
#include "DTDRemoteConfigValue.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDRemoteConfig
	{
	public:
		static double GetRemoteConfigWaiting();
		static void SetRemoteConfigWaiting(double value);
		static double GetGroupDefinitionWaiting();
		static void SetGroupDefinitionWaiting(double value);
		static void SetDefaults(
			const DTDDictionaryInt& intDefaults,
			const DTDDictionaryLong& longDefaults,
			const DTDDictionaryDouble& floatDefaults,
			const DTDDictionaryBool& boolDefaults,
			const DTDDictionaryString& stringDefaults);
		static void ApplyConfig();
		static void ResetConfig();
		static void CacheTestExperiment();
		static DTDString GetConfigJson();
	};
}
