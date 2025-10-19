/*
    Single Number II

    Given an integer array nums where every element appears three times except for one, which appears exactly once.
    Find the single element and return it.

    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:

    Input: nums = [2,2,3,2]
    Output: 3
    Example 2:

    Input: nums = [0,1,0,1,0,1,99]
    Output: 99

    Constraints:

    1 <= nums.length <= 3 * 10^4
    -2^31 <= nums[i] <= 2^31 - 1
    Each element in nums appears exactly three times except for one element which appears once.
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(n), S.C. : O(n)
int brute(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (auto n : nums)
    {
        freq[n] += 1;
    }

    unordered_map<int, int>::iterator it = freq.begin();
    while (it != freq.end())
    {
        if (it->second == 1)
        {
            return it->first;
        }
        it++;
    }
    return -1;
}

// T.C. : O(32 * n), S.C. : O(1)
int better(vector<int> &nums)
{
    int ans = 0;
    for (int bitIdx = 0; bitIdx < 32; bitIdx++)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // check if the ith bit is set
            if (nums[i] & (1 << bitIdx))
            {
                cnt++;
            }
        }

        if (cnt % 3 == 1)
        {
            // set the bit
            ans = ans | (1 << bitIdx);
        }
    }
    return ans;
}

// T.C. : O(n * log(n) + n/3), S.C. : O(1)
int optimal(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i += 3)
    {
        if (nums[i] != nums[i - 1])
        {
            return nums[i - 1];
        }
    }
    return nums.back();
}

// T.C. : O(n), S.C. : O(1)
int anotherApproach(vector<int> &nums)
{
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones = (ones ^ nums[i]) & (~twos); // store in ones if not in twos
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}

int singleNumber(vector<int> &nums)
{
    // Brute Force
    // return brute(nums);

    // Most optimal
    return anotherApproach(nums);
}

int main()
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(nums) << endl;
    return 0;
}