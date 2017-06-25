#include "BinaryHeap.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


int BinaryHeap::getLeftChild(int index)
{
	int result = 2 * index + 1;
		return result;

}

int BinaryHeap::getRightChild(int index)
{
	int result = 2 * index + 2;
		return result;

}

int BinaryHeap::getParent(int index)
{
	int result = (index - 1) / 2;

		return result;

}

void BinaryHeap::printBT(string sp, string sn, string cr, string cp, string cl, int v)
{
	string s;

	if (v < heapSize)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr,cr,cp,cl, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		cout << s << sn << array[v] << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl,cr,cp,cl, 2 * v + 1);
	}
}

BinaryHeap::BinaryHeap(int size)
{
	array = new int[size];
	this->size = size;
	heapSize = 0;
}

BinaryHeap::~BinaryHeap()
{
	delete [] array;
}

void BinaryHeap::PrintData()
{
	string cr, cl, cp;

	for(int i = 0; i < heapSize; i++)
	{
		cout << setw(8) << array[i];
	}
	cout << endl;

	cr = cl = cp = "  ";
	//cr = "┌─";
	//cl = "└─";
	//cp = "│ ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	printBT("", "", cr, cp, cl, 0);
}



void BinaryHeap::Add(int value, int index)
{
	if(heapSize == size)
	{
		int* temp = new int[heapSize + 1];
		for(int i = 0; i < heapSize; i++)
		{
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
		size++;
	}

	int parent;
	index = heapSize;
	parent = getParent(index);

	while(index > 0 && array[parent] < value)
	{
		array[index] = array[parent];
		index = parent;
		parent = getParent(index);
	}

	array[index] = value;

	heapSize++;
}

void BinaryHeap::Delete(int index)
{
	index = 0;																				  //Zawsze bedziemy usuwac 1 element
	int value, child;
	heapSize--;
	array[0] = array[heapSize];
	

	child = getLeftChild(index);
	value = array[0];
	while(child < heapSize)
	{
		if(child + 1 < heapSize && array[child + 1] > array[child])								// Wybor wiekszego dziecka
		{
			child++;
		}
		if(value > array[child])																//Czy wartosc juz jest w dobrym miejscu
		{
			break;
		}
		array[index] = array[child];															//Jesli nie to przejscie w dol
		index = child;
		child = getLeftChild(index);
	}
	array[index] = value;
}

bool BinaryHeap::Search(int value)
{		
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
			return true;
	}
	return false;
}

std::string BinaryHeap::GetStructureName()
{
	return "Kopiec";
}


int BinaryHeap::GetSize()
{
	return heapSize;
}

BinaryHeap* BinaryHeap::LoadDataFromFile(string path)
{
	int size, temp;
	BinaryHeap* structure = nullptr;
	fstream file;
	file.open(path, ios::in);

	if (file.is_open())
	{
		file >> size;
		if (file.fail())
		{
			cout << "FILE ERROR - READ SIZE" << endl;
			return nullptr;
		}
		else
		{
			structure = new BinaryHeap(size);
			for (int i = 0; i < size; i++)
			{
				file >> temp;
				if (file.fail())
				{
					cout << "FILE ERROR - READ DATA" << endl;
					return nullptr;
				}
				else
				{
					structure->Add(temp,i);
				}
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
