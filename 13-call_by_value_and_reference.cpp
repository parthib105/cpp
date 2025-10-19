#include<iostream>
using namespace std;

void swap_by_value(int a, int b)
{
    int temp = a;
    a = b;
    b = a;
}

void swap_by_pointer(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_by_refVar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    // ***************call by value***************

    // int a = 5, b = 8;
    // cout << "The value of a, b is " << a << ", " << b << endl;
    // swap_by_value (a, b);
    // cout << "The value of a, b is " << a << ", " << b << endl;
    
    // This will not swap a, b

    // ***************call by reference(pointer)***************

    // int a = 5, b = 8;
    // cout << "The value of a, b is " << a << ", " << b << endl;
    // swap_by_pointer (&a, &b);
    // cout << "The value of a, b is " << a << ", " << b << endl;
    
    // ***************call by reference(variable)***************

    int a = 5, b = 8;
    cout << "The value of a, b is " << a << ", " << b << endl;
    swap_by_refVar(a, b);
    cout << "The value of a, b is " << a << ", " << b << endl;
    return 0;
}