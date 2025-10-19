/*
    K-th element of two Arrays

    Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

    Examples :

    Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
    Output: 6
    Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

    Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
    Output: 256
    Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.

    Constraints:

    1 <= a.size(), b.size() <= 10^6
    1 <= k <= a.size() + b.size()
    0 <= a[i], b[i] < 10^8
*/

#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> &a, vector<int> &b, int k)
{
    priority_queue<int> pq;

    for (int a_n : a)
        pq.push(a_n);

    for (int b_n : b)
        pq.push(b_n);

    while (pq.size() > 0 && pq.size() != k)
        pq.pop();

    return pq.top();
}

int binarySearch(vector<int> &a, vector<int> &b, int k)
{
    int n1 = a.size(), n2 = b.size();

    if (n1 > n2) // swap
        return binarySearch(b, a, k);

    int n = n1 + n2;
    int low = max(k - n2, 0), high = min(n1, k);
    int left = k; // No. of elements required on left
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        // assign l1, l2, r1, r2
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 > 0)
            l1 = a[mid1 - 1];
        if (mid2 > 0)
            l2 = b[mid2 - 1];

        // binary search conditions
        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > l2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return -1;
}

int kthElement(vector<int> &a, vector<int> &b, int k)
{
    // Brute Force approach
    // return bruteForce(a, b, k);

    // Binary Search approach
    return binarySearch(a, b, k);
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    cout << "The k-th element is : " << kthElement(a, b, k) << endl;
    return 0;
}