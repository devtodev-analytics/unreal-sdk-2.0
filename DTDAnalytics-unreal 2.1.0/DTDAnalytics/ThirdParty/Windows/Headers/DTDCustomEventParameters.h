#pragma once

#include "DTDDefines.h"
#include "DTDDictionaryBool.h"
#include "DTDDictionaryDouble.h"
#include "DTDDictionaryLong.h"
#include "DTDDictionaryString.h"


namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDCustomEventParameters
	{
	public:
		DTDCustomEventParameters();
		DTDDictionaryString StringParameters;
		DTDDictionaryLong LongParameters;
		DTDDictionaryDouble DoubleParameters;
		DTDDictionaryBool BoolParameters;
	};
}
