#pragma once
#include<cstring>

namespace ExceptionHandler {
	class NodeAlreadyTakenException {
	public:
		char str[200];
		int node;

		NodeAlreadyTakenException() { *str = 0; node = 0; }
		NodeAlreadyTakenException(const char* s, int i) {
			strcpy_s(str, s);
			node = i;
		}

	};

}