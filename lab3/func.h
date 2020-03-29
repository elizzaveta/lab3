#pragma once
#include <iostream>
#include <sstream>
#include "structures.h"

using namespace std;

string arguments(int, char* []);
string* to_postfix(string);
int prior(string);
int prior(char);
string qu_to_str(Queue);
double calculate_result(string*, int);
bool ifdigit(string);
bool check_operation(char);
bool check_negative(char, string, int);
string addition(Stack&);
string subtraction(Stack&);
string multiplication(Stack&);
string division(Stack&);
string power(Stack&);
int n_tokens(string*, string);