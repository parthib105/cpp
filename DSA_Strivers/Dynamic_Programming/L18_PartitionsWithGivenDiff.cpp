/*
    Partitions With Given Difference

    Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.

    Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.

    If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

    1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
    2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.
    Refer to the example below for clarification.
    Note that the sum of the elements of an empty subset is 0.

    For example :
    If N = 4, D = 3, ARR = {5, 2, 5, 1}
    There are only two possible partitions of this array.
    Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
    Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
    These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
    Input Format :
    The first line contains a single integer ‘T’ denoting the number of test cases, then each test case follows:

    The first line of each test case contains two space-separated integers, ‘N’ and ‘D,’ denoting the number of elements in the array and the desired difference.

    The following line contains N integers denoting the space-separated integers ‘ARR’.
    Output Format :
    For each test case, find the number of partitions satisfying the above conditions modulo 10^9 + 7.
    Output for each test case will be printed on a separate line.
    Note :
    You are not required to print anything; it has already been taken care of. Just implement the function.
    Constraints :
    1 ≤ T ≤ 10
    1 ≤ N ≤ 50
    0 ≤ D ≤ 2500
    0 ≤ ARR[i] ≤ 50

    Time limit: 1 sec
    Sample Input 1 :
    2
    4 3
    5 2 6 4
    4 0
    1 1 1 1
    Sample Output 1 :
    1
    6
    Explanation For Sample Input 1 :
    For test case 1:
    We will print 1 because :
    There is only one possible partition of this array.
    Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3

    For test case 2:
    We will print 6 because :
    The partition {1, 1}, {1, 1} is repeated 6 times:
    Partition 1 : {ARR[0], ARR[1]}, {ARR[2], ARR[3]}
    Partition 2 : {ARR[0], ARR[2]}, {ARR[1], ARR[3]}
    Partition 3 : {ARR[0], ARR[3]}, {ARR[1], ARR[2]}
    Partition 4 : {ARR[1], ARR[2]}, {ARR[0], ARR[3]}
    Partition 5 : {ARR[1], ARR[3]}, {ARR[0], ARR[2]}
    Partition 6 : {ARR[2], ARR[3]}, {ARR[0], ARR[1]}
    The difference is in the indices chosen for the subset S1(or S2).
    Sample Input 2 :
    3
    3 1
    4 6 3
    5 0
    3 1 1 2 1
    5 1
    3 2 2 5 1
    Sample Output 2 :
    1
    6
    3
*/

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
const int mod = 1e9 + 7;

int solveRecur(int i, int k, int currSum, int n, vector<int>& arr)
{
    if (i == n)
        return currSum == k;
    
    int ways = 0;

    // pick
    if (currSum + arr[i] <= k)
        ways = (ways + solveRecur(i + 1, k, currSum + arr[i], n, arr)) % mod;

    // skip
    ways  = (ways + solveRecur(i + 1, k, currSum, n, arr)) % mod;

    return ways;
}

int solveRM(int i, int k, int currSum, int n, vector<int>& arr, vector<vector<int>>& dp)
{
    if (i == n)
        return currSum == k;
    if (dp[i][currSum] != -1)
        return dp[i][currSum];

    int ways = 0;

    // pick
    if (currSum + arr[i] <= k)
        ways = (ways + solveRM(i + 1, k, currSum + arr[i], n, arr, dp)) % mod;

    // skip
    ways  = (ways + solveRM(i + 1, k, currSum, n, arr, dp)) % mod;

    dp[i][currSum] = ways;
    return dp[i][currSum];
}

int solveTab(int k, int n, vector<int>& arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    dp[n][k] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int s = k; s >= 0; s--)
        {
            int ways = 0;
            if (s + arr[i] <= k)
                ways = (ways + dp[i + 1][s + arr[i]]) % mod;
            ways = (ways + dp[i + 1][s]) % mod;
            dp[i][s] = ways;
        }
    }
    return dp[0][0];
}

int countPartitions(int n, int d, vector<int> &arr) 
{
    int totSum = accumulate(arr.begin(), arr.end(), 0);

    if ((totSum - d) < 0 || ((totSum - d) & 1))
        return 0;
    int k = (totSum - d) / 2;
    
    // Recursive Solution
    // return solveRecur(0, k, 0, n, arr);

    // Recursion + Memoization
    // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    // return solveRM(0, k, 0, n, arr, dp);

    // Tabulation
    return solveTab(k, n, arr);
}

int main()
{
    int n = 4, d = 3;
    vector<int> arr = {5, 2, 6, 4};

    cout << countPartitions(n, d, arr) << endl;
    return 0;
}