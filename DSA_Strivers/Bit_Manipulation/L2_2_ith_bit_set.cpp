/*
    K-th Bit is Set or Not

    Given a number n and a bit number k, check if kth index bit of n is set or not. A bit is called set if it is 1. Position 
    of set bit '1' should be indexed starting with 0 from LSB side in binary representation of the number.
    
    Note: Index is starting from 0. You just need to return true or false, driver code will take care of printing "Yes" and "No".

    Examples : 

    Input: n = 4, k = 0
    Output: No
    Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
    Input: n = 4, k = 2
    Output: Yes
    Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
    Input: n = 500, k = 3
    Output: No
    Explanation: Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.

    Expected Time Complexity: O(1).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 ≤ n ≤ 10^9
    0 ≤ k ≤ 31
*/

#include<bits/stdc++.h>
using namespace std;

/*
    n = 13, k = 2

    n = 13       ->  1101
    (1 << k)     ->  0100
    n & (1 << k) ->  0100   
*/
bool checkBit(int n, int k)
{
    // using left shift
    // return n & (1 << k);

    // using right shift
    return (n >> k) & 1;
}

int setBit(int n, int k)
{
    return n | (1 << k);
}

int clearBit(int n, int k)
{
    return n & (~(1 << k));
}

int toggleBit(int n, int k)     // flip 1 to 0 and 0 to 1
{
    return n ^ (1 << k);
}

int main()
{
    cout << setBit(9, 2) << endl;
    cout << clearBit(15, 0) << endl;
    return 0;
}