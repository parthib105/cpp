/*
    Number of Longest Increasing Subsequence

    Given an integer array nums, return the number of longest increasing subsequences.

    Notice that the sequence has to be strictly increasing.

    Example 1:

    Input: nums = [1,3,5,4,7]
    Output: 2
    Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
    Example 2:

    Input: nums = [2,2,2,2,2]
    Output: 5
    Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.


    Constraints:

    1 <= nums.length <= 2000
    -10^6 <= nums[i] <= 10^6
    The answer is guaranteed to fit inside a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int lis = 0;
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                count[i] = count[j];
            }
            else if (nums[i] > nums[j] && 1 + dp[j] == dp[i])
                count[i] += count[j];
        }
        lis = max(lis, dp[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == lis)
            cnt += count[i];
    }
    return cnt;
}

int main()
{
    vector<int> nums = {2, 2, 2, 2, 2};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}