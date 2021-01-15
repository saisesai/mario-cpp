#include "Window.h"

#include <plog/Log.h>

#include "Timer.h"
#include "MouseListener.h"
#include "KeyboardListener.h"

Window::Window()
{
	PLOG(plog::info) << "start create window...";
	this->width = 1280;
	this->height = 720;
	this->title = "Super Mario";
	this->glfwWindow = nullptr;
	this->r = this->g = this->b = 1.0f;
	this->currentScene = nullptr;
	this->init();
	PLOG(plog::info) << "create window successful!";
}

Window::~Window()
{
	glfwDestroyWindow(this->glfwWindow);
	glfwTerminate();
}

Window* Window::GetInstance()
{
	extern Window* WindowInstance;
	if (WindowInstance == nullptr)
	{
		WindowInstance = new Window();
	}
	return WindowInstance;
}

void Window::Run()
{
	PLOG(plog::info) << "window start main loop";
	this->loop();
	PLOG(plog::info) << "window main loop stop";
	glfwHideWindow(this->glfwWindow);
}

void Window::ChangeScene(int newScene)
{
	if (this->currentScene != nullptr)
	{
		delete this->currentScene;
	}

	switch (newScene)
	{
	case 0:
		this->currentScene = new LevelEditorScene();
		break;
	case 1:
		this->currentScene = new LevelScene();
		break;
	default:
		PLOG(plog::error) << "unknown scene";
		break;
	}
}

void Window::init()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		PLOG(plog::error) << "ERROR:failed to initialize glfw";
		exit(-1);
	}

	// Configure GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

	// Create the window
	this->glfwWindow = glfwCreateWindow(this->width,
		this->height, this->title.c_str(), NULL, NULL);

	// Make the OpenGL the context
	glfwMakeContextCurrent(this->glfwWindow);

	// Initialize glew
	if (glewInit() != GLEW_OK)
	{
		PLOG(plog::error) << "ERROR:failed to initialize glew";
		exit(-1);
	}

	// Set callbacks here
	glfwSetCursorPosCallback(this->glfwWindow, MouseListener::CursorPosCallback);
	glfwSetMouseButtonCallback(this->glfwWindow, MouseListener::MouseButtonCallback);
	glfwSetScrollCallback(this->glfwWindow, MouseListener::ScrollCallback);
	glfwSetKeyCallback(this->glfwWindow, KeyboardListener::KeyCallback);

	// Enable v-sync
	glfwSwapInterval(1);

	// Make the window visible
	glfwShowWindow(this->glfwWindow);

	// Change scene
	this->ChangeScene(0);
}

void Window::loop()
{
	float beginTime = Timer::GetInstance()->GetTime();
	float endTime = 0;
	float dt = -1.0f;

	while (!glfwWindowShouldClose(this->glfwWindow))
	{
		// Poll event
		glfwPollEvents();

		glClearColor(this->r, this->g, this->b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (dt >= 0) {
			this->currentScene->Update(dt);
		}

		glfwSwapBuffers(this->glfwWindow);

		endTime = Timer::GetInstance()->GetTime();
		dt = endTime - beginTime;
		beginTime = endTime;
	}
}
