/*
    Reverse the Array

    Given an array 'ARR' of integers and a position 'M'. You have to reverse the array after that position

    EX : 
        ARR = {1, 2, 3, 4, 5, 6}, M = 3  (0-based indexing)
        output = {1, 2, 3, 4, 6, 5}
*/

#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    int i = m + 1;
    int j = arr.size() - 1;

    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i ++;
        j --;
    }
}

int main()
{
    vector<int> arr = {10, 9, 8, 7, 6};
    int m = 2;
    cout << "Before Reverse : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    
    reverseArray(arr, m);

    cout << "After Reverse : " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}