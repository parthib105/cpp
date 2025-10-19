#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    // ***************Constants***************

    const int a = 3.14;
    cout << "The value of a was: " << a << endl;
    a = 3.15; // you will get an error because 'a' is a constant
    cout << "The value of a is: " << a << endl;

    // ***************Manipulators***************
    // 'endl' is a manipulator
    
    int a = 3, b = 78, c = 1233;
    cout << "The value of a without setw is: " << a << endl;
    cout << "The value of b without setw is: " << b << endl;
    cout << "The value of c without setw is: " << c << endl;

    cout << "The value of a with is: " << setw(4) << a << endl;
    cout << "The value of b with is: " << setw(4) << b << endl;
    cout << "The value of c with is: " << setw(4) << c << endl;
    
    return 0;
}