/*
    Merge Intervals

    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of
    the non-overlapping intervals that cover all the intervals in the input.

    Example 1:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

    Example 2:

    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
    Explanation: Intervals [1,4] and [4,5] are considered overlapping.

    Constraints:

    1 <= intervals.length <= 10^4
    intervals[i].length == 2
    0 <= starti <= endi <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(n log(n)) + O(2n), S.C. : O(n)
vector<vector<int>> brute(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int st = arr[i][0];
        int ed = arr[i][1];
        if (!ans.empty() && ed <= ans.back()[1]) // skip if already present
        {
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= ed)
            {
                ed = max(ed, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({st, ed});
    }
    return ans;
}

// T.C. : O(n), S.C. : O(1)
vector<vector<int>> optimal(vector<vector<int>> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> intrvl = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] >= intrvl[0] && arr[i][0] <= intrvl[1])
        {
            intrvl[1] = max(intrvl[1], arr[i][1]);
        }
        else
        {
            ans.push_back(intrvl);
            intrvl = arr[i];
        }
    }
    ans.push_back(intrvl);
    return ans;
}

vector<vector<int>> merge(vector<vector<int>> &arr)
{
    // Brute Force
    // return brute(arr);

    // optimal
    return optimal(arr);
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 4}, {2, 6}, {8, 10}, {9, 12}, {15, 18}, {16, 17}};
    vector<vector<int>> ans = merge(arr);

    for (auto i : ans)
    {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}