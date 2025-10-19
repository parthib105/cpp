// Insertion sort

#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j --;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    string S = "10010";

    for (int i = 0; i < S.length(); i++)
    {
        cout << S[i] - '0' << " ";
    }
    
    return 0;
}