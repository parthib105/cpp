/*
    Minimum cost for ticket

    Ninja's Trip

    Ninja is willing to take some time off from his training and planning a year-long tour. You are given a DAYS array 
    consisting of ‘N’ days when Ninjas will be traveling during the year. Each Day is an integer between 1 to 365 (both 
    inclusive). Train tickets are sold in three different ways:

    A 1-day pass is sold for 'COST'[0] coins,
    A 7-day pass is sold for 'COST'[1] coins, and
    A 30-day  pass is sold for 'COST'[2] coins.

    The passes allow for many days of consecutive travel.
    Your task is to help the Ninja to find the minimum number of coins required to complete his tour. For example,
    If Ninja gets a 7-day pass on day 2, then he can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.

    Constraints:
    1 <= N <= 365
    1 <= DAYS[i] <= 365

    Time Limit: 1 sec

    Sample Input 1:
    2 
    2 5
    1 4 25 

    7
    1 3 4 5 7 8 10
    2 7 20

    Sample Output 1:
    2
    11

    Explanation For sample input 1:

    For the first test case, 
    On Day 2, Ninja will buy a 1-day pass with 1 coin.
    On Day 5, Ninja will buy a 1-day pass with 1 coin.
    In total, Ninja will spend 2 coins. Hence the answer is 2.

    For the second test case,
    On Day 1, Ninja will buy a 1-day pass with 2 coins.
    On Day 3, Ninja will buy a 7-day pass with 7 coins valid for days 3,4,5...9.
    On Day 10, Ninja will buy a 1-day pass with 2 coins.
    In total, Ninja will spend 11 coins. Hence the answer is 11.

    Sample Input 2:
    6
    1 4 6 7 8 20
    2 7 15

    12
    1 2 3 4 5 6 7 8 9 10 30 31
    2 7 15 
    Sample Output 2:
    11
    17
*/

#include<bits/stdc++.h>
using namespace std;

int solveRecur(int n, int idx, vector<int> &days, vector<int> &cost)
{
    if (idx >= n)
    {
        return 0;
    }

    // 1 day trip
    int _1_day_trip = cost[0] + solveRecur(n, idx + 1, days, cost);
    
    int i;
    for (i = idx; i < n && days[i] < days[idx] + 7; i++);

    // 7 days trip
    int _7_days_trip = cost[1] + solveRecur(n, i, days, cost);

    for (i = idx; i < n && days[i] < days[idx] + 30; i++);

    // 30 days trip
    int _30_days_trip = cost[2] + solveRecur(n, i, days, cost);

    return min(_1_day_trip, min(_7_days_trip, _30_days_trip));
}

int solveRM(int n, int idx, vector<int> &days, vector<int> &cost, vector<int> &dp)
{
    if (idx >= n)
    {
        return 0;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    // 1 day trip
    int _1_day_trip = cost[0] + solveRM(n, idx + 1, days, cost, dp);
    
    int i;
    for (i = idx; i < n && days[i] < days[idx] + 7; i++);

    // 7 days trip
    int _7_days_trip = cost[1] + solveRM(n, i, days, cost, dp);

    for (i = idx; i < n && days[i] < days[idx] + 30; i++);

    // 30 days trip
    int _30_days_trip = cost[2] + solveRM(n, i, days, cost, dp);

    dp[idx] = min(_1_day_trip, min(_7_days_trip, _30_days_trip));
    return dp[idx];
}

int solveTab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int j = n - 1; j >= 0; j--)
    {
        // 1 day trip
        int _1_day_trip = cost[0] + dp[j + 1];

        int i;
        for (i = j; i < n && days[i] < days[j] + 7; i++);

        // 7 days trip
        int _7_days_trip = cost[1] + dp[i];

        for (i = j; i < n && days[i] < days[j] + 30; i++);

        // 30 days trip
        int _30_days_trip = cost[2] + dp[i];

        dp[j] = min(_1_day_trip, min(_7_days_trip, _30_days_trip));
    }

    return dp[0];
}

int solveSO(int n, vector<int> &days, vector<int> &cost)
{
    int ans = 0;

    // queue<days, cost till day>
    queue<pair<int, int>> week;
    queue<pair<int, int>> month;

    for (int day : days)
    {
        // Remove expired days
        while (!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
        }
        while (!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }

        // add cost for current day
        week.push({day, ans + cost[1]});
        month.push({day, ans + cost[2]});

        // update ans
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Recursive 
    // return solveRecur(n, 0, days, cost);

    // Recursion + Memoization
    // vector<int> dp(n + 1, -1);
    // return solveRM(n, 0, days, cost, dp);
    
    // Tabulation
    // return solveTab(n, days, cost);

    // Space Optimization
    return solveSO(n, days, cost);
}

int main()
{
    int n = 12;
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> cost = {2, 7, 15};

    cout << minimumCoins(n, days, cost);
    return 0;
}