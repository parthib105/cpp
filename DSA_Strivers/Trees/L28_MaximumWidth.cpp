/*
    Maximum Width of Binary Tree

    Given the root of a binary tree, return the maximum width of the given tree.

    The maximum width of a tree is the maximum width among all levels.

    The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

    It is guaranteed that the answer will in the range of a 32-bit signed integer.



    Example 1:


    Input: root = [1,3,2,5,3,null,9]
    Output: 4
    Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
    Example 2:


    Input: root = [1,3,2,5,null,null,9,6,null,7]
    Output: 7
    Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
    Example 3:


    Input: root = [1,3,2,5]
    Output: 2
    Explanation: The maximum width exists in the second level with length 2 (3,2).


    Constraints:

    The number of nodes in the tree is in the range [1, 3000].
    -100 <= Node.val <= 100
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    ~TreeNode()
    {
        if (this->left)
            delete this->left;
        if (this->right)
            delete this->right;
    }
};

TreeNode<int> *buildTree(vector<int> &lo)
{
    int i = 1, n = lo.size();
    if (n == 0)
        return nullptr;

    TreeNode<int> *root = new TreeNode<int>(lo[0]);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty() && i < n)
    {
        TreeNode<int> *curr = q.front();
        q.pop();

        if (i < n && lo[i] != -1)
        {
            curr->left = new TreeNode<int>(lo[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && lo[i] != -1)
        {
            curr->right = new TreeNode<int>(lo[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void printLevelOrder(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();

        if (!curr)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

class Solution
{
public:
    int widthOfBinaryTree(TreeNode<int> *root)
    {
        if (!root)
            return 0;

        long long ans = 0;
        queue<pair<TreeNode<int> *, long long>> q;

        q.push({root, 0LL});
        while (!q.empty())
        {
            int s = q.size();
            long long minId = q.front().second;
            long long first, last;
            for (int i = 0; i < s; i++)
            {
                TreeNode<int> *node = q.front().first;
                long long nodeId = q.front().second - minId;
                q.pop();

                if (i == 0)
                    first = nodeId;
                if (i == s - 1)
                    last = nodeId;

                if (node->left)
                    q.push({node->left, (long long)2 * nodeId + 1});
                if (node->right)
                    q.push({node->right, (long long)2 * nodeId + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};

int main()
{
    vector<int> lo = {1, 3, 2, 5, -1, -1, 9, 6, -1, 7};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    int ans = sol.widthOfBinaryTree(root);

    cout << ans << endl;
    return 0;
}