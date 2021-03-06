#include "ShaderManager.h"

#include <plog/Log.h>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>

using namespace std;

ShaderManager::ShaderManager()
{
}

ShaderManager::~ShaderManager()
{
}

GLuint ShaderManager::MakeShaderProgram(const char* shaderName)
{
	GLuint vertexID = 0;
	GLuint fragmentID = 0;
	GLuint shaderProgram = 0;

	string vs = readShaderSrc(shaderName, shaderType::VERTEX_SHADER);
	string fs = readShaderSrc(shaderName, shaderType::FRAGMENT_SHADER);

	const char* vertexShaderSource = vs.c_str();
	const char* fragmentShaderSource = fs.c_str();
	
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

string ShaderManager::readShaderSrc(string shaderName, shaderType type)
{
	string src;
	string filePath = "";
	if (type == shaderType::VERTEX_SHADER)
	{
		filePath = "./assets/shaders/" + shaderName + "/vertex.glsl";
	}
	else if (type == shaderType::FRAGMENT_SHADER)
	{
		filePath = "./assets/shaders/" + shaderName + "/fragment.glsl";
	}
	ifstream fileStream(filePath, ios::in);
	string line = "";
	while (!fileStream.eof())
	{
		getline(fileStream, line);
		src.append(line + "\n");
	}
	return src;
}

void ShaderManager::UploadMatrix4f(GLuint shaderProgram, const char* varName ,glm::mat4 mat4)
{
	GLint varLocation = glGetUniformLocation(shaderProgram, varName);
	glUniformMatrix4fv(varLocation, 1, GL_FALSE, glm::value_ptr(mat4));
}

void ShaderManager::UploadMatrix3f(GLuint shaderProgram, const char* varName, glm::mat3 mat3)
{
	GLint varLocation = glGetUniformLocation(shaderProgram, varName);
	glUniformMatrix3fv(varLocation, 1, GL_FALSE, glm::value_ptr(mat3));
}

void ShaderManager::UploadVector4f(GLuint shaderProgram, const char* varName, glm::vec4 vec4)
{
	GLint varLocation = glGetUniformLocation(shaderProgram, varName);
	glUniform4f(varLocation, vec4.x, vec4.y, vec4.z, vec4.w);
}

void ShaderManager::UploadVector3f(GLuint shaderProgram, const char* varName, glm::vec3 vec3)
{
	GLint varLocation = glGetUniformLocation(shaderProgram, varName);
	glUniform3f(varLocation, vec3.x, vec3.y, vec3.z);
}

void ShaderManager::UploadVector2f(GLuint shaderProgram, const char* varName, glm::vec2 vec2)
{
	GLint varLocatrion = glGetUniformLocation(shaderProgram, varName);
	glUniform2f(varLocatrion, vec2.x, vec2.y);
}

void ShaderManager::UploadFloat(GLuint shaderProgram, const char* varName, float var)
{
	GLint varLocation = glGetUniformLocation(shaderProgram, varName);
	glUniform1f(varLocation, var);
}

void ShaderManager::UploadInt(GLuint shaderProgram, const char* varName, int var)
{
	GLint varLocation = glGetUniformLocation(shaderProgram, varName);
	glUniform1i(varLocation, var);
}

void ShaderManager::UploadTexture(GLuint shaderProgram, const char* textureName, int slot)
{
	GLint varLocation = glGetUniformLocation(shaderProgram, textureName);
	glUniform1i(varLocation, slot);
}