#include "TextureManager.h"

#define STB_IMAGE_IMPLEMENTATION

#include <plog/Log.h>
#include <stb_image.h>

#include <string>
using namespace std;

TextureManger::TextureManger()
{
}

TextureManger::~TextureManger()
{
}

GLuint TextureManger::MakeTexture(const char* imagePath)
{
	GLuint textureID = 0;
	// Generate texture on GPU
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Set texture parameters
	// Repeat the image in both directions
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// When stretching image, pixelate
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// When shrinking image, pixelate
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	int width, height, channel;
	string pathStr = "./assets/images/" + string(imagePath);
	unsigned char* imagePtr = stbi_load(pathStr.c_str(), &width, &height, &channel, 0);
	if (imagePtr != nullptr)
	{
		if (channel == 3)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
				GL_RGB, GL_UNSIGNED_BYTE, imagePtr);
		}
		else if (channel == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
				GL_RGBA, GL_UNSIGNED_BYTE, imagePtr);
		}
		else
		{
			PLOG(plog::error) << "unknown image channel number " << channel
				<< " in: " + pathStr;
		}
	}
	else
	{
		PLOG(plog::error) << "cannot open image file: " + pathStr;
	}
	stbi_image_free(imagePtr);

	glBindTexture(GL_TEXTURE_2D, 0);

	return textureID;
}