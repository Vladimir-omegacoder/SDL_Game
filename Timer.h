#pragma once
#ifndef TIMER_CLASS
#define TIMER_CLASS

#include "SDL.h"



class Timer
{

public:

	Timer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 getTicks();

	bool isStarted();
	bool isPaused();

private:

	Uint32 startTicks;
	Uint32 pausedTicks;

	bool paused;
	bool started;

};

#endif