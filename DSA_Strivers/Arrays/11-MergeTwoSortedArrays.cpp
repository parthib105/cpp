/*
    Merge Two Sorted Arrays Without Extra Space

    Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.
    You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space. Of all the 'N + M' sorted elements, 
    array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.

    Note:
    You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
    For example:
    When ‘N’ = 4, ‘A’ = {1, 4, 5, 7} and ‘M’ = 3, ‘B’ = {2, 3, 6}. 
    We can merge these two arrays into {1, 2, 3, 4, 5, 6, 7} (The elements of ‘A’ are {1, 2, 3, 4} ).
    Hence, the answer is {1, 2, 3, 4, 5, 6, 7}.

    Sample Input 1:
    3 4
    1 8 8
    2 3 4 5
    Sample Output 1:
    1 2 3 4 5 8 8
    Explanation Of Sample Input 1:
    We have ‘A’ = {1, 8, 8} and ‘B’ = {2, 3, 4, 5}. 
    Merging the two arrays results in {1, 2, 3, 4, 5, 8, 8}.
    Hence the answer is {1, 2, 3, 4, 5, 8, 8}, where ‘A’ contains {1, 2, 3} and ‘B’ contains {4, 5, 8, 8}.
    
    Sample Input 2:
    4 5
    1 1 1 1 
    2 2 3 3 5
    Sample Output 2:
    1 1 1 1 2 2 3 3 5
    
    Constraints:
    1 <= N <= 10^5
    1 <= M <= 10^5
    0 <= A[i] <= 10^9
    0 <= B[i] <= 10^9

    The sum of ‘N + M’ over all test cases does not exceed 2 * 10^5.
    Time Limit: 1-sec
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(n + m), S.C. : O(n + m)
void brute(vector<long long> &a, vector<long long> &b)
{
	int n = a.size();
	int m = b.size();
	int i = 0, j = 0, k = 0;;

	// merge two sorted arrays
	vector<long long> arr(n + m, 0);
	while (i < n && j < m)
	{
		if (a[i] <= b[j])
		{
			arr[k] = a[i];
			i++;
		}
		else
		{
			arr[k] = b[j];
			j++;
		}
		k++;
	}

	while (i < n)
	{
		arr[k] = a[i];
		i++;
		k++;
	}
	while (j < m)
	{
		arr[k] = b[j];
		j++;
		k++;
	}

	// put them back to original arrays
	i = 0, j = 0, k = 0;
	while (i < n)
	{
		a[i] = arr[k];
		i++;
		k++;
	}
	while (j < m)
	{
		b[j] = arr[k];
		j++;
		k++;
	}
}

// T.C. : O(min(n, m)) + O(n log(n)) + O(m log(m)), S.C. : O(1)
void better(vector<long long> &a, vector<long long> &b)
{
	int n = a.size(), m = b.size();
	int i = n - 1;
	int j = 0;

	while (i >= 0 && j < m)
	{
		if (a[i] > b[j])
		{
			swap(a[i], b[j]);
			i --;
			j ++;
		}
		else
		{
			break;
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
}

// gap method
// T.C. : O((n+m) * log(n+m)), S.C. : O(1)
void optimal(vector<long long> &a, vector<long long> &b)
{
	int n = a.size(), m = b.size();
	int len = n + m;
	int gap = (len/2) + (len%2);

	while (gap > 0)
	{
		int l = 0;
		int r = l + gap;
		while (r < len)
		{
			if (l < n && r < n && a[l] > a[r]) // l in a and r in a
			{
				swap(a[l], a[r]);
			}
			else if (l < n && r >= n && a[l] > b[r - n])	// l in a and r in b
			{
				swap(a[l], b[r - n]);
			}
			else if (l >= n && a[l - n] > b[r - n]) // l in b and r in b
			{
				swap(a[l - n], b[r - n]);
			}
			l ++;
			r ++;
		}

		if (gap == 1)
		{
			break;
		}
		gap = (gap/2) + (gap%2);
	}
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
	// Brute Force
	// brute(a, b);

	// Better
	// better(a, b);

	// optimal
	optimal(a, b);
}

int main()
{
    
    return 0;
}