/*
    Find Unique

    You have been given an integer array arr of size N, N = 2 * M + 1
    Now, in the given array 'M' no.s are present twice and one no is present
    only once.

    You need to find and return that no. which is unique in the array

    => XOR property :
        a ^ a = 0
        0 ^ a = a
*/

#include <iostream>
using namespace std;

int findUnique(int arr[], int size)
{
    int ans = 0;    
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int arr[9] = {1, 3, 1, 3, 6, 6, 8, 11, 8};
    cout << "Unique number is : " << findUnique(arr, 9);
    return 0;
}