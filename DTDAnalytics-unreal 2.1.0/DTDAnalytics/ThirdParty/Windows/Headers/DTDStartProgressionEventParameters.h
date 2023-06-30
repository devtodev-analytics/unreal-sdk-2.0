#pragma once

#include "DTDDefines.h"
#include "DTDString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDStartProgressionEventParameters
	{
	public:
		DTDStartProgressionEventParameters();
		bool ApplyDifficulty = false;
		__int32 Difficulty = 0;
		bool ApplySource = false;
		DTDString Source;
	};
}
