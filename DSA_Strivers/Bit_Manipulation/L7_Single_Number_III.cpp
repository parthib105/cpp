/*
    Single Number III

    Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly
    twice. Find the two elements that appear only once. You can return the answer in any order.

    You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

    Example 1:

    Input: nums = [1,2,1,3,2,5]
    Output: [3,5]
    Explanation:  [5, 3] is also a valid answer.
    Example 2:

    Input: nums = [-1,0]
    Output: [-1,0]
    Example 3:

    Input: nums = [0,1]
    Output: [1,0]


    Constraints:

    2 <= nums.length <= 3 * 10^4
    -2^31 <= nums[i] <= 2^31 - 1
    Each integer in nums will appear twice, only two integers will appear once.
    */

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(n), S.C. : O(m), m = 1 + n/2
vector<int> brute(vector<int> &nums)
{
    unordered_map<int, int> freq;
    for (auto n : nums)
    {
        freq[n] += 1;
    }

    vector<int> ans;
    unordered_map<int, int>::iterator it = freq.begin();
    while (it != freq.end())
    {
        if (it->second == 1)
        {
            ans.push_back(it->first);
        }
        it++;
    }
    return ans;
}

vector<int> optimal(vector<int> &nums)
{
    // take xor of all numbers
    long int xorr = 0;
    for (auto num : nums)
    {
        xorr = (xorr ^ (long int)num);
    }

    // get the rightmost bit
    long int r = (xorr & (xorr - 1)) ^ xorr;

    int buc1 = 0, buc2 = 0;
    for (auto n : nums)
    {
        if ((long int)n & r)
        {
            buc1 = buc1 ^ n;
        }
        else
        {
            buc2 = buc2 ^ n;
        }
    }

    if (buc1 < buc2)
    {
        return {buc1, buc2};
    }
    return {buc2, buc1};
}

vector<int> singleNumber(vector<int> &nums)
{
    // Brute Force
    // return brute(nums);

    // Optimal
    return optimal(nums);
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> unique = singleNumber(nums);

    vector<int>::iterator it = unique.begin();
    while (it != unique.end())
    {
        cout << *it << " ";
        it++;
    }
    return 0;
}