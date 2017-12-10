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
	vector<Node<char>*> ret = bt.SeqentialOrderTraversal();
	for (auto node : ret) {
		cout << node->data;
	}
	cout << "\n树的高度:" << bt.height() << endl;
	cout << "D节点的深度:" << bt.depth(ret[3]) << endl;
	system("pause");
	/*
	int height = 3;
	int spacing = headSpacing(height);

	while (height) {
		printSpace(spacing--);
	}
	printSpace(spacing);
	printElem('A');
	newLine();

	printSpace(spacing - 1);
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
	*/
	return 0;
}