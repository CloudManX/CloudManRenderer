#include "CMR_Pch.h"
#include "RenderCore/Log.h"

int main()
{
	CMR::Log::Init();
	CMR_CORE_INFO("Hello CloudMan!");

	int n;
	std::cin >> n;
}