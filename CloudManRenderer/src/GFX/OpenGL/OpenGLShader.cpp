#include "CMR_Pch.h"
#include "OpenGLShader.h"

namespace CMR
{
	OpenGLShader::OpenGLShader(const std::string& VertexSrc, const std::string& PixelSrc) : Shader(VertexSrc, PixelSrc)
	{
		GLint CompilationSuccess = 0;

		GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* VSource = VertexSrc.c_str();
		glShaderSource(VertexShader, 1, &VSource, 0);

		glCompileShader(VertexShader);
		glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &CompilationSuccess);

		if (CompilationSuccess == GL_FALSE)
		{
			GLint MaxLogLength = 0;
			glGetShaderiv(VertexShader, GL_INFO_LOG_LENGTH, &MaxLogLength);

			std::vector<GLchar> InfoLog(MaxLogLength);
			glGetShaderInfoLog(VertexShader, MaxLogLength, &MaxLogLength, &InfoLog[0]);
			
			glDeleteShader(VertexShader);
			
			CMR_CORE_ERROR("{0}{1}", "ERROR::SHADER::VERTEX::", InfoLog.data());
			CMR_CORE_ASSERT(false, "VERTEX SHADER COMPILATION FAILED!");
			return;
		}

		GLuint PixelShader = glCreateShader(GL_FRAGMENT_SHADER);

		const GLchar* PSource = PixelSrc.c_str();
		glShaderSource(PixelShader, 1, &PSource, 0);

		glCompileShader(PixelShader);
		glGetShaderiv(PixelShader, GL_COMPILE_STATUS, &CompilationSuccess);

		if (CompilationSuccess == GL_FALSE)
		{
			GLint MaxLogLength = 0;
			glGetShaderiv(PixelShader, GL_INFO_LOG_LENGTH, &MaxLogLength);

			std::vector<GLchar> InfoLog(MaxLogLength);
			glGetShaderInfoLog(PixelShader, MaxLogLength, &MaxLogLength, &InfoLog[0]);
			
			glDeleteShader(PixelShader);
			
			CMR_CORE_ERROR("{0}{1}", "ERROR::SHADER::PIXEL::", InfoLog.data());
			CMR_CORE_ASSERT(false, "PIXEL SHADER COMPILATION FAILED!");
			return;
		}

		ShaderProgram = glCreateProgram();

		glAttachShader(ShaderProgram, VertexShader);
		glAttachShader(ShaderProgram, PixelShader);

		glLinkProgram(ShaderProgram);

		GLint LinkSuccess = 0;
		glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &LinkSuccess);
		if (LinkSuccess == GL_FALSE)
		{
			GLint MaxLogLength = 0;
			glGetProgramiv(ShaderProgram, GL_INFO_LOG_LENGTH, &MaxLogLength);

			std::vector<GLchar> InfoLog(MaxLogLength);
			glGetProgramInfoLog(ShaderProgram, MaxLogLength, &MaxLogLength, InfoLog.data());
			
			glDeleteProgram(ShaderProgram);
			glDeleteShader(VertexShader);
			glDeleteShader(PixelShader);
			
			CMR_CORE_ERROR("{0}{1}", "ERROR::SHADER::LINK::", &InfoLog[0]);
			CMR_CORE_ASSERT(false, "SHADER LINK FAILED!");
			return;
		}

		glDetachShader(ShaderProgram, VertexShader);
		glDetachShader(ShaderProgram, PixelShader);
	}


	void OpenGLShader::Bind() const
	{
		glUseProgram(ShaderProgram);
	}

	void OpenGLShader::UnBind() const
	{
		glUseProgram(0);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(ShaderProgram);
	}
}