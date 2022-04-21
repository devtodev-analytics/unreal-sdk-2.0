#pragma once

#include <string>

#include "DTDDefines.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDString
	{
	public:
		DTDString();
		DTDString(const wchar_t* str);
		const wchar_t* GetData() const;
	private:
		std::wstring value;
	};
}
