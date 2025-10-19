/*
    Count Subsets with Sum K

    You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
    Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
    Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.

    Example:
    Input: 'arr' = [1, 1, 4, 5]

    Output: 3

    Explanation: The possible ways are:
    [1, 4]
    [1, 4]
    [5]
    Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    4 5
    1 4 4 5


    Sample Output 1 :
    3


    Explanation For Sample Output 1:
    The possible ways are:
    [1, 4]
    [1, 4]
    [5]
    Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.


    Sample Input 2 :
    3 2
    1 1 1


    Sample Output 2 :
    3


    Explanation For Sample Output 1:
    There are three 1 present in the array. Answer is the number of ways to choose any two of them.


    Sample Input 3 :
    3 40
    2 34 5


    Sample Output 3 :
    0


    Expected time complexity :
    The expected time complexity is O('n' * 'k').


    Constraints:
    1 <= 'n' <= 100
    0 <= 'arr[i]' <= 1000
    1 <= 'k' <= 1000

    Time limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// T.C. : O(2^n), S.C. : O(n)
int solveRecur(int i, int n, int k, int currSum, vector<int>& arr)
{
	if (currSum == k)
		return 1;
	if (i >= n || currSum > k) // out of bounds or sum exceeded
        return 0;
	
	int ways = 0;
	
	// include the current element
	ways = (ways + solveRecur(i + 1, n, k, currSum + arr[i], arr)) % mod;

	// exclude the current element
	ways = (ways + solveRecur(i + 1, n, k, currSum, arr)) % mod;

	return ways;
}

// T.C. : O(n x k), S.C. : O(n x k) + O(n)
int solveRM(int i, int n, int k, int currSum, vector<int>& arr, vector<vector<int>>& dp)
{
	if (currSum == k)
		return 1;
	if (i == n || currSum > k) // out of bounds or sum exceeded
        return 0;
	if (dp[i][currSum] != -1)
		return dp[i][currSum];
	
	int ways = 0;
	
	// include the current element
	ways = (ways + solveRM(i + 1, n, k, currSum + arr[i], arr, dp)) % mod;

	// exclude the current element
	ways = (ways + solveRM(i + 1, n, k, currSum, arr, dp)) % mod;

	dp[i][currSum] = ways;
	return dp[i][currSum];
}

// T.C. : O(n x k), S.C. : O(n x k)
int solveTab(int k, int n, vector<int>& arr)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // base case
    for (int i = 0; i <= n; i++)
        dp[i][k] = 1;
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int s = k - 1; s >= 0; s--)
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

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();

	// Recursive Solution
	// return solveRecur(0, n, k, 0, arr);

	// Recursion + Memoization
	// vector<vector<int>> dp(n, vector<int>(k + 1, -1));
	// return solveRM(0, n, k, 0, arr, dp);

    // Tabulation
    return solveTab(k, n, arr);
}

int main()
{
    int k = 5;
    vector<int> arr = {1, 4, 4, 5};

    cout << findWays(arr, k) << endl;
    return 0;
}