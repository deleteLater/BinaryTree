#pragma once
#include <queue>
#include "treePrint.h"
#include "BTNode.h"
using namespace std;

/*
   定义:
	树的大小:节点数量
	树的高度:所有节点中的最大深度
	树中某个节点的深度:该节点到根节点路径上的链接数
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
	void addNode(Node<T>& parent, Node<T>& child, CHILD_AS lor);//lor: left or right
	int size();
	int depth(Node<T>* node);
	int height();
	//void InOrderTraversal();
	//void PreOrderTraversal();
	//void PostOrderTraversal();
	vector<T> SeqentialOrderTraversal();
	void printTree(Node<T>* root);
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
		root->rchild = nullptr;
	}

	if (ch1 == '#' && ch2 == '#') {
		cout << root->data << "节点为叶子节点!" << endl << endl;
		return;
	}
	cout << "现在," << root->data << "节点的左孩子为: " << root->lchild << ",右孩子为: " << root->rchild << endl << endl;
	buildTree(root->lchild);
	buildTree(root->rchild);
}

template <class T>
BinaryTree<T>::BinaryTree(Node<T>* root, BUILD_MODEL model) {
	this->root = root;
	if (model == BUILD_MODEL::BY_FILE_DATA) {
	}
	cout << "构造树(当左右节点均为 '#'字符或数字35 时结束构造): \n";
	buildTree(root);
	cout << "构造结束!\n";
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	destroy();
}

template <class T>
void BinaryTree<T>::destroy() {
}

template <class T>
int BinaryTree<T>::depth(Node<T>* node) {
}

template <class T>
int BinaryTree<T>::calculateHeight(Node<T>* root) {
	Node<T>* node = root;
	if (node == nullptr) {
		return 0;
	}
	int leftMaxDepth = 1 + calculateHeight(node->lchild);
	int rightMaxDepth = 1 + calculateHeight(node->rchild);

	return (leftMaxDepth > rightMaxDepth ? leftMaxDepth : rightMaxDepth);
}

template <class T>
int BinaryTree<T>::height() {
	return calculateHeight(root);
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

template <class T>
vector<T> BinaryTree<T>::SeqentialOrderTraversal() {
	Node<T>* curRoot = root;
	queue<Node<T>* > nodesQueue;
	vector<T> ret;
	nodesQueue.push(curRoot);
	while (!nodesQueue.empty()) {
		curRoot = nodesQueue.front();
		nodesQueue.pop();
		ret.push_back(curRoot->data);
		if (curRoot->lchild) {
			nodesQueue.push(curRoot->lchild);
		}
		if (curRoot->rchild) {
			nodesQueue.push(curRoot->rchild);
		}
	}
	return ret;
}