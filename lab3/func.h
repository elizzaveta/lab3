#pragma once
#include <iostream>
#include "structures.h"

using namespace std;

string arguments(int, char* []);
string to_postfix(string);
int prior(char);
string qu_to_str(Queqe);
int calculate_result(string);