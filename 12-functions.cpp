#include<iostream>
using namespace std;

// function prototype
int sum(int, int);

int main()
{
    int num1, num2;
    // num1 and num2 are actual parameters

    cout << "Enter first number ";
    cin >> num1;

    cout << "Enter second number ";
    cin >> num2;

    cout << "The sum is " << sum(num1, num2);

    return 0;
}

int sum(int a, int b)
{
    //Formal parameters a and b will be taking values from actual parameters
    int c = a + b;
    return c;
}