#pragma once
#include <iostream>
#include "BTNode.h"
using namespace std;

void printSpace(int times = 0) {
	for (int i = 0; i < times; i++) {
		cout << ' ';
	}
}
void printTreeCrotch(int interval) {
	cout << "/";
	printSpace(interval);
	cout << "\\";
}
void newLine() {
	cout << endl;
}
template <class T>
void printElem(T elem) {
	cout << elem;
}
template <class T>
void printChilds(Node<T>* parent) {
	if (curRoot->lchild) {
		cout << curRoot->data;
	}
	if (curRoot->rchild) {
		cout << curRoot->data;
	}
}