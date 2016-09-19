// taken from http://cplus.about.com/od/howtodothingsi2/a/timing.htm

#ifndef _HR_TIME_HPP
#define _HR_TIME_HPP

#ifdef WIN32

#include <windows.h>

/*
 * This class provides functionality to determine the elapsed time for an operation.
 */

typedef struct {
	LARGE_INTEGER start;
	LARGE_INTEGER stop;
} stopWatch;

class CStopWatch {

private:
	stopWatch timer;
	LARGE_INTEGER frequency;
	double LIToSecs( LARGE_INTEGER & L);

public:
	CStopWatch();
	void startTimer();
	void stopTimer();
	double getElapsedTime();
};

#endif

#endif // _HR_TIME_HPP