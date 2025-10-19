/*
    Merge Sort
*/

#include<bits/stdc++.h>
using namespace std;

void mergeArrays(int* arr, int s, int e)
{
    int m = s + (e - s)/2;
    int len1 = m - s + 1;
    int len2 = e - m;
    int idx = s;

    // copy values into new arrays
    int* left = new int[len1];
    int* right = new int[len2];

    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[idx++];
    }

    idx = m + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[idx++];
    }
    
    // merge two sorted arrays
    idx = s;
    int idx1 = 0;
    int idx2 = 0;

    while(idx1 < len1 && idx2 < len2)
    {
        if (left[idx1] < right[idx2])
        {
            arr[idx] = left[idx1];
            idx ++;
            idx1 ++;
        }
        else
        {
            arr[idx] = right[idx2];
            idx ++;
            idx2 ++;
        }
    }

    while (idx1 < len1)
    {
        arr[idx] = left[idx1];
        idx ++;
        idx1 ++;
    }

    while (idx2 < len2)
    {
        arr[idx] = right[idx2];
        idx ++;
        idx2 ++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, int s, int e)
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

    mergeArrays(arr, s, e);
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}