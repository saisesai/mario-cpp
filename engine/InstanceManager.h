#ifndef INSTANCEMANAGER_H
#define INSTANCEMANAGER_H

#include "Timer.h"
#include "Window.h"
#include "MouseListener.h"
#include "KeyboardListener.h"

class InstanceManager
{
public:
	InstanceManager();
	~InstanceManager();

private:
	Timer* timerInstance;
	Window* windowInstace;
	MouseListener* mouseListenerInstance;
	KeyboardListener* keyboardListenerInstance;
};

#endif //!INSTANCEMANAGER_H