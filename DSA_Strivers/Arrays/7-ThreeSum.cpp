/*
    3Sum

    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
    and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Example 1:

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation: 
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].
    Notice that the order of the output and the order of the triplets does not matter.
    
    Example 2:

    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.
    
    Example 3:

    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.

    Constraints:

    3 <= nums.length <= 3000
    -10^5 <= nums[i] <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(n^3 * log(no. of unique elements)), S.C. : O(no. of unique triplets)
vector<vector<int>> brute(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

// T.C. : O(n^2 * log(m)), S.C. : O(no. of unique triplets)  , m->for set insertion
vector<vector<int>> better(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> optimal(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int currSum = nums[i] + nums[j] + nums[k];
            if (currSum == 0)
            {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
            else if (currSum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    return ans;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    // Brute Force
    // return brute(nums);

    // Better solution
    // return better(nums);

    // Optimal
    return optimal(nums);
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
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