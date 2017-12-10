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
	cout << "B节点的深度:" << bt.depth(ret[1]) << endl;
	cout << "节点个数: " << bt.size();
	cout << "给节点D添加左孩子后:\n";
	bt.addNode(ret[3], new Node<char>('F'), CHILD_AS::L_CHILD);
	ret = bt.SeqentialOrderTraversal();
	cout << "层序遍历结果:";
	for (auto node : ret) {
		cout << node->data;
	}
	cout << endl;
	system("pause");
	return 0;
}