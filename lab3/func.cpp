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
		else if (check_negative(token, expr, i))
		{
			token = expr[i + 1];
			int  j = i + 2;
			while (isdigit(expr[j])) {
				j++;
			}
			string token1 = expr.substr(i, j - i);
			i = j - 1;
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
	double a = 0;
	for (int i = 0; i < l; i++) {
		string token = postfix[i];
		if (ifdigit(token)||(token.length() > 1))
			stek.push(token);
		else if (token == "+")
			stek.push(addition(stek));
		else if (token == "-")
			stek.push(subtraction(stek));
		else if (token == "*")
			stek.push(multiplication(stek));
		else if (token == "/")
			stek.push(division(stek));
		else if (token == "^")
			stek.push(power(stek));
	}
	a = stod(stek.back());
	return a;
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
bool check_operation(char token)
{
	if (token == '+' || token == '-' || token == '+' || token == '*' || token == '^' || token == '('||token=='/')
		return true;
	else
		return false;
}
bool check_negative(char token, string elem, int i)
{

	if (token == '-' && (i == 0 || (i != 0 && (check_operation(elem[i - 1])))))
		return true;
	else
		return false;
}
string addition(Stack &stek)
{
	string s = stek.pop();
	double second = stod(s);
	s = stek.pop();
	double first = stod(s);
	double sum = first + second;
	s = to_string(sum);
	return s;
}
string subtraction(Stack& stek)
{
	string s = stek.pop();
	double second = stod(s);
	s = stek.pop();
	double first = stod(s);
	double dif = first - second;
	s = to_string(dif);
	return s;
}
string multiplication(Stack& stek)
{
	string s = stek.pop();
	double second = stod(s);
	s = stek.pop();
	double first = stod(s);
	double comp = first * second;
	s = to_string(comp);
	return s;
}
string division(Stack& stek)
{
	string s = stek.pop();
	double second = stod(s);
	s = stek.pop();
	double first = stod(s);
	double quot = first / second;
	s = to_string(quot);
	return s;
}
string power(Stack& stek)
{
	string s = stek.pop();
	double second = stod(s);
	s = stek.pop();
	double first = stod(s);
	double pow = first;
	for (int i = 0; i < second - 1; i++) {
		pow *= first;
	}
	s = to_string(pow);
	return s;
}

int n_tokens(string* p, string s)
{
	int k = 0;
	for (int i = 0; i < s.length(); i++) {
		if (p[i] != "")
			k++;
		else
			break;
	}
	return k;
}