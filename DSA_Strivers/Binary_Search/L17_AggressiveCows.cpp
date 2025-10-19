/*
    You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

    Examples :

    Input: stalls[] = [1, 2, 4, 8, 9], k = 3
    Output: 3
    Explanation: The first cow can be placed at stalls[0], the second cow can be placed at stalls[2] and
    the third cow can be placed at stalls[3].
    The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

    Input: stalls[] = [10, 1, 2, 7, 5], k = 3
    Output: 4
    Explanation: The first cow can be placed at stalls[0], the second cow can be placed at stalls[1] and
    the third cow can be placed at stalls[4].
    The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.

    Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
    Output: 1
    Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
    The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.

    Constraints:
    2 <= stalls.size() <= 10^6
    0 <= stalls[i] <= 10^8
    2 <= k <= stalls.size()
*/

#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(int minDist, int k, vector<int> &stalls)
{
    int cows = 1, lastStall = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (abs(stalls[i] - lastStall) >= minDist)
        {
            cows += 1;
            lastStall = stalls[i];
        }
    }

    if (cows >= k)
    {
        return true;
    }
    return false;
}

// Brute Force solution
int bruteForceLS(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    for (int dist = (stalls.back() - stalls[0]); dist >= 1; dist--)
    {
        if (canPlaceCows(dist, k, stalls))
        {
            return dist;
        }
    }
    return -1;
}

// Optimized solution
int optimalApproachBS(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    
    int ans = -1;
    int low = 1, high = (stalls.back() - stalls[0]);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(mid, k, stalls))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    // Brute Force solution
    return bruteForceLS(stalls, k);
}

int main()
{
    return 0;
}