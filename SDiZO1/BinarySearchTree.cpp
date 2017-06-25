#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
using namespace std;


BSTNode* BinarySearchTree::findNodeByValue(int value)
{
	BSTNode *ptr = root;

	while (ptr && ptr->Number != value)
	{
		if (ptr->Number > value)
		{
			ptr = ptr->Left;
		}
		else
		{
			ptr = ptr->Right;
		}
	}

	return ptr;
}

BSTNode* BinarySearchTree::findMinNode(BSTNode* node)
{
	if(node)
	{
		while (node->Left)
			node = node->Left;
	}
	return node;
}

BSTNode* BinarySearchTree::findSuccesor(BSTNode* node)
{
	BSTNode* ptr;
	if(node)																		
	{
		if(node->Right)																// Jesli wezel posiada prawego syna to nastepnikiem jest wezel
		{																			// o minimalnym kluczu z prawego poddrzewa
			return findMinNode(node->Right);
		}
		else																		// ptr wskazuje na ojca node, poruszamy sie w gore drzewa az trafimy
		{																			// na wezel dla ktorego node lezy w lewym poddrzewie
			ptr = node->Up;
			while(ptr && (node == ptr->Right))
			{
				node = ptr;
				ptr = ptr->Up;
			}
			return ptr;
		}
	}
	return node;
}

void BinarySearchTree::rotateLeft(BSTNode* node)
{
	BSTNode* rightChild = node->Right;
	BSTNode* parent = node->Up;

	if (rightChild)
	{
		node->Right = rightChild->Left;
		if (node->Right)
		{
			node->Right->Up = node;
		}
		rightChild->Left = node;
		rightChild->Up = parent;
		node->Up = rightChild;

		if (parent)
		{
			if (parent->Left == node)
				parent->Left = rightChild;
			else
				parent->Right = rightChild;
		}
		else
		{
			root = rightChild;
		}
	}
}

void BinarySearchTree::rotateRight(BSTNode* node)
{
	BSTNode* leftChild = node->Left;
	BSTNode* parent = node->Up;

	if (leftChild)
	{
		node->Left = leftChild->Right;
		if (node->Left)
		{
			node->Left->Up = node;
		}
		leftChild->Right = node;
		leftChild->Up = parent;
		node->Up = leftChild;

		if (parent)
		{
			if (parent->Left == node)
				parent->Left = leftChild;
			else
				parent->Right = leftChild;
		}
		else
		{
			root = leftChild;
		}
	}
}


void BinarySearchTree::DswBalance()
{
	BSTNode* ptr = root;
	int rotatesNeeded;
	while(ptr)
	{
		if(ptr->Left)
		{
			rotateRight(ptr);
			ptr = ptr->Up;
		}
		else
		{
			ptr = ptr->Right;
		}
	}


	rotatesNeeded = size + 1 - pow(2, floor(log2(size + 1)));
	ptr = root;
	for(int i = 0; i < rotatesNeeded; i++)
	{
		rotateLeft(ptr);
		ptr = ptr->Up->Right;	
	}


	rotatesNeeded = size - rotatesNeeded;
	while(rotatesNeeded > 1)
	{
		rotatesNeeded >>= 1;
		ptr = root;
		for(int i = 0; i < rotatesNeeded; i++)
		{
			rotateLeft(ptr);
			ptr = ptr->Up->Right;
		}
	}

}

void BinarySearchTree::printBT(std::string sp, std::string sn, BSTNode* v)
{
	string s, sr, cl, cr, cp;

	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;

	if (v)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		printBT(s + cp, cr, v->Right);

		s = s.substr(0, sp.length() - 2);
		cout << s << sn << v->Number << endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		printBT(s + cp, cl, v->Left);
	}
}

BinarySearchTree::BinarySearchTree()
{
	root = new BSTNode();
	size = 0;
}

BinarySearchTree::BinarySearchTree(int value)
{
	size = 1;
	root = new BSTNode(nullptr, nullptr, nullptr, value);

}

BinarySearchTree::~BinarySearchTree()
{
	delete root;
}

bool BinarySearchTree::RotateLeft(int value)
{
	BSTNode* node = findNodeByValue(value);
	if(node)
	{
		rotateLeft(node);
		return true;
	}
	else
	{
		return false;
	}
}

bool BinarySearchTree::RotateRight(int value)
{
	BSTNode* node = findNodeByValue(value);
	if (node)
	{
		rotateRight(node);
		return true;
	}
	else
	{
		return false;
	}
}

void BinarySearchTree::PrintData()
{
	printBT("", "", root);
}

void BinarySearchTree::Add(int value, int index)
{
	BSTNode* node = new BSTNode(nullptr, nullptr, nullptr, value);
	BSTNode* ptr = root;

	if (root == nullptr)
	{
		root = node;
	}
	else
	{
		while (true)
		{
			if (value < ptr->Number)
			{
				if(ptr->Left == NULL)
				{
					ptr->Left = node;
					break;
				}
				else
				{
					ptr = ptr->Left;
				}
			}
			else
			{
				if(ptr->Right == NULL)
				{
					ptr->Right = node;
					break;
				}
				else
				{
					ptr = ptr->Right;
				}
			}
		}
	}
	node->Up = ptr;
	size++;
		
}

void BinarySearchTree::Delete(int value)
{
	BSTNode* node = findNodeByValue(value);
	if (!node)
		return;

	BSTNode* deleteNode;													//deleteNode wskazuje na wezel do usuniecia
	BSTNode* child;														//child wskazuje na syna deleteNode jesti istnieje, w przeciwnym wypadku null

	if(node->Left == nullptr || node->Right == nullptr)
		deleteNode = node;													//Jesli wezel jest lisciem 
	else
		deleteNode = findSuccesor(node);

	if(deleteNode->Left != nullptr)										// Ustawienie wskazania na dziecko deleteNode (lub null jesli nie ma)
		child = deleteNode->Left;
	else
		child = deleteNode->Right;

	if(child)															//Jesli dziecko deleteChild istnieje to zajmie jego miejsce
		child->Up = deleteNode->Up;

	if (deleteNode->Up == nullptr)										//Jesli usuwany wezel jest korzeniem - ustawienie dziecka jako korzenia
		root = child;
	else if (deleteNode == deleteNode->Up->Left)						//Child zastepuje w drzewie deleteNode
		deleteNode->Up->Left = child;
	else
		deleteNode->Up->Right = child;

	if (deleteNode != node)												//Jesli usuwany wezel jest nastepnikiem wezla node (przenosimy wartosci w gore drzewa)
		node->Number = deleteNode->Number;								//Zamiana wartosci

	delete deleteNode;													//Ostatecznie usuniecie wezla

	size--;
}

bool BinarySearchTree::Search(int value)
{
	BSTNode *ptr = root;

	while(ptr && ptr->Number != value)
	{
		if(ptr->Number > value)
		{
			ptr = ptr->Left;
		}
		else
		{
			ptr = ptr->Right;
		}
	}
	if(ptr == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int BinarySearchTree::GetSize()
{
	return size;
}

std::string BinarySearchTree::GetStructureName()
{
	return "Drzewo binarnych poszukiwan";
}

BinarySearchTree* BinarySearchTree::LoadDataFromFile(std::string path)
{
	int size, temp;
	BinarySearchTree* structure = nullptr;
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

			for (int i = 0; i < size; i++)
			{
				file >> temp;
				if (file.fail())
				{
					cout << "FILE ERROR - READ DATA" << endl;
					return nullptr;
				}
				if(i == 0)
				{
					structure = new BinarySearchTree(temp);
				}
				else
				{
					structure->Add(temp, 0);
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

BSTNode::BSTNode(BSTNode* up, BSTNode* left, BSTNode* right, int num)
{
	Up = up;
	Left = left;
	Right = right;
	Number = num;
}

BSTNode::BSTNode()
{
	Up = nullptr;
	Left = nullptr;
	Right = nullptr;
	Number = NULL;
}

BSTNode::~BSTNode()
{
}



