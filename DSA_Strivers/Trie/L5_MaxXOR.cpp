/*
    Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

    Example 1:

    Input: nums = [3,10,5,25,2,8]
    Output: 28
    Explanation: The maximum result is 5 XOR 25 = 28.
    Example 2:

    Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
    Output: 127


    Constraints:

    1 <= nums.length <= 2 * 10^5
    0 <= nums[i] <= 2^{31} - 1
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children;

    TrieNode()
    {
        this->children.resize(2, nullptr);
    }

    bool containsKey(int bit)
    {
        return this->children[bit] != nullptr;
    }

    TrieNode *get(int bit)
    {
        return this->children[bit];
    }

    void put(int bit, TrieNode *node)
    {
        this->children[bit] = node;
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

    // insert 32 bit integer
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
            int bit = (num >> i) & 1; // get ith bit
            if (curr->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i); // set ith bit
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
private:
    int solveBrute(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int currXOR = nums[i] ^ nums[j];
                ans = max(ans, currXOR);
            }
        }
        return ans;
    }

    int solveTrie(vector<int> &nums)
    {
        Trie trie;
        for (int num : nums)
            trie.insert(num);

        int maxNum = 0;
        for (int num : nums)
        {
            int currMax = trie.getMaxXor(num);
            maxNum = max(maxNum, currMax);
        }
        return maxNum;
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        // Brute Force
        // return solveBrute(nums);

        // Using Trie
        return solveTrie(nums);
    }
};

int main()
{
    vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};

    Solution sol;
    int maxXor = sol.findMaximumXOR(nums);

    cout << maxXor << endl;
    return 0;
}