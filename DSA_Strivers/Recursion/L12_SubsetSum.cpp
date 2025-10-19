/*
    Subset Sums

    Given a array arr of integers, return the sums of all subsets in the list.  Return the sums in any order.

    Examples:

    Input: arr[] = [2, 3]
    Output: [0, 2, 3, 5]
    Explanation: When no elements are taken then Sum = 0. When only 2 is taken then Sum = 2. When only 3 is taken then Sum = 3. When elements 2 and 3 are taken then Sum = 2+3 = 5.
    Input: arr[] = [1, 2, 1]
    Output: [0, 1, 1, 2, 2, 3, 3, 4]
    Explanation: The possible subset sums are 0 (no elements), 1 (either of the 1's), 2 (the element 2), and their combinations.
    Input: arr[] = [5, 6, 7]
    Output: [0, 5, 6, 7, 11, 12, 13, 18]
    Explanation: The possible subset sums are 0 (no elements), 5, 6, 7, and their combinations.

    Constraints:
    1 ≤ arr.size() ≤ 15
    0 ≤ arr[i] ≤ 10^4
*/

#include<bits/stdc++.h>
using namespace std;

void solveRecur(int i, int sum, vector<int>& ans, vector<int>& arr)
{
    if (i >= arr.size())
    {
        ans.push_back(sum);
        return;
    }
    
    // skip
    solveRecur(i + 1, sum, ans, arr);

    // take
    solveRecur(i + 1, sum + arr[i], ans, arr);
}

vector<int> subsetSums(vector<int>& arr) 
{
    vector<int> ans;
    solveRecur(0, 0, ans, arr);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {5, 6, 7};
    vector<int> ans = subsetSums(arr);

    for (int elm : ans)
        cout << elm << " ";
    return 0;
}