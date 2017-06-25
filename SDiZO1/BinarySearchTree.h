#pragma once
#include <string>
#include "DataStructure.h"

#ifndef BST_TREE_HEADER
#define BST_TREE_HEADER

class BSTNode;

class BinarySearchTree : public DataStructure
{
private:
	BSTNode* root;
	int size;
	BSTNode* findNodeByValue(int value);
	BSTNode* findMinNode(BSTNode *node);
	BSTNode* findSuccesor(BSTNode* node);
	void rotateLeft(BSTNode* node);
	void rotateRight(BSTNode* node);
	void printBT(std::string sp, std::string sn, BSTNode * v);					//Zrodlo: eduinf.waw.pl/inf/alg/001_search/0115.php
public:
	BinarySearchTree();
	BinarySearchTree(int value);
	~BinarySearchTree();
	bool RotateLeft(int value);
	bool RotateRight(int value);
	void PrintData();
	void Add(int value, int index = 0);
	void Delete(int value);
	bool Search(int value);
	int GetSize();
	std::string GetStructureName();
	static BinarySearchTree* LoadDataFromFile(std::string path);
	void DswBalance();
};

class BSTNode
{
public:
	BSTNode(BSTNode* up, BSTNode* left, BSTNode* right, int num);
	BSTNode();
	~BSTNode();
	BSTNode* Up;
	BSTNode* Left;
	BSTNode* Right;
	int Number;
};
#endif
