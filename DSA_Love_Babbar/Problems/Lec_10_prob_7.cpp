/*
    You have been given an integer array 'ARR' of size 'N'. It only contains 0s, 1s and 2s
    Write an algorithm to sort this array.
*/

#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> arr)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        
        if (arr[i] == 2)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        }
        else if (arr[i] == 2 && arr[j] == 2)
        {
            i ++;
            j --;
        }
        else
        {
            i++;
        }
    }

    if (arr[j] == 2)
    {
        j --;
    }
    
    i = 0;
    while (i < j)
    {
        if (arr[i] == 1)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        }
        else if (arr[i] == 1 && arr[j] == 1)
        {
            i ++;
            j --;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 2, 0};
    // 0 0 0 1 1 1 2 2
    sort012(arr);
    return 0;
}