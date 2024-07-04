#pragma once
#include "DTDDefines.h"
#include "DTDString.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackOptionalStringArg
	{
	public:
		virtual ~DTDCallbackOptionalStringArg() = default;
		virtual void Call(bool success, const DTDString& arg) const = 0;
	};
}
