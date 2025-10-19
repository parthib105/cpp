/*
    Quick sort
*/

#include<bits/stdc++.h>
using namespace std;

int partition(int* arr, int s, int e)
{
    int pivot = arr[s];
    int countNum = 0;
    for (int i = s; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            countNum ++;
        }
    }

    int pivotIdx = s + countNum;
    // swap
    int temp = arr[s];
    arr[s] = arr[pivotIdx];
    arr[pivotIdx] = temp;

    int i = s;
    int j = e;

    while (i < pivotIdx && j > pivotIdx)
    {
        while (arr[i] <= pivot)
        {
            i ++;
        }

        while (arr[j] > pivot)
        {
            j --;
        }

        if (i < pivotIdx && j > pivotIdx)
        {
            swap(arr[i++], arr[j--]);
        }

    }

    return pivotIdx;
}

void quickSort(int* arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    // for left part
    quickSort(arr, s, p - 1);

    // for right part
    quickSort(arr, p + 1, e);
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

    quickSort(arr, 0, n - 1);

    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}