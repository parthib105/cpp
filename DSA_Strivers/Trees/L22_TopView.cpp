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
    vector<int> topView(TreeNode<int>* root)
    {
        map<int, int> nodeMap;      // {hd, node}
        queue<pair<TreeNode<int>*, int>> q; // {node, hd}

        q.push({root, 0});
        while (!q.empty())
        {
            TreeNode<int>* curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            if (nodeMap.find(hd) == nodeMap.end())
                nodeMap[hd] = curr->data;

            if (curr->left)
                q.push({curr->left, hd - 1});
            if (curr->right)
                q.push({curr->right, hd + 1});
        }

        vector<int> res;
        map<int, int>::iterator it = nodeMap.begin();
        while (it != nodeMap.end())
        {
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};

int main()
{
    vector<int> lo = {2, -7, 5, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    vector<int> res = sol.topView(root);

    for (int& row : res)
        cout << row << " ";
    return 0;
}