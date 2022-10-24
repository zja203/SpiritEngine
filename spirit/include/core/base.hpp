#pragma once

#include <memory>

#if defined(__linux__) || defined(__linux) || defined(linux)
	#define SPRT_PLATFORM_LINUX
#elif defined(_WIN64)
	#define SPRT_PLATFORM_WINDOWS
#endif

#ifdef SPRT_PLATFORM_WINDOWS
	#ifdef SPRT_BUILD_DLL
		#define SPIRIT_API __declspec(dllexport)
	#else
		#define SPIRIT_API __declspec(dllimport)
	#endif
#elif defined(SPRT_PLATFORM_LINUX)
	#define SPIRIT_API
	#include <signal.h>
	#define SPRT_BREAKDEBUGGER raise(SIGTRAP)
#else
	#error Spirit only supports (64 bit) Windows and Linux!
#endif

#ifdef SPRT_ENABLE_ASSERTS
       #define SPRT_ASSERT(x, ...) { if(!(x)) { SPRT_ERROR("Assertion Failed: {0}", __VA_ARGS__); SPRT_BREAKDEBUGGER(); } }
       #define SPRT_CORE_ASSERT(x, ...) { if(!(x)) { SPRT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); SPRT_BREAKDEBUGGER; } }
#endif

#define BIT(x) (1 <<x )
