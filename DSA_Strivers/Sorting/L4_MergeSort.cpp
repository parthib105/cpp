/*
    Merge Sort

    Given a sequence of numbers ‘ARR’. Your task is to return a sorted sequence of ‘ARR’ in non-descending order with help of 
    the merge sort algorithm.

    Example :

    Merge Sort Algorithm -
    Merge sort is a Divide and Conquer based Algorithm. It divides the input array into two-parts, until the size of the 
    input array is not ‘1’. In the return part, it will merge two sorted arrays a return a whole merged sorted array.

    The above illustrates shows how merge sort works.
    Note :
    It is compulsory to use the ‘Merge Sort’ algorithm.
    
    Constraints :
    1 <= T <= 50
    1 <= N <= 10^4
    -10^9 <= arr[i] <= 10^9

    Time Limit : 1 sec
    Sample Input 1 :
    2
    7
    3 4 1 6 2 5 7
    4
    4 3 1 2
    Sample Output 1 :
    1 2 3 4 5 6 7
    1 2 3 4
    Explanation For Sample Input 1:
    Test Case 1 :

    Given ‘ARR’ : { 3, 4, 1, 6, 2, 5, 7 }

    Then sorted 'ARR' in non-descending order will be : { 1, 2, 3, 4, 5, 6, 7 }. Non-descending order means every element must be greater than or equal to the previse element.

    Test Case 2 :

    Given ‘ARR’ : { 4, 3, 1, 2 }

    Then sorted 'ARR' in non-descending order will be : { 1, 2, 3, 4 }. 
    
    Sample Input 2 :
    2
    4
    5 4 6 7
    3
    2 1 1
    Sample Output 2 :
    4 5 6 7
    1 1 2
*/

#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &arr, int s, int m, int e)
{
    vector<int> temp;

    int l = s;
    int r = m + 1;
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
}

// T.C. : O(n log(n)), S.C. : O(n)
void mergeSort(vector<int>& arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int m = s + (e - s)/2;

    // left part
    mergeSort(arr, s, m);

    // right part
    mergeSort(arr, m + 1, e);

    mergeArrays(arr, s, m, e);
}

int main()
{
    int n = 7;
    vector<int> arr = {3, 4, 1, 6, 2, 5, 7};
    cout << "Before sorting : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "After sorting  : ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}