/*
    Subarray Sum Equals K

    Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

    A subarray is a contiguous non-empty sequence of elements within an array.

    Example 1:

    Input: nums = [1,1,1], k = 2
    Output: 2
    Example 2:

    Input: nums = [1,2,3], k = 3
    Output: 2

    Constraints:

    1 <= nums.length <= 2 * 10^4
    -1000 <= nums[i] <= 1000
    -10^7 <= k <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(n^3), S.C. : O(1)
int brute(vector<int> &nums, int k)
{
    int n = nums.size();
    int subArrays = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currSum = 0;
            for (int p = i; p <= j; p++)
            {
                currSum += nums[p];
            }
            if (currSum == k)
            {
                subArrays ++;
            }
        }
    }
    return subArrays;
}

// T.C. : O(n^2), S.C. : O(1)
int better(vector<int> &nums, int k)
{
    int n = nums.size();
    int subArrays = 0;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += nums[j];
            if (currSum == k)
            {
                subArrays ++;
            }
        }
    }
    return subArrays;
}

// T.C. : O(n), S.C. : O(n)
int optimal(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = 1;

    int preSum = 0, subArrays = 0;
    for (int i = 0; i < n; i++)
    {
        // add to the prefix sum
        preSum += nums[i];

        // count the subarray that has remainder as prefix sum
        int rem = preSum - k;
        subArrays += mp[rem];

        // store the prefux sum
        mp[preSum] += 1;
    }
    return subArrays;
}

int anotherApproach(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = nums[i] + prefixSum[i - 1];
    }

    unordered_map<int, int> preSum;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (prefixSum[i] == k)
        {
            ans++;
        }

        // check for remainder
        int rem = prefixSum[i] - k;
        if (preSum.find(rem) != preSum.end())
        {
            ans += preSum[rem];
        }

        // put prefix sum into map
        preSum[prefixSum[i]]++;
    }
    return ans;
}

int subarraySum(vector<int> &nums, int k)
{
    // Brute Force
    // return brute(nums, k);

    // Better Solution
    // return better(nums, k);

    // Optimal Solution
    return optimal(nums, k);
}

int main()
{
    vector<int> nums = {1, 2, 3, -3};
    int k = 3;

    cout << subarraySum(nums, k) << endl;
    return 0;
}