/*
    4Sum

    Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] 
    such that: 0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target
    You may return the answer in any order.

    Example 1:

    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    Example 2:

    Input: nums = [2,2,2,2,2], target = 8
    Output: [[2,2,2,2]]
    

    Constraints:

    1 <= nums.length <= 200
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long currSum = nums[i] + nums[j];
                    currSum += nums[k];
                    currSum += nums[l];
                    if (currSum == target)
                    {
                        vector<int> arr = {nums[i], nums[j], nums[k], nums[l]};
                        sort(arr.begin(), arr.end());
                        s.insert(arr);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

// T.C. O(n^3 log(m))
vector<vector<int>> better(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashSet;
            for (int k = j + 1; k < n; k++)
            {
                long long currSum = nums[i] + nums[j];
                currSum += nums[k];

                long long last = target - (nums[i] + nums[j] + nums[k]);
                if (hashSet.find(last) != hashSet.end())
                {
                    vector<int> arr = {nums[i], nums[j], nums[k], (int)last};
                    sort(arr.begin(), arr.end());
                    s.insert(arr);
                }
                hashSet.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> optimal(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) // skip the duplicates
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) // skip the duplicates
            {
                continue;
            }

            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long currSum = nums[i] + nums[j];
                currSum += nums[k];
                currSum += nums[l];

                if (currSum < target)
                {
                    k++;
                }
                else if (currSum > target)
                {
                    l--;
                }
                else // currSum == target
                {
                    vector<int> arr = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(arr);
                    k++;
                    l--;

                    // skip the duplicate elements
                    while (k < l && nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                    while (k < l && nums[l] == nums[l + 1])
                    {
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // Brute Force
    // return brute(nums, target);

    // Better solution
    // return better(nums, target);

    // optimal solution
    return optimal(nums, target);
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> ans = fourSum(nums, target);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}