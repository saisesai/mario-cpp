#include "Camera.h"

#include <plog/Log.h>
#include <gl/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTA
#include <glm/gtx/string_cast.hpp>

Camera::Camera(glm::vec2 postion)
{
	PLOG(plog::info) << "start crete camera...";
	this->Position = postion;
	this->projectrionMatrix = glm::mat4();
	this->viewMatrix = glm::mat4();
	this->adjustProjectrion();
	PLOG(plog::info) << "create camera successful!";
}

Camera::~Camera()
{
}

void Camera::adjustProjectrion()
{
	this->projectrionMatrix = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, 0.0f, 100.0f);
	//PLOG(plog::debug) << glm::to_string(this->projectrionMatrix);
}

glm::mat4 Camera::GetViewMatrix()
{
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	this->viewMatrix = glm::lookAt(glm::vec3(this->Position.x, this->Position.y, 20.0f),
		cameraFront + glm::vec3(this->Position.x, this->Position.y, 0.0f),
		cameraUp);
	//PLOGD << "Camera::GetViewMatrix()" << this->i++;
	//PLOGD << glm::to_string(this->viewMatrix);
	return this->viewMatrix;
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return this->projectrionMatrix;
}


