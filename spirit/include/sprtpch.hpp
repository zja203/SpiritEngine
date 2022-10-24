#pragma once

#include <string>

#include "core/log.hpp"
#include "core/base.hpp"

#if defined(SPRT_PLATFORM_WINDOWS)
	#include <Windows.h>
#elif defined(SPRT_PLATFORM_LINUX)
	#include <stdlib.h>
#endif
