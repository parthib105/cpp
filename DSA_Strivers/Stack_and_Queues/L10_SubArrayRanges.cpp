/*
    Sum of Subarray Ranges

    You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

    Return the sum of all subarray ranges of nums.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:

    Input: nums = [1,2,3]
    Output: 4
    Explanation: The 6 subarrays of nums are the following:
    [1], range = largest - smallest = 1 - 1 = 0 
    [2], range = 2 - 2 = 0
    [3], range = 3 - 3 = 0
    [1,2], range = 2 - 1 = 1
    [2,3], range = 3 - 2 = 1
    [1,2,3], range = 3 - 1 = 2
    So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
    Example 2:

    Input: nums = [1,3,3]
    Output: 4
    Explanation: The 6 subarrays of nums are the following:
    [1], range = largest - smallest = 1 - 1 = 0
    [3], range = 3 - 3 = 0
    [3], range = 3 - 3 = 0
    [1,3], range = 3 - 1 = 2
    [3,3], range = 3 - 3 = 0
    [1,3,3], range = 3 - 1 = 2
    So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
    Example 3:

    Input: nums = [4,-2,-3,4,1]
    Output: 59
    Explanation: The sum of all subarray ranges of nums is 59.
    

    Constraints:

    1 <= nums.length <= 1000
    -10^9 <= nums[i] <= 10^9
*/

#include<bits/stdc++.h>
using namespace std;


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

vector<int> findNGE(int n, vector<int>& arr)
{
    vector<int> nge(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
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

vector<int> findPGEE(int n, vector<int>& arr)
{
    vector<int> pgee(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        
        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pgee;
}

long long sumSubarrayMins(vector<int>& arr)
{
    int n = arr.size();
    vector<int> nse = findNSE(n, arr);      // O(2N), O(2N)
    vector<int> psee = findPSEE(n, arr);    // O(2N), O(2N)
    long long total = 0;

    for (int i = 0; i < n; i++)     // O(N)
    {
        int left = i - psee[i];
        int right = nse[i] - i;
        total = (total + ((long long)left * (long long)right * (long long)arr[i]));
    }
    return total;
}

long long sumSubarrayMaxs(vector<int>& arr)
{
    int n = arr.size();
    vector<int> nge = findNGE(n, arr);      // O(2N), O(2N)
    vector<int> pgee = findPGEE(n, arr);    // O(2N), O(2N)
    long long total = 0;

    for (int i = 0; i < n; i++)     // O(N)
    {
        int left = i - pgee[i];
        int right = nge[i] - i;
        total = (total + ((long long)left * (long long)right * (long long)arr[i]));
    }
    return total;
}


// T.C. : O(N^2), S.C. : O(1)
long long subArrayRangesBrute(vector<int>& arr)
{
    int n = arr.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int minElm = arr[i], maxElm = arr[i];
        for (int j = i; j < n; j++)
        {
            minElm = min(minElm, arr[j]);
            maxElm = max(maxElm, arr[j]);
            sum += (long long)(maxElm - minElm);
        }
    }
    return sum;
}

long long subArrayRangesOptimal(vector<int>& nums)
{
    long long maxSum = sumSubarrayMaxs(nums);
    long long minSum = sumSubarrayMins(nums);
    return maxSum - minSum;
}

long long subArrayRanges(vector<int>& nums) {
    // Brute Force solution'
    // return subArrayRangesBrute(nums);

    // Optimal Solution
    return subArrayRangesOptimal(nums);
}

int main()
{
    vector<int> nums = {4, -2, -3, 4, 1};
    cout << subArrayRanges(nums) << endl;
    return 0;
}