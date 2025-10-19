/*
    Single Element in a Sorted Array

    You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, 
    which appears only once. Return the number that appears once.

    Example:
    Input: 'arr' = [1,1,2,2,4,5,5]

    Output: 4 

    Explanation: 
    Number 4 only appears once the array.


    Note :
    Exactly one number in the array 'arr' appears once.

    Sample Input 1 :
    5 
    1 1 3 5 5 


    Sample Output 1 :
    3 


    Explanation of Sample Input 1 :
    Given array is [1, 1, 3, 5, 5]    
    Here, 3 occurs once in the array. So, the answer is 3.

    Sample Input 2 :
    5
    1 1 4 4 15


    Sample Output 2 :
    15


    Explanation of Sample Input 2 :
    The array is [1, 1, 4, 4, 15].    
    Here, 15 occurs once in the array. So, the answer is 15.


    Expected Time Complexity:
    Try to solve this in O(log(n)).


    Constraints :
    1 <= n <= 10^5
    0 <= arr[i] <= 10^9

    Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach 1 : O(N)
int bruteApproach1(vector<int>& arr)
{
    for (int i = 1; i < arr.size() - 1; i++)
    {
        if (arr[i]!=arr[i - 1] && arr[i]!=arr[i + 1])
        {
            return arr[i];
        }
    }
    return -1;
}

// Brute Force Approach 2 : O(N)
int bruteApproach2(vector<int>& arr)
{
    int ans = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		ans = ans ^ arr[i];
	}

	return ans;
}

// Binary Search Approach : O(log(n))
int binarySearch(vector<int>& arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }
    if (arr[0] != arr[1])
    {
        return arr[0];
    }
    if (arr[n - 1] != arr[n - 2])
    {
        return arr[n - 1];
    }

    int s = 1, e = n - 2;
    while (s <= e)
    {
        int m = s + (e - s)/2;
        if (arr[m] != arr[m - 1] && arr[m] != arr[m + 1])
        {
            return arr[m];
        }
        else if ((m % 2 == 1 && arr[m] == arr[m - 1]) || (m % 2 == 0 && arr[m] == arr[m + 1]))
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return -1;
}

int singleNonDuplicate(vector<int>& arr)
{
	// Brute Force (1)
    // return bruteApproach1(arr);

    // Brute Force (2)
    // return bruteApproach2(arr);

    // Optimal Approach
    return binarySearch(arr);
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 5, 5};
    int singleInt = singleNonDuplicate(arr);
    if (singleInt == -1)
    {
        cout << "No sinlge element found!" << endl;
    }
    else
    {
        cout << "Single element found : " << singleInt << endl;
    }
    return 0;
}