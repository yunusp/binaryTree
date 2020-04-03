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
	void overRideNode(int index, std::string child, int val);
	void overRideNode(int index, std::string child, float val);
	void overRideNode(int index, std::string child, double val);
	void overRideNode(int index, std::string child, long val);
	void overRideNode(int index, std::string child, char val);
	void overRideNode(int index, std::string child, char* val);
	//void overRideNode(int index, std::string child, long int val);

	void pushNode(int index, std::string child, std::string val);


	std::string getNode(int index, std::string child = "none");

	int* getChildIndex(int index);

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

	if (child != Node::children.leftChild && child != Node::children.rightChild && child!=std::string("none"))
		throw ExceptionHandler::InvalidChildException(child);

	if (child == std::string("none")) {
		tree[index].setVal(val);
	}
	else if (child == Node::children.rightChild) {
		tree[2 * index + 1].setVal(val);
	}
	else if (child == Node::children.leftChild) {
		tree[2 * index].setVal(val);
	}
}
void BinaryTree::overRideNode(int index, std::string child, int val) {
	std::string str = std::to_string(val);
	overRideNode(index, child, str);
}
void BinaryTree::overRideNode(int index, std::string child, float val) {
	std::string str = std::to_string(val);
	overRideNode(index, child, str);
}
void BinaryTree::overRideNode(int index, std::string child, double val) {
	std::string str = std::to_string(val);
	overRideNode(index, child, str);
}
void BinaryTree::overRideNode(int index, std::string child, char val) {
	std::string str = std::to_string(val);
	overRideNode(index, child, str);
}
void BinaryTree::overRideNode(int index, std::string child, char* val) {
	std::string str = val;
	overRideNode(index, child, str);
}
void BinaryTree::overRideNode(int index, std::string child, long val) {
	std::string str = std::to_string(val);
	overRideNode(index, child, str);
}
/*void BinaryTree::overRideNode(int index, std::string child, long int val) {
	std::string str = std::to_string(val);
	overRideNode(index, child, str);
}*/


std::string BinaryTree::getNode(int index, std::string child) {
	
	if (child.compare(Node::children.leftChild) != 0 && child.compare(Node::children.rightChild) != 0 && child.compare(std::string("none")) != 0) {
		throw ExceptionHandler::InvalidChildException(child);
		return "0";
	}
	if (child == std::string("none")) {
		return tree[index].getVal();
	}
	else if (child == std::string(Node::children.leftChild)) {
		return tree[2 * index].getVal();
	}
	else if (child == std::string(Node::children.rightChild)) {
		return tree[2 * index + 1].getVal();
	}
}

int* BinaryTree::getChildIndex(int index) {
	int* results = new int[2];
	results[0] = 2 * index;
	results[1] = 2 * index + 1;

	return results;
}


void BinaryTree::pushNode(int index, std::string child, std::string val) {
	if(getNode(index,child) != "0" ){}
}