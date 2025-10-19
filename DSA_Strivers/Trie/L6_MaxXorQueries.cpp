/*
    Maximum XOR With an Element From Array

    You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

    The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

    Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

    Example 1:

    Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
    Output: [3,3,7]
    Explanation:
    1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
    2) 1 XOR 2 = 3.
    3) 5 XOR 2 = 7.
    Example 2:

    Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
    Output: [15,-1,5]


    Constraints:

    1 <= nums.length, queries.length <= 10^5
    queries[i].length == 2
    0 <= nums[j], xi, mi <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[2];

    TrieNode()
    {
        this->children[0] = nullptr;
        this->children[1] = nullptr;
    }

    bool containsKey(int idx)
    {
        return this->children[idx] != nullptr;
    }

    TrieNode *get(int idx)
    {
        return this->children[idx];
    }

    void put(int idx, TrieNode *node)
    {
        this->children[idx] = node;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        this->root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *curr = this->root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!curr->containsKey(bit))
            {
                curr->put(bit, new TrieNode());
            }
            curr = curr->get(bit);
        }
    }

    int getMaxXor(int num)
    {
        int maxNum = 0;
        TrieNode *curr = this->root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (curr->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                curr = curr->get(1 - bit);
            }
            else
                curr = curr->get(bit);
        }
        return maxNum;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int q = queries.size();
        int idx = 0, n = nums.size();

        // sort the array
        sort(nums.begin(), nums.end());

        vector<vector<int>> oQ;
        for (int i = 0; i < q; i++)
            oQ.push_back({queries[i][1], queries[i][0], i});

        // sort the offline queries {mi, xi, i}
        sort(oQ.begin(), oQ.end());

        Trie trie;
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++)
        {
            int mi = oQ[i][0];
            int xi = oQ[i][1], qInd = oQ[i][2];

            while (idx < n && nums[idx] <= mi)
            {
                trie.insert(nums[idx]);
                idx++;
            }

            if (idx == 0)
                ans[qInd] = -1;
            else
                ans[qInd] = trie.getMaxXor(xi);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {5, 2, 4, 6, 6, 3};
    vector<vector<int>> queries = {{12, 4}, {8, 1}, {6, 3}};

    Solution sol;
    vector<int> q = sol.maximizeXor(nums, queries);
    for (int qi : q)
        cout << qi << " ";
    cout << endl;
    return 0;
}