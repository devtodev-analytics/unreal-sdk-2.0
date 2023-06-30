#pragma once
#include "DTDDefines.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackBoolArg
	{
	public:
		virtual ~DTDCallbackBoolArg() = default;
		virtual void Call(bool arg) const = 0;
	};
}
