/*
    COmbination Sum II

    Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.


    Example 1:

    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output: 
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
    Example 2:

    Input: candidates = [2,5,2,1,2], target = 5
    Output: 
    [
    [1,2,2],
    [5]
    ]
    

    Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30
*/

#include<bits/stdc++.h>
using namespace std;

void solveRecur(int i, int target, vector<int>& arr, vector<int>& combos, vector<vector<int>>& res)
{
    if (target < 0)
        return;
    if (target == 0)
    {
        res.push_back(combos);
        return;
    }

    for (int j = i; j < arr.size(); j++)
    {
        if (arr[j] > target)
            break;
        if (j > i && arr[j] == arr[j - 1])
            continue;

        combos.push_back(arr[j]);
        solveRecur(j + 1, target - arr[j], arr, combos,res);
        combos.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> res;
    vector<int> combos;
    solveRecur(0, target, candidates, combos, res);
    return res;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;   
    vector<vector<int>> res = combinationSum2(candidates, target);

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