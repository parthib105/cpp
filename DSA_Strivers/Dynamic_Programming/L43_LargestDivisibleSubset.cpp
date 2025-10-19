/*
    Largest Divisible Subset

    Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
    If there are multiple solutions, return any of them.



    Example 1:

    Input: nums = [1,2,3]
    Output: [1,2]
    Explanation: [1,3] is also accepted.
    Example 2:

    Input: nums = [1,2,4,8]
    Output: [1,2,4,8]


    Constraints:

    1 <= nums.length <= 1000
    1 <= nums[i] <= 2 * 10^9
    All the integers in nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> solveTab(int n, vector<int> &nums)
{
    vector<int> dp(n, 1);
    vector<int> hash(n);

    int lds = 0;
    int lastIdx = -1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > lds)
        {
            lds = dp[i];
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

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    // Using tabulation Longest Divisible Subsequence
    return solveTab(n, nums);
}

int main()
{
    vector<int> nums = {1, 2, 4, 8};
    vector<int> ans = largestDivisibleSubset(nums);
    for (int a : ans)
        cout << a << " ";
    cout << endl;
    return 0;
}