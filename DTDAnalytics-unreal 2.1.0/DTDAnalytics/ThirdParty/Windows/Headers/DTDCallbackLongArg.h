#pragma once
#include "DTDDefines.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackLongArg
	{
	public:
		virtual ~DTDCallbackLongArg() = default;
		virtual void Call(__int64 arg) const = 0;
	};
}
