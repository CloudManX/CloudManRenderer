#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace CMR 
{
	class Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }

	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
	};
}

#define CMR_CORE_ERROR(...) ::CMR::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CMR_CORE_FATAL(...) ::CMR::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define CMR_CORE_INFO(...)  ::CMR::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CMR_CORE_TRACE(...) ::CMR::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CMR_CORE_WARN(...)  ::CMR::Log::GetCoreLogger()->warn(__VA_ARGS__)
