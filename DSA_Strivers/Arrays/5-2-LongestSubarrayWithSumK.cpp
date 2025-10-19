/*
    Longest Sub-Array with Sum K

    Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with
    the sum of the elements equal to the given value k.

    Examples:

    Input :
    arr[] = {10, 5, 2, 7, 1, 9}, k = 15
    Output : 4
    Explanation:
    The sub-array is {5, 2, 7, 1}.
    Input :
    arr[] = {-1, 2, 3}, k = 6
    Output : 0
    Explanation:
    There is no such sub-array with sum 6.

    Expected Time Complexity: O(n).
    Expected Auxiliary Space: O(n).

    Constraints:
    1 <= n <= 10^5
    -10^5 <= arr[i], K <=10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force, TC : O(n^2), SC : O(1)
int bruteForce(int A[], int N, int K)
{
    int maxLen = 0;
    for (int i = 0; i < N; i++)
    {
        int s = 0;
        for (int j = i; j < N; j++)
        {
            s += A[j];
            if (s == K)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

// Better Approach, TC : O(n^2), SC : O(1)
int better(int A[], int N, int K)
{
    int maxLen = 0;
    int currSum = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < N; i++)
    {
        currSum += A[i];
        if (currSum == K)
        {
            maxLen = i + 1;
        }

        // check for remaining length
        int rem = currSum - K;
        if (mp.find(rem) != mp.end())
        {
            maxLen = max(maxLen, i - mp[rem]);
        }

        if (mp.find(currSum) == mp.end())
        {
            mp[currSum] = i;
        }
    }
    return maxLen;
}

int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    // Brute Force
    // return bruteForce(A, N, K);
    
    // Better solution
    return better(A, N, K);
}

int main()
{

    return 0;
}