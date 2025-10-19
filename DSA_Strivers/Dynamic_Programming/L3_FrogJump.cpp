/*
    https://www.naukri.com/code360/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

    Frog Jump

    There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' 
    is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by 
    absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair 
    or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' 
    stair.

    For Example
    If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair 
    (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy 
    lost is 20.
    
    Constraints:
    1 <= T <= 10
    1 <= N <= 100000.
    1 <= HEIGHTS[i] <= 1000 .

    Time limit: 1 sec

    Sample Input 1:
    2
    4
    10 20 30 10
    3
    10 50 10
    Sample Output 1:
    20
    0
    Explanation of sample input 1:
    For the first test case,
    The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
    Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
    So, the total energy lost is 20 which is the minimum. 
    Hence, the answer is 20.

    For the second test case:
    The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
    So, the total energy lost is 0 which is the minimum. 
    Hence, the answer is 0.
    Sample Input 2:
    2
    8
    7 4 4 2 6 6 3 4 
    6
    4 8 3 10 4 4 
    Sample Output 2:
    7
    2


    Hints:
    1. Think about all the possibilities at each stair.
    2. Using recursion, try to divide the problem into subproblems and calculate the answer for each subproblem only once - 
       store it for reusing in the future.
    3. The above can also be done iteratively.

*/

#include<bits/stdc++.h>
using namespace std;

int solveRecur2(int i, int n, vector<int> &heights)
{
    if (i == 0)
    {
        return 0;
    }

    int right = INT_MAX;
    int left = solveRecur2(i - 1, n, heights) + abs(heights[i] - heights[i - 1]);
    
    if (i > 1)
    {
        right = solveRecur2(i - 2, n, heights) + abs(heights[i] - heights[i - 2]);
    }

    return min(left, right);
}

int solveRecur(int i, int n, vector<int> &heights)
{
    if (i >= n - 1)
    {
        return 0;
    }

    int step1 = INT_MAX, step2 = INT_MAX;

    // jump i + 1
    if (i + 1 < n)
    {
        step1 = abs(heights[i + 1] - heights[i]) + solveRecur(i + 1, n, heights);
    } 
    if (i + 2 < n)
    {
        step2 = abs(heights[i + 2] - heights[i]) + solveRecur(i + 2, n, heights);
    }

    return min(step1, step2);
}

int solveRM(int i, int n, vector<int> &heights, vector<int> &dp)
{
    if (i >= n - 1)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }

    int step1 = INT_MAX, step2 = INT_MAX;

    // jump i + 1
    if (i + 1 < n)
    {
        step1 = abs(heights[i + 1] - heights[i]) + solveRM(i + 1, n, heights, dp);
    } 
    if (i + 2 < n)
    {
        step2 = abs(heights[i + 2] - heights[i]) + solveRM(i + 2, n, heights, dp);
    }

    return dp[i] = min(step1, step2);
}

int solveTab(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        int step1 = INT_MAX, step2 = INT_MAX;

        if (i + 1 < n)
        {
            step1 = abs(heights[i + 1] - heights[i]) + dp[i + 1];
        } 
        if (i + 2 < n)
        {
            step2 = abs(heights[i + 2] - heights[i]) + dp[i + 2];
        }
        dp[i] = min(step1, step2);
    }

    return dp[0];
}

int solveSO(int n, vector<int> &heights)
{
    int next2 = 0;
    int next1 = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        int step1 = INT_MAX, step2 = INT_MAX;

        if (i + 1 < n)
        {
            step1 = abs(heights[i + 1] - heights[i]) + next1;
        } 
        if (i + 2 < n)
        {
            step2 = abs(heights[i + 2] - heights[i]) + next2;
        }
        int curr = min(step1, step2);
        next2 = next1;
        next1 = curr;
    }
    return next1;
}

int frogJump(int n, vector<int> &heights)
{
    // Recursion
    // return solveRecur(0, n, heights);

    // Recursion + Memoization
    // vector<int> dp(n + 1, -1);
    // return solveRM(0, n, heights, dp);

    // Tabulation
    // return solveTab(n, heights);

    // Space Optimization
    return solveSO(n, heights);
}

int main()
{
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    cout << frogJump(n, heights) << endl;
    return 0;
}