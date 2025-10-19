// Binary to decimal conversion

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    // ********** Usual approach **********

    // int num = 0;
    // int mult = 1;
    // while (n != 0)
    // {
    //     int rem = n % 2;
    //     num = num + mult * rem;
    //     mult = mult * 10;
    //     n = n / 2;
    // }
    // cout << num;

    // ********** Using bit manipulation **********

    // int num = 0;
    // int mult = 1;
    // while (n != 0)
    // {
    //     int bit = n & 1;
    //     num = num + mult * bit;
    //     mult = mult * 10;
    //     n = n >> 1;
    // }
    // cout << num;

    // ********** Decimal to Binary **********

    int num = 0;
    int mult = 1;
    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            num = num + mult * digit;
        }
        mult = mult * 2;
        n = n / 10;
    }
    cout << num;
    return 0;
}