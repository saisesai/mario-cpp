#include "ShaderManager.h"

#include <plog/Log.h>
#include <cstring>

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

GLuint ShaderManager::MakeShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	GLuint vertexID = 0;
	GLuint fragmentID = 0;
	GLuint shaderProgram = 0;
	

	PLOG(plog::info) << "Compile and link shaders...";

	// 1. Load and compile the vertex shader
	vertexID = glCreateShader(GL_VERTEX_SHADER);
	// Pass the shader source to the GPU
	glShaderSource(vertexID, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexID);
	// Check for errors in compilation
	int success = 0;
	char infoLog[512] = {0};
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
		PLOG(plog::error) << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog;
	}

	// 2. Load and compile the fragment shader
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	// Pass the shader source to the GPU
	glShaderSource(fragmentID, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentID);
	// Check for errors in compilation
	success = 0;
	memset(infoLog, 0, 512);
	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
		PLOG(plog::error) << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog;
	}

	// 3. Link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexID);
	glAttachShader(shaderProgram, fragmentID);
	glLinkProgram(shaderProgram);
	// Check for linking errors
	success = 0;
	memset(infoLog, 0, 512);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (success == GL_FALSE)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		PLOG(plog::error) << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog;
	}

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);

	PLOG(plog::info) << "create shader program successful!";

	return shaderProgram;
}