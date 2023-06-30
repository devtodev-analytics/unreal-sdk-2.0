#pragma once

#include <map>

#include "DTDDefines.h"
#include "DTDString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDDictionaryLong
	{
	public:
		DTDDictionaryLong();
		void Add(const DTDString& key, __int64 value);
		std::map<std::wstring, __int64> GetDictionary() const;
	private:
		std::map<std::wstring, __int64> dictionary;
	};
}

