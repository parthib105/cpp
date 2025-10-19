/*
    You have been given a sorted array ARR consisting of 'N' elements. You are also given an integer 'K'.
    Now the array is rotated at some pivot point unknown to you. For example, if ARR = [1, 3, 5, 7, 8].
    Then after rotating ARR at index 3, the array will be ARR = [7, 8, 1, 3, 5].

    Now, your task is to find the index at which 'K' is present in ARR

    EX. ARR = [12, 15, 18, 2, 4, 7, 8] , K = 4
*/

#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &arr)
{
    int n = arr.size();

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        int mid = i + (j - i) / 2;

        if (arr[mid] >= arr[0])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return i;
}

int findPosition(vector<int> &arr, int n, int k)
{
    int i, j;

    int pivot = findPivot(arr);

    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        i = pivot;
        j = n - 1;
    }
    else
    {
        i = 0;
        j = pivot - 1;
    }

    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return -1;
}

int binarySearch(vector<int> &nums, int target, int s, int e)
{
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (nums[m] == target)
        {
            return m;
        }
        else if (target > nums[m])
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

bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int pivot = findPivot(nums);

    if (nums[pivot] == target)
    {
        return true;
    }

    int s = 0;
    int e = n - 1;

    if (target > pivot && target <= n - 1)
    {
        int ans = binarySearch(nums, target, pivot, n - 1);
        if (ans == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        int ans = binarySearch(nums, target, 0, pivot - 1);
        if (ans == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int main()
{
    vector<int> arr = {2, 2, 2, 3, 2, 2, 2};
    cout << findPivot(arr) << endl;
    // cout << findPosition(arr, 7, 17) << endl;
    return 0;
}