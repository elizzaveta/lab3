#include <iostream>
#include <sstream>
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
string* to_postfix(string expr) {
	Stack stek(expr.length());
	Queue qu(expr.length());
	for (int i = 0; i < expr.length(); i++) {
		char token = expr[i];
		stringstream str;
		str << token;
		string token2;
		str >> token2;
		if (isdigit(token)) {
			int  j = i + 1;
			while (isdigit(expr[j])) {
				j++;
			}
			string token1 = expr.substr(i, j - i);
			i = j-1;
			qu.enqueue(token1);
		}
		else if((token!='(')&&(token!=')')){
			while ((stek.point != -1) && (stek.back() != "(") && (prior(stek.back()) >= prior(token))) {
				qu.enqueue(stek.pop());
			}
			stek.push(token2);
		}
		else if (token == '(') {
			stek.push(token2);
		}
		else if (token == ')'){
			while (stek.back() != "(") {
				qu.enqueue(stek.pop());
			}
			stek.remove();
		}
	}
	while (stek.size() != 0) {
		qu.enqueue(stek.pop());
	}
	string *postfix = new string[expr.length()];
	int i = 0;
	while (qu.size() != 0) {
		postfix[i] = qu.dequeue();
		i++;
	}
	return postfix;
}

string qu_to_str(Queue qu) {
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
	case '^':return 3; break;
	}
}

int prior(string d) {

	if (d == "*") { return 2; }
	if (d == "*") { return 2; }
	if (d == "+") { return 1; }
	if (d == "-") { return 1; }
	if (d == "^") { return 3; }

}

double calculate_result(string* postfix, int l) {
	Stack stek(l);
	for (int i = 0; i < l; i++) {
		string token = postfix[i];
		if (ifdigit(token)) {
			stek.push(token);
		}
		else if (token == "+") {
			double second = atoi(stek.pop().c_str());
			double first = atoi(stek.pop().c_str());
			double sum = first + second;
			cout << sum << endl;
			stek.push(to_string(sum));
		}
		else if (token == "-") {
			double second = atoi(stek.pop().c_str());
			double first = atoi(stek.pop().c_str());
			double dif = first - second;
			cout << dif << endl;
			stek.push(to_string(dif));
		}
		else if (token == "*") {
			double second = atoi(stek.pop().c_str());
			double first = atoi(stek.pop().c_str());
			double comp = first * second;
			stek.push(to_string(comp));
		}
		else if (token == "/") {
			double second = atoi(stek.pop().c_str());
			double first = atoi(stek.pop().c_str());
			double quot = first / second;
			stek.push(to_string(quot));
		}
		else if (token == "^") {
			double second = atoi(stek.pop().c_str());
			double first = atoi(stek.pop().c_str());
			double pow = first;
			for (int i = 0; i < second; i++) {
				pow *= first;
			}
			stek.push(to_string(pow));
		}
	}
	string se = stek.pop();
	cout << se << "jk" << endl;
	return 0;
}

bool ifdigit(string a) {
	int c = 0;
	for (int i = 0; i < a.length(); i++) {
		char m = a[i];
		if (!isdigit(m)) { c++; }
	}
	if (c == 0) {
		return true;
	}
	else {
		return false;
	}
	
}