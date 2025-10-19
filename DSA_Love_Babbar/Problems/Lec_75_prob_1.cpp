/*
    K-th smallest element

    Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest 
    element in the given array. It is given that all array elements are distinct.

    Note:-  l and r denotes the starting and ending index of the array.
*/

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& arr, int k)
{
    int n = arr.size();
    priority_queue<int> pq;

    // put first k elements into heap
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // for rest of the array
    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main()
{
    int n = 7;
    int k = 3;
    vector<int> arr = {7, 10, 4, 3, 20, 15, 2};

    cout << k << "th smallest element is : " << kthSmallest(arr, k) << endl;
    return 0;
}