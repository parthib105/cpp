#include<bits/stdc++.h>
using namespace std;

// following 0-based indexing
// put the current element into it's right position
// leaf nodes lies from (n/2 + 1) to n
void heapify(vector<int> &arr, int n, int idx)
{
    int curr = idx;

    // find the left and right child
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;

    if (lc < n && arr[curr] < arr[lc])
    {
        curr = lc;
    }
    if (rc < n && arr[curr] < arr[rc])
    {
        curr = rc;
    }

    if (curr != idx)
    {
        swap(arr[curr], arr[idx]);
        heapify(arr, n, curr);
    }
}

void heapSort(vector<int> &arr, int size)
{
    // heap creation
    for (int i = size/2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    
    // heap sort
    while (size > 0)
    {
        // step 1 : swap with first element
        swap(arr[0], arr[size - 1]);
        
        // step 2 : decrease the size
        size = size - 1;
        
        // step 3 : heapify
        heapify(arr, size, 0);
    }
}

int main()
{
    int n = 8;
    vector<int> arr = {43, 23, 45, 34, 65, 100, 1, 0};
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}