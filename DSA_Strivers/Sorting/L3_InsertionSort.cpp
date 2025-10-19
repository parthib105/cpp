/*
    take an element and put it in it's correct position
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. O(N^2)
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = curr;
    }
}

void printVec(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    cout << "Before sorting : ";
    printVec(arr);
    cout << endl;

    insertionSort(arr);

    cout << "After sorting : ";
    printVec(arr);
    cout << endl;


    return 0;
}