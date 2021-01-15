#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <gl/glew.h>

class ShaderManager
{
public:
	ShaderManager();
	~ShaderManager();

	static GLuint MakeShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

private:

};

#endif // !SHADERMANAGER_H
