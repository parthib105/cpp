#include <iostream>
using namespace std;

int c = 45;

int main()
{
    // ***************Build in Data Types***************
    
    // int a, b, c;
    // cout << "Enter the value of a: ";
    // cin >> a;
    // cout << "Enter the value of b: ";
    // cin >> b;
    // c = a + b;
    // cout << "The sum is: " << c << endl;
    // cout << "The global c is: " << ::c; //scope resolution operator, '::' , can be use to use the global variable

    // ***************Reference Variables***************

    // float x = 455;
    // float &y = x;
    // cout << x << endl;
    // cout << y << endl;

    // ***************Typecasting***************

    float n = 45.99;
    cout << "The value of n is " << int(n) << endl;
    cout << "The value of n is " << (int)n << endl;
    return 0;
}