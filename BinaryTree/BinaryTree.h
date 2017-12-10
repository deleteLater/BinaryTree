#pragma once
#include <queue>
#include <iostream>
#include <fstream>
#include "treePrint.h"
#include "BTNode.h"
using namespace std;

/*
   ����:
	���Ĵ�С:�ڵ�����
	���ĸ߶�:���нڵ��е�������
	����ĳ���ڵ�����:�ýڵ㵽���ڵ�·���ϵ�������
*/

enum class CHILD_AS {
	L_CHILD,
	R_CHILD
};

enum class BUILD_MODEL {
	BY_INPUT,
	BY_FILE_DATA
};

template <class T>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(Node<T>* root, BUILD_MODEL model);
	~BinaryTree();

	void destroy();
	void addNode(Node<T>*parent, Node<T>* child, CHILD_AS lor);//lor: left or right
	int size();
	int depth(Node<T>* node);
	int height();
	Node<T>* getRoot();
	void InOrderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();
	vector<Node<T>*> SeqentialOrderTraversal();
private:
	Node<T>* root;
	int nodesCount;
	void buildTree(Node<T>* root);
	int calculateHeight(Node<T>* root);
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
	cout << "��ǰ���ڵ�: " << root->data << endl;
	T ch1, ch2;

	cout << "��������: ";
	cin >> ch1;
	if (ch1 != (T)'#') {
		root->lchild = new Node<T>(ch1);
		nodesCount++;
	}
	else {
		root->lchild = nullptr;
	}
	cout << ch1;
	cout << "�����Һ���: ";
	cin >> ch2;
	if (ch2 != (T)'#') {
		root->rchild = new Node<T>(ch2);
		nodesCount++;
	}
	else {
		root->rchild = nullptr;
	}
	cout << ch2 << endl;
	if (ch1 == '#' && ch2 == '#') {
		cout << root->data << "�ڵ�ΪҶ�ӽڵ�!" << endl << endl;
		return;
	}
	cout << "����," << root->data << "�ڵ������Ϊ: " << root->lchild << ",�Һ���Ϊ: " << root->rchild << endl << endl;
	buildTree(root->lchild);
	buildTree(root->rchild);
}

template <class T>
BinaryTree<T>::BinaryTree(Node<T>* root, BUILD_MODEL model) {
	this->root = root;
	nodesCount = 1;	//���ڵ�
	if (model == BUILD_MODEL::BY_FILE_DATA) {
		cout << "ͨ�� dataIn.txt �ļ����������,�����Ϣ�� logOut.txt �ļ��� ...\n";
		streambuf* default_in = cin.rdbuf();
		streambuf* default_out = cout.rdbuf();
		ifstream fin;
		ofstream fout;
		fout.open("logOut.txt");
		fin.open("dataIn.txt");
		//redirect
		cin.rdbuf(fin.rdbuf());
		cout.rdbuf(fout.rdbuf());
		//build tree
		buildTree(root);
		//Restore Default
		fout.close();
		fin.close();
		cin.rdbuf(default_in);
		cout.rdbuf(default_out);
		cout << "�������!";
	}
	else {
		cout << "ͨ�����빹����(�����ҽڵ��Ϊ '#'�ַ�������35 ʱ��������): \n";
		buildTree(root);
		cout << "�������!\n";
	}
}

template <class T>
void BinaryTree<T>::destroy() {
	vector<Node<T>*> nodes = SeqentialOrderTraversal();
	for (auto node : nodes) {
		delete node;
		node = nullptr;
	}
	nodes.clear();
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	destroy();
}

template <class T>
int BinaryTree<T>::calculateHeight(Node<T>* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftMaxDepth = 1 + calculateHeight(root->lchild);
	int rightMaxDepth = 1 + calculateHeight(root->rchild);
	return (leftMaxDepth > rightMaxDepth ? leftMaxDepth : rightMaxDepth);
}

template <class T>
int BinaryTree<T>::height() {
	return calculateHeight(root);
}

template <class T>
int BinaryTree<T>::depth(Node<T>* node) {
	return (calculateHeight(root) - calculateHeight(node));
}

template <class T>
void BinaryTree<T>::addNode(Node<T>* parent, Node<T>* child, CHILD_AS lor) {
	if (lor == CHILD_AS::L_CHILD) {
		if (parent->lchild == nullptr) {
			parent->lchild = child;
			nodesCount++;
		}
		else {
			cout << "��ӽڵ�ʧ��!��Ϊ��ѡ���ڵ��Ѿ�����Ӧ���ӽڵ�!";
			return;
		}
	}
	else if (lor == CHILD_AS::R_CHILD) {
		if (parent->rchild == nullptr) {
			parent->rchild = child;
			nodesCount++;
		}
		else {
			cout << "��ӽڵ�ʧ��!��Ϊ��ѡ���ڵ��Ѿ�����Ӧ���ӽڵ�!";
			return;
		}
	}
}

template <class T>
int BinaryTree<T>::size() {
	return nodesCount;
}

template <class T>
Node<T>* BinaryTree<T>::getRoot() {
	return root;
}

template <class T>
void BinaryTree<T>::InOrderTraversal() {
	if (root == nullptr) {
		return;
	}
	InOrderTraversal(root->lchild);
	cout << root->data;
	InOrderTraversal(root->rchild);
}

template <class T>
void BinaryTree<T>::PreOrderTraversal() {
	if (root == nullptr) {
		return;
	}
	cout << root->data;
	PreOrderTraversal(root->lchild);
	PreOrderTraversal(root->rchild);
}

template <class T>
void BinaryTree<T>::PostOrderTraversal() {
	if (root == nullptr) {
		return;
	}
	PostOrderTraversal(root->lchild);
	PostOrderTraversal(root->rchild);
	cout << root->data;
}

template <class T>
vector<Node<T>*> BinaryTree<T>::SeqentialOrderTraversal() {
	Node<T>* curRoot = root;
	queue<Node<T>* > nodesQueue;
	vector<Node<T>*> ret;
	nodesQueue.push(curRoot);
	while (!nodesQueue.empty()) {
		curRoot = nodesQueue.front();
		nodesQueue.pop();
		ret.push_back(curRoot);
		if (curRoot->lchild) {
			nodesQueue.push(curRoot->lchild);
		}
		if (curRoot->rchild) {
			nodesQueue.push(curRoot->rchild);
		}
	}
	return ret;
}