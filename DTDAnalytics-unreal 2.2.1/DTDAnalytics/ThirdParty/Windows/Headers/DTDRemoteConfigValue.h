#pragma once
#include "DTDDefines.h"
#include <string>
#include "DTDRemoteConfigSource.h"
#include "DTDString.h"
namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDRemoteConfigValue
	{
	public:
		DTDRemoteConfigValue();
		void SetStringValue(const DTDString& value);
		void SetInt32Value(int32_t value);
		void SetInt64Value(int64_t value);
		void SetFloatValue(float value);
		void SetBoolValue(bool value);
		void SetSource(DTDRemoteConfigSource source);
		std::wstring GetStringValue();
		int32_t GetInt32Value();
		int64_t GetInt64Value();
		float GetFloatValue();
		bool GetBoolValue();
		DTDRemoteConfigSource GetSource();
	private:
		std::wstring s_value;
		int32_t i32_value;
		int64_t i64_value;
		float f_value;
		bool b_value;
		DTDRemoteConfigSource source;
	};
}

