
#include "CMR_Pch.h"
#include "Log.h"

namespace CMR
{
	std::shared_ptr<spdlog::logger> Log::sCoreLogger;
	
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sCoreLogger = spdlog::stdout_color_mt("CloudMan");
		sCoreLogger->set_level(spdlog::level::trace);
		
	}
}