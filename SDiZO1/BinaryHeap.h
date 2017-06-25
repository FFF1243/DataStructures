#pragma once
#include "DataStructure.h"
#include <string>

#ifndef BINARY_HEAP_HEADER
#define BINARY_HEAP_HEADER
class BinaryHeap : public DataStructure
{
private:
	int* array;
	int heapSize;
	int size;
	int getLeftChild(int index);
	int getRightChild(int index);
	int getParent(int index);
	void printBT(std::string sp, std::string sn, std::string cr, std::string cp, std::string cl, int v);		// Zrodlo: eduinf.waw.pl/inf/alg/001_search/0113.php
public:
	BinaryHeap(int size = 0);
	~BinaryHeap();
	void PrintData();
	void Add(int value, int index);
	void Delete(int index = 0);
	bool Search(int value);
	std::string GetStructureName();
	int GetSize();
	static BinaryHeap* LoadDataFromFile(std::string path);
};
#endif
