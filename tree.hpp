#include "tree.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<typename T>
void Tree<T>::insertNode(T _data)
{
	Tree<T>* node = new Tree<T>(_data);
	Tree<T>* n;
	queue<Tree<T>*> q;
	q.push(this);
	while (1)
	{
		n = q.front();
		q.pop();
		if (n->left == NULL)
		{
			n->left = node;
			break;
		}
		if (n->right == NULL)
		{
			n->right = node;
			break;
		}
		q.push(n->left);
		q.push(n->right);
	}
}

bool isPower2(int n)
{
	while (n)
	{
		if (n % 2 == 1)
			return false;
		n /= 2;
		if (n == 1)
			return true;
	}
	return true;
}

template<typename T>
void Tree<T>::showTree()
{
	Tree<T>* node;
	queue<Tree<T>*> q;
	q.push(this);
	int i = 0, index = 0;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (node->left != NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
		cout << node->data << " ";
		i++;
		if (i == pow(2, index))
		{
			i = 0;
			index++;
			cout << endl;
		}
	}
}

template<typename T>
void Tree<T>::preorderRecursive()
{
	preorderHelper(this);
}

template<typename T>
void Tree<T>::preorder()
{
	stack<Tree<T>*> s;
	Tree<T>* n = this;
	while (!s.empty() || n)
	{
		while (n)
		{
			s.push(n);
			cout << "->" << n->data;
			n = n->left;
		}
		if (!s.empty())
		{
			n = s.top();
			s.pop();
			//cout << "->" << n->data;
			n = n->right;
		}
	}
}

template<typename T>
void Tree<T>::inorder()
{
	stack<Tree<T>*> s;
	Tree<T>* n = this;
	while (!s.empty() || n)
	{
		while (n)
		{
			s.push(n);
			//cout << "->" << n->data;
			n = n->left;
		}
		if (!s.empty())
		{
			n = s.top();
			s.pop();
			cout << "->" << n->data;
			n = n->right;
		}
	}
}

template<typename T>
void Tree<T>::postorder()
{
	stack<Tree<T>*> s;
	Tree<T>* n = this;

	while (!s.empty() || n)
	{
		while (n)
		{
			s.push(n);
			n->first = 1;
			n = n->left;
		}
		if (!s.empty())
		{
			n = s.top();
			s.pop();
			if (n->first)
			{
				n->first = false;
				s.push(n);
				n = n->right;
			}
			else
			{
				cout << "->" << n->data;
				n = NULL;
			}
		}
	}
}

template<typename T>
void Tree<T>::preorderHelper(Tree<T>*n)
{
	if (n)
	{
		cout << "->" << n->data;
		preorderHelper(n->left);
		preorderHelper(n->right);
	}
}

