#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include <GLFW/glfw3.h>

class MouseListener
{
public:
	MouseListener();
	~MouseListener();

	static MouseListener* GetInstance();

	static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void EndFrame();
	static float GetX();
	static float GetY();
	static float GetDx();
	static float GetDy();
	static float GetScrollX();
	static float GetScrollY();
	static bool IsButtonDown(int button);

	int GetMouseButtonNumber();

private:
	double xPos, yPos, lastXPos, lastYPos;
	double scrollX, scrollY;
	bool mouseButtonPressed[3];
	int mouseButtonNumber;
};

static MouseListener* MouseListenerInstance = nullptr;

#endif // !MOUSELISTENER_H