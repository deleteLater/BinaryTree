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
	PreOrderIterator(Node<T>* root) {
		if (root)
			nodeStack.push(root);
	}
	virtual Node<T>* next() {
		Node<T>* ret(nullptr);
		if (!nodeStack.empty()) {
			ret = nodeStack.top();
			nodeStack.pop();
			if (ret->rchild) {
				nodeStack.push(ret->rchild);
			}
			if (ret->lchild) {
				nodeStack.push(ret->lchild);
			}
			return ret;
		}
		return nullptr;
	}
private:
	stack<Node<T>*> nodeStack;
};

template <class T>
class InOrderIterator : public Iterator<T> {
public:
	InOrderIterator(Node<T>* root){
		while (root) {
			nodeStack.push(root);
			root = root->lchild;
		}
	}
	virtual Node<T>* next() {
		Node<T>* ret(nullptr);
		Node<T>* cur(nullptr);
		if (!nodeStack.empty()) {
			ret = nodeStack.top();
			nodeStack.pop();
			cur = ret->rchild;
			while (cur) {
				nodeStack.push(cur);
				cur = cur->lchild;
			}
		}
		return ret;
	}
private:
	stack<Node<T>*> nodeStack;
};

template <class T>
class PostOrderIterator : public Iterator<T> {
public:
	PostOrderIterator(Node<T>* root): pre(nullptr){
		while (root) {
			nodeStack.push(root);
			root = root->lchild;
		}
	}
	virtual Node<T>* next() {
		Node<T>* cur(nullptr);
		while (cur || !nodeStack.empty()) {
			//push curRoot's lchilds
			while (cur) {
				nodeStack.push(cur);
				cur = cur->lchild;
			}
			cur = nodeStack.top();
			nodeStack.pop();
			//if curNode->rchild == nullptr || curNode->rchild has been visited , return
			if (cur->rchild == pre || cur->rchild == nullptr) {
				pre = cur;
				return cur;
			}
			//else push rchild
			else
			{
				nodeStack.push(cur);
				cur = cur->rchild;
			}
		}
		return nullptr;
	}
private:
	Node<T>* pre;	//previously visited node
	stack<Node<T>*> nodeStack;
};

template <class T>
class SeqentialOrderIterator : public Iterator<T> {
public:
	SeqentialOrderIterator(Node<T>* root) {
		nodeQueue.push(root);
	}
	virtual Node<T>* next() {
		Node<T>* ret(nullptr);
		if (!nodeQueue.empty()) {
			ret = nodeQueue.front();
			nodeQueue.pop();
			if (ret->lchild) {
				nodeQueue.push(ret->lchild);
			}
			if (ret->rchild) {
				nodeQueue.push(ret->rchild);
			}
			return ret;
		}
		return nullptr;
	}
private:
	queue<Node<T>*> nodeQueue;
};