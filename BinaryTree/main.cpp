// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	Node<char> *root = new Node<char>('A');
	BinaryTree<char> bt(root);
	cout << "height: " << bt.height();
	//cout << "\n***A**";
	//cout << "\n**/*\\*";
	//cout << "\n*B***C\n";

	system("pause");
	return 0;
}