// Initialization list in Constructors

/*
Syntax for initialization list in constructor:
constructor (argument-list) : initialization-section
{
    assignment + other code
}
*/

#include<iostream>
using namespace std;

class Test
{
private:
    int a;
    int b;

public:
    // Test(int i, int j) : a(i), b(i + j)
    // Test(int i, int j) : a(i), b(2 * j)
    // Test(int i, int j) : a(i), b(a + j)
    // Test(int i, int j) : b(j), a(b + i) // RED FLAG --> This will create problem because a will be initialized first
    Test(int i, int j) : a(i), b(j)
    {
        cout << "Constructor executed" << endl;
        cout << "value of a is " << a << endl;
        cout << "value of b is " << b << endl; 
    }
};

int main()
{
    Test t(4, 6);
    return 0;
}