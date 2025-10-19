/*
    Subset Sum II

    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Example 1:

    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
    Example 2:

    Input: nums = [0]
    Output: [[],[0]]
    

    Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/

#include<bits/stdc++.h>
using namespace std;

void solveRecur(int i, vector<int>& nums, vector<int>& currSub, vector<vector<int>>& res)
{
    res.push_back(currSub);

    for (int j = i; j < nums.size(); j++)
    {
        if (j > i && nums[j] == nums[j - 1])
            continue;
        
        currSub.push_back(nums[j]);
        solveRecur(j + 1, nums, currSub, res);
        currSub.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    vector<int> currSub;

    solveRecur(0, nums, currSub, res);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = subsetsWithDup(nums);

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