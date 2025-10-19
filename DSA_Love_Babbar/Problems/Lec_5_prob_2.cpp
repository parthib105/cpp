/*
    Given an integer n, return the no. of '1' bit it has
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int count = 0;
    while (n != 0)
    {
        if (n & 1)         // checking last bit
        {
            count ++;
        }
        n = n >> 1;        // using right shift operator
    }

    cout << count;
    return 0;
}