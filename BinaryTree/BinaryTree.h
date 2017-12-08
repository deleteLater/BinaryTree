#pragma once
#include <sstream>
#include <iostream>
#include <string>

/*
   定义:
	树的大小:节点数量
	树的高度:所有节点中的最大深度
	树中某个节点的深度:该节点到根节点路径上的链接数
*/
using namespace std;
template <class T>
class Node {
public:
	T data;
	Node* lchild;
	Node* rchild;
	Node() {
		//do nothing
	}
	Node(T data) {
		this->data = data;
		lchild = nullptr;
		rchild = nullptr;
	}
	string nodeInfo() {
		ostringstream oss;
		oss << "NodeInfo: [ address: " << this << " || data: " << this->data <<
			" || L_CHILD: " << this->lchild << " || R_CHILD: " << this->rchild << "]";
		return oss.str();
	}
};

enum class CHILD_AS {
	L_CHILD,
	R_CHILD
};

template <class T>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(Node<T> root);

	void addNode(Node<T>& parent, Node<T>& child, CHILD_AS lor);//lor: left or right
	int size();
	int depth(Node<T>& node);
	int height();
	//void InOrderTraversal();
	//void PreOrderTraversal();
	//void PostOrderTraversal();
	//void SeqentialOrderTraversal();
	void printTree(Node<T>* root);
private:
	Node<T>* root;
	int nodesCount;
	void buildTree(Node<T>* root);
};

template <class T>
BinaryTree<T>::BinaryTree() {
	root = nullptr;
	nodesCount = 0;
}

template <class T>
void BinaryTree<T>::buildTree(Node<T>* root) {
	if (root == nullptr) {
		return;
	}
	cout << "当前根节点: " << root->data << endl;
	T ch1, ch2;

	cout << "输入左孩子: ";
	cin >> ch1;
	if (ch1 != (T)'#') {
		root->lchild = new Node<T>(ch1);
		nodesCount++;
	}
	else {
		root->lchild = nullptr;
	}

	cout << "输入右孩子: ";
	cin >> ch2;
	if (ch2 != (T)'#') {
		root->rchild = new Node<T>(ch2);
		nodesCount++;
	}
	else {
		root->lchild = nullptr;
	}

	if (ch1 == '#' && ch2 == '#') {
		return;
	}
	cout << "现在,该节点的左孩子为: " << root->lchild->data << ",右孩子为: " << root->rchild->data << endl << endl;
	buildTree(root->lchild);
	buildTree(root->rchild);
}

template <class T>
BinaryTree<T>::BinaryTree(Node<T> root) {
	this->root = &root;
	cout << "构造树(当左/右节点均为 '#'字符或数字35 时结束构造): \n";
	buildTree(this->root);
	cout << "构造结束!\n";
}

template <class T>
int BinaryTree<T>::depth(Node<T>& node) {
	return 0;
}

template <class T>
void BinaryTree<T>::addNode(Node<T>& parent, Node<T>& child, CHILD_AS lor) {
	if (lor == CHILD_AS::L_CHILD) {
		if (parent.lchild == nullptr) {
			parent.lchild = &child;
			nodesCount++;
		}
		else {
			cout << "添加节点失败!因为所选父节点已经有相应的子节点!";
		}
	}
	else if (lor == CHILD_AS::R_CHILD) {
		if (parent.rchild == nullptr) {
			parent.rchild = &child;
			nodesCount++;
		}
		else {
			cout << "添加节点失败!因为所选父节点已经有相应的子节点!";
		}
	}
}

template <class T>
int BinaryTree<T>::size() {
	return nodesCount;
}

template <class T>
void BinaryTree<T>::printTree(Node<T>* root) {
	if (root->rchild == nullptr && root->rchild = nullptr) {
		return;
	}
}