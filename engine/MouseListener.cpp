#include "MouseListener.h"
#include "plog/Log.h"

MouseListener::MouseListener()
{
	PLOG(plog::info) << "start create mouse listener...";
	this->xPos = 0.0;
	this->yPos = 0.0;
	this->lastXPos = 0.0;
	this->lastYPos = 0.0;
	this->scrollX = 0.0;
	this->scrollY = 0.0;
	this->mouseButtonPressed[0] = false;
	this->mouseButtonPressed[1] = false;
	this->mouseButtonPressed[2] = false;
	this->mouseButtonNumber = 3;
	PLOG(plog::info) << "create mouse listener successful!";
}

MouseListener::~MouseListener()
{
}

MouseListener* MouseListener::GetInstance()
{
	extern MouseListener* MouseListenerInstance;
	if (MouseListenerInstance == nullptr)
	{
		MouseListenerInstance = new MouseListener();
	}
	return MouseListenerInstance;
}

void MouseListener::CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
	MouseListener::GetInstance()->lastXPos = MouseListener::GetInstance()->xPos;
	MouseListener::GetInstance()->lastYPos = MouseListener::GetInstance()->yPos;
	MouseListener::GetInstance()->xPos = xpos;
	MouseListener::GetInstance()->yPos = ypos;
}

void MouseListener::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button < MouseListener::GetInstance()->GetMouseButtonNumber())
	{
		if (action == GLFW_PRESS)
		{
			MouseListener::GetInstance()->mouseButtonPressed[button] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			MouseListener::GetInstance()->mouseButtonPressed[button] = false;
		}
	}
}

void MouseListener::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	MouseListener::GetInstance()->scrollX = xoffset;
	MouseListener::GetInstance()->scrollY = yoffset;
}

void MouseListener::EndFrame()
{
	MouseListener::GetInstance()->scrollX = 0;
	MouseListener::GetInstance()->scrollY = 0;
	MouseListener::GetInstance()->lastXPos = MouseListener::GetInstance()->xPos;
	MouseListener::GetInstance()->lastYPos = MouseListener::GetInstance()->yPos;
}

float MouseListener::GetX()
{
	return (float)MouseListener::GetInstance()->xPos;
}

float MouseListener::GetY()
{
	return (float)MouseListener::GetInstance()->yPos;
}

float MouseListener::GetDx()
{
	return (float)(MouseListener::GetInstance()->xPos - MouseListener::GetInstance()->lastXPos);
}

float MouseListener::GetDy()
{
	return (float)(MouseListener::GetInstance()->yPos - MouseListener::GetInstance()->lastYPos);
}

float MouseListener::GetScrollX()
{
	return (float)MouseListener::GetInstance()->scrollX;
}

float MouseListener::GetScrollY()
{
	return (float)MouseListener::GetInstance()->scrollY;
}

bool MouseListener::IsButtonDown(int button)
{
	if (button < MouseListener::GetInstance()->GetMouseButtonNumber())
	{
		return MouseListener::GetInstance()->mouseButtonPressed[button];
	}
	else
	{
		return false;
	}
}

int MouseListener::GetMouseButtonNumber()
{
	return this->mouseButtonNumber;
}
