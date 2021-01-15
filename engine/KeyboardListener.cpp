#include "KeyboardListener.h"
#include <cstring>
#include <plog/Log.h>

KeyboardListener::KeyboardListener()
{
	PLOG(plog::info) << "start create keyboard listener...";
	this->keyNumber = 350;
	memset(this->KeyPressed, 0, sizeof(bool) * this->keyNumber);
	PLOG(plog::info) << "create keyboard listener successful!";
}

KeyboardListener::~KeyboardListener()
{
}

KeyboardListener* KeyboardListener::GetInstance()
{
	extern KeyboardListener* KeyboardListenerInstance;
	if (KeyboardListenerInstance == nullptr)
	{
		KeyboardListenerInstance = new KeyboardListener();
	}
	return KeyboardListenerInstance;
}

void KeyboardListener::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key < KeyboardListener::GetInstance()->GetKeyNumber())
	{
		if (action == GLFW_PRESS)
		{
			KeyboardListener::GetInstance()->KeyPressed[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			KeyboardListener::GetInstance()->KeyPressed[key] = false;
		}
	}
}

bool KeyboardListener::IsKeyPressed(int keyCode)
{
	if (keyCode < KeyboardListener::GetInstance()->GetKeyNumber())
	{
		return KeyboardListener::GetInstance()->KeyPressed[keyCode];
	}
	else
	{
		return false;
	}
}

int KeyboardListener::GetKeyNumber()
{
	return this->keyNumber;
}