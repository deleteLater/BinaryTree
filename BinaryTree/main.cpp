// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	Node<char> *root = new Node<char>('A');
	BinaryTree<char> bt(root, BUILD_MODEL::BY_FILE_DATA);
	cout << "层序遍历结果:";
	vector<char> ret = bt.SeqentialOrderTraversal();
	for (char value : ret) {
		cout << value;
	}
	cout << "\n树的高度:" << bt.height();
	system("pause");
	*/
	printSpace(5);
	printElem('A');
	newLine();
	printSpace(4);
	printTreeCrotch(1);
	newLine();
	printSpace(3);
	cout << "/   \\";
	newLine();
	printSpace(2);
	printElem('B');
	printSpace(5);
	printElem('C');
	newLine();
	printSpace(1);
	printTreeCrotch(1);
	printSpace(3);
	printTreeCrotch(1);
	newLine();
	printElem('D');
	printSpace(3);
	printElem('E');
	printSpace(1);
	printElem('F');
	printSpace(3);
	printElem('G');
	cout << endl;
	system("pause");
	return 0;
}