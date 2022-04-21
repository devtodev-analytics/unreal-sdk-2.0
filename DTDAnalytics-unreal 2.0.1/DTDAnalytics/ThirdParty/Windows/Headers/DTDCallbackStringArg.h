#pragma once
#include "DTDDefines.h"
#include "DTDString.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackStringArg
	{
	public:
		virtual ~DTDCallbackStringArg() = default;
		virtual void Call(const DTDString& arg) const = 0;
	};
}
