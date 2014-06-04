#ifndef TIMER_H
#define TIMER_H


#include <windows.h>



 
 
class Timer
{

 private:

	 LARGE_INTEGER timeFrequency;
	 LARGE_INTEGER lastStartTime;
	 LARGE_INTEGER deltaLastLap;
	

     double LIToSecs( LARGE_INTEGER & L) ;
	 
 public:
	Timer(); 	
	float deltaTime;

	float lastLapTime() const; //timeElapsedLastFrame
	bool Initialize();
	bool shutdown();	
	void Start();
	void Stop();
	void lap(); //newFrame

	float Interval();

	float FPS();
	float SPF();
};

#endif // !TIMER_H
