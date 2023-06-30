#pragma once

#include <map>

#include "DTDDefines.h"
#include "DTDString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDDictionaryBool
	{
	public:
		DTDDictionaryBool();
		void Add(const DTDString& key, bool value);
		std::map<std::wstring, bool> GetDictionary() const;
	private:
		std::map<std::wstring, bool> dictionary;
	};
}

