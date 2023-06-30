#pragma once

#include "DTDDefines.h"
#include "DTDLogLevel.h"
#include "DTDString.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackLogLevelAndStringArgs
	{
	public:
		virtual ~DTDCallbackLogLevelAndStringArgs() = default;
		virtual void Call(DTDLogLevel logLevel, const DTDString& arg) const = 0;
	};
}
