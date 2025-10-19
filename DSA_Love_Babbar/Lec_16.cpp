// Selection Sort
// Time Complexity = O({n}^{2})

/*
    Find the minumum element at each iteration and place it at right position.
*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // finding minumum element in rest of the array
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        // swap the elements
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    } 
}

int main()
{
    vector<int> arr = {4, 1, 2, 3, 6};
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        // finding minumum element in rest of the array
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        // swap the elements
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}