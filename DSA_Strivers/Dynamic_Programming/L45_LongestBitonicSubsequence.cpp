/*
    A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.

    A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending order sequence.

    For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.

    You are given an array 'arr' consisting of 'n' positive integers.
    Find the length of the longest bitonic subsequence of 'arr'.

    Example :
    Input: 'arr' = [1, 2, 1, 2, 1]

    Output: 3

    Explanation: The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive 2's are neither strictly increasing, nor strictly decreasing.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    5 
    1 2 1 2 1


    Sample Output 1:
    3


    Explanation For Sample Input 1:
    The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive 2's are neither strictly increasing, nor strictly decreasing.


    Sample Input 2 :
    5
    1 2 1 3 4


    Sample Output 2 :
    4


    Explanation For Sample Input 2:
    The longest bitonic sequence for this array will be [1, 2, 3, 4].


    Expected time complexity :
    The expected time complexity is O(n ^ 2).


    Constraints:
    1 <= 'n' <= 10^3
    1 <= 'arr[i]' <= 10^5

    Time Limit: 1sec
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> LIS(int n, vector<int>& arr)
{
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && 1 + dp[j] > dp[i])
				dp[i] = 1 + dp[j];
		}
	}
	return dp;
}

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// LIS dp for left view
	vector<int> lDP = LIS(n, arr);

    // Reverse the array and get the right view
	reverse(arr.begin(), arr.end());
	vector<int> rDP = LIS(n, arr);

    // reverse the rDP
	reverse(rDP.begin(), rDP.end());

	int lbs = 0;
	for (int i = 0; i < n; i++)
		lbs = max(lbs, lDP[i] + rDP[i] - 1);
	return lbs;
}

int main()
{   
    int n = 11;
    vector<int> arr = {20, 11, 8, 17, 38, 25, 41, 22, 32, 46, 34};

    cout << longestBitonicSubsequence(arr, n) << endl;
    return 0;
}