/*
    Reducing Dishes

    A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

    Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by
    its satisfaction level i.e. time[i] * satisfaction[i].

    Return the maximum sum of like-time coefficient that the chef can obtain after preparing some amount of dishes.

    Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

    Example 1:

    Input: satisfaction = [-1,-8,0,5,-9]
    Output: 14
    Explanation: After Removing the second and last dish, the maximum total like-time coefficient will be equal to
    (-1*1 + 0*2 + 5*3 = 14).
    Each dish is prepared in one unit of time.
    Example 2:

    Input: satisfaction = [4,3,2]
    Output: 20
    Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
    Example 3:

    Input: satisfaction = [-1,-4,-5]
    Output: 0
    Explanation: People do not like the dishes. No dish is prepared.


    Constraints:

    n == satisfaction.length
    1 <= n <= 500
    -1000 <= satisfaction[i] <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

int solveRecur(int idx, int time, vector<int> &satisfaction)
{
    if (idx == satisfaction.size())
    {
        return 0;
    }

    // include and exclude
    int incl = satisfaction[idx] * (time + 1) + solveRecur(idx + 1, time + 1, satisfaction);
    int excl = solveRecur(idx + 1, time, satisfaction);

    return max(incl, excl);
}

int solveRM(int idx, int time, vector<int> &satisfaction, vector<vector<int>> &dp)
{
    if (idx == satisfaction.size())
    {
        return 0;
    }

    if (dp[idx][time] != -1)
    {
        return dp[idx][time];
    }

    int incl = satisfaction[idx] * (time + 1) + solveRecur(idx + 1, time + 1, satisfaction);
    int excl = solveRecur(idx + 1, time, satisfaction);

    dp[idx][time] = max(incl, excl);
    return dp[idx][time];
}

// Tabulation
int solveTab(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int time = idx; time >= 0; time--)
        {
            int incl = satisfaction[idx] * (time + 1) + dp[idx + 1][time + 1];
            int excl = dp[idx + 1][time];

            dp[idx][time] = max(incl, excl);
        }
    }
    return dp[0][0];
}

int solveSO(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int time = idx; time >= 0; time--)
        {
            int incl = satisfaction[idx] * (time + 1) + next[time + 1];
            int excl = next[time];

            curr[time] = max(incl, excl);
        }
        next = curr;
    }
    return next[0];
}

int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());

    // recursive solution
    // return solveRecur(0, 0, satisfaction);

    // Recursion + Memoization
    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // return solveRM(0, 0, satisfaction, dp);

    // Tabulation
    // return solveTab(satisfaction);

    // Space Optimization
    return solveSO(satisfaction);
}

int main()
{
    vector<int> s = {-1, -8, 0, 5, -9};
    cout << maxSatisfaction(s) << endl;
    return 0;
}