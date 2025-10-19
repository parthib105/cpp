/*
    Bubble sort using recursion
*/

#include<bits/stdc++.h>
using namespace std;

void bubbleSortRecur(int* arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    
    // sort for one round
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    bubbleSortRecur(arr, n - 1);
}

/*
    Insertion sort using recursion
*/

void insertionSortRecur(int* arr, int n, int i)
{
    if (n <= 1)
    {
        return;
    }
    if (i >= n)
    {
        return;
    }

    int temp = arr[i];
    int j = i - 1;
    while (j >= 0)
    {
        if (arr[j] > temp)
        {
            arr[j + 1] = arr[j];
        }
        else
        {
            break;
        }
        j --;
    }
    arr[j + 1] = temp;

    insertionSortRecur(arr, n, i + 1);
}

/*
    Selection sort using recursion
*/

void selectionSortRecur(int* arr, int n, int i)
{
    if (n <= 1)
    {
        return;
    }
    if (i >= n)
    {
        return;
    }

    int minIdx = i;
    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[minIdx])
        {
            minIdx = j;
        }
    }

    int temp = arr[minIdx];
    arr[minIdx] = arr[i];
    arr[i] = temp;

    selectionSortRecur(arr, n, i + 1);
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

    selectionSortRecur(arr, n, 0);

    cout << "Sorted array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}