#pragma once
#include "DTDDefines.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackOptionalBoolArg
	{
	public:
		virtual ~DTDCallbackOptionalBoolArg() = default;
		virtual void Call(bool success, bool arg) const = 0;
	};
}
