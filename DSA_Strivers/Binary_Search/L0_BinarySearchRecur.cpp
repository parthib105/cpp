/*
    Binary Search using recursion
*/

#include<bits/stdc++.h>
using namespace std;

int binaryRecur(vector<int> arr, int s, int e, int k)
{
    if (s > e)
    {
        return -1;
    }

    int m = s + (e - s)/2;
    
    if (arr[m] == k)
    {
        return m;
    }
    else if (k < arr[m])
    {
        return binaryRecur(arr, s, m - 1, k);
    }
    else
    {
        return binaryRecur(arr, m + 1, e, k);
    }
}

int main()
{
    int n = 8, k = 0;
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    cout << binaryRecur(arr, 0, n - 1, k);
    return 0;
}