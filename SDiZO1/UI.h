#pragma once
#ifndef UI_HEADER
#define UI_HEADER
#include "DataStructure.h"
#include <string>


class UI
{
private:
	static int ShowArrayAndListFunctionsMenu();
	static int ShowHeapFunctionsMenu();
	static int ShowBSTFunctionsMenu();
	static void ArrayAndListMenu(DataStructure* data);
	static void HeapMenu(DataStructure* data);
	static void BSTMenu(DataStructure *data);
public:
	static int ShowMainMenu();
	static void Start();
	static int ReadValue();
	static int ReadIndex(int max);
};

#endif