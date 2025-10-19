/*
    Two Sum

    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.



    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    Example 2:

    Input: nums = [3,2,4], target = 6
    Output: [1,2]
    Example 3:

    Input: nums = [3,3], target = 6
    Output: [0,1]


    Constraints:

    2 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9
    Only one valid answer exists.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force
vector<int> bruteForce(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

// Better
vector<int> better(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            ans.push_back(mp[target - nums[i]]);
            ans.push_back(i);
            break;
        }
        mp.insert({nums[i], i});
    }

    return ans;
}

// Optimal
vector<int> optimal(vector<int> &nums, int target)
{
    int l = 0, r = nums.size();
    sort(nums.begin(), nums.end());

    while (l < r)
    {
        int sum = nums[l] + nums[r];
        if (sum == target)
        {
            return {l, r};
        }
        else if (sum > target)
        {
            l ++;
        }
        else
        {
            r --;
        }
    }
    return {-1, -1};
}

vector<int> twoSum(vector<int> &nums, int target)
{
    // Brute Force
    // return bruteForce(nums, target);

    // Better Approach
    return better(nums, target);
}

int main()
{

    return 0;
}