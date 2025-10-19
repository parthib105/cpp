/*
    Sum of Subarray Minimums

    Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

    Example 1:

    Input: arr = [3,1,2,4]
    Output: 17
    Explanation: 
    Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
    Sum is 17.
    Example 2:

    Input: arr = [11,81,94,43,3]
    Output: 444
    

    Constraints:

    1 <= arr.length <= 3 * 10^4
    1 <= arr[i] <= 3 * 10^4
*/

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

vector<int> findNSE(int n, vector<int>& arr)
{
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findPSEE(int n, vector<int>& arr)
{
    vector<int> psee(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

// T.C. : O(N^2), S.C. : O(1)
int sumSubarrayMinsBrute(vector<int>& arr)
{
    int n = arr.size();
    int subarrSum = 0;
    for (int i = 0; i < n; i++)
    {
        int minElm = arr[i];
        for (int j = i; j < n; j++)
        {
            minElm = min(minElm, arr[j]);
            subarrSum = (subarrSum + minElm) % mod;
        }
    }
    return subarrSum;
}

// T.C. : O(5N), S.C. : O(5N)
int sumSubarrayMinsOptimal(vector<int>& arr)
{
    int n = arr.size();
    vector<int> nse = findNSE(n, arr);      // O(2N), O(2N)
    vector<int> psee = findPSEE(n, arr);    // O(2N), O(2N)
    long long total = 0;

    for (int i = 0; i < n; i++)     // O(N)
    {
        int left = i - psee[i];
        int right = nse[i] - i;
        total = (total + ((long long)left * (long long)right * (long long)arr[i])%mod) % mod;
    }
    return total;
}

int sumSubarrayMins(vector<int>& arr) {
    // Brute Force solution
    // return sumSubarrayMinsBrute(arr);

    // Optimal solution
    return sumSubarrayMinsOptimal(arr);
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << sumSubarrayMins(arr) << endl;
    return 0;
}