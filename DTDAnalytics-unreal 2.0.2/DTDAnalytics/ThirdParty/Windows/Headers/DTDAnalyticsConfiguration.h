#pragma once

#include "DTDDefines.h"
#include "DTDLogLevel.h"
#include "DTDString.h"
#include "DTDTrackingStatus.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDAnalyticsConfiguration
	{
	public:
		DTDAnalyticsConfiguration();
		DTDLogLevel LogLevel = DTDLogLevelNo;
		bool ApplyCurrentLevel = false;
		__int32 CurrentLevel = 0;
		bool ApplyUserId = false;
		DTDString UserId = DTDString();
		bool ApplyApplicationVersion = false;
		DTDString ApplicationVersion = DTDString();
		DTDTrackingStatus TrackingAvailability = DTDTrackingStatusUnknown;
	};
}

