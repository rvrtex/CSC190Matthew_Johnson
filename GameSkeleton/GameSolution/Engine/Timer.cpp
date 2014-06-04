#include "Timer.h"


Timer::Timer()
{
	

}

bool Timer::Initialize()
{
	 
	if(QueryPerformanceFrequency(&timeFrequency))
		return false;
	if(QueryPerformanceCounter(&lastStartTime))
	{
		return true;
	}
	else
	{
	return false;
	}

};

bool Timer::shutdown()
{
	return true;
}

void Timer::Start()
{
	QueryPerformanceCounter(&lastStartTime);


};

void Timer::Stop()
{
	LARGE_INTEGER thisTime;
	QueryPerformanceCounter(&thisTime);
	LARGE_INTEGER delta;
	delta.QuadPart = thisTime.QuadPart - lastStartTime.QuadPart;
	deltaTime = ((float)delta.QuadPart) / timeFrequency.QuadPart;
	deltaLastLap.QuadPart = thisTime.QuadPart;
}

void Timer::lap()
{
	Stop();
	Start();

};

float Timer::lastLapTime() const
{
	return deltaTime;
}




float Timer::Interval()
{
	LARGE_INTEGER thisTime;
	QueryPerformanceCounter(&thisTime);
	LARGE_INTEGER lastInterval;
	lastInterval.QuadPart = thisTime.QuadPart - lastStartTime.QuadPart;
	deltaTime = ((float)lastInterval.QuadPart/timeFrequency.QuadPart);
	deltaLastLap.QuadPart = thisTime.QuadPart;
	return deltaTime;
};

float SPF()
{

	return -1;

};

float FPS()
{
	return -1;

};