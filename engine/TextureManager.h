#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>

class TextureManger

{
public:
	TextureManger();
	~TextureManger();

	static GLuint MakeTexture(const char* imagePath);

private:

};

#endif // !TEXTUREMANAGER_H
