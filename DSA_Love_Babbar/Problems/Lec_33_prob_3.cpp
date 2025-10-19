/*
    Linear search and binary search
*/

#include<bits/stdc++.h>
using namespace std;

int linearSearch(int* arr, int size, int key)
{
    static int idx = -1;
    // base case
    if (size == 0)
    {
        return -1;
    }

    idx ++;

    if (arr[0] == key)
    {
        return idx;
    }
    else
    {
        return linearSearch(arr + 1, size - 1, key);
    }
}

int binarySearch(int* arr, int s, int e, int key)
{
    if (s > e)
    {
        return -1;
    }

    int m = s + (e - s)/2;
    if (arr[m] == key)
    {
        return m;
    }
    else if (arr[m] < key)
    {
        return binarySearch(arr, m + 1, e, key);
    }
    else 
    {
        return binarySearch(arr, s, m - 1, key);
    }
}

int main()
{
    int n, key;
    cout << "Enter the size of the array : ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the ley to be searched : ";
    cin >> key;

    int ls = linearSearch(arr, n, key);
    int bs = binarySearch(arr, 0, n - 1, key);

    (ls == -1) ? (cout << "(Linear Search) Element not found\n") : (cout << "(Linear Search) Element found at index " << ls << endl);

    (bs == -1) ? (cout << "(Binary Search) Element not found\n") : (cout << "(Binary Search) Element found at index " << bs << endl);


    delete[] arr;
    return 0;
}