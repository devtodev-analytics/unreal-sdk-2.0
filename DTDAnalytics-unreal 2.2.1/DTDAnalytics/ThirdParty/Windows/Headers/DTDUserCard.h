#pragma once

#include "DTDArrayString.h"
#include "DTDCallbackBoolArg.h"
#include "DTDCallbackGenderArg.h"
#include "DTDCallbackLongArg.h"
#include "DTDCallbackOptionalBoolArg.h"
#include "DTDCallbackOptionalDoubleArg.h"
#include "DTDCallbackOptionalLongArg.h"
#include "DTDCallbackOptionalStringArg.h"
#include "DTDCallbackStringArg.h"
#include "DTDDefines.h"
#include "DTDString.h"
#include "DTDGender.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDUserCard
	{
	public:
		static void TryGetString(const DTDString& key, const DTDCallbackOptionalStringArg* del);
		static void TryGetBool(const DTDString& key, const DTDCallbackOptionalBoolArg* del);
		static void TryGetDouble(const DTDString& key, const DTDCallbackOptionalDoubleArg* del);
		static void TryGetLong(const DTDString& key, const DTDCallbackOptionalLongArg* del);
		static void SetCheater(bool cheater);
		static void SetTester(bool tester);
		static void SetString(const DTDString& key, const DTDString& value);
		static void SetBool(const DTDString& key, bool value);
		static void SetLong(const DTDString& key, __int64 value);
		static void SetDouble(const DTDString& key, double value);
		static void Unset(const DTDString& key);
		static void UnsetArray(const DTDArrayString& keys);
		static void IncrementLong(const DTDString& key, __int64 value);
		static void IncrementDouble(const DTDString& key, double value);
		static void ClearUser();
	};
}
