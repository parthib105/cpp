// Binary Search

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int N, int key)
{
    int i = 0;
    int j = N - 1;

    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
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

/*
    In case of large values, use the given formula

    mid = i + (j - i) / 2;
*/

int main()
{
    int N = 8;
    int arr[N] = {1, 3, 6, 7, 10, 26, 37, 47};
    int key = 0;
    int idx = BinarySearch(arr, N, key);
    if (idx != -1)
    {
        cout << "Index of " << key << " is : " << idx;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}