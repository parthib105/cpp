/*
    Rod cutting problem

    Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

    Note:
    1. The sizes will range from 1 to ‘N’ and will be integers.

    2. The sum of the pieces cut should be equal to ‘N’.

    3. Consider 1-based indexing.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 50
    1 <= N <= 100
    1 <= A[i] <= 100

    Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod, and A[i] is the cost of sub-length.

    Time limit: 1 sec.
    Sample Input 1:
    2
    5
    2 5 7 8 10
    8
    3 5 8 9 10 17 17 20
    Sample Output 1:
    12
    24
    Explanation of sample input 1:
    Test case 1:

    All possible partitions are:
    1,1,1,1,1           max_cost=(2+2+2+2+2)=10
    1,1,1,2             max_cost=(2+2+2+5)=11
    1,1,3               max_cost=(2+2+7)=11
    1,4                 max_cost=(2+8)=10
    5                   max_cost=(10)=10
    2,3                 max_cost=(5+7)=12
    1,2,2               max _cost=(1+5+5)=12    

    Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost which is 12.


    Test case 2:

    Possible partitions are:
    1,1,1,1,1,1,1,1         max_cost=(3+3+3+3+3+3+3+3)=24
    1,1,1,1,1,1,2           max_cost=(3+3+3+3+3+3+5)=23
    1,1,1,1,2,2             max_cost=(3+3+3+3+5+5)=22
    and so on….

    If we cut the rod into 8 pieces of length 1, for each piece 3 adds up to the cost. Hence for 8 pieces, we get 8*3 = 24.
    Sample Input 2:
    1
    6
    3 5 6 7 10 12
    Sample Output 2:
    18
*/

#include<bits/stdc++.h>
using namespace std;

int solveRecur(int i, int n, vector<int>& price)
{
	if (i == 0)
		return n*price[0];

	// exclude
	int exc = solveRecur(i - 1, n, price);

	// include
	int inc = INT_MIN, rodLen = i + 1;
	if (rodLen <= n)
		inc = price[i] + solveRecur(i, n - rodLen, price);

	return max(inc, exc);
}

int solveRM(int i, int n, vector<int>& price, vector<vector<int>>& dp)
{
	if (i == 0)
		return n*price[0];
	if (dp[i][n] != -1)
		return dp[i][n];

	// exclude
	int exc = solveRM(i - 1, n, price, dp);

	// include
	int inc = INT_MIN, rodLen = i + 1;
	if (rodLen <= n)
		inc = price[i] + solveRM(i, n - rodLen, price, dp);

	dp[i][n] = max(inc, exc);
	return dp[i][n];
}

int solveTab(int n, vector<int>& price)
{
	vector<vector<int>> dp(n, vector<int>(n + 1, 0));

	for (int l = 1; l <= n; l++)
		dp[0][l] = l * price[0];

	for (int i = 1; i < n; i++)
	{
		for (int l = 1; l <= n; l++)
		{
			// exclude
			int exc = dp[i - 1][l];

			// include
			int inc = INT_MIN, rodLen = i + 1;
			if (rodLen <= l)
				inc = price[i] + dp[i][l - rodLen];

			dp[i][l] = max(inc, exc);
		}
	}
	return dp[n - 1][n];
}

int solveSO(int n, vector<int>& price)
{
	vector<int> prev(n + 1, 0), curr(n + 1, 0);

	for (int l = 1; l <= n; l++)
		prev[l] = l * price[0];

	for (int i = 1; i < n; i++)
	{
		for (int l = 1; l <= n; l++)
		{
			// exclude
			int exc = prev[l];

			// include
			int inc = INT_MIN, rodLen = i + 1;
			if (rodLen <= l)
				inc = price[i] + curr[l - rodLen];

			curr[l] = max(inc, exc);
		}
		prev = curr;
	}
	return prev[n];
}

int cutRod(vector<int> &price, int n)
{
	// Recursive solution
	// return solveRecur(n - 1, n, price);

	// Recursion + Memoization
	// vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	// return solveRM(n - 1, n, price, dp);/

	// Tabulation
	// return solveTab(n, price);

	// Space Optimization
	return solveSO(n, price);
}


int main()
{
    int n = 6;
    vector<int> price = {3, 5, 6, 7, 10, 12};

    cout << cutRod(price, n) << endl;
    return 0;
}