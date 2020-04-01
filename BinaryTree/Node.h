#pragma once
#include<string>
#include<array>

/*maybe i should define parents can children outside but have them associated here?
*/

class Node {
private:
	int index = 0;
	std::string value;
	int leftChild = 0, rightChild = 0, parent = 0;
	//void setParent(int index); // not required
	//void setChildren();  //not required
	struct Children {
		int leftChild = 0, rightChild = 1;
	};
	Children children; // this struct is not useful but im keeping it should it be useful later


public:
	Node(int index); // construct with an index
	Node(int index, int parentIndex, int rightChildIndex, int leftChildIndex, std::string val); // maybe this will be useful
	Node(Node& o); // copy constructor
	Node(int index, std::string val); //construct with a value

	void setVal(std::string str) { this->value = str; }
	void setParentIndex(int index) { this->parent = index; }
	void setLeftChildIndex(int index) { this->leftChild = index; }
	void setRightChildIndex(int index) { this->rightChild = index; }

	//std::string getVal(Children child); //get value for a given child //I do not think this should be there as it should be provided by the tree class
	std::string getVal() { return this->value; } // get value of this index eg. Node n(1,"hello"); n.getVal();

	//int* getIndices(std::string val); // get indices for a given value //i also dont think this should be implemented here
	void setIndex(int index); //manually set index. use only if using copy constructor.

	//std::array<std::string, 2> getChildren(int index); //get children for a given index //this is not required too

	//int getParentIndex(int childIndex); //get parent index for a given child index // not required

};

Node::Node(int index) {
	this->index = index; // put index;
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

