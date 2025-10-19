/*
    Select the minimum and swap

*/

#include<bits/stdc++.h>
using namespace std;

// T.C. O(N^2)
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        // Find minimum element index
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
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

    selectionSort(arr);

    cout << "After sorting : ";
    printVec(arr);
    cout << endl;

    return 0;
}