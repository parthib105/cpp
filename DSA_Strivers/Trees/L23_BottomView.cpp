/*
    Bottom View of Binary Tree

    You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

    Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

    Examples :

    Input: root = [1, 2, 3, 4, 5, N, 6]
        
    Output: [4, 2, 5, 3, 6]
    Explanation: The Green nodes represent the bottom view of below binary tree.
        
    Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
        
    Output: [5, 10, 4, 28, 25]
    Explanation: The Green nodes represent the bottom view of below binary tree.
        
    Constraints:
    1 ≤ number of nodes ≤ 10^5
    1 ≤ node->data ≤ 10^5


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
            this->left = NULL;
        if (this->right)
            this->right = NULL;
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
    vector<int> bottomView(TreeNode<int>* root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        // {hd, node}
        map<int, int> botNode;
        queue<pair<TreeNode<int>*, int>> q; // {node, hd}

        q.push({root, 0});
        while (!q.empty())
        {
            TreeNode<int>* node = q.front().first;
            int hd = q.front().second;
            q.pop();

            // update
            botNode[hd] = node->data;
            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        map<int, int>::iterator it = botNode.begin();
        while (it != botNode.end())
        {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};

int main()
{
    vector<int> lo = {2, -7, 5, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    vector<int> res = sol.bottomView(root);

    for (int& row : res)
        cout << row << " ";
    return 0;
}