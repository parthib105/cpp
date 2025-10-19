/*
    Maximum sum of non-adjacent elements

    You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the 
    constraint that no two elements are adjacent in the given array/list.

    Note:
    A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving 
    the remaining elements in their original order.

    Constraints:
    1 <= N <= 1000
    0 <= ARR[i] <= 10^5

    Where 'ARR[i]' denotes the 'i-th' element in the array/list.

    Time Limit: 1 sec.

    Sample Input 1:
    3
    1 2 4

    4
    2 1 4 9

    Sample Output 1:
    5
    11

    Explanation to Sample Output 1:
    In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

    In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' 
    and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no 
    elements are adjacent in the given array/list.
*/

#include<bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(vector<int>& nums, int i, int n)
{
    if (i >= n)
    {
        return 0;
    }

    // include - exclude
    int incl = solveRecur(nums, i + 2, n) + nums[i];
    int excl = solveRecur(nums, i + 1, n);

    return max(incl, excl);
}

// Recursion + Memoization
int solveRM(int i, int n, vector<int>& nums, vector<int> &dp)
{
    if (i >= n)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int incl = solveRM(i + 2, n, nums, dp) + nums[i];
    int excl = solveRM(i + 1, n, nums, dp);

    dp[i] = max(incl, excl);
    return dp[i];
}

// Tabulation
int solveTab(vector<int> &nums, int n)
{
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[n - 1];
}

// Space Optimization
int solveSO(vector<int> &nums, int n)
{
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1;

        int curr = max(incl, excl);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    // using recursion
    // return solveRecur(nums, 0, n);

    // using recursion + memoization
    // vector<int> dp(n, -1);
    // return solveRM(0, n, nums, dp);

    // Tabulation
    return solveTab(nums, n);

    // Space Optimization
    return solveSO(nums, n);

}

int main()
{
    vector<int> nums = {2, 1, 4, 9};
    cout << maximumNonAdjacentSum(nums) << endl;
    return 0;
}