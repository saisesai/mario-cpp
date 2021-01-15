#include "LevelEditorScene.h"
#include <plog/Log.h>
#include <gl/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "KeyboardListener.h"

LevelEditorScene::LevelEditorScene()
{
	PLOG(plog::info) << "inside level editor scene";
	this->changingScene = false;
	this->timeToChangeScene = 1.0f;
}

LevelEditorScene::~LevelEditorScene()
{
}

void LevelEditorScene::Update(float dt)
{
	PLOG(plog::debug) << (1.0f / dt) << "fps";
	if (!this->changingScene && KeyboardListener::IsKeyPressed(GLFW_KEY_SPACE))
	{
		this->changingScene = true;
	}
	else if (this->changingScene && this->timeToChangeScene >= 0)
	{
		this->timeToChangeScene -= dt;
		Window::GetInstance()->r -= dt * 1.0f;
		Window::GetInstance()->g -= dt * 1.0f;
		Window::GetInstance()->b -= dt * 1.0f;
	}
	else if (this->changingScene)
	{
		Window::GetInstance()->ChangeScene(1);
	}
}