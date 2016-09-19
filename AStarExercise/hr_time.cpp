// taken from http://cplus.about.com/od/howtodothingsi2/a/timing.htm
#ifdef WIN32
#include <windows.h>

#include "hr_time.hpp"

double CStopWatch::LIToSecs( LARGE_INTEGER & L) {
	return ((double)L.QuadPart /(double)frequency.QuadPart) ;
}

CStopWatch::CStopWatch(){
	timer.start.QuadPart=0;
	timer.stop.QuadPart=0; 
	QueryPerformanceFrequency( &frequency ) ;
}

void CStopWatch::startTimer( ) {
	QueryPerformanceCounter(&timer.start) ;
}

void CStopWatch::stopTimer( ) {
	QueryPerformanceCounter(&timer.stop) ;
}

double CStopWatch::getElapsedTime() {
	LARGE_INTEGER time;
	time.QuadPart = timer.stop.QuadPart - timer.start.QuadPart;
	return LIToSecs( time) ;
}
#endif