#pragma once
#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class Tree
{
private:
	T data;
	Tree<T>* left;
	Tree<T>* right;
	bool first;

	bool isLeaf()
	{
		if (left == NULL && right == NULL)
			return true;
		return false;
	}
	void preorderHelper(Tree<T>*);
public:
	inline Tree():data(0),left(NULL),right(NULL){}
	inline Tree(T _data):data(_data){}
 
	void insertNode(T _data);

	void showTree();

	void preorderRecursive();
	void preorder();
	void inorder();
	void postorder();
};

