#pragma once

#include <map>

#include "DTDDefines.h"
#include "DTDReferralProperty.h"
#include "DTDString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDDictionaryReferralProperty
	{
	public:
		DTDDictionaryReferralProperty();
		void Add(DTDReferralProperty key, const DTDString& value);
		std::map<DTDReferralProperty, std::wstring> GetDictionary() const;
	private:
		std::map<DTDReferralProperty, std::wstring> dictionary;
	};
}

