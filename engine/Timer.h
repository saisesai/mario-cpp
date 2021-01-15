#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:
	Timer();
	~Timer();
	
	float GetTime();

	static Timer* GetInstance();
	

private:
	float timeStarted;
};

static Timer* TimerInstance = nullptr;

#endif // !TIMER_H
