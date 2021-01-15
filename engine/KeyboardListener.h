#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H

#include <GLFW/glfw3.h>

class KeyboardListener
{
public:
	KeyboardListener();
	~KeyboardListener();

	static KeyboardListener* GetInstance();
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool IsKeyPressed(int keyCode);

	int GetKeyNumber();

private:
	int keyNumber;
	bool KeyPressed[350];

};

static KeyboardListener* KeyboardListenerInstance = nullptr;

#endif // !KEYBOARDLISTENER_H
