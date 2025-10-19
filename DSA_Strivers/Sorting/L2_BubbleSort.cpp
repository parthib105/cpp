/*
    Pushes the maximum to the last by adjacent swaps
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. O(N^2)
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--)
    {
        bool swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            return;
        }
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

    bubbleSort(arr);

    cout << "After sorting : ";
    printVec(arr);
    cout << endl;


    return 0;
}