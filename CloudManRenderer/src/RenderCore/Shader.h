#pragma once
#include <string>

namespace CMR
{
	class Shader
	{
	public:
		Shader(const std::string& VertexSrc, const std::string& PixelSrc);

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
	};
}

