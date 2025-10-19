/*
 Sometimes we want to make small operations side by side
 want to seperate the program, we use inline functions.
 Remember to make inline functions when the purpose of function 
 is not too large.

 ** Don't use inline function while using static variables
 in function.
*/

#include<iostream>
using namespace std;

inline int prod(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b;
    cout << "Enter the values of a and b" << endl;
    cin >> a >> b;

    cout << "The product of a and b is " << prod(a, b) << endl;
    cout << "The product of a and b is " << prod(a, b) << endl; 
    cout << "The product of a and b is " << prod(a, b) << endl;
    cout << "The product of a and b is " << prod(a, b) << endl;
    cout << "The product of a and b is " << prod(a, b) << endl;
    cout << "The product of a and b is " << prod(a, b) << endl;
    cout << "The product of a and b is " << prod(a, b) << endl;
    return 0;
}