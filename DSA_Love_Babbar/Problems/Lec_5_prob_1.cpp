/*
    Given an integer n, return the difference between 
    the product of its digits and the sum of its digits
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    int sum = 0;
    int prod = 1;
    while (n > 0)
    {
        int dig = n % 10;
        sum += dig;
        prod *= dig;
        n = n / 10;
    }

    cout << prod - sum;
    return 0;
}