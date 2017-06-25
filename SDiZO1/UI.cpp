#include "UI.h"
#include <iostream>
#include "Array.h"
#include <Windows.h>
#include "DoublyLinkedList.h"
#include "Timer.h"
#include "BinaryHeap.h"
#include "BinarySearchTree.h"


int UI::ShowMainMenu()
{
	int a;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		cout << "Wybierz strukture: " << endl
			<< "1. Tablica " << endl
			<< "2. Lista dwukierunkowa" << endl
			<< "3. Kopiec binarny" << endl
			<< "4. Drzewo poszukiwan binarnych." << endl;

		cin >> a;

	} while (cin.fail() || a > 4 || a < 0 );


	return a;
}

int UI::ShowArrayAndListFunctionsMenu()
{
	int a;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << "Wybierz operacje " << endl
			<< "1. Dodaj na poczatek " << endl
			<< "2. Dodaj w srodku (wartosc index) " << endl
			<< "3. Dodaj na koniec" << endl
			<< "4. Usun" << endl
			<< "5. Wyszukaj" << endl
			<< "6. Pokaz zawartosc" << endl
			<< "7. Wyjscie" << endl;

		cin >> a;

	} while (a > 7 || a < 1 || cin.fail());
	return a;
}

int UI::ShowHeapFunctionsMenu()
{
	int a;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		cout << "Wybierz operacje " << endl
			<< "1. Dodaj" << endl
			<< "2. Usun" << endl
			<< "3. Wyszukaj" << endl
			<< "4. Pokaz zawartosc" << endl
			<< "5. Wyjscie" << endl;

		cin >> a;

	} while (a > 5 || a < 1 || cin.fail());
	return a;
}

int UI::ShowBSTFunctionsMenu()
{
	int a;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		cout << "Wybierz operacje " << endl
			<< "1. Dodaj" << endl
			<< "2. Usun" << endl
			<< "3. Wyszukaj" << endl
			<< "4. Pokaz zawartosc" << endl
			<< "5. Rownowaz drzewo " << endl
			<< "6. Rotacja w prawo" << endl
			<< "7. Rotacja w lewo" << endl
			<< "8. Wyjscie" << endl;

		cin >> a;

	} while (a > 8 || a < 1 || cin.fail());
	return a;
}


void UI::ArrayAndListMenu(DataStructure* data)
{
	int value, index, function;
	do
	{
		function = ShowArrayAndListFunctionsMenu();
		switch (function)
		{
		case 1:
		{
			value = ReadValue();
			data->Add(value, 0);
			break;
		}
		case 2:
		{
			value = ReadValue();
			index = ReadIndex(data->GetSize() - 1);
			data->Add(value, index);
			
			
			break;
		}
		case 3:
		{
			value = ReadValue();
			data->Add(value, data->GetSize() - 1);

			break;
		}
		case 4:
		{
			index = ReadIndex(data->GetSize() - 1);
			data->Delete(index);
			break;
		}
		case 5:
		{
			value = ReadValue();
			if(data->Search(value))
			{
				cout << "Wartosc znajduje sie w strukturze" << endl;
			}
			else
			{
				cout << "Nie znaleziono tej wartosci" << endl;
			}
			break;
		}
		case 6:
		{
			data->PrintData();
			break;
		}
		case 7:
		{
			delete data;
			return;
		}
		default:
		{
			cout << "ERROR" << endl;
			break;
		}
		}
	} while (true);
}

void UI::BSTMenu(DataStructure* data)
{
	int value, function;
	do
	{
		function = ShowBSTFunctionsMenu();
		switch (function)
		{
		case 1:
		{
			value = ReadValue();
			data->Add(value, 0);
			break;
		}
		case 2:
		{
				value = ReadValue();
				data->Delete(value);
			break;
		}
		case 3:
		{
			value = ReadValue();
			if (data->Search(value))
			{
				cout << "Wartosc znajduje sie w strukturze" << endl;
			}
			else
			{
				cout << "Nie znaleziono tej wartosci" << endl;
			}
		}
		case 4:
		{
			data->PrintData();
			break;
		}
		case 5:
		{
			static_cast<BinarySearchTree*>(data)->DswBalance();
			break;
		}
		case 6:
		{
			value = ReadValue();
			if(!static_cast<BinarySearchTree*>(data)->RotateRight(value))
			{
				cout << "W drzewie nie ma takiej wartosci" << endl;
			}
			break;
		}
		case 7:
		{
			value = ReadValue();
			if(!static_cast<BinarySearchTree*>(data)->RotateLeft(value))
			{
				cout << "W drzewie nie ma takiej wartosci" << endl;
			}
			break;
		}
		case 8:
		{
			delete data;
			return;
		}
		default:
		{
			cout << "ERROR" << endl;
			break;
		}
		}
	} while (true);
}

void UI::HeapMenu(DataStructure* data)
{
	int value, function;
	do
	{
		function = ShowHeapFunctionsMenu();
		switch (function)
		{
			case 1:
			{
				value = ReadValue();
				data->Add(value, 0);
				break;
			}
			case 2:
			{
				data->Delete(0);
				break;
			}
			case 3:
			{
				value = ReadValue();
				if(data->Search(value))
				{
					cout << "Wartosc znajduje sie w strukturze" << endl;
				}
				else
				{
					cout << "Nie znaleziono tej wartosci" << endl;
				}
			}
			case 4:
			{
				data->PrintData();
				break;
			}
			
			case 5:
			{
				//delete data;
				return;
			}
			default:
			{
				cout << "ERROR" << endl;
				break;
			}
		}
	} while (true);
}

void UI::Start()
{
	DataStructure* data = nullptr;

	int structure = ShowMainMenu();
	switch(structure)
	{
		case 1:
		{
			data = Array::LoadDataFromFile("Text.txt");
			if(data)
				ArrayAndListMenu(data);
			break;
		}
		case 2:
		{
			data = DoublyLinkedList::LoadDataFromFile("Text.txt");
			if(data)
				ArrayAndListMenu(data);
			break;
		}
		case 3:
		{
			data = BinaryHeap::LoadDataFromFile("Text.txt");
			if(data)
				HeapMenu(data);
			break;
		}
		case 4:
		{
			data = BinarySearchTree::LoadDataFromFile("Text.txt");
			if(data)
				BSTMenu(data);
			break;
		}
		default:
		{
			break;
		}
	}

	if (!data)
	{
		cout << "ERROR LOADING DATA" << endl;
		cin.get();
		cin.ignore();
	}

	
}

int UI::ReadValue()
{
	int val;

	do
	{
		if (cin.fail())
		{
			cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		cout << "Podaj wartosc: ";
		cin.clear();
		cin.sync();
		cin >> val;

	} while (cin.fail());

	return val;
}

int UI::ReadIndex(int max)
{
	int val;
	do
	{
		if (cin.fail())
		{
			cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
		cout << "Podaj index [0; wielkosc - 1]: ";
		cin.clear();
		cin.sync();
		cin >> val;

	} while (cin.fail() || val < 0 || val > max);

	return val;
}



