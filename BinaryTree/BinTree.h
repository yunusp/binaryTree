#pragma once
#include"Node.h"

#define MAX_SIZE  100
#define UPPER_LIMIT 1000

class BinaryTree {
private:
	Node tree[MAX_SIZE] ;
	struct null {
		const char nullVal[11] = "!NULL_VAL!";
	};
	null noVal;

public:
	BinaryTree(); //blank tree (values default to "")
	BinaryTree(std::string val); // tree with all nodes initialized with custom value
	BinaryTree(int startIndex, std::string val); // nodes initialized with custom value and starts at index
	BinaryTree(int startIndex); // start from custom index

	void overRideNode(int index, std::string child, std::string val);



};


BinaryTree::BinaryTree() {
	for (int i = 0; i < MAX_SIZE; i++) {
		tree[i] =  Node(i+1);
	}
}
BinaryTree::BinaryTree(std::string val) {
	for (int i = 0; i < MAX_SIZE; i++) {
		tree[i] = Node(i+1, val);
	}
}
BinaryTree::BinaryTree(int startIndex) {
	int size = MAX_SIZE + startIndex;

	if (size > UPPER_LIMIT)
		throw ExceptionHandler::UpperLimitViolatedException();

	for (int i = 0; i < size; i++) {
		if (i < startIndex) {
			tree[i] = Node(i, std::string(noVal.nullVal));
		}
		else{
			tree[i] = Node(i);
		}
	}
}
BinaryTree::BinaryTree(int startIndex,std::string val) {
	int size = MAX_SIZE + startIndex;

	if (size > UPPER_LIMIT)
		throw ExceptionHandler::UpperLimitViolatedException();

	for (int i = 0; i < size; i++) {
		if (i < startIndex) {
			tree[i] = Node(i, std::string(noVal.nullVal));
		}
		else {
			tree[i] = Node(i,val);
		}
	}
}

void BinaryTree::overRideNode(int index, std::string child, std::string val) {
	if (child != Node::children.leftChild || child != Node::children.rightChild)
		throw ExceptionHandler::InvalidChildException(child);

	if (child == Node::children.rightChild) {
		tree[2 * index + 1].setVal(val);
	}
	else if (child == Node::children.leftChild) {
		tree[2 * index].setVal(val);
	}
}