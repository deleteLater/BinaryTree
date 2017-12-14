#pragma once
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
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
	void addNode(Node<T>*parent, Node<T>* child, CHILD_AS lor);//lor: left or right
	int size();
	int depth(Node<T>* node);
	int height();
	Node<T>* getRoot();
	void InOrderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();
	void SeqentialOrderTraversal();
private:
	Node<T>* root;
	int nodesCount;
	void buildTree(Node<T>* root);
	int calculateDepth(Node<T>* root);
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
	cout << ch1;
	cout << "输入右孩子: ";
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
	nodesCount = 1;	//根节点
	if (model == BUILD_MODEL::BY_FILE_DATA) {
		cout << "通过 dataIn.txt 文件构造二叉树,输出信息在 logOut.txt 文件中 ...\n";
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
		cout << "构造完成!";
	}
	else {
		cout << "通过输入构造树(当左右节点均为 '#'字符或数字35 时结束构造): \n";
		buildTree(root);
		cout << "构造完成!\n";
	}
}

template <class T>
void BinaryTree<T>::destroy() {
	stack<Node<T>*> nodes;
	nodes.push(root);
	while (!nodes.empty()) {
		root = nodes.top();
		nodes.pop();
		if (root->lchild) {
			nodes.push(root->lchild);
		}
		if (root->rchild) {
			nodes.push(root->rchild);
		}
		cout << "delete: " << root->data << endl;
		delete root;
	}
	root = nullptr;
	nodesCount = 0;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	if (root == nullptr) {
		return;
	}
	destroy();
}

template <class T>
int BinaryTree<T>::calculateDepth(Node<T>* root) {
	/*
	if (root == nullptr) {
		return 0;
	}
	int leftMaxDepth = 1 + calculateDepth(root->lchild);
	int rightMaxDepth = 1 + calculateDepth(root->rchild);
	return (leftMaxDepth > rightMaxDepth ? leftMaxDepth : rightMaxDepth);
	*/
	queue<Node<T>*> nodes;
	Node<T>* curNode = nullptr;
	nodes.push(root);
	int curDepth = 0;
	while (!nodes.empty()) {
		int visited = 0;
		int curLevelNodes = nodes.size();
		while (visited < curLevelNodes) {
			curNode = nodes.front();
			nodes.pop();
			visited++;
			if (curNode->lchild) {
				nodes.push(curNode->lchild);
			}
			if (curNode->rchild) {
				nodes.push(curNode->rchild);
			}
		}
		curDepth++;
	}
	return curDepth;
}

template <class T>
int BinaryTree<T>::height() {
	return calculateDepth(root);
}

template <class T>
int BinaryTree<T>::depth(Node<T>* node) {
	return (calculateDepth(root) - calculateDepth(node));
}

template <class T>
void BinaryTree<T>::addNode(Node<T>* parent, Node<T>* child, CHILD_AS lor) {
	if (lor == CHILD_AS::L_CHILD) {
		if (parent->lchild == nullptr) {
			parent->lchild = child;
			nodesCount++;
		}
		else {
			cout << "添加节点失败!因为所选父节点已经有相应的子节点!";
			return;
		}
	}
	else if (lor == CHILD_AS::R_CHILD) {
		if (parent->rchild == nullptr) {
			parent->rchild = child;
			nodesCount++;
		}
		else {
			cout << "添加节点失败!因为所选父节点已经有相应的子节点!";
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
	/*RecursiveVersion

	if (root == nullptr) {
		return;
	}
	InOrderTraversal(root->lchild);
	cout << root->data;
	InOrderTraversal(root->rchild);
	*/
	Node<T>* curRoot = root;
	stack<Node<T>*> nodes;	
	while (!nodes.empty() || curRoot) {
		while (curRoot) {
			nodes.push(curRoot);
			curRoot = curRoot->lchild;//将左孩子作为根
		}
		cout << nodes.top()->data;	  //栈顶就是当前根的最小(最底层)左/右孩子 
		curRoot = nodes.top()->rchild;//将右孩子作为根
		nodes.pop();
	}
}

template <class T>
void BinaryTree<T>::PreOrderTraversal() {
	/*RecursiveVersion

	if (root == nullptr) {
		return;
	}
	cout << root->data;
	PreOrderTraversal(root->lchild);
	PreOrderTraversal(root->rchild);
	*/

	//对于每个节点访问两次
	//第一次输出并入栈,第二次访问其右孩子后出栈
	Node<T>* curRoot = root;
	stack<Node<T>*> nodes;
	while (!nodes.empty() || curRoot) {
		while (curRoot) {
			cout << curRoot->data;
			nodes.push(curRoot);
			curRoot = curRoot->lchild;
		}
		if (!nodes.empty()) {
			curRoot = nodes.top()->rchild;
			nodes.pop();
		}
	}
}

template <class T>
void BinaryTree<T>::PostOrderTraversal() {
	/*RecursiveVersion
	if (root == nullptr) {
		return;
	}
	PostOrderTraversal(root->lchild);
	PostOrderTraversal(root->rchild);
	cout << root->data;
	*/

	//对于每个节点都会访问两次
	//false:第一次访问入栈 true:第二次访问出栈并输出
	stack<pair<Node<T>*, bool>> nodes;
	Node<T>* curRoot = root;
	while (!nodes.empty() || curRoot) {
		while (curRoot) {
			nodes.push(make_pair(curRoot, false));	//第一次访问
			curRoot = curRoot->lchild;
		}
		while (!nodes.empty() && nodes.top().second == true) {
			cout << nodes.top().first->data;//第二次访问
			nodes.pop();
		}
		if (!nodes.empty()) {
			curRoot = nodes.top().first->rchild;
			nodes.top().second = true;	//下一次就是第二次访问
		}
	}
}

template <class T>
void BinaryTree<T>::SeqentialOrderTraversal() {
	//对于每个节点访问且仅访问一次
	//出队顺序就是层序遍历
	if (root == nullptr) {
		cout << "EmptyTree!";
		return;
	}
	Node<T>* curRoot = root;
	queue<Node<T>* > nodesQueue;
	nodesQueue.push(curRoot);
	while (!nodesQueue.empty()) {
		curRoot = nodesQueue.front();
		nodesQueue.pop();		
		cout << curRoot->data;
		if (curRoot->lchild) {
			nodesQueue.push(curRoot->lchild);
		}
		if (curRoot->rchild) {
			nodesQueue.push(curRoot->rchild);
		}
	}
}