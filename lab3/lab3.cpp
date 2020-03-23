#include <iostream>
#include <sstream>
#include "func.h"
#include "structures.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    //some test code
    string s = "1+2*4+1";
    string p = to_postfix(s);
    cout << p << endl;
    double r = calculate_result(p);
    cout << r;
    
}