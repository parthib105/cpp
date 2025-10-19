/*
    You are given two integers arrays 'nums1' and 'nums2', sorted in non-decreasing order, and two ubtegers 'm' and 'n', representating the number of elements in 'nums1' and 'nums2' respectively.
    Merge 'nums1' and 'nums2' into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, but instead be stored inside the
    array 'nums1'. To accommodate this, 'nums1' has a length of m+n, where the first 'm' elements
    denote the elements that should me merged, and the last 'n' elements are set to 0 and should 
    be ignored. 'nums2' has length of 'n'.
*/
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> arr;
    for (int i = 0; i < m; i++)
    {
        arr.push_back(nums1[i]);
    }
    
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (arr[i] <= nums2[j])
        {
            nums1[k] = arr[i];
            k ++;
            i ++;
        }
        else
        {
            nums1[k] = nums2[j];
            k ++;
            j ++;
        }
    }
    while (i < m)
    {
        nums1[k] = arr[i];
        k ++;
        i ++;
    }

    while (j < n)
    {
        nums1[k] = nums2[j];
        k ++;
        j ++;
    }
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 7, 9, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 5;
    int n = 3;

    cout << "Before merging :" << endl;
    cout << "nums1 : ";
    for(auto i : nums1)
    {
        cout << i << " ";
    } 
    cout << endl << "nums2 : ";
    for(auto i : nums2)
    {
        cout << i << " ";
    }

    merge(nums1, m, nums2, n);

    cout << endl << "After merging :" << endl;
    cout << "nums1 : ";
    for(auto i : nums1)
    {
        cout << i << " ";
    }
    return 0;
}