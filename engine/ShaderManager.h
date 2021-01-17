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
	static void UploadMatrix3f(GLuint shaderProgram, const char* varName, glm::mat3 mat3);
	static void UploadVector4f(GLuint shaderProgram, const char* varName, glm::vec4 vev4);
	static void UploadVector3f(GLuint shaderProgram, const char* varName, glm::vec3 vec3);
	static void UploadVector2f(GLuint shaderProgram, const char* varName, glm::vec2 vec2);
	static void UploadFloat(GLuint shaderProgram, const char* varName, float var);
	static void UploadInt(GLuint shaderProgram, const char* varName, int var);
	static void UploadTexture(GLuint shaderProgram, const char* textureName, int slot);

private:
	static string readShaderSrc(string shaderName, shaderType type);
};

#endif // !SHADERMANAGER_H
