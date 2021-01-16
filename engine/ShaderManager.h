#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <string>
#include <gl/glew.h>
#include <glm/glm.hpp>

using namespace std;

enum class shaderType {
	VERTEX_SHADER,
	FRAGMENT_SHADER
};

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

	static GLuint MakeShaderProgram(const char* shaderName);
	static void UploadMatrix4f(GLuint shaderProgram, const char* varName, glm::mat4 mat4);

private:
	static string readShaderSrc(string shaderName, shaderType type);
};

#endif // !SHADERMANAGER_H
