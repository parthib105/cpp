/*
    ZigZag Traversal

    You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to print the zigzag traversal of the given tree.

    Note:
    In zigzag order, level 1 is printed from left to right fashion, level 2 is printed from right to left. and level 3 is printed from left to right again, and so on…..
    For example:
    For the given binary tree

    The zigzag  traversal is [1, 4, 3, 5, 2, 7, 6]
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= 'T' <= 100
    0 <= 'N' <= 10^3
    0 <= 'NODES' <= 10^9    

    Where NODES represent any node value

    Time Limit: 1sec
    Sample Input 1:
    2
    1 2 3 -1 -1 -1  6 -1 -1
    1 2 3 -1 -1 -1 -1
    Sample Output 1:
    1 3 2 6
    1 3 2
    Explanation of Sample Input 1:
    For the first test case, the given binary tree is shown below.

    zigzag traversal of given tree = [1, 3, 2, 6]

    For the second test case, the given binary tree is shown below.

    ZigZag traversal of given tree = [1, 3, 2]
    Sample Input 2:
    1
    1 2 4 5 3 -1 -1 -1 -1 -1 -1
    Sample Output 2:
    1 4 2 5 3
    Explanation of Sample Input 2:
    For the first test case, the given binary tree is shown below.

    ZigZag traversal of given tree = [1, 4, 2, 5, 3] 
*/

#include<bits/stdc++.h>
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

    TreeNode<int>* root = new TreeNode<int>(lo[0]);
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty() && i < n)
    {
        TreeNode<int>* curr = q.front();
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
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode<int>* root) 
    {
        if (!root)
            return {};
        
        int l = 0;
        queue<TreeNode<int>*> q;

        q.push(root);
        while (!q.empty())
        {
            int s = q.size();
            vector<int> level;
            for (int i = 0; i < s; i++)
            {
                TreeNode<int>* u = q.front();
                q.pop();

                level.push_back(u->data);

                if (u->left)
                    q.push(u->left);
                if (u->right)
                    q.push(u->right);
            }

            if (l & 1)
                reverse(level.begin(), level.end());
            this->res.push_back(level);

            l ++;
        }
        return this->res;
    }
};

int main()
{
    vector<int> lo = {2, -7, 5, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    vector<vector<int>> res = sol.zigzagLevelOrder(root);

    for (vector<int>& row : res)
    {
        for (int e : row)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}