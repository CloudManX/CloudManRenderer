#pragma once

#include "RenderCore/Window.h"

struct GLFWwindow;

namespace CMR
{
	class X64Window : public Window
	{
	public:
		X64Window(const WindowProps& props);

		virtual void OnUpdate() override;

		uint32_t GetWidth() const override { return m_Data.Width; };
		uint32_t GetHeight() const override { return m_Data.Height; };
	
		virtual void SetVSync(bool b_EnableVsync) override;
		virtual bool IsVSync() const override;
		
		virtual void Shutdown();

		~X64Window();

	private:
		virtual void Init(const WindowProps& props);

		GLFWwindow* m_Window;

		struct X64WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool Vsync;
		};

		X64WindowData m_Data;

		static void ShutdownGLFWWindow(GLFWwindow* Window);
	};


}
