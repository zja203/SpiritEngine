#pragma once

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
#else
	#error Spirit only supports (64 bit) Windows and Linux!
#endif

#define BIT(x) (1 <<x )
