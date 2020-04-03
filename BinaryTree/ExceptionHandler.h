#pragma once
#include<cstring>
#include<string>

namespace ExceptionHandler {
	class NodeAlreadyTakenException {
	public:
		char string[200];
		int node;

		NodeAlreadyTakenException() { *string = 0; node = 0; }
		NodeAlreadyTakenException(const char* s, int i) {
			strcpy_s(string, s);
			node = i;
		}

	};

	class NodeNotFoundException {
	public:
		char string[200];
		int index;

		NodeNotFoundException() { *string = 0, index = 0; }
		NodeNotFoundException(const char* s, int i) {
			strcpy_s(string, s);
			index = i;
		}
	};


	class UpperLimitViolatedException {
	public:
		char string[100];
		UpperLimitViolatedException(const char* s = "Upper limit violated") { strcpy_s(string, s); }
	};

	class InvalidChildException {
	public:
		char string[200];
		std::string args;

		InvalidChildException(std::string arg,const char* s = "Invalid child argument:\t"){
			strcpy_s(string, s);
			args = arg;
		}
	};
}