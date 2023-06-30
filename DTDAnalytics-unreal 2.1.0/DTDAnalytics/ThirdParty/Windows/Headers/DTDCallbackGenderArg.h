#pragma once
#include "DTDDefines.h"
#include "DTDGender.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCallbackGenderArg
	{
	public:
		virtual ~DTDCallbackGenderArg() = default;
		virtual void Call(DTDGender gender) const = 0;
	};
}
