/*
    Symbol Table 

    It is an important data structure created and maintained by the compiler in
    order to keep track of semantics of variables i.e. it stores information about
    the scope and binding information about names, instances of various entities such as
    variable and function names, classes, objects etc.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num = 5;

    // cout << num << endl;

    // // address of Operator - &

    // cout << "Address of num is : " << &num << endl;

    // int* ptr = &num;

    // cout << "Address is : " << ptr << endl;
    // cout << "Value is : " << *ptr << endl;

    // double d = 4.3;
    // double* p2 = &d;

    // cout << "Address is : " << p2 << endl;
    // cout << "Value is : " << *p2 << endl;

    // cout << "Size of integer is : " << sizeof(num) << endl;
    // cout << "Size of pointer is : " << sizeof(ptr) << endl;
    // cout << "Size of pointer is : " << sizeof(p2) << endl;

    /***** important *****/
    // int *p = 0;
    // cout << *p << endl;     // segmentation fault as pointer is pointing to NULL

    int a = num;
    cout << "num before : " << num << endl;
    a++;
    cout << "num after : " << num << endl;

    int *p = &num;
    cout << "before : " << num << endl;
    (*p) ++;
    cout << "after : " << num << endl;


    /***** copy a pointer to another pointer *****/
    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    /***** pointer arithmatic *****/
    int i = 3;
    int *t = &i;
    cout << ++(*t) << endl;

    cout << "t before : " << t << endl;
    t = t + 1;
    cout << "t after : " << t << endl;


    return 0;
}