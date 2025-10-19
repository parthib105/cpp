// What is a pointer? -----> data type which holds the address
// of other data types

#include<iostream>
using namespace std;

int main()
{
    int a = 3;
    int* b = &a;
    
    // & ---> (Address of) operator
    cout << "The address of a is " << b << endl;
    cout << "The address of a is " << &a << endl;

    // * ---> (value at) Dereference operator
    cout << "The value at address b is " << *b << endl;

    // Pointer to pointer
    int** c = &b;
    cout << "The address of b is " << &b << endl;
    cout << "The address of b is " << c << endl;
    cout << "The value_at(c) is " << *c << endl;
    cout << "The value_at(value_at(c)) is " << **c << endl;

    return 0;
}