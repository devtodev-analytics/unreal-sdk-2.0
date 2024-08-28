#pragma once

#include "CoreMinimal.h"

// Print log error if null and return
#define IF_NULL_RETURN(condition) IF_NULL_RETURN_SMTH(condition,)

// Print log error if null and return smth
#define IF_NULL_RETURN_SMTH(condition, smth)\
if(!(condition))\
{\
	UE_LOG(LogDTD, Error, TEXT("[DTD Android Error] The null reference at %hs:%d"), __FILE__, __LINE__);\
	return smth;\
}
