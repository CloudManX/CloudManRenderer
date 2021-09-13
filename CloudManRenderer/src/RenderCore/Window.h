#pragma once

#include <sstream>

#define DEFAULT_WINDOW_WIDTH 1600
#define DEFAULT_WINDOW_HEIGHT 900

namespace CMR
{

	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& Title_ = "CloudManRenderer",
			uint32_t Width_ = DEFAULT_WINDOW_WIDTH,
			uint32_t Height_ = DEFAULT_WINDOW_HEIGHT	
		) : Title(Title_), Width(Width_), Height(Height_)
		{
		}
	};

	class Window
	{
	public:

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;


		virtual void SetVSync(bool b_EnableVsync) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& Props_ = WindowProps());
	};
}
