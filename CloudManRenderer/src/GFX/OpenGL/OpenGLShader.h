#pragma once
#include "RenderCore/Shader.h"
#include <glad/glad.h>

namespace CMR
{
	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& VertexSrc, const std::string& PixelSrc);

		virtual void Bind() const override;
		virtual void UnBind() const override;	

		~OpenGLShader();
	private:
		GLuint ShaderProgram = 0;
	};
}

