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