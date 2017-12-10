#pragma once
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