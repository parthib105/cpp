/*
    You are given an array 'ARR' of size 'N' containing number between 1 and 'N' - 1 at least once.
    There is a single integer value that is present in the array twice.
    Find that duplicate integer.
*/

#include <iostream>
using namespace std;

int method1(int arr[], int N)
{
    int a[N] = {0};
    for (int i = 0; i < N; i++)
    {
        a[arr[i]]++;
    }
    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] > 1)
        {
            ans = i;
        }
    }
    return ans;
}

int method2(int arr[], int N)
{
    int ans = 0;

    // XORing all array elements
    for (int i = 0; i < N; i++)
    {
        ans = ans ^ arr[i];
    }

    // XOR [1, N - 1]
    for (int i = 0; i < N; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    int N = 6;
    int arr[N] = {1, 2, 4, 3, 4, 5};
    cout << method2(arr, N);
    return 0;
}