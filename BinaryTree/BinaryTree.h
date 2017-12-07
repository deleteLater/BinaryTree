#pragma once

template <class T>
class Node {
public:
	T data;
	Node* lchild;
	Node* rchild;
	Node(T data) {
		this->data = data;
		lchild = nullptr;
		rchild = nullptr;
	}
};

template <class T>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(Node* root);
	void buildTree(Node* root);
	void InOrderTraversal();
	void PreOrderTraversal();
	void PostOrderTraversal();
	void SeqentialOrderTraversal();
private:
	Node<T> *root;
};

template <class T>
BinaryTree::BinaryTree() {
	//build emptyTree
	root = nullptr;
}
template <class T>
BinaryTree::BinaryTree(Node* root) {
	if (root == nullptr) {
		this->root = nullptr;
	}
	buildTree(root);
}

template <class T>
void BinaryTree::buildTree(Node* root) {
}