// pointers - II

#include<bits/stdc++.h>
using namespace std;

void print(int* p)
{
    cout << "Printing pointer : " << p << endl;
    cout << "Printing value associated with the pointer : " << *p << endl;
}

void update(int* p)
{
    p = p + 1;
    cout << "Inside update function, p : " << p << endl;
}

void valueUpdate(int* p)
{
    *p = *p + 1;
    cout << "Inside update function, *p : " << *p << endl;
}

int main()
{

    /******************** Integer arrays ********************/

    // // array as self pointers
    // int arr[10] = {23, 122, 41, 67};
    // cout << "Address of first memory block (arr) : " << arr << endl;
    // cout << "Address of  first memory block (&arr[0]) : " << &arr[0] << endl;

    // cout << "*arr : " << *arr << endl;
    // cout << "*arr + 1: " << *arr + 1 << endl;
    // cout << "*(arr + 1) : " << *(arr + 1) << endl;

    // // arr[i] = *(arr + i) or i[arr] = *(i + arr)
    // cout << "Printing 2nd element (arr[2]) : " << arr[2] << endl;
    // cout << "Printing 2nd element (*(arr + 2)) : " << *(arr + 2) << endl;
    // cout << "Printing 2nd element (2[arr]) : " << 2[arr] << endl;

    // // size of arrays and pointer
    // int temp[10];
    // cout << "Size of array : " << sizeof(temp) << endl;

    // int* ptr = &temp[0];
    // cout << "Size of pointer : " << sizeof(ptr) << endl;

    // int Array[10];

    // // error
    // // Array = Array + 1;

    // int* pointer = &Array[0];
    // cout << "Pointer to Array : " << pointer << endl;
    // pointer = pointer + 1;
    // cout << "Pointer to Array : " << pointer << endl;

    /*********************************************************/


    /******************** Character arrays ********************/

    // // Difference between integer and character arrays
    // int arr[5] = {1, 2, 3, 4, 5};
    // char ch[6] = "abcde";

    // cout << "Printing arr : " << arr << endl;

    // // Try printing ch same as arr
    // cout << "Printing ch : " << ch << endl;

    // char* c = &ch[0];
    // cout << "Printing pointer to ch[0] : " << c << endl;
    // // implementation of cout is different for integer and character

    // char temp = 'z';
    // char *p = &temp;
    // cout << p << endl;

    /*********************************************************/


    /******************** Pointers and functions ********************/
    int val = 5;
    int* p = &val;

    print(p);

    cout << "Before updating, p : " << p << endl;
    update(p);
    cout << "After updating, p : " << p << endl;

    cout << "Before updating, *p : " << *p << endl;
    valueUpdate(p);
    cout << "After updating, *p : " << *p << endl;

    /****************************************************************/
    return 0;
}