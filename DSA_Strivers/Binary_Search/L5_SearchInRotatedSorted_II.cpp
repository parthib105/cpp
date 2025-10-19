/*
    Search In A Rotated Sorted Array II

    You are given a rotated sorted array 'a' of length 'n' and a 'key'. You need to determine if the 'key' exists in the 
    array 'a'. The given sorted array is rotated from an unknown index 'x'. Such that after rotation the array became 
    [a[x], a[x+1]...., a[n-1], a[1]..., a[x-1]], (0-based indexing). For example, if the array is [1, 2, 3, 4, 5] and x = 2 
    then the rotated array will be [3, 4, 5, 1, 2, 3].

    Return the index if the 'key' is found in 'a'. Otherwise, return -1.
    Note: Array ‘a’ may contain duplicate elements.

    Example:

    Input: a = [6, 10, 1, 3, 5], key = 3
    Output: 3
    Explanation: The array 'a' contains the 'key' = 3, so we return index 3.

    Sample Input 1:
    7 4
    3 4 5 0 0 1 2

    Sample Output 1:
    1

    Explanation Of Sample Input 1:
    Input: a = [3, 4, 5, 0, 0, 1, 2], key = 4
    Output: 1
    Explanation: The array 'a' contains the 'key' = 4, so we return index 1.


    Sample Input 2:
    6 47
    31 44 56 0 10 13

    Sample Output 2:
    -1

    Expected Time Complexity:
    Try to solve this with average time complexity O(log(n)).
    Constraints:
    1 <= 'n' <= 10^5
    0 <= 'a[i]', 'key' <= 10^9
    Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;

int searchInARotatedSortedArrayII(vector<int>&A, int key) 
{
    int s = 0, e = A.size() - 1;

    while (s <= e)
    {
        int m = s + (e - s)/2;

        if (A[m] == key)
        {
            return m;
        }

        if (A[s] == A[m] && A[m] == A[e])
        {
            s = s + 1;
            e = e - 1;
            continue;
        }
        else if (A[s] <= A[m])
        {
            if (key >= A[s] && key <= A[m])
            {
                e = m - 1;
            }
            else
            {
                s = m + 1;
            }
        }
        else
        {
            if (key >= A[m] && key <= A[e])
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
    int n = 7, k = 0;
    vector<int> A = {3, 4, 5, 0, 0, 1, 2};

    cout << searchInARotatedSortedArrayII(A, k);
    return 0;
}