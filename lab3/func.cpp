#include <iostream>
#include "func.h"

using namespace std;

//to get the expression from cmd
string arguments(int argc, char* argv[]) {
	string s = "";

	for (int i = 1; i < argc; ++i) {
		s += argv[i];
	}
	return s;
}