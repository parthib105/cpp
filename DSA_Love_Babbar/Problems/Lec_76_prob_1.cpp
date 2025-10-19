/*
    K-th Largest Sum Subarray

    Given an array of integers, find the Kth largest sum subarray For example, given the array [1, -2, 3, -4, 5] and K = 2, 
    the 2nd largest sum subarray would be [3, -4, 5], which has a sum of 4.

    Please note that a subarray is the sequence of consecutive elements of the array.

    Sample input 1 :
    3 3
    3 -2 5

    2 2
    4 1
    Sample output 1 :
    3
    4
    Explanation of Sample output 1 :
    For the first test case, 
    Sum of [0, 0] = 3
    Sum of [0, 1] = 1
    Sum of [0, 2] = 6
    Sum of [1, 1] = -2
    Sum of [1, 2] = 3
    Sum of [2, 2] = 5
    All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.

    For the second test case, 
    Sum of [0, 0] = 4
    Sum of [0, 1] = 5
    Sum of [1, 1] = 1
    All sum of subarrays are {5, 4, 1} where the second largest element is 4.
*/

#include<bits/stdc++.h>
using namespace std;

/******************** Approach 1 : T.C. : O(n^2 log(n)), S.C. : O(n^2) ********************/
int getKthLargest1(vector<int> &arr, int k)
{
	vector<int> sumArray;
    for (int i = 0; i < arr.size(); i++)
    {
        int currSum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            currSum += arr[j];
            sumArray.push_back(currSum);
        }
    }

    sort(sumArray.begin(), sumArray.end());

    return sumArray[sumArray.size() - k];
}

/******************** Approach 2 : T.C. : O(n^2 log(n)), S.C. : O(k) ********************/
int getKthLargest2(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < arr.size(); i++)
	{
		int currSum = 0;
		for (int j = i; j < arr.size(); j++)
		{
			currSum += arr[j];
			if (pq.size() < k)
			{
				pq.push(currSum);
			}
			else if (currSum > pq.top())
			{
				pq.pop();
				pq.push(currSum);
			}
		}
	}
	return pq.top();
}

int main()
{
    vector<int> arr = {1, -2, 3, -4, 5};
    int k = 2;
    cout << k << "th largest sum : " << getKthLargest2(arr, k) << endl;

    return 0;
}