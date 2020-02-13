#include <iostream>
#include "tree.hpp"

using namespace std;

int main()
{
	int i;
	Tree<int> bt;
	bt.insertNode(1);
	bt.insertNode(2);
	bt.insertNode(3);
	bt.insertNode(4);
	bt.insertNode(5);
	bt.insertNode(6);
	bt.insertNode(7);
	bt.insertNode(8);
	bt.showTree();
	bt.postorder();

	return 0;
}

