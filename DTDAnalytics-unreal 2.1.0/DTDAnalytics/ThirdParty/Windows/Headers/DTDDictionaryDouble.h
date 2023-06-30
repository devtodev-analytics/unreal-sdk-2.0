#pragma once

#include <map>

#include "DTDDefines.h"
#include "DTDString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDDictionaryDouble
	{
	public:
		DTDDictionaryDouble();
		void Add(const DTDString& key, double value);
		std::map<std::wstring, double> GetDictionary() const;
	private:
		std::map<std::wstring, double> dictionary;
	};
}

