/*
    Swap two numbers

    Swap given two numbers and print them. (Try to do it without a temporary variable.) and return it.

    Example 1:

    Input: a = 13, b = 9
    Output: 9 13
    Explanation: after swapping it
    becomes 9 and 13.
    Example 2:

    Input: a = 15, b = 8
    Output: 8 15
    Explanation: after swapping it
    becomes 8 and 15.
    
    Expected Time Complexity: O(1)
    Expected Auxiliary Space: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a = 13, b = 34;
    cout << "Before swapping : " << " a : " << a << " , b : " << b << endl;
    swap(a, b);
    cout << "After swapping : " << " a : " << a << " , b : " << b << endl;

    return 0;
}