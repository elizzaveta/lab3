#include <iostream>
#include "func.h"
#include "structures.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    //some test code
    string s = "1+1+2+4";
    string p = to_postfix(s);
    cout << p << endl;
    cout << calculate_result(p);
    
}