#pragma once
#include "DTDDefines.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackOptionalLongArg
	{
	public:
		virtual ~DTDCallbackOptionalLongArg() = default;
		virtual void Call(bool success, __int64 arg) const = 0;
	};
}
