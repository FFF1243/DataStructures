#include "Test.h"
#include "Timer.h"
#include <Windows.h>
#include <random>
#include <fstream>
#include "Array.h"
#include "DoublyLinkedList.h"
#include "BinaryHeap.h"
#include "BinarySearchTree.h"
using namespace std;

string Test::PATH = "C:\\Users\\sebas\\OneDrive\\Dokumenty\\Visual Studio 2015\\Projects\\SDiZO1\\SDiZO1\\Nowe\\";

void Test::AddToEnd(string structureName, int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, size);
	long long int start, stop;
	int number = distribution(generator);
	DataStructure* structure;
	string path;
	for(int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		if (structureName == "Tablica")
		{
			structure = Array::LoadDataFromFile(path.c_str());
		}
		else if(structureName == "Lista")
		{
			structure = DoublyLinkedList::LoadDataFromFile(path.c_str());
		}
		else if(structureName == "Kopiec")
		{
			structure = BinaryHeap::LoadDataFromFile(path.c_str());
		}
		else
		{
			structure = BinarySearchTree::LoadDataFromFile(path.c_str());
		}
		start = Timer::ReadQPC();
		structure->Add(number, size - 1);
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("Dodawanie na koncu", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
}

void Test::AddToBeginning(string structureName, int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, INT_MAX);
	long long int start, stop;
	int number = distribution(generator);
	DataStructure* structure = nullptr;
	string path;
	for (int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		if (structureName == "Tablica")
		{
			structure = Array::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Lista")
		{
			structure = DoublyLinkedList::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Kopiec")
		{
			structure = BinaryHeap::LoadDataFromFile(path.c_str());
		}
		else
		{
			structure = BinarySearchTree::LoadDataFromFile(path.c_str());
		}
		start = Timer::ReadQPC();
		structure->Add(number, 0);
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("Dodawanie na poczatku", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
}

void Test::Add(string structureName, int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 1000000);
	int index = distribution(generator);
	long long int start, stop;
	DataStructure *structure = nullptr;
	int number = distribution(generator);
	string path;
	for (int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		if (structureName == "Tablica")
		{
			structure = Array::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Lista")
		{
			structure = DoublyLinkedList::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Kopiec")
		{
			structure = BinaryHeap::LoadDataFromFile(path.c_str());
		}
		else
		{
			structure = BinarySearchTree::LoadDataFromFile(path.c_str());
			((BinarySearchTree*)structure)->DswBalance();
		}
		start = Timer::ReadQPC();
		structure->Add(number, index);
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("Dodawanie w srodku", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
}

void Test::DeleteFromEnd(string structureName, int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, size - 2);
	long long int start, stop;
	int number = distribution(generator);
	DataStructure* structure = nullptr;
	string path;
	for (int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		if (structureName == "Tablica")
		{
			structure = Array::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Lista")
		{
			structure = DoublyLinkedList::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Kopiec")
		{
			structure = BinaryHeap::LoadDataFromFile(path.c_str());
		}
		else
		{
			structure = BinarySearchTree::LoadDataFromFile(path.c_str());
		}
		start = Timer::ReadQPC();
		structure->Delete(size - 1);
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("Usuwanie z konca", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
}

void Test::DeleteFromBegining(string structureName, int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, size - 2);
	long long int start, stop;
	int number = distribution(generator);
	DataStructure* structure = nullptr;
	string path;
	for (int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		if (structureName == "Tablica")
		{
			structure = Array::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Lista")
		{
			structure = DoublyLinkedList::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Kopiec")
		{
			structure = BinaryHeap::LoadDataFromFile(path.c_str());
		}
		else
		{
			structure = BinarySearchTree::LoadDataFromFile(path.c_str());
		}
		start = Timer::ReadQPC();
		structure->Delete(0);
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("Usuwanie z poczatku", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
}

void Test::Delete(string structureName, int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, size - 2);
	int index = distribution(generator);
	long long int start, stop;
	DataStructure *structure = nullptr;
	int number = distribution(generator);
	string path;
	for (int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		if (structureName == "Tablica")
		{
			structure = Array::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Lista")
		{
			structure = DoublyLinkedList::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Kopiec")
		{
			structure = BinaryHeap::LoadDataFromFile(path.c_str());
		}
		else
		{
			structure = BinarySearchTree::LoadDataFromFile(path.c_str());
			std::uniform_int_distribution<int> distributionValue(0, 1000000);						// Usuwanie po wartosci dla BST
			index = distributionValue(generator);
		}
		start = Timer::ReadQPC();
		structure->Delete(index);
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("Usuwanie ze srodka", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
	
}

void Test::Search(string structureName, int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, size);
	long long int start, stop;
	int number = distribution(generator);
	DataStructure* structure = nullptr;
	string path;
	for (int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		if (structureName == "Tablica")
		{
			structure = Array::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Lista")
		{
			structure = DoublyLinkedList::LoadDataFromFile(path.c_str());
		}
		else if (structureName == "Kopiec")
		{
			structure = BinaryHeap::LoadDataFromFile(path.c_str());
		}
		else
		{
			structure = BinarySearchTree::LoadDataFromFile(path.c_str());
		}
		start = Timer::ReadQPC();
		structure->Search(number);
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("Wyszukiwanie", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
}

void Test::DSW(int size)
{
	long long int start, stop;
	BinarySearchTree* structure = nullptr;
	string path;
	for (int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		structure = BinarySearchTree::LoadDataFromFile(path);

		start = Timer::ReadQPC();
		structure->DswBalance();
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("DSW", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
}

void Test::Rotate(int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 100);
	long long int start, stop;
	int number = distribution(generator);
	BinarySearchTree* structure = nullptr;
	string path;
	for (int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size) + "\\";
		path.append(std::to_string(i) + ".txt");
		
		structure = BinarySearchTree::LoadDataFromFile(path);

		start = Timer::ReadQPC();
		structure->RotateLeft(number);
		stop = Timer::ReadQPC();
		Timer::SaveToCsv("Rotacja", structure, Timer::GetElapsedTime(start, stop));

		delete structure;
	}
}


void Test::GenerateRandomNumbers(int size)
{
	fstream file;
	string path =  "C:\\Users\\sebas\\OneDrive\\Dokumenty\\Visual Studio 2015\\Projects\\SDiZO1\\SDiZO1\\" +std::to_string(size);
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 1000000);
	int number;
	for(int i = 0; i < 100; i++)
	{
		path = PATH + std::to_string(size);
		path.append("\\" + std::to_string(i) + ".txt");
		file.open(path.c_str(), ios::out);
		if(file.good())
		{
			for (int j = 0; j < size; j++)
			{
				if (j == 0)
				{
					file << size << endl;
				}
				number = distribution(generator);
				file << number << "\t";
			}
			file.close();
		}

	}
}



