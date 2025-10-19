/*
    First and Last Position of an Element In Sorted Array

    You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.
    Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

    Note :
    1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
    2. 'arr' may contain duplicate elements.

    Example:

    Input: 'arr' = [0,1,1,5] , 'k' = 1
    Output: 1 2
    Explanation:
    If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

    Sample Input 1:
    8 2
    0 0 1 1 2 2 2 2

    Sample output 1:
    4 7

    Explanation of Sample output 1:
    For this testcase the first occurrence of 2 in at index 4 and last occurrence is at index 7.

    Sample Input 2:
    4 2
    1 3 3 5

    Sample output 2:
    -1 -1

    Expected Time Complexity:
    Try to do this in O(log(n)).

    Constraints:
    1 <= n <= 10^5
    0 <= k <= 10^9
    0 <= arr[i] <= 10^9

    Time Limit : 1 second
*/

#include<bits/stdc++.h>
using namespace std;

/******************** T.C. : O(n), S.C. : O(1) ********************/
pair<int, int> brute(vector<int>& arr, int n, int k)
{
    int f = -1, l = -1;

    for (int i = 0; i < n; i++)
    {
        if (f == -1 && arr[i] == k)
        {
            f = i;
            l = i;
        }
        else if (f != -1 && arr[i] == k)
        {
            l = i;
        }
    }

    return {f, l};
}
/******************************************************************/

/******************** T.C. : 2 * O(log(n)), S.C. : O(1) ********************/
int lowerBound(vector<int>& arr, int n, int k)
{
    int lb = n;
    int s = 0, e = n - 1;

    while (s <= e)
    {
        int m = s + (e - s)/2;

        if (arr[m] >= k)
        {
            lb = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return lb;
}

int upperBound(vector<int>& arr, int n, int k)
{
    int ub = n;
    int s = 0, e = n - 1;

    while (s <= e)
    {
        int m = s + (e - s)/2;

        if (arr[m] > k)
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
 
pair<int, int> better(vector<int>& arr, int n, int k)
{
    int lb = lowerBound(arr, n, k);
    int ub = upperBound(arr, n, k);

    if (lb == n || arr[lb] != k)
    {
        return {-1, -1};
    }
    return {lb, ub - 1};
}
/***************************************************************************/

/******************** T.C. : 2 * O(log(n)), S.C. : O(1) ********************/
int firstOccurance(vector<int>& arr, int n, int k)
{
    int f = -1;

    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s)/2;

        if (arr[m] == k)
        {
            f = m;
            e = m - 1;
        }
        else if (k > arr[m])
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return f;
}

int lastOccurance(vector<int>& arr, int n, int k)
{
    int l = -1;

    int s = 0, e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s)/2;

        if (arr[m] == k)
        {
            l = m;
            s = m + 1;
        }
        else if (k > arr[m])
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return l;
}

pair<int, int> optimal(vector<int>& arr, int n, int k)
{
    int fo = firstOccurance(arr, n, k);
    int lo = lastOccurance(arr, n, k);

    return {fo, lo};
}
/***************************************************************************/

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Brute Force
    // return brute(arr, n, k);

    // Better
    // return better(arr, n, k);

    // Optimal
    return optimal(arr, n, k);
    
}

int main()
{
    int n = 8, k = 2;
    vector<int> arr = {0, 0, 1, 1, 2, 2, 2, 2};

    pair<int, int> FL = firstAndLastPosition(arr, n, k);

    cout << "First : " << FL.first << " , Last : " << FL.second << endl;
    return 0;
}