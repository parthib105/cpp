/*
    Subsets

        Given an integer array nums of unique elements, return all possible 
    subsets
    (the power set).

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

// T.C. : O(n * 2^n), S.C. : O(n * 2^n)
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> sub;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sub.push_back(nums[j]);
            }
        }
        ans.push_back(sub);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 4};
    vector<vector<int>> ans = subsets(nums);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}