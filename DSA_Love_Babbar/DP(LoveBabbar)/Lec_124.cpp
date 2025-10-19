/*
    Minimum Swaps To Make Sequences Increasing

    You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i]
    with nums2[i].

    For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4]
    and nums2 = [5,6,7,8].
    Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated
    so that the given input always makes it possible.

    An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

    Example 1:

    Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
    Output: 1
    Explanation:
    Swap nums1[3] and nums2[3]. Then the sequences are:
    nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
    which are both strictly increasing.
    Example 2:

    Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
    Output: 1


    Constraints:

    2 <= nums1.length <= 105
    nums2.length == nums1.length
    0 <= nums1[i], nums2[i] <= 2 * 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(vector<int> &nums1, vector<int> &nums2, int idx, bool swapped)
{
    if (idx == nums1.size())
    {
        return 0;
    }

    int ans = INT_MAX;
    int prev1 = nums1[idx - 1];
    int prev2 = nums2[idx - 1];

    if (swapped)
    {
        swap(prev1, prev2);
    }

    // no swap
    if (nums1[idx] > prev1 && nums2[idx] > prev2)
    {
        ans = solveRecur(nums1, nums2, idx + 1, 0);
    }

    // swap
    if (nums1[idx] > prev2 && nums2[idx] > prev1)
    {
        ans = min(ans, 1 + solveRecur(nums1, nums2, idx + 1, 1));
    }

    return ans;
}

// Recursion + Memoization
int solveRM(vector<int> &nums1, vector<int> &nums2, int idx, bool swapped, vector<vector<int>> &dp)
{
    if (idx == nums1.size())
    {
        return 0;
    }
    if (dp[idx][swapped] != -1)
    {
        return dp[idx][swapped];
    }

    int ans = INT_MAX;
    int prev1 = nums1[idx - 1];
    int prev2 = nums2[idx - 1];

    if (swapped)
    {
        swap(prev1, prev2);
    }

    // no swap
    if (nums1[idx] > prev1 && nums2[idx] > prev2)
    {
        ans = solveRM(nums1, nums2, idx + 1, 0, dp);
    }

    // swap
    if (nums1[idx] > prev2 && nums2[idx] > prev1)
    {
        ans = min(ans, 1 + solveRM(nums1, nums2, idx + 1, 1, dp));
    }

    dp[idx][swapped] = ans;
    return dp[idx][swapped];
}

// Tabulation
int solveTab(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 1; i--)
    {
        for (int s = 1; s >= 0; s--)
        {
            int ans = INT_MAX;
            int prev1 = nums1[i - 1];
            int prev2 = nums2[i - 1];

            if (s)
            {
                swap(prev1, prev2);
            }

            // no swap
            if (nums1[i] > prev1 && nums2[i] > prev2)
            {
                ans = dp[i + 1][0];
            }

            // swap
            if (nums1[i] > prev2 && nums2[i] > prev1)
            {
                ans = min(ans, 1 + dp[i + 1][1]);
            }

            dp[i][s] = ans;
        }
    }
    return dp[1][0];
}

int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    // Using recursion
    // return solveRecur(nums1, nums2, 1, 0);

    // Recursion + Memoization
    // vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
    // return solveRM(nums1, nums2, 1, 0, dp);

    // Tabulation
    return solveTab(nums1, nums2);
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 4};
    vector<int> nums2 = {1, 2, 3, 7};
    cout << minSwap(nums1, nums2) << endl;
    return 0;
}