/*
    Given an array ‘Arr’ that has ‘N’ elements. You have to find the subarray of ‘Arr’ that has the largest product. You must
    return the product of the subarray with the maximum product.

    For example:
    When ‘N’ = 5, and ‘Arr’ = {-2, 3, -4, 0}
    The subarrays of ‘Arr’ are:
    {-2}, {-2, 3}, {-2, 3, -4}, {-2, 3, -4, 0}, {3}, {3, -4}, {3, -4, 0}, {-4}, {-4, 0}, {0}.
    Among these, {-2, 3, -4} is the subarray having the maximum product equal to 24.
    Hence, the answer is 24.

    Sample Input 1:
    4
    1 -2 3 -4
    Sample Output 1:
    24
    Explanation Of Sample Input 1:
    Given, ‘Arr’ = {1, -2, 3, -4}. The subarrays of ‘Arr’ are: 
    {{1}, {1, -2}, {1, -2, 3}, {1, -2, 3, -4}, {-2}, {-2, 3}, {-2, 3, -4}, {3}, {3, -4}, {-4}}.
    Among these subarrays, {1, -2, 3, -4} and {-2, 3, -4} have the maximum product, equal to 24.
    Hence, the answer is 24.
    
    Sample Input 2:
    5
    -1 3 0 -4 3
    Sample Output 2:
    3
    Constraints:
    1 <= N <= 10^5
    -100 <= Arr[i] <= 100

    -10^9 <= The product of elements of any subarray <= 10^9.
    The sum of ‘N’ over all test cases <= 10^5.
    Time Limit: 1-sec
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(n^2)
int brute(vector<int> &arr)
{
	int maxProd = INT_MIN;
	for (int i = 0; i < arr.size(); i++)
	{
		int prod = 1;
		for (int j = i; j < arr.size(); j++)
		{
			prod = prod * arr[j];
			maxProd = max(maxProd, prod);
		}
	}
	return maxProd;
}

// T.C. : O(n)
int optimal(vector<int> &arr)
{
	int maxProd = INT_MIN;

	int pre = 1, suf = 1;
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		if (pre == 0)
		{
			pre = 1;
		}
		if (suf == 0)
		{
			suf = 1;
		}

		pre = pre * arr[i];
		suf = suf * arr[n - i - 1];
		maxProd = max(maxProd, max(pre, suf));
	}

	return maxProd;
}

int subarrayWithMaxProduct(vector<int> &arr)
{
	// Brute Force
	// return brute(arr);

	// Optimal
	return optimal(arr);
}

int main()
{
    
    return 0;
}