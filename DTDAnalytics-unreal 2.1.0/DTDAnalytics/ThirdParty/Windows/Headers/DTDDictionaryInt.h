#pragma once

#include <map>

#include "DTDDefines.h"
#include "DTDString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDDictionaryInt
	{
	public:
		DTDDictionaryInt();
		void Add(const DTDString& key, __int32 value);
		std::map<std::wstring, __int32> GetDictionary() const;
	private:
		std::map<std::wstring, __int32> dictionary;
	};
}
