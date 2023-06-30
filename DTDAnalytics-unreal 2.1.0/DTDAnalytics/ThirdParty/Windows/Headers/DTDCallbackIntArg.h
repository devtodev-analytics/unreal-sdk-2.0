#pragma once

#include "DTDDefines.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackIntArg
	{
	public:
		virtual ~DTDCallbackIntArg() = default;
		virtual void Call(__int32 arg) const = 0;
	};
}
