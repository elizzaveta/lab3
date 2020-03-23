#include <iostream>
#include "func.h"
#include "structures.h"

using namespace std;

//to get the expression from cmd
string arguments(int argc, char* argv[]) {
	string s = "";

	for (int i = 1; i < argc; ++i) {
		s += argv[i];
	}
	return s;
}

//to convert infix to postfix notation
string to_postfix(string expr) {
	Stack stek(expr.length());
	Queqe qu(expr.length());
	for (int i = 0; i < expr.length(); i++) {
		char token = expr[i];
		if (isdigit(token)) {
			qu.enqueue(token);
		}
		else if((token!='(')&&(token!=')')){
			while ((stek.point != -1) && (stek.back() != '(') && (prior(stek.back()) >= prior(token))) {
				qu.enqueue(stek.pop());
			}
			stek.push(token);
		}
		else if (token == '(') {
			stek.push(token);
		}
		else if (token == ')'){
			while (stek.back() != '(') {
				qu.enqueue(stek.pop());
			}
			stek.remove();
		}
	}
	while (stek.size() != 0) {
		qu.enqueue(stek.pop());
	}
	string postfix = "";
	while (qu.size() != 0) {
		postfix += qu.dequeue();
	}
	return postfix;
}

string qu_to_str(Queqe qu) {
	string result = "";
	while (qu.size() != 0) {
		result += qu.dequeue();
	}
	return result;
}



int prior(char d) {
	switch (d)
	{
	case '*':return 2; break;
	case '/':return 2; break;
	case '+':return 1; break;
	case '-':return 1; break;
	}
}