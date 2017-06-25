#pragma once
#ifndef TIMER_HEADER
#define TIMER_HEADER
#include <string>
#include "DataStructure.h"

class Timer
{

public:
	static long long ReadQPC();
	static void SaveToCsv(std::string operation ,DataStructure* data, double result);
	static double GetElapsedTime(long long start, long long stop);
};

#endif