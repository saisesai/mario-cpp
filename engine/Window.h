#ifndef WINDOW_H
#define WINDOW_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include "Scene.h"
#include "LevelScene.h"
#include "LevelEditorScene.h"

using namespace std;

class Window
{
public:
	float r, g, b;

	Window();
	~Window();

	static Window* GetInstance();

	static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

	void Run();
	void ChangeScene(int newScene);

private:
	int width;
	int height;
	string title;
	GLFWwindow* glfwWindow;
	Scene* currentScene;

	void init();
	void loop();

};

static Window* WindowInstance = nullptr;

#endif // !WINDOW_H
