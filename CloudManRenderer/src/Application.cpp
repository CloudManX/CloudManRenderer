#include "CMR_Pch.h"
#include "RenderCore/Log.h"
#include "RenderCore/Window.h"
#include "GFX/OpenGL/OpenGLShader.h"
#include <glad/glad.h>

int main()
{
	CMR::Log::Init();
	CMR_CORE_INFO("Hello CloudMan!");
	
	std::string VS = R"(
		#version 330 core	
		layout(location = 0) in vec3 a_Position;

		void main()
		{
			gl_Position = vec4(a_Position, 1.0);
		}	
	)";

	std::string PS = R"(
		#version 330 core
		out vec4 FragColor;

		void main()
		{
			FragColor = vec4(0.8f, 0.2f, 0.3f, 1.0f);
		}
	)";


	std::unique_ptr<CMR::Window> m_Window(CMR::Window::Create());
	std::unique_ptr<CMR::Shader> MyShader(new CMR::OpenGLShader(VS, PS));
	while (1)
	{
		glClearColor(1, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		// MyShader->Bind();
		// MyShader->UnBind();
		m_Window->OnUpdate();
	}
}