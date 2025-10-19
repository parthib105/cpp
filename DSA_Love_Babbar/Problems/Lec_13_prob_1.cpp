/*
    Given an sorted array and an element k, task is to find the first and last occurance of k.
    if k is not present in the array, return -1
*/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    pair<int, int> ans;

    int i = 0;
    int j = n - 1;
    int idx = -1;
    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == k)
        {
            idx = mid;
            j = mid - 1;
        }
        else if (arr[mid] < k)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }

    ans.first = idx;

    idx = -1;
    i = 0;
    j = n - 1;

    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == k)
        {
            idx = mid;
            i = mid + 1;
        }
        else if (arr[mid] < k)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    ans.second = idx;

    return ans;
}

int main()
{
    vector<int> arr = {0, 2, 2, 6, 6, 6};
    int n = 6;
    int k = 3;

    pair<int, int> ans = firstAndLastPosition(arr, n, k);

    cout << ans.first << " " << ans.second << endl;
    return 0;
}