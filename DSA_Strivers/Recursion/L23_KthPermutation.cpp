/*
    Permutation Sequence

    The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

    By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
    Given n and k, return the kth permutation sequence.

    Example 1:

    Input: n = 3, k = 3
    Output: "213"
    Example 2:

    Input: n = 4, k = 9
    Output: "2314"
    Example 3:

    Input: n = 3, k = 1
    Output: "123"


    Constraints:

    1 <= n <= 9
    1 <= k <= n!
*/

#include <bits/stdc++.h>
using namespace std;

void solveRecur(int i, int k, int n, string &arr, priority_queue<string> &pq)
{
    if (i >= n)
    {
        pq.push(arr);
        if (pq.size() > k)
            pq.pop(); // keep only k smallest
        return;
    }

    for (int j = i; j < n; j++)
    {
        swap(arr[i], arr[j]);
        solveRecur(i + 1, k, n, arr, pq);
        swap(arr[i], arr[j]);
    }
}

// T.C. : O(n · n! · log k), O(n · n!)
string getPermutationBrute(int n, int k)
{
    string arr = "";
    for (int i = 1; i <= n; i++)
    {
        arr += to_string(i);
    }

    priority_queue<string> pq; // max-heap
    solveRecur(0, k, n, arr, pq);

    return pq.top();
}

// T.C. : O(n^2), S.C. : O(n)
string getPermutationOptimal(int n, int k)
{
    vector<int> nums, fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        nums.push_back(i);
        fact[i] = fact[i - 1] * i;
    }

    // convert to 0-based indexing
    k = k - 1;
    string ans = "";
    for (int i = n; i >= 1; i--)
    {
        int idx = k / fact[i - 1]; // which number to pick
        ans += to_string(nums[idx]);
        nums.erase(nums.begin() + idx);

        k = k % fact[i - 1];
    }
    return ans;
}

string getPermutation(int n, int k)
{
    // brute force
    // return getPermutationBrute(n, k);

    // Optimal
    return getPermutationOptimal(n, k);
}

int main()
{
    int n = 4, k = 9;
    cout << getPermutation(n, k) << endl;
    return 0;
}