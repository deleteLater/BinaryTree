// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	Node<char> *root = new Node<char>('A');
	BinaryTree<char> bt(root, BUILD_MODEL::BY_FILE_DATA);
	cout << "层序遍历结果:";
	bt.SeqentialOrderTraversal();

	cout << endl;
	system("pause");
	return 0;
}