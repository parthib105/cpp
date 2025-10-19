/*
    Search In Rotated Sorted Array I

    You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
    Now the array is rotated at some pivot point unknown to you.

    For example, if 'arr' = [ 1, 3, 5, 7, 8], then after rotating 'arr' at index 3, the array will be 'arr' = [7, 8, 1, 3, 5].

    Now, your task is to find the index at which ‘k’ is present in 'arr'.
    Note :
    1. If ‘k’ is not present in 'arr', then print -1.
    2. There are no duplicate elements present in 'arr'. 
    3. 'arr' can be rotated only in the right direction.

    Example:
    
    Input: 'arr' = [12, 15, 18, 2, 4] , 'k' = 2
    Output: 3
    Explanation:
    If 'arr' = [12, 15, 18, 2, 4] and 'k' = 2, then the position at which 'k' is present in the array is 3 (0-indexed).

    Sample Input 1:
    4 3
    8 9 4 5

    Sample output 1:
    -1 

    Explanation of Sample Output 1:
    For the test case, 3 is not present in the array. Hence the output will be -1.


    Sample Input 2:
    4 3
    2 3 5 8

    Sample output 2:
    1

    Expected Time Complexity:
    Try to do this in O(log(n)). 

    Constraints:
    1 <= n <= 10^5
    0 <= k <= 10^9
    0 <= arr[i] <= 10^9

    Time Limit: 1 second
*/

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k)
{
    int s = 0, e = n - 1;
    
    while (s <= e)
    {
        int m = s + (e - s)/2;

        if (arr[m] == k)
        {
            return m;
        }
        else if (arr[s] <= arr[m])  // left part is sorted
        {
            if (k >= arr[s] && k <= arr[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        else    // right part is sorted
        {
            if (k >= arr[m] && k <= arr[e])
            {
                s = m + 1;
            }
            else
            {
                e = m - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n = 13, k = 50;
    vector<int> arr = {12, 15, 18, 22, 45, 50, 2, 4, 5, 6, 7, 9, 10};

    cout << search(arr, n, k) << endl;
    return 0;
}