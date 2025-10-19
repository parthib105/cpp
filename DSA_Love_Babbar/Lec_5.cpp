// Bitwise Operators, For Loops, Operator Precedence & Variable Scoping

/*
    XOR             AND             OR

    x   y   x^y     x   y   x&y     x   y   x|y
    0   0   0       0   0   0       0   0   0
    0   1   1       0   1   0       0   1   1
    1   0   1       1   0   0       1   0   1
    1   1   0       1   1   1       1   1   1
*/

#include <iostream>
using namespace std;

int main()
{
    // ********** Biteise Operators **********

    // cout << "Bitwise and, 2 & 3 : " << (2 & 3) << endl;
    // cout << "Bitwise or, 2 | 3 : " << (2 | 4) << endl;
    // cout << "Bitwise negation, ~2 : " << (~2) << endl;
    // cout << "Bitwise xor, ~2 : " << (2 ^ 4) << endl;

    // ********** Left-Shift or Right-SHift Operator **********

    // cout << (17 << 1) << endl;  // 17 * 2 = 34
    // cout << (17 << 2) << endl;  // 17 * 4 = 68
    // cout << (21 >> 1) << endl;  // 21 / 2 = 10
    // cout << (21 >> 2) << endl;  // 21 / 4 = 5

    // ********** For Loop **********

    // Fibonacci Series

    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int a = 0;
    int b = 1;
    cout << a << " " << b << " ";
    for (int i = 0; i < n; i++)
    {
        int c = a + b;
        cout << c << " ";

        a = b;
        b = c;
    }

    // int c = 0;
    // for (int i = 0, a = 0, b = 1; i < n; i++, a = b, b = c)
    // {
        
    // }
    
    
    return 0;
}