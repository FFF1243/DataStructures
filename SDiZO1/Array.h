#pragma once
#ifndef ARRAY_HEADER
#define ARRAY_HEADER

#include "DataStructure.h"
#include <string>
using namespace std;

class Array : public DataStructure
{
private:
	int size;
	int* array;
	void addToBeginning(int x);
	void addToEnd(int x);

public:
	Array(int s = 0);
	~Array();
	int GetSize();
	void PrintData();
	void Add(int x, int index);
	void Delete(int index);
	bool Search(int value);
	string GetStructureName();
	static Array* LoadDataFromFile(string path);

};

#endif

