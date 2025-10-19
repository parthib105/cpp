#include <iostream>
using namespace std;

int main()
{
    // int a = 2;
    // int b = a + 1;

    // if ((a = 3) == b)
    // {
    //     cout << "a : " << a;
    // }
    // else
    // {
    //     cout << "a + 1 : " << a + 1;
    // }

    /*
        Question:
        
        char ch
        if 'a' < ch < 'z' -> lower case
        if 'A' < ch < 'Z' -> upper case
        if '0' < ch < '9' -> numeric

        a = 97
        z = 122
        A = 65
        Z = 90
        0 = 48
        9 = 57
    */

    char ch;
    cout << "Enter the value of ch : ";
    cin >> ch;

    int a = ch;
    if (a >= 97 && a <= 122)
    {
        cout << "Lower case";
    }
    else if (a >= 65 && a <= 90)
    {
        cout << "Upper case";
    }
    else if (a >= 48 && a <= 57)
    {
        cout << "Numeric";
    }
    return 0;
}