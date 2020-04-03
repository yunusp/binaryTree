#include"BinTree.h"
#include<iostream>

using namespace std;

Node::Children Node::children; //so for some reason this has to be here to instantiate the static struct
 std::string Node::initVal = "0";

BinaryTree bt;
int main() {
	

	bt.overRideNode(1, "left", "help");
	bt.overRideNode(1, "right", "he");
	bt.overRideNode(1, "none", "hlp");

	try {
		bt.overRideNode(1, "r", "ss");
	}
	catch (ExceptionHandler::InvalidChildException e) {
		cout << e.string << e.args<<endl;
	}


	cout << "helloTest";
}