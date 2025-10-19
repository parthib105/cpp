/*
    PEEK INDEX IN A MOUNTAIN ARRAY

    let's call an array a mountain array if the following properties hold :
        * arr.length >= 3
        * There exists some i with 0 < i < arr.length - 1 such that:
                => arr[0] < arr[1] < ... arr[i - 1] < arr[i],
                => arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

    Given an integer array arr that is guaranteed to be a mountain array, return any i
    such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
*/

#include <bits/stdc++.h>
using namespace std;

int peekIndexInMountainArray(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        int mid = i + (j - i) / 2;

        if ((arr[mid - 1] < arr[mid]) && (arr[mid] > arr[mid + 1]))
        {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {3, 4, 5, 2};
    cout << peekIndexInMountainArray(arr) << endl;
    return 0;
}