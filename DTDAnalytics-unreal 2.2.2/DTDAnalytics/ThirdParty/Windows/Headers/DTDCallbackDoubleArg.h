#pragma once
#include "DTDDefines.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackDoubleArg
	{
	public:
		virtual ~DTDCallbackDoubleArg() = default;
		virtual void Call(double arg) const = 0;
	};
}
