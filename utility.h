#ifndef _UTILITY_H
#define _UTILITY_H

#include <time.h>

#ifdef _WIN32
#include <windows.h>

/*
 * Do not forget to initialize the clock so the timer would work.
 */
double frequency;
void initClock()
{
	LARGE_INTEGER _frequency;
	QueryPerformanceFrequency(&_frequency);
	frequency = (double)_frequency.QuadPart;
}

double millis()
{
	LARGE_INTEGER _count;
	QueryPerformanceCounter(&_count);
	double count = (double)_count.QuadPart;
	return count / frequency * 1000.0;
}

#else

/* clock() is found to have lower precision than the time APIs provided by operating systems */

void initClock() {}

double millis()
{
	return (double)clock() / CLOCKS_PER_SEC * 1000.0;
}

#endif

void initRandom()
{
	srand(time(NULL));
}

int random()
{
	return rand() | rand() << 15;
}

#endif
