/*
    First negative integer in every window of size k

    Given an array A[] of size N and a positive integer K, find the first negative integer for each and 
    every window(contiguous subarray) of size K.
*/

#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(vector<long long int> A, long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;

    // processing for first window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store ans for first window
    if (!dq.empty())
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // for remaining windows
    for (int i = K; i < N; i++)
    {
        // removing
        if (!dq.empty() && (i - dq.front()) >= K)
        {
            dq.pop_front();
        }

        // adding 
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // store ans
        if (!dq.empty())
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    vector<long long int> A = {-8, 2, 3, -6, 10};
    long long int N = 5;
    long long int K = 3;
    vector<long long> ans = printFirstNegativeInteger(A, N, K);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}