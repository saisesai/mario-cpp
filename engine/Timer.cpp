#include "Timer.h"

#include <GLFW/glfw3.h>
#include <plog/Log.h>

Timer::Timer()
{
	PLOG(plog::info) << "start create Timer instance...";

	this->timeStarted = (float)glfwGetTime();

	PLOG(plog::info) << "timer instance created successful!";
}

Timer::~Timer()
{
}

Timer* Timer::GetInstance()
{
	extern Timer* TimerInstance;
	if (TimerInstance == nullptr)
	{
		TimerInstance = new Timer();
	}
	return TimerInstance;
}

float Timer::GetTime()
{
	return (float)(glfwGetTime() - this->timeStarted);
}