/*
    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

    The overall run time complexity should be O(log (m+n)).


    Example 1:

    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.
    Example 2:

    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


    Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -10^6 <= nums1[i], nums2[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(n1 + n2), S.C. : O(n1 + n2)
double bruteForce(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0, j = 0;
    vector<int> nums3;

    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            nums3.push_back(nums1[i++]);
        }
        else
        {
            nums3.push_back(nums2[j++]);
        }
    }
    while (i < n1)
    {
        nums3.push_back(nums1[i++]);
    }
    while (j < n2)
    {
        nums3.push_back(nums2[j++]);
    }

    int n = n1 + n2;
    if (n % 2 == 1)
    {
        return nums3[n / 2];
    }
    return (double)(nums3[n / 2] + nums3[n / 2 - 1]) / 2.0;
}

// T.C. : O(n1 + n2), S.C. : O(1)
double better(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0, j = 0;
    int n = n1 + n2;
    int ind2 = (n / 2), ind1 = (n / 2) - 1;
    int cnt = 0;
    int elm1 = -1, elm2 = -1;
    while (i < n1 && j < n2)
    {
        if (nums1[i] < nums2[j])
        {
            if (cnt == ind1)
                elm1 = nums1[i];
            if (cnt == ind2)
                elm2 = nums1[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                elm1 = nums2[j];
            if (cnt == ind2)
                elm2 = nums2[j];
            cnt++;
            j++;
        }
    }
    while (i < n1)
    {
        if (cnt == ind1)
            elm1 = nums1[i];
        if (cnt == ind2)
            elm2 = nums1[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            elm1 = nums2[j];
        if (cnt == ind2)
            elm2 = nums2[j];
        cnt++;
        j++;
    }

    if (n & 1)
        return elm2;
    return (double)(elm1 + elm2) / 2.0;
}

// T.C. : O(min(log(n1), log(n2))), S.C. : O(1)
double binarySearch(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();

    if (n1 > n2) // swap
        return binarySearch(nums2, nums1);

    int n = n1 + n2;
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2; // No. of elements required on left
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        // assign l1, l2, r1, r2
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (mid1 > 0)
            l1 = nums1[mid1 - 1];
        if (mid2 > 0)
            l2 = nums2[mid2 - 1];

        // binary search conditions
        if (l1 <= r2 && l2 <= r1)
        {
            if (n & 1)
                return max(l1, l2);
            return (double)((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
        }
        else if (l1 > l2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0.0;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // brute force approach
    // return bruteForce(nums1, nums2);

    // Better Approach
    return better(nums1, nums2);
}

int main()
{

    return 0;
}