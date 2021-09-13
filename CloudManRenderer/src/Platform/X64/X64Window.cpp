#include "CMR_pch.h"
#include "Platform/X64/X64Window.h"

namespace CMR
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new X64Window(props);
	}


	X64Window::X64Window(const WindowProps& props)
	{
		Init(props);
	}

	void X64Window::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void X64Window::SetVSync(bool b_EnableVsync)
	{
		if (b_EnableVsync)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}

		m_Data.Vsync = b_EnableVsync;
		
	}

	bool X64Window::IsVSync() const
	{
		return m_Data.Vsync;
	}

	void X64Window::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void X64Window::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		
		CMR_CORE_INFO("Creating Window {0} ({1}, {2}}", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			if (!success)
			{
				CMR_CORE_ERROR("GLFW Initialization Failed");
			}
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow(
			(int)m_Data.Width, 
			(int)m_Data.Height, 
			m_Data.Title.c_str(), 
			nullptr, 
			nullptr);
		
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		
	}

}