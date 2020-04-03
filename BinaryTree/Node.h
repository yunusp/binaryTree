#pragma once
#include"ExceptionHandler.h"
#include<string>
#include<array>


/*maybe i should define parents and children outside but have them associated here?
*/

class Node {
private:
	int index = 0;
	std::string value;
	bool isTerminalNode = false; //might be useful
	int leftChild = 0, rightChild = 0, parent = 0;
	//void setParent(int index); // not required
	//void setChildren();  //not required



public:

	static std::string initVal;

	static struct Children {
		std::string leftChild = "left";
		std::string rightChild = "right";
	}children;

	//default constructor
	Node() { value = initVal; index = 0; }; 
	// construct with an index
	Node(int index); 

	Node(int index, int parentIndex, int rightChildIndex, int leftChildIndex, std::string val = std::string(NULL)); // maybe this will be useful
	// copy constructor
	Node(Node& o); 
	//construct with a value
	Node(int index, std::string val); 

	void setVal(std::string str) { this->value = str; }
	void setParentIndex(int index) { this->parent = index; }
	void setLeftChildIndex(int index) { this->leftChild = index; }
	void setRightChildIndex(int index) { this->rightChild = index; }


	//std::string getVal(Children child); //get value for a given child //I do not think this should be there as it should be provided by the tree class

	// get value of this index eg. Node n(1,"hello"); n.getVal();
	std::string getVal() { return this->value; } 

	//int* getIndices(std::string val); // get indices for a given value //i also dont think this should be implemented here
	
	//manually set index. use only if using copy constructor.
	void setIndex(int index); 

	//std::array<std::string, 2> getChildren(int index); //get children for a given index //this is not required too

	//int getParentIndex(int childIndex); //get parent index for a given child index // not required

};

Node::Node(int index) {
	this->index = index; // put index;
	this->value = initVal;
}
Node::Node(int index, std::string val) {
	this->index = index; //put index
	this->value = value; // put value
}
Node::Node(Node& o) {
	this->value = o.value; //copy value not index
}
Node::Node(int index, int parentIndex, int rightChildIndex, int leftChildIndex, std::string val) { // set all indices 
	this->index = index;
	this->parent = parentIndex;
	this->leftChild = leftChildIndex;
	this->rightChild = rightChildIndex;
	this->value = val;
}


void Node::setIndex(int index) {
	this->index = index;
}
