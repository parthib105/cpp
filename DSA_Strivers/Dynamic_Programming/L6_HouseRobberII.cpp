/*
    House Robber II

    Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden.
    All houses along this street are arranged in a circle. That means the first house is the neighbour of the last one.
    Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent
    houses are broken into on the same night.

    You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to
    return the maximum amount of money Mr. X can rob tonight without alerting the police.

    Note:
    It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. Just print the maximum
    possible robbed amount, irrespective of sets of houses robbed.

    For example:
    (i) Given the input array arr[] = {2, 3, 2} the output will be 3 because Mr X cannot rob house 1 (money = 2) and then rob
        house 3 (money = 2), because they are adjacent houses. So, he’ll rob only house 2 (money = 3)

    (ii) Given the input array arr[] = {1, 2, 3, 1} the output will be 4 because Mr X rob house 1 (money = 1) and then rob
         house 3 (money = 3).

    (iii) Given the input array arr[] = {0} the output will be 0 because Mr. X has got nothing to rob.

    Constraints:
    1 <= T <= 10
    1 <= N <= 5 x 10 ^ 3
    1 <= ARR[i] <= 10 ^ 9

    Time limit: 1 sec.

    Sample Input 1:
    3
    1
    0
    3
    2 3 2
    4
    1 3 2 1
    Sample Output 1:
    0
    3
    4

    Explanation of Input 1:

    (i) Mr. X has only one house to rob, but with no money.

    (ii) Mr. X cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses (remember,
         it’s a circular street). So, he’ll rob only house 2 (money = 3) with a maximum value

    (iii) Mr. X will get maximum value when he robs house 2 (money = 3) and then robs house 4 (money = 1) i.e. 4 units of money.
    Sample Input 2:
    3
    5
    1 5 1 2 6
    3
    2 3 5
    4
    1 3 2 0
    Sample Output 2:
    11
    5
    3
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int i, vector<int> &nums)
{
    if (i >= nums.size())
    {
        return 0;
    }

    // rob
    int incl = nums[i] + solveRecur(i + 2, nums);
    // skip
    int excl = 0 + solveRecur(i + 1, nums);

    return max(incl, excl);
}

int solveRM(int i, vector<int> &nums, vector<int> &dp)
{
    if (i >= nums.size())
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    // rob
    int incl = nums[i] + solveRM(i + 2, nums, dp);
    // skip
    int excl = 0 + solveRM(i + 1, nums, dp);

    return dp[i] = max(incl, excl);
}

int solveTab(vector<int> &nums)
{
    vector<int> dp(nums.size() + 2, 0);

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        // rob
        int incl = nums[i] + dp[i + 2];
        // skip
        int excl = 0 + dp[i + 1];

        dp[i] = max(incl, excl);
    }

    return dp[0];
}

int solveSO(vector<int> &nums)
{
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int curr = max(prev2 + nums[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    vector<int> fst, lst;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0)
        {
            fst.push_back(nums[i]);
        }
        if (i < nums.size() - 1)
        {
            lst.push_back(nums[i]);
        }
    }

    int op1, op2;

    // Recursion
    // op1 = solveRecur(0, fst);
    // op2 = solveRecur(0, lst);

    // Recursion + Memoization
    // vector<int> dp1(fst.size() + 1, -1);
    // vector<int> dp2(lst.size() + 1, -1);
    // op1 = solveRM(0, fst, dp1);
    // op2 = solveRM(0, lst, dp2);

    // Tabulation
    // op1 = solveTab(fst);
    // op2 = solveTab(lst);

    // Space Optimization
    op1 = solveSO(fst);
    op2 = solveSO(lst);

    return max(op1, op2);
}

int main()
{
    int n = 5;
    vector<int> nums = {1, 5, 1, 2, 6};

    cout << rob(nums) << endl;
    return 0;
}