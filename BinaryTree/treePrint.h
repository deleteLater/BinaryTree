#pragma once
#include <iostream>
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