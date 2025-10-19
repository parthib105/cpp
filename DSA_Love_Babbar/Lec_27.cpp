// Double pointers

#include<bits/stdc++.h>
using namespace std;

void update(int** p)
{
    // p = p + 1;      // no updation

    // *p = *p + 1;    // changes ptr

    **p = **p + 1;     // changes i

    // cout << "Inside function, p : " << p << endl;
}

int main()
{
    int i = 5;
    int* ptr = &i;
    int** ptr2 = &ptr;

    /******************* Double Pointers ********************/

    // cout << "Printing ptr (ptr) : " << ptr << endl;
    // cout << "Printing ptr (*pyr2) : " << *ptr2 << endl;
    // cout << "Address of ptr (&ptr) : " << &ptr << endl;
    // cout << "Address of ptr (ptr2) : " << ptr2 << endl;

    // // printing i
    // cout << "Print i (i) : " << i << endl;
    // cout << "Print i (*ptr) : " << *ptr << endl;
    // cout << "Print i (**ptr2) : " << **ptr2 << endl;

    // // printing ptr
    // cout << "Print ptr (&i) : " << &i << endl;
    // cout << "Print ptr (ptr) : " << ptr << endl;
    // cout << "Print ptr (*ptr2) : " << *ptr2 << endl;

    // // printing ptr2
    // cout << "Print ptr2 (&ptr) : " << &ptr << endl;
    // cout << "Print ptr2 (ptr2) : " << ptr2 << endl;

    /*********************************************************************/


    /******************* Double Pointers in Functions ********************/
    
    cout << "Before update, i : " << i << endl;
    cout << "Before update, ptr : " << ptr << endl;
    cout << "Before update, ptr2 : " << ptr2 << endl;
    update(ptr2);
    cout << "After updation, i : " << i << endl;
    cout << "After updation, ptr : " << ptr << endl;
    cout << "After updation, ptr2 : " << ptr2 << endl;
    /*********************************************************************/
    
    return 0;
}