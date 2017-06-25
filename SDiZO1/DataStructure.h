#pragma once

#ifndef DATASTRUCTURE_HEADER
#define DATASTRUCTURE_HEADER
#include <string>

class DataStructure
{
public:
	virtual ~DataStructure() = default;
	virtual void PrintData() = 0;
	virtual void Add(int value, int index) = 0;
	virtual void Delete(int) = 0;
	virtual bool Search(int value) = 0;
	virtual int GetSize() = 0;
	virtual std::string GetStructureName() = 0;
};

#endif
