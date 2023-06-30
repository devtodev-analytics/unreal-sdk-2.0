#pragma once

#include "DTDDefines.h"
#include "DTDDictionaryLong.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDFinishProgressionEventParameters
	{
	public:
		DTDFinishProgressionEventParameters();
		bool SuccessfulCompletion = false;
		__int32 Duration = 0;
		DTDDictionaryLong Spent;
		DTDDictionaryLong Earned;
	};
}
