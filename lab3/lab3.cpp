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
    string s;
    cin >> s;
    string* p = to_postfix(s);
    int k = n_tokens(p);
    //for (int i = 0; i < s.length(); i++) {
    //    cout << p[i] << " ";
    //    if (p[i] != "")
    //        k++;
    //}
    double r = calculate_result(p, k);
    cout << r;

    
    
}