#pragma once
#include "DTDDefines.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackOptionalDoubleArg
	{
	public:
		virtual ~DTDCallbackOptionalDoubleArg() = default;
		virtual void Call(bool success, double arg) const = 0;
	};
}
