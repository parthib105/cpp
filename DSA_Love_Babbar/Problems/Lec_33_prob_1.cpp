/*
    Check if the array is sorted or not using recursion
*/

#include<bits/stdc++.h>
using namespace std;

// concidering ascending order of sorting
bool isSorted(int* arr, int size)
{
    // base case
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr + 1, size - 1);
    }
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

    cout << "The array is sorted? -> " << isSorted(arr, n) << endl;

    delete[] arr;
    
    return 0;
}