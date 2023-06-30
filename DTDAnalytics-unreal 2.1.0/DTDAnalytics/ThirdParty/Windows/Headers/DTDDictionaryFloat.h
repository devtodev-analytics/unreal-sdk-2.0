#pragma once

#include <map>

#include "DTDDefines.h"
#include "DTDString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDDictionaryFloat
	{
	public:
		DTDDictionaryFloat();
		void Add(const DTDString& key, float value);
		std::map<std::wstring, float> GetDictionary() const;
	private:
		std::map<std::wstring, float> dictionary;
	};
}
