#include <iostream>
#include <sstream>
#include "func.h"
#include "structures.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    //some test code
    cout << "Input your string" << endl;
    string s = "13+2-4";
    cin >> s;
    int k = 0;
    string* p = to_postfix(s);
    for (int i = 0; i < s.length(); i++) {
        cout << p[i] << " ";
        if (p[i] != "")
            k++;
    }
    double r = calculate_result(p, k);
    cout << r;

    
    
}