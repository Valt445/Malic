#pragma once
#pragma warning(disable : 4996) // Disable C4996 warning
// ... other code ...


#include "Core.h"
#include "spdlog/spdlog.h"

namespace Malic
{
	class MALIC_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// core log macro
#define MA_CORE_ERROR(...)         ::Malic::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MA_CORE_INFO(...)          ::Malic::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MA_CORE_TRACE(...)         ::Malic::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MA_CORE_WARN(...)          ::Malic::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MA_CORE_CRITICAL(...)      ::Malic::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define MA_ERROR(...)              ::Malic::Log::GetClientLogger()->error(__VA_ARGS__)
#define MA_INFO(...)               ::Malic::Log::GetClientLogger()->info(__VA_ARGS__)
#define MA_TRACE(...)              ::Malic::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MA_WARN(...)               ::Malic::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MA_CRITICAL(...)           ::Malic::Log::GetClientLogger()->critical(__VA_ARGS__)
