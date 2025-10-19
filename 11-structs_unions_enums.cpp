#include<iostream>
using namespace std;

typedef struct employee // here, struct allocates 9 bytes of memory
{
    int eID; // 4 bytes
    char favChar; // 1 byte
    float salary; // 4 bytes
} ep;

union money // allocates the max byte of memory among the given
{
    int rice; // 4 bytes
    char car; // 1 byte
    float pounds; // 4 bytes
}; // one value at a time

int main()
{
    // ***************struct***************

    // ep parthib;
    // parthib.eID = 1;
    // parthib.favChar = 'c';
    // parthib.salary = 1200000;
    // cout << "The value is " << parthib.eID << endl;
    // cout << "The value is " << parthib.favChar << endl;
    // cout << "The value is " << parthib.salary << endl;

    // ***************union***************

    // union money m1;
    // m1.rice = 34;
    // m1.car = 'c';
    // cout << m1.rice;

    // ***************enum***************
    
    enum Meal{ breakfast, lunch, dinner }; // Meal is now a datatype
    cout << breakfast << endl;
    cout << lunch << endl;
    cout << dinner << endl;

    return 0;
}