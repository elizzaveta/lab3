#include <iostream>
#include <sstream>
#include "func.h"
#include "structures.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    //some test code
    string s = "13+2-4";
    cout << s << endl;
    string* p = to_postfix(s);
    for (int i = 0; i < s.length(); i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    double r = calculate_result(p, s.length());
    cout << r;

    
    
}