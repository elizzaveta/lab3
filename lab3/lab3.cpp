#include <iostream>
#include "func.h"
#include "structures.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";



    //some test code to check if stack works after pull request from github
    Stack stek(3);
    for (int i = 0; i < 3; i++) {
        stek.push(i + 1);
    }
    int a = stek.size();
    for (int i = 0; i < a; i++) {
        cout << "elem to go: " << stek.pop() << endl;
    }
    stek.clear();
    //delete after check
}