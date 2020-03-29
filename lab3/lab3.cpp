﻿#include <iostream>
#include <sstream>
#include "func.h"
#include "structures.h"

using namespace std;

int main(int argc, char* argv[])
{
   

    string s = arguments(argc, argv);
    string* p = to_postfix(s);
    int k = n_tokens(p, s);
    double r = calculate_result(p, k);
    cout << "Result: " << r;

    
    
}