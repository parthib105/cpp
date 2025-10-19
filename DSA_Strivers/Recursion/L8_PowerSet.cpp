/*
    Subsets

    Given an integer array nums of unique elements, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    Example 2:

    Input: nums = [0]
    Output: [[],[0]]
    

    Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
    All the numbers of nums are unique.
*/

#include<bits/stdc++.h>
using namespace std;

void backtrack(int i, int n, vector<int>& sub, vector<int>& nums, vector<vector<int>>& res)
{
    if (i >= n)
    {
        res.push_back(sub);
        return;
    }

    // exclude the current element
    backtrack(i + 1, n, sub, nums, res);

    // include the current element
    sub.push_back(nums[i]);
    backtrack(i + 1, n, sub, nums, res);
    sub.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> sub;
    backtrack(0, nums.size(), sub, nums, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> res = subsets(nums);

    for (vector<int> sub : res)
    {
        cout << "[";
        for (int i = 0; i < sub.size(); i++)
        {
            if (i == sub.size() - 1)
                cout << sub[i];
            else
                cout << sub[i] << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}