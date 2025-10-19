/*
    Given two arrays 'A' and 'B' of size 'N' and 'M' repectively. Both these arrays are
    sorted in non-decreasing order. You have to find the intersection of these two arrays.

    Intersection of two arrays is an array that consists of all the common elements occurring in 
    both arrays.

    Ex.  1 2 2 2 3 4
         2 2 3 4

    ans: 2 2 3 
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(int arr1[], int arr2[], int N, int M)
{
    int i = 0;
    int j = 0;

    vector<int> ans;

    while (i < N && j < M)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        if (arr2[j] < arr1[i])
        {
            j++;
        }
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int N = 6;
    int M = 4;

    int arr1[N] = {1, 2, 2, 2, 3, 4};
    int arr2[M] = {2, 2, 3, 3};

    vector<int> ans = intersection(arr1, arr2, N, M);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}