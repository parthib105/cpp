/*
    Quick Sort

    Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order.
    Given an array arr[], with starting index low and ending index high, complete the functions partition() and quickSort().
    Use the last element as the pivot, so that all elements less than or equal to the pivot come before it, and elements greater than the pivot follow it.

    Note: low and high are inclusive.

    Examples:

    Input: arr[] = [4, 1, 3, 9, 7]
    Output: [1, 3, 4, 7, 9]
    Explanation: After sorting, all elements are arranged in ascending order.
    Input: arr[] = [2, 1, 6, 10, 4, 1, 3, 9, 7]
    Output: [1, 1, 2, 3, 4, 6, 7, 9, 10]
    Explanation: Duplicate elements (1) are retained in sorted order.
    Input: arr[] = [5, 5, 5, 5]
    Output: [5, 5, 5, 5]
    Explanation: All elements are identical, so the array remains unchanged.

    Constraints:
    1 ≤ arr.size() ≤ 10^5
    1 ≤ arr[i] ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        // find arr[i] > arr[p];
        while (arr[i] <= pivot && i < high)
            i++;

        // find arr[j] < arr[p]
        while (arr[j] > pivot && j > low)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// T.C. : O(n log(n)), S.C. : O(1)
void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

int main()
{

    return 0;
}