/*
    Single Number

    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    You must implement a solution with a linear runtime complexity and use only constant extra space.

    Example 1:

    Input: nums = [2,2,1]
    Output: 1
    Example 2:

    Input: nums = [4,1,2,1,2]
    Output: 4
    Example 3:

    Input: nums = [1]
    Output: 1


    Constraints:

    1 <= nums.length <= 3 * 10^4
    -3 * 104 <= nums[i] <= 3 * 10^4
    Each element in the array appears twice except for one element which appears only once.
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

// T.C. : O(n), S.C. : O(1)
int optimal(vector<int> &nums)
{
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans = (ans ^ nums[i]);
    }
    return ans;
}

int singleNumber(vector<int> &nums)
{
    // Brute Force
    // return brute(nums);

    // Optimal
    return optimal(nums);
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;
    return 0;
}