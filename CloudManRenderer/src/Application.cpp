#include "CMR_Pch.h"
#include "RenderCore/Log.h"
#include "RenderCore/Window.h"
#include <GLFW/glfw3.h>

int main()
{
	CMR::Log::Init();
	CMR_CORE_INFO("Hello CloudMan!");
		
	std::unique_ptr<CMR::Window> m_Window(CMR::Window::Create());
	while (1)
	{
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}
}