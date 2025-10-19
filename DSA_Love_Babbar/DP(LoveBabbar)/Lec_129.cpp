/*
    Minimum Cost Tree From Leaf Values

    Given an array arr of positive integers, consider all binary trees such that:

    Each node has either 0 or 2 children;
    The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
    The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree,
    respectively. Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf
    node. It is guaranteed this sum fits into a 32-bit integer.

    A node is a leaf if and only if it has zero children.

    Example 1:

    Input: arr = [6,2,4]
    Output: 32
    Explanation: There are two possible trees shown.
    The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

    Example 2:

    Input: arr = [4,11]
    Output: 44

    Constraints:

    2 <= arr.length <= 40
    1 <= arr[i] <= 15
    It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 2^631).
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(vector<int> &arr, map<pair<int, int>, int> &rangeMax, int i, int j)
{
    // leaf node
    if (i == j)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int curr = rangeMax[{i, k}] * rangeMax[{k + 1, j}] + solveRecur(arr, rangeMax, i, k) + solveRecur(arr, rangeMax, k + 1, j);
        ans = min(ans, curr);
    }
    return ans;
}

// Recursion + Memoization
int solveRM(vector<int> &arr, map<pair<int, int>, int> &rangeMax, vector<vector<int>> &dp, int i, int j)
{
    // leaf node
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int curr = rangeMax[{i, k}] * rangeMax[{k + 1, j}] + solveRM(arr, rangeMax, dp, i, k) + solveRM(arr, rangeMax, dp, k + 1, j);
        ans = min(ans, curr);
    }
    return dp[i][j] = ans;
}

int mctFromLeafValues(vector<int> &arr)
{
    // store max elements from range i to j
    int n = arr.size();
    map<pair<int, int>, int> rangeMax;
    for (int i = 0; i < arr.size(); i++)
    {
        rangeMax[{i, i}] = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            rangeMax[{i, j}] = max(arr[j], rangeMax[{i, j - 1}]);
        }
    }

    // Recursive solution
    // return solveRecur(arr, rangeMax, 0, n - 1);

    // Recursion + Memoization
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solveRM(arr, rangeMax, dp, 0, n - 1);
}

int main()
{
    vector<int> arr = {4, 11};
    cout << mctFromLeafValues(arr) << endl;
    return 0;
}