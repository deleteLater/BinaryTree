// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.h"
#include <shlobj.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//redirect cin,cout
	streambuf* default_in = cin.rdbuf();
	streambuf* default_out = cout.rdbuf();
	ifstream fin;
	ofstream fout;
	fout.open("logOut.txt");
	fin.open("dataIn.txt");
	cin.rdbuf(fin.rdbuf());
	cout.rdbuf(fout.rdbuf());

	Node<char> *root = new Node<char>('A');
	BinaryTree<char> bt(root, BUILD_MODEL::BY_FILE_DATA);

	vector<char> ret = bt.SeqentialOrderTraversal();
	cout.rdbuf(default_out);
	for (char value : ret) {
		cout << value;
	}

	system("pause");
	/*
	printSpace(5);
	printElem('A');
	newLine();
	printSpace(4);
	printTreeCrotch(1);
	newLine();
	printSpace(3);
	cout << "/   \\";
	newLine();
	printSpace(2);
	printElem('B');
	printSpace(5);
	printElem('C');
	newLine();
	printSpace(1);
	printTreeCrotch(1);
	printSpace(3);
	printTreeCrotch(1);
	newLine();
	printElem('D');
	printSpace(3);
	printElem('E');
	printSpace(1);
	printElem('F');
	printSpace(3);
	printElem('G');
	cout << endl;
	system("pause");
	*/
	return 0;
}