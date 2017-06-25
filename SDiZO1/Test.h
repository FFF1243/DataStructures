#pragma once

#ifndef TEST_HEADER
#define TEST_HEADER
#include "DataStructure.h"

class Test
{
public:
	static std::string PATH;
	static void AddToEnd(std::string structureName, int size);
	static void AddToBeginning(std::string structureName, int size);
	static void Add(std::string structureName, int size);
	static void DeleteFromEnd(std::string structureName, int size);
	static void DeleteFromBegining(std::string structureName, int size);
	static void Delete(std::string structureName, int size);
	static void Search(std::string structureName, int size);
	static void DSW(int size);
	static void Rotate(int size);
	static void GenerateRandomNumbers(int size);					// Metoda generujaca losowe liczby (ilosc - size) - zapisuje je w plikach w folderze o sciezce PATH						
};

#endif