/*
    Combination Sum

    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

    The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

    The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.


    Example 1:

    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    Explanation:
    2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
    7 is a candidate, and 7 = 7.
    These are the only two combinations.
    Example 2:

    Input: candidates = [2,3,5], target = 8
    Output: [[2,2,2,2],[2,3,3],[3,5]]
    Example 3:

    Input: candidates = [2], target = 1
    Output: []
    

    Constraints:

    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40
*/

#include<bits/stdc++.h>
using namespace std;

void solveRecur2(int i, int target, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res)
{
    if (i == arr.size())
    {
        if (target == 0)
            res.push_back(temp);
        return;
    }

    // include the element
    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        solveRecur2(i, target - arr[i], arr, temp, res);
        temp.pop_back();
    }

    // exclude
    solveRecur2(i + 1, target, arr, temp, res);
}

void solveRecur(int i, int target, vector<int>& temp, vector<int>& arr, vector<vector<int>>& res)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }

    // check for all possible combinations
    for (int j = i; j < arr.size(); j ++)
    {
        temp.push_back(arr[j]);
        solveRecur(j, target - arr[j], temp, arr, res);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    solveRecur(0, target, temp, candidates, res);
    return res;
}

int main()
{
    vector<int> candidates = {2, 3, 5};
    int target = 8;   
    vector<vector<int>> res = combinationSum(candidates, target);

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