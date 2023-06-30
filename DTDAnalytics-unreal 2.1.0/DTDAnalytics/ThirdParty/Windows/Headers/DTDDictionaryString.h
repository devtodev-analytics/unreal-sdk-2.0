#pragma once

#include <map>

#include "DTDDefines.h"
#include "DTDString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDDictionaryString
	{
	public:
		DTDDictionaryString();
		void Add(const DTDString& key, const DTDString& value);
		std::map<std::wstring, std::wstring> GetDictionary() const;
	private:
		std::map<std::wstring, std::wstring> dictionary;
	};
}

