#pragma once

#include "DTDDefines.h"
#include "DTDString.h"
#include "DTDRemoteConfigReceiveResult.h"
#include "DTDRemoteConfigChangeResult.h"

namespace DevToDevAnalyticsUnrealWindows
{
	class DLL_SPEC DTDRemoteConfigListener
	{
	public:
		virtual ~DTDRemoteConfigListener() = default;
		virtual void OnReceived(DTDRemoteConfigReceiveResult result) const = 0;
		virtual void OnPrepareToChange() const = 0;
		virtual void OnChanged(DTDRemoteConfigChangeResult result, const DTDString& error) const = 0;
	};
}
