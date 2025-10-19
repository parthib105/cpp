/*
    Minimum Elements

    You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell the 
    minimum number of elements you have to take to reach the target sum ‘X’.

    Note:
    You have an infinite number of elements of each type.
    For example
    If N=3 and X=7 and array elements are [1,2,3]. 
    Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
    Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
    Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
    Hence the output is 3.

    Constraints:
    1 <= N <= 15
    1 <= nums[i] <= (2^31) - 1
    1 <= X <= 10000

    All the elements of the “nums” array will be unique.
    Time limit: 1 sec

    Sample Input 1 :
    3 7
    1 2 3

    1 0
    1
    Sample output 1 :
    3
    0

    Explanation For Sample Output 1:
    For the first test case,
    Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
    Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
    Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
    Hence the output is 3.

    For the second test case,
    Way 1 - You can take 3 elements  [1, 1, 1] as 1 + 1 + 1  = 3.
    Way 2 - You can take 2 elements  [2, 1] as 2 + 1 = 3.
    Here, you can see in Way 2 we have used 2 coins to reach the target sum of 7.
    Hence the output is 2.
*/

#include<bits/stdc++.h>
using namespace std;

// Recursion
int solveRecur(vector<int> &num, int x)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x < 0)
    {
        return INT_MAX;
    }

    int minElm = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveRecur(num, x - num[i]);
        if (ans != INT_MAX)
        {
            minElm = min(minElm, 1 + ans);
        }
    }
    return minElm;
}

// Recursion + Memoization
int solveRM(vector<int> &num, int x, vector<int>& dp)
{
    if (x == 0)
    {
        return 0;
    }
    else if (x < 0)
    {
        return INT_MAX;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int minElm = INT_MAX;
    for (int i = 0; i < num.size(); i++)
    {
        int ans = solveRecur(num, x - num[i]);
        if (ans != INT_MAX)
        {
            minElm = min(minElm, 1 + ans);
        }
    }

    dp[x] = minElm;
    return dp[x];
}

// Tabulation
int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    if (dp[x] == INT_MAX)
    {
        return -1;
    }
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    // Recursion
    // int ans = solveRecur(num, x);
    // if (ans == INT_MAX)
    // {
    //     return -1;
    // }
    // return ans;

    // Recursion + Memoization
    // vector<int> dp(x + 1, -1);
    // int ans = solveRM(num, x, dp);
    // if (ans == INT_MAX)
    // {
    //     return -1;
    // }
    // return ans;

    // Tabulation
    return solveTab(num, x);
}

int main()
{
    vector<int> num = {2, 1};
    int x = 11;
    cout << minimumElements(num, x) << endl;
    return 0;
}