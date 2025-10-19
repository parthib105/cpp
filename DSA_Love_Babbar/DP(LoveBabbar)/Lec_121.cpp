/*
    Pizza With 3n Slices

    There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
        -> You will pick any pizza slice.
        -> Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
        -> Your friend Bob will pick the next slice in the clockwise direction of your pick.
    Repeat until there are no more slices of pizzas.
    Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum
    possible sum of slice sizes that you can pick.

    Example 1:
    Input: slices = [1,2,3,4,5,6]
    Output: 10
    Explanation: Pick pizza slice of size 4, Alice and Bob will pick slices with size 3 and 5 respectively. Then Pick slices with size 6, finally Alice and Bob will pick slice of size 2 and 1 respectively. Total = 4 + 6.

    Example 2:
    Input: slices = [8,9,8,6,1,1]
    Output: 16
    Explanation: Pick pizza slice of size 8 in each turn. If you pick slice with size 9 your partners will pick slices of
    size 8.

    Constraints:

    3 * n == slices.length
    1 <= slices.length <= 500
    1 <= slices[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
int solveRecur(int st, int ed, int n, vector<int> &slices)
{
    if (n == 0 || st > ed)
    {
        return 0;
    }

    // eating pizza => I can't eat pizzas at idx - 1 and idx + 1
    int incl = slices[st] + solveRecur(st + 2, ed, n - 1, slices);
    int excl = solveRecur(st + 1, ed, n, slices);

    return max(incl, excl);
}

// Recursion + Memoization
int solveRM(int st, int ed, int n, vector<int> &slices, vector<vector<int>> &dp)
{
    if (n == 0 || st > ed)
    {
        return 0;
    }
    if (dp[st][n] != -1)
    {
        return dp[st][n];
    }

    // eating pizza => I can't eat pizzas at idx - 1 and idx + 1
    int incl = slices[st] + solveRM(st + 2, ed, n - 1, slices, dp);
    int excl = solveRM(st + 1, ed, n, slices, dp);
    dp[st][n] = max(incl, excl);

    return dp[st][n];
}

// Tabulation
int solveTab(vector<int> &slices)
{
    int k = slices.size();
    vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
    vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));

    // case 1
    for (int idx = k - 2; idx >= 0; idx--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int incl = slices[idx] + dp1[idx + 2][n - 1];
            int excl = dp1[idx + 1][n];
            dp1[idx][n] = max(incl, excl);
        }
    }
    int case1 = dp1[0][k / 3];

    // case 2
    for (int idx = k - 1; idx >= 1; idx--)
    {
        for (int n = 1; n <= k / 3; n++)
        {
            int incl = slices[idx] + dp2[idx + 2][n - 1];
            int excl = dp2[idx + 1][n];
            dp2[idx][n] = max(incl, excl);
        }
    }
    int case2 = dp2[1][k / 3];

    return max(case1, case2);
}

int maxSizeSlices(vector<int> &slices)
{
    int k = slices.size();

    // Recursive Solution
    // int case1 = solveRecur(0, k - 2, k / 3, slices);
    // int case2 = solveRecur(1, k - 1, k / 3, slices);
    // return max(case1, case2);

    // Recursion + Memoization
    // vector<vector<int>> dp1(k, vector<int>(k, -1));
    // vector<vector<int>> dp2(k, vector<int>(k, -1));
    // int case1 = solveRM(0, k - 2, k/3, slices, dp1);
    // int case2 = solveRM(1, k - 1, k/3, slices, dp2);
    // return max(case1, case2);

    // Tabulation
    return solveTab(slices);
}

int main()
{
    vector<int> slices = {8, 9, 8, 6, 1, 1};
    cout << maxSizeSlices(slices) << endl;
    return 0;
}