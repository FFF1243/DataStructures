#include "Array.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void Array::addToBeginning(int value)
{
	size++;
	int *temp = new int[size];
	temp[0] = value;
	for(int i = 1; i < size; i++)
	{
		temp[i] = array[i - 1];
	}
	delete[] array;
	array = temp;
}

void Array::addToEnd(int value)
{
	size++;
	int* temp = new int[size];
	for(int i = 0; i < size; i++)
	{
		temp[i] = array[i];
	}
	temp[size - 1] = value;
	delete[] array;
	array = temp;
}

Array::Array(int s)
{
	size = s > 0 ? s : 0;
	array = new int[size];
}

Array::~Array()
{
	delete [] array;
	array = nullptr;
}

int Array::GetSize()
{
	return size;
}

void Array::PrintData()
{
	if(size == 0)
	{
		cout << "Nie ma zadnych elementow w strukturze" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << setw(8) << array[i];
		}
		cout << endl;
	}
}

void Array::Add(int value, int index)
{
	if(index == size - 1)
	{
		addToEnd(value);
	}
	else if(index == 0)
	{
		addToBeginning(value);
	}
	else
	{
		size++;
		int* temp = new int[size];
		for(int i = 0; i < index; i++)
		{
			temp[i] = array[i];
		}
		temp[index] = value;
		for(int i = index + 1; i < size; i++)
		{
			temp[i] = array[i - 1];
		}
		delete [] array;
		array = temp;
	}
}

void Array::Delete(int index)
{
	size--;
	int* temp = new int[size];
	for(int i = 0; i < index; i++)
	{
		temp[i] = array[i];
	}
	for(int i = index; i < size; i++)
	{
		temp[i] = array[i + 1];
	}
	delete[] array;
	array = temp;
}

bool Array::Search(int value)
{
	for(int i =0; i < size; i++)
	{
		if(array[i] == value)
		{
			return true;
		}
	}
	return false;
}

string Array::GetStructureName()
{
	return "Tablica";
}

Array * Array::LoadDataFromFile(string path)
{
	int temp;
	Array* structure = nullptr;
	fstream file;
	file.open(path, ios::in);

	if (file.is_open())
	{
		file >> temp;
		if (file.fail())
		{
			cout << "FILE ERROR - READ SIZE" << endl;
			return nullptr;
		}
		else
		{
			structure = new Array(temp);
			for (int i = 0; i < structure->size; i++)
			{
				file >> temp;
				if (file.fail())
				{
					cout << "FILE ERROR - READ DATA" << endl;
					return nullptr;
				}
				structure->array[i] = temp;
			}
		}
		file.close();
	}
	else
	{
		cout << "FILE ERROR - OPEN FILE" << endl;
	}

	return structure;
}

