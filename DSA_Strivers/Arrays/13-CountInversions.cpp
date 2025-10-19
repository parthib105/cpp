/*
    Number of Inversions

    There is an integer array ‘A’ of size ‘N’.
    Number of inversions in an array can be defined as the number of pairs of ‘i’, ‘j’ such that ‘i’ < ‘j’ and 
    ‘A[i]’ > ‘A[j]’.

    You must return the number of inversions in the array.

    For example,
    Input:
    A = [5, 3, 2, 1, 4], N = 5
    Output:
    7
    Explanation: 
    The pairs satisfying the condition for inversion are (1, 2), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), and (3, 4). 
    The number of inversions in the array is 7.
    Detailed explanation ( Input/output format, Notes, Images )
    
    Sample Input 1:
    4
    4 3 2 1
    Sample Output 1:
    6
    Explanation Of Sample Input 1:
    
    Input:
    A = [4, 3, 2, 1], N = 4
    Output:
    6
    Explanation: 
    The pairs satisfying the condition for inversion are (1, 2), (1, 3), (1, 4), (2, 3), (2, 4), and (3, 4).    
    The number of inversions in the array is 6.
    
    Sample Input 2:
    5
    1 20 6 4 5
    Sample Output 2:
    5
    Constraints:
    1 <= N <= 10^5
    1 <= A[i] <= 10^9
    Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(n^2), S.C. : O(1)
int brute(vector<int> &a, int n)
{
    int countInv = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                countInv++;
            }
        }
    }
    return countInv;
}

int mergeArrays(vector<int> &arr, int s, int m, int e)
{
    vector<int> temp;

    int l = s;
    int r = m + 1;
    int cnt = 0;
    while (l <= m && r <= e)
    {
        if (arr[l] <= arr[r])
        {
            temp.push_back(arr[l]);
            l++;
        }
        else
        {
            temp.push_back(arr[r]);
            cnt += (m - l + 1);
            r++;
        }
    }
    while (l <= m)
    {
        temp.push_back(arr[l]);
        l++;
    }
    while (r <= e)
    {
        temp.push_back(arr[r]);
        r++;
    }

    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i - s];
    }
    return cnt;
}

// T.C. : O(n log(n)), S.C. : O(n)
int optimal(vector<int> &a, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }

    int m = s + (e - s)/2;
    int inversions = 0;
    inversions += optimal(a, s, m);
    inversions += optimal(a, m + 1, e);

    inversions += mergeArrays(a, s, m, e);

    return inversions;
}

int numberOfInversions(vector<int>&a, int n) 
{
    // Brute Force
    // return brute(a, n);

    // optimal (using merge sort)
    return optimal(a, 0, n - 1);
}

int main()
{
    vector<int> a = {1, 20, 6, 4, 5};
    int n = 5;

    cout << numberOfInversions(a, n) << endl;
    return 0;
}