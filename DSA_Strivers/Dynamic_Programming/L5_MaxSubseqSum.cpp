/*
    Maximum sum of non-adjacent elements
    
    You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the 
    constraint that no two elements are adjacent in the given array/list.

    Note:
    A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving 
    the remaining elements in their original order.
    
    Constraints:
    1 <= T <= 500
    1 <= N <= 1000
    0 <= ARR[i] <= 10^5

    Where 'ARR[i]' denotes the 'i-th' element in the array/list.

    Time Limit: 1 sec.

    Sample Input 1:
    2
    3
    1 2 4
    4
    2 1 4 9
    Sample Output 1:
    5
    11
    Explanation to Sample Output 1:
    In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

    In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and
    'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no 
    elements are adjacent in the given array/list.

    Sample Input 2:
    2
    5
    1 2 3 5 4
    9
    1 2 3 1 3 5 8 1 9
    Sample Output 2:
    8
    24
    Explanation to Sample Output 2:
    In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]' and 'ARR[4]', i.e. 8, it will give 
    the maximum sum of sequence in which no elements are adjacent in the given array/list.

    In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]', 'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', 
    i.e. 24 so, it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.
*/

#include<bits/stdc++.h>
using namespace std;

int solveRecur(int i, vector<int> &nums)
{
    if (i < 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return nums[i];
    }

    int incl = nums[i] + solveRecur(i - 2, nums);
    int excl = 0 + solveRecur(i - 1, nums);
    return max(incl, excl);
}

int solveRM(int i, vector<int> &nums, vector<int> &dp)
{
    if (i < 0)
    {
        return 0;
    }
    if (i == 0)
    {
        return nums[i];
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int incl = nums[i] + solveRM(i - 2, nums, dp);
    int excl = 0 + solveRM(i - 1, nums, dp);
    return dp[i] = max(incl, excl);
}

int solveTab(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];

    for (int i = 1; i <= n; i++)
    {
        int incl = INT_MIN;
        if (i - 2 >= 0)
        {
            incl = nums[i] + dp[i - 2];
        }

        int excl = 0 + dp[i - 1];

        dp[i] = max(incl, excl);
    } 
    return dp[n - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();

    // Recursion
    // return solveRecur(n - 1, nums);

    // Recursion + Memoization
    // vector<int> dp(n + 1, -1);
    // return solveRM(n - 1, nums, dp);

    // Tabulation
    return solveTab(nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    cout << maximumNonAdjacentSum(nums) << endl;
    return 0;
}