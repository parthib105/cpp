/*
    Printing Longest Increasing Subsequence

    You are given an array 'arr' of length 'n'.Find the Longest Increasing Subsequence of the array.

    A subsequence is a subset of an array achieved by removing some (possibly 0) elements without changing the order of the remaining elements. Increasing subsequence means a subsequence in which all the elements are strictly increasing.

    Longest increasing subsequence is an increasing subsequence that has the largest length possible.
    Please note that there may be more than one LIS (Longest Increasing Subsequence) possible. Return any one of the valid sequences.

    Example:
    Input: ‘arr’ = [5, 6, 3, 4, 7, 6]

    Output: LIS = [5, 6, 7] OR [3, 4, 7] OR [3, 4, 6]

    Explanation: All these three subsequences are valid Longest Increasing Subsequences. Returning any of them is correct.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    6
    5 6 3 4 7 6


    Sample Output 1:
    3


    Explanation Of Sample Input 1 :
    There are three valid LIS for the given array: [5, 6, 7], [3, 4, 7] OR [3, 4, 6], and their length is 3.


    Sample Input 2 :
    5
    1 2 3 4 5


    Sample Output 2 :
    5


    Explanation Of Sample Input 2 :
    There is only one valid LIS for the array: [1, 2, 3, 4, 5], and its length is 5.


    Expected time complexity:
    The expected time complexity is O(‘n’ ^ 2).


    Constraints:
    1 <= ‘n’ <= 500
    1 <= ‘arr[i]’ <= 10^5
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> printingLIS(int n, vector<int>& nums) 
{
	vector<int> dp(n, 1);
    vector<int> hash(n);

    int lis = 0;
    int lastIdx = -1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev ++)
        {
            if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > lis)
        {
            lis = dp[i];
            lastIdx = i;
        }
    }

    vector<int> ans;
    ans.push_back(nums[lastIdx]);
    while (hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        ans.push_back(nums[lastIdx]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 6;
    vector<int> nums = {5, 4, 11, 1, 16, 8};

    
    return 0;
}