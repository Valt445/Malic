#pragma once

#ifdef MA_PLATFORM_WINDOWS
	#ifdef MA_BUILD_DLL
		#define MALIC_API __declspec(dllexport)
	#else
		#define MALIC_API __declspec(dllimport)
	#endif
#else
	#error Malic only supports windows
#endif

#define BIT(X) (1 << x)