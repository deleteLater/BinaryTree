// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include "BTIterator.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	Node<char> *root = new Node<char>('A');
	BinaryTree<char> bt(root, BUILD_MODEL::BY_FILE_DATA);
	cout << "\n树高:" << bt.height();
	cout << "\n层序遍历结果:";
	bt.SeqentialOrderTraversal();
	cout << "\n前序遍历结果:";
	bt.PreOrderTraversal();
	cout << "\n中序遍历结果:";
	bt.InOrderTraversal();
	cout << "\n后序遍历结果:";
	bt.PostOrderTraversal();
	cout << endl;
	cout << "\n迭代器遍历:";
	cout << "\n层序迭代器:";
	SeqentialOrderIterator<char> si(root);
	Node<char>* t1 = root;
	while ((t1 = si.next()) != nullptr) {
		cout << t1->data;
	}
	cout << "\n先序迭代器:";
	PreOrderIterator<char> pi(root);
	Node<char>* t2 = root;
	while ((t2 = pi.next()) != nullptr) {
		cout << t2->data;
	}
	cout << "\n中序迭代器:";

	cout << "\n摧毁树:\n";
	bt.destroy();

	system("pause");
	return 0;
}