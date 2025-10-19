/*
    Implement Lower Bound

    You are given an array 'arr' sorted in non-decreasing order and a number 'x'. You must return the index of the lower 
    bound of 'x'.
    Note:
    1. For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that the value 
       'arr[idx]' is not less than 'x'.If all numbers are smaller than 'x', then 'n' should be the 'lower_bound' of 'x', 
       where 'n' is the size of array.
    2. Try to do this in O(log(n)).

    Example:
    Input: ‘arr’ = [1, 2, 2, 3] and 'x' = 0

    Output: 0

    Explanation: Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.

    Constraints:
    1 <= ‘n’ <= 10^5
    0 <= ‘arr[i]’ <= 10^5
    1 <= ‘x’ <= 10^5
    Sample Input 1:
    6
    1 2 2 3 3 5
    0

    Sample Output 1:
    0

    Explanation Of Sample Input 1 :
    Index '0' is the smallest index such that 'arr[0]' is not less than 'x'.

    Sample Input 2:
    6
    1 2 2 3 3 5
    2

    Sample Output 2:
    1

    Sample Input 3:
    6
    1 2 2 3 3 5
    7

    Sample Output 3:
    6
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(n), S.C. : O(1)
int bruteLB(vector<int> arr, int n, int x)
{
	int lb = n;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= x)
		{
			lb = i;
			break;
		}
	}
	return lb;
}

// T.C. : O(log(n)), S.C. : O(1)
int optimalLBBS(vector<int> arr, int n, int x)
{
	int s = 0, e = n - 1;
	int lb = n;

	while (s <= e)
	{
		int m = s + (e - s)/2;
		if (arr[m] >= x)
		{
			e = m - 1;
			lb = m;
		}
		else
		{
			s = m + 1;
		}
	}
	return lb;
}

int lowerBound(vector<int> arr, int n, int x) 
{
	// Brute Force
	// return brute(arr, n, x);

	// Optimal Approach
	return optimalLBBS(arr, n, x);
}

// T.C. : O(n), S.C. : O(1)
int bruteUB(vector<int> &arr, int x, int n)
{
	int ub = n;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > x)
		{
			ub = i;
			break;
		}
	}
	return ub;
}

// T.C. : O(log(n)), S.C. : O(1)
int optimalUBBS(vector<int> &arr, int x, int n)
{
	int ub = n;

	int s = 0, e = n - 1;
	while (s <= e)
	{
		int m = s + (e - s)/2;

		if (arr[m] > x)
		{
			ub = m;
			e = m - 1;
		}
		else
		{
			s = m + 1;
		}
	}

	return ub;
}

int upperBound(vector<int> &arr, int x, int n)
{
	// Brute Force
	// return bruteUB(arr, x, n);

	// Optimal 
	return optimalUBBS(arr, x, n);	
}

int main()
{
    int n = 6, x = 4;
    vector<int> arr = {1, 2, 2, 3, 3, 5};

    cout << upperBound(arr, x, n) << endl;
    return 0;
}