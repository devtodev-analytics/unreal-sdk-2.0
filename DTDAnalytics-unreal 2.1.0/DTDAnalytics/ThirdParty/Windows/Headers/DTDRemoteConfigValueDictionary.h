#pragma once
#include "DTDDefines.h"
#include "DTDRemoteConfigValue.h"
#include <map>

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDRemoteConfigValueDictionary
	{
	public:
		DTDRemoteConfigValueDictionary();
		void Add(const DTDRemoteConfigSource& source, const DTDString& value);
		std::map<DTDRemoteConfigValue, std::wstring> GetDictionary() const;
	private:
		std::map<DTDRemoteConfigValue, std::wstring> dictionary;
	};
}

