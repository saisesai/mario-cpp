#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera
{
public:
	glm::vec2 Position;

	Camera(glm::vec2 postion);
	~Camera();
	void adjustProjectrion();
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
	
private:
	glm::mat4 projectrionMatrix;
	glm::mat4 viewMatrix;
	int i = 0;
};

#endif // !CAMERA_H
