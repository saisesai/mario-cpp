#include "LevelScene.h"

#include <plog/Log.h>

#include "Window.h"

LevelScene::LevelScene()
{
	PLOG(plog::info) << "inside level scene";
	Window::GetInstance()->r -= 1.0f;
	Window::GetInstance()->r -= 1.0f;
	Window::GetInstance()->r -= 1.0f;
}

LevelScene::~LevelScene()
{
}

void LevelScene::Update(float dt)
{
	
}