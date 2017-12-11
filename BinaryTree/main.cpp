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
	cout << "\n层序遍历结果:";
	bt.SeqentialOrderTraversal();
	cout << "\n中序遍历结果:";
	bt.InOrderTraversal();
	cout << "\n前序遍历结果:";
	//bt.PreOrderTraversal();
	cout << "\n后序遍历结果:";
	//bt.PostOrderTraversal();
	//bt.destroy();

	cout << endl;
	system("pause");
	return 0;
}