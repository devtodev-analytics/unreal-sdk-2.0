#pragma once
#include "DTDDefines.h"
namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackVoidArg
	{
	public:
		virtual ~DTDCallbackVoidArg() = default;
		virtual void Call() const = 0;
	};
}