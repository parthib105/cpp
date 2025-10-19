/*
    Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum.

    Examples:

    Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
    Output: true
    Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
    Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
    Output: false
    Explanation: There is no subset with target sum 30.
    Input: arr[] = [1, 2, 3], sum = 6
    Output: true
    Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
    Constraints:
    1 <= arr.size() <= 200
    1<= arr[i] <= 200
    1<= sum <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(2^N), S.C. : O(N) (stack space)
bool solveRecur(int i, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[i] == target;

    // include
    bool exc = solveRecur(i - 1, target, arr);

    // exclude
    bool inc = false;
    if (arr[i] <= target)
        inc = solveRecur(i - 1, target - arr[i], arr);

    return inc || exc;
}

// T.C. : O(N x sum), S.C. : O(N x sum) + O(N) (stack space)
bool solveRM(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[i] == target;

    if (dp[i][target] != -1)
        return dp[i][target];

    // include
    bool exc = solveRM(i - 1, target, arr, dp);

    // exclude
    bool inc = false;
    if (arr[i] <= target)
        inc = solveRM(i - 1, target - arr[i], arr, dp);

    dp[i][target] = inc || exc;
    return dp[i][target];
}

// T.C. : O(N x sum), S.C. : O(N x sum)
bool solveTab(int target, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // base case
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int t = 1; t <= target; t++)
        {
            // include
            bool exc = dp[i - 1][t];

            // exclude
            bool inc = false;
            if (arr[i] <= t)
                inc = dp[i - 1][t - arr[i]];

            dp[i][t] = inc || exc;
        }
    }
    return dp[n - 1][target];
}

// T.C. : O(N x sum), S.C. : O(2 x sum)
bool solveSO(int target, vector<int> &arr)
{
    int n = arr.size();

    vector<bool> prev(target + 1, false), curr(target + 1, false);

    // base case
    prev[0] = curr[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int t = 1; t <= target; t++)
        {
            // include
            bool exc = prev[t];

            // exclude
            bool inc = false;
            if (arr[i] <= t)
                inc = prev[t - arr[i]];

            curr[t] = inc || exc;
        }
        prev = curr;
    }
    return prev[target];
}

bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();

    // Using recursion
    // return solveRecur(n - 1, sum, arr);

    // Recursion + Memoization
    // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    // return solveRM(n - 1, sum, arr, dp);

    // Tabulation
    // return solveTab(sum, arr);

    // Space Optimization
    return solveSO(sum, arr);
}

int main()
{
    int sum = 9;
    vector<int> arr = {3, 34, 4, 12, 5, 2};

    bool ans = isSubsetSum(arr, sum);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}