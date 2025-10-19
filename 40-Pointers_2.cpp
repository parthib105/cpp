// Revisiting pointers

#include<iostream>
using namespace std;

int main()
{
    // basic example
    int a = 4;
    int* ptr = &a;
    cout << "The value of a is " << *(ptr) << endl;

    // new keyword, dynamically allocates memory

    // int *p = new int(40);
    float *p = new float(40.78);
    // cout << "The address of 40 is " << p << endl;
    cout << "The value at address p is " << *(p) << endl;

    // allocating contiguous block of memory
    int* arr = new int[4];
    arr[0] = 2;
    arr[1] = 8;
    arr[2] = 3;
    arr[3] = 6;
    delete[] arr; // make dynamically allocated memory free

    cout<< "The value of arr[0] is " << arr[0] << endl;
    cout<< "The value of arr[1] is " << arr[1] << endl;
    cout<< "The value of arr[2] is " << arr[2] << endl;
    cout<< "The value of arr[3] is " << arr[3] << endl;
    return 0;
}