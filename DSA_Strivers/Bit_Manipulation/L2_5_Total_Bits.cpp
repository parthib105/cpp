/*
    Count total set bits

    You are given a number n. Find the total count of set bits for all numbers from 1 to n(both inclusive).

    Examples :

    Input: n = 4
    Output: 5
    Explanation: For numbers from 1 to 4. For 1: 0 0 1 = 1 set bits For 2: 0 1 0 = 1 set bits
                 For 3: 0 1 1 = 2 set bits For 4: 1 0 0 = 1 set bits Therefore, the total set bits is 5.
    Input: n = 17
    Output: 35
    Explanation: From numbers 1 to 17(both inclusive), the total number of set bits is 35.

    Expected Time Complexity: O(log N).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 ≤ n ≤ 10^8
*/

#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int count = 0;

    // Iterate over all bits (from the least significant bit to the most significant bit)
    for (int i = 0; i < 32; i++)
    {
        // Find current bit position
        int powerOf2 = 1 << i;

        // If powerOf2 exceeds n, further bits will have no contribution
        if (powerOf2 > n)
        {
            break;
        }

        // For every group of 2^(i+1), there are 'powerOf2' numbers
        // where the ith bit is set to 1
        int completeGroups = (n + 1) / (2 * powerOf2);
        int remainingNumbers = (n + 1) % (2 * powerOf2);

        // Add set bits from complete groups and remaining numbers
        count += completeGroups * powerOf2 + max(0, remainingNumbers - powerOf2);
    }

    return count;
}

int main()
{
    int n = 17;
    cout << countSetBits(n) << endl;
    return 0;
}