#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <gl/glew.h>
#include <string>

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

private:
	static string readShaderSrc(string shaderName, shaderType type);
};

#endif // !SHADERMANAGER_H
