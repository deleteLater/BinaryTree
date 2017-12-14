#pragma once
#include "BTNode.h"
#include <stack>
#include <queue>
using std::stack;
using std::queue;

template <class T>
class Iterator {
public:
	virtual Node<T>* next() = 0;
};

template <class T>
class PreOrderIterator : public Iterator<T> {
public:
	PreOrderIterator(nodeStack<T>* root) {
		if (root)
			nodeStack.push(root);
	}
	virtual Node<T>* next() {
		Node<T>* ret(nullptr);
		if (!nodeStack.empty()) {
			top = nodeStack.top();
			nodeStack.pop();
			if (top->rchild) {
				nodeStack.push(top->rchild);
			}
			if (top->lchild) {
				nodeStack.push(top->lchild);
			}
		}
		return ret;
	}
private:
	stack<Node<T>* > nodeStack;
};

template <class T>
class InOrderIterator : public Iterator<T> {
public:
	InOrderIterator(Node<T>* root){
		if (root) {
			nodeStack.push(root);
			if (root->lchild) {
				nodeStack.push(root->lchild);
			}
		}
	}
	virtual Node<T>* next() {
		Node<T>* ret(nullptr);
		Node<T>* cur(nullptr);
		if (!nodeStack.empty()) {
			cur = nodeStack.top();
			ret = cur;
			while (cur) {
				if(cur = cur->lchild)
			}
		}
	}
private:
	stack<Node<T>*> nodeStack;
};