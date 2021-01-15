#include "InstanceManager.h"

#include <plog/Log.h>

InstanceManager::InstanceManager()
{
	PLOG(plog::info) << "start create instance manager...";

	this->windowInstace = Window::GetInstance();
	PLOG(plog::info) << "window instace pointer:" << this->windowInstace;
	this->mouseListenerInstance = MouseListener::GetInstance();
	PLOG(plog::info) << "mouse listener instance pointer:" << this->mouseListenerInstance;
	this->keyboardListenerInstance = KeyboardListener::GetInstance();
	PLOG(plog::info) << "keyboard listener instance pointer:" << this->keyboardListenerInstance;
	this->timerInstance = Timer::GetInstance();
	PLOG(plog::info) << "timer instance pointer:" << this->timerInstance;
	PLOG(plog::info) << "time:" << Timer::GetInstance()->GetTime();

	PLOG(plog::info) << "create instance manager successful!";
}

InstanceManager::~InstanceManager()
{
	delete this->timerInstance;
	delete this->windowInstace;
	delete this->mouseListenerInstance;
	delete this->keyboardListenerInstance;
}