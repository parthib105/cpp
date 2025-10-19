// Bubble Sort

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)      // for round 1 to n - 1
    {
        for (int j = 0; j < n - i; j++)
        {
            // process element till n - i th index
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// optimized code for bubble sort
void bubbleSortOptimized(vector<int>& arr, int n)
{
    int i, j, isSwapped;
    isSwapped = 1;
    for(i = 0; i < n - 1 && isSwapped; ++i)
    {
        isSwapped = 0;
        for(j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSwapped = 1;
            }
        }
    }
}

int main()
{
    vector<int> arr = {10, 1, 7, 6, 14, 9};
    int n = 6;
    bubbleSortOptimized(arr, n);
    // printArray(arr, n);
    return 0;
}