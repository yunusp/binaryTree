#pragma once 
#include<array>
#include<string>
#include"ExceptionHandler.h"
#define MAX_INT_LIM 100
#define LEFT 0
#define RIGHT 1

//enum Children { LEFT, RIGHT };
class Tree {

	std::string tree[MAX_INT_LIM];
	void checkException(int node, int child);

public:
	int lastNode = 0;
	//Children children;

	int overRideNode(int node, int child, int value);
	int overRideNode(int node, int child, float value);
	int overRideNode(int node, int child, double value);
	int overRideNode(int node, int child, const char* value);

	int pushChild(int node, int child, int value);
	int pushChild(int node, int child, float value);
	int pushChild(int node, int child, double value);
	int pushChild(int node, int child, const char* value);

	std::string getVal(int node, int child); // convert all returned values to string as i cant overload based on return type.

	/*std::string* search(int val);
	std::string* search(float val);
	std::string* search(double val);
	std::string* search(const char* val);
*/
	std::array<std::string, 2> getChildren(int node);

	int* getNode(std::string val);

	Tree();
};

Tree::Tree() {
	for (int i = 0; i < MAX_INT_LIM; i++) {
		tree[i] = '\0';
	}
}

void Tree::checkException(int node, int child) {
	if (getVal(node, child) != "") {
		if (child == RIGHT)
			throw ExceptionHandler::NodeAlreadyTakenException("Node right already taken", node * 2 + 1);
		else if (child == LEFT)
			throw ExceptionHandler::NodeAlreadyTakenException("Node already taken", node * 2);
	}
}

int Tree::overRideNode(int node, int child, int value) {
	if (!node) exit(1);



	lastNode = node;

	if (child) {
		tree[2 * node + 1] = std::to_string(value);
	}
	else {
		tree[2 * node] = std::to_string(value);
	}
	return node;
}
int Tree::overRideNode(int node, int child, float value) {
	if (!node) exit(1);

	if (getVal(node, child) != std::to_string('\0')) {
		if (child == RIGHT)
			throw ExceptionHandler::NodeAlreadyTakenException("Node already taken", node * 2 + 1);
		else if (child == LEFT)
			throw ExceptionHandler::NodeAlreadyTakenException("Node already taken", node * 2);
	}

	lastNode = node;
	if (child) {
		tree[2 * node + 1] = std::to_string(value);
		return node;
	}
	else {
		tree[2 * node] = std::to_string(value);
	}
	return node;
}
int Tree::overRideNode(int node, int child, double value) {
	if (!node) exit(1);



	lastNode = node;

	if (child) {
		tree[2 * node + 1] = std::to_string(value);
		return node;
	}
	else {
		tree[2 * node] = std::to_string(value);
	}
	return node;
}
int Tree::overRideNode(int node, int child, const char* value) {
	if (!node) exit(1);



	lastNode = node;

	if (child) {
		tree[2 * node + 1] = std::string(value);
		return node;
	}
	else {
		tree[2 * node] = std::string(value);
	}
	return node;
}

int Tree::pushChild(int node, int child, int value) {
	checkException(node, child);
	return overRideNode(node, child, value);
}
int Tree::pushChild(int node, int child, float value) {
	checkException(node, child);
	return overRideNode(node, child, value);
}
int Tree::pushChild(int node, int child, double value) {
	checkException(node, child);
	return overRideNode(node, child, value);
}
int Tree::pushChild(int node, int child, const char* value) {
	checkException(node, child);
	return overRideNode(node, child, value);
}

std::string Tree::getVal(int node, int child) {
	if (!node) exit(1);
	if (child) {
		return tree[2 * node + 1];
	}
	else {
		return tree[2 * node];
	}
}

/*std::string* Tree::search(int val) {
	int times = 0;
	int ptr = 0;
	std::string s = std::to_string(val);

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == s) times++;
	}

	std::string* results = new std::string[times];
	results[0] = std::to_string(times);
	ptr++;

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == s) {
			results[ptr] = tree[i];
			ptr++;
		}
	}
	return results;
}
std::string* Tree::search(float val) {
	int times = 0;
	int ptr = 0;
	std::string s = std::to_string(val);

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == s) times++;
	}

	std::string* results = new std::string[times];
	results[0] = std::to_string(times);
	ptr++;

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == s) {
			results[ptr] = tree[i];
			ptr++;
		}
	}
	return results;
}
std::string* Tree::search(double val) {
	int times = 0;
	int ptr = 0;
	std::string s = std::to_string(val);

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == s) times++;
	}

	std::string* results = new std::string[times];
	results[0] = std::to_string(times);
	ptr++;

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == s) {
			results[ptr] = tree[i];
			ptr++;
		}
	}
	return results;
}
std::string* Tree::search(const char* val) {
	int times = 0;
	int ptr = 0;
	std::string s(val);

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == s) times++;
	}

	std::string* results = new std::string[times];
	results[0] = std::to_string(times);
	ptr++;

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == s) {
			results[ptr] = tree[i];
			ptr++;
		}
	}
	return results;
}*/

std::array<std::string, 2> Tree::getChildren(int node) {
	std::array<std::string, 2> children;
	for (int i = 0; i < 2; i++) {
		children[i] = tree[2 * node + i];
	}
	return children;
}

int* Tree::getNode(std::string val) {
	int* results = new int[100];
	int ptr = 0;
	for (int i = 0; i < 100; i++) results[i] = 0;

	for (int i = 0; i < MAX_INT_LIM; i++) {
		if (tree[i] == val) {
			results[ptr] = i / 2;
			ptr++;
		}
	}

	return results;
}
