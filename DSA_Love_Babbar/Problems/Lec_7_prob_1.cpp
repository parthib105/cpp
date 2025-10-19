/*
    Given a signed 32-bit integer x, return x with its digits reversed.
    If reversing x causes the value to go outside the signed 32-bit integer
    range [-{2}^{31}, {2}^{31} - 1], then return 0
*/

#include <iostream>
using namespace std;

int reverse(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int digit = x % 10;
        if ((rev > INT32_MAX / 10) || (rev < INT32_MIN / 10))
        {
            return 0;
        }
        rev = rev * 10 + digit;
        x = x / 10;
    }

    return rev;
}

int main()
{
    cout << reverse(136) << endl;
    return 0;
}