#include <Windows.h>
#include "Timer.h"
#include <fstream>
#include "DataStructure.h"
using namespace std;

long long Timer::ReadQPC()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return ((long long int)  start.QuadPart);
}

void Timer::SaveToCsv(string operation,DataStructure* data, double result)
{
	string path = data->GetStructureName() + ".csv";
	ofstream file;

	if(!ifstream(path))
	{
		file.open(path, ios_base::app);
		file << "Operacja:;" << "Wielkosc strukutry:;" << "Czas[us];" << "\n";
		file << operation + ";" << std::to_string(data->GetSize()) + ";" << fixed << result << "\n";
	}
	else
	{
		file.open(path, ios_base::app);
		file << operation + ";" << std::to_string(data->GetSize()) + ";" << fixed << result << "\n";
	}

	file.close();

}

double Timer::GetElapsedTime(long long start, long long stop)
{
	long long int elapsed, freq;
	elapsed = stop - start;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	return (1000000.0 * elapsed) / freq;
}


