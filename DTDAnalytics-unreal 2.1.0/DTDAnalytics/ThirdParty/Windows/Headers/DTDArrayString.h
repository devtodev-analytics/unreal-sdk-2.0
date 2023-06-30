#pragma once

#include <vector>

#include "DTDDefines.h"
#include "DTDString.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDArrayString
	{
	public:
		DTDArrayString();
		void Add(const DTDString& value);
		std::vector<std::wstring> GetVector() const;
	private:
		std::vector<std::wstring> array;
	};
}
