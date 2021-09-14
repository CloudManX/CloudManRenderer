#pragma once
#include "RenderCore/Log.h"

#ifdef CMR_DEBUG
	#define CMR_CORE_ASSERT(x, ...) { if (!(x)) { CMR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CMR_CORE_ASSERT(x, ...)
#endif
