#include "CMR_pch.h"
#include "RenderCore/Core.h"
#include "Platform/X64/X64Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace CMR
{
	static int s_GLFWWindowCount = 0;

	Window* Window::Create(const WindowProps& Props)
	{
		return new X64Window(Props);
	}


	X64Window::X64Window(const WindowProps& Props)
	{
		Init(Props);
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
		ShutdownGLFWWindow(m_Window);
	}

	X64Window::~X64Window()
	{
		Shutdown();
	}

	void X64Window::Init(const WindowProps& Props)
	{
		m_Data.Title = Props.Title;
		m_Data.Width = Props.Width;
		m_Data.Height = Props.Height;
		
		CMR_CORE_INFO("Creating Window {0} ({1}, {2})", Props.Title, Props.Width, Props.Height);

		if (!s_GLFWWindowCount)
		{
			int success = glfwInit();
			CMR_CORE_ASSERT(success, "GLFW Initialization Failed");
			++s_GLFWWindowCount;
		}

		m_Window = glfwCreateWindow(
			(int)m_Data.Width, 
			(int)m_Data.Height, 
			m_Data.Title.c_str(), 
			nullptr, 
			nullptr);
		glfwMakeContextCurrent(m_Window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		CMR_CORE_ASSERT(status, "Glad Initialziation Failed!")
		CMR_CORE_INFO("Glad is Initailized.");
		
		glfwSetWindowUserPointer(m_Window, &m_Data);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* Window)
		{
			X64Window::ShutdownGLFWWindow(Window);
		});

		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* Window, int Width, int Height)
		{
			X64WindowData& Data= *(X64WindowData*)glfwGetWindowUserPointer(Window);
			Data.Width = Width;
			Data.Height = Height;
		});
		
	}

	void X64Window::ShutdownGLFWWindow(GLFWwindow* Window)
	{
		glfwDestroyWindow(Window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0)
		{
			glfwTerminate();
		}
	}

}