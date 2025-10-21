/*
    Path In A Tree

    You are given a binary tree with ‘N’ number of nodes and a node ‘X’. Your task is to print the path from the root node to the given node ‘X’.

    A binary tree is a hierarchical data structure in which each node has at most two children.

    Example:
    Here, for ‘X ’= 7, the output will be 1 3 7.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 10
    1 <= N <= 10000
    1 <= X <= N
    All the node values will be in a range from 1 to N.

    Time limit: 1 sec.
    Sample Input 1 :
    2
    1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    7
    3 2 1 -1 -1 -1 -1
    1
    Sample output 1 :
    1 3 7
    3 1
    Explanation For Sample Output 1:
    For the first test case, the tree will be:

    Here, for ‘X ’= 7, the output will be 1 3 7.


    For the second test case, the tree will be:

    Here, for ‘X ’= 1, the output will be 3 1.
    Sample Input 2 :
    2
    1 3 -1 -1 4 2 -1 -1 -1
    1
    4 -1 1 2 -1 -1 3 -1 -1
    1
    Sample output 2 :
    1
    4 1
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
private:
    bool getPath(TreeNode<int> *root, int x, vector<int> &path)
    {
        if (!root)
            return false;

        path.push_back(root->data);

        if (root->data == x)
            return true;

        bool lSub = getPath(root->left, x, path);
        bool rSub = getPath(root->right, x, path);

        if (lSub || rSub)
            return true;

        path.pop_back();
        return false;
    }

public:
    vector<int> pathInATree(TreeNode<int> *root, int x)
    {
        vector<int> path;
        bool _null = getPath(root, x, path);
        return path;
    }
};

int main()
{
    vector<int> lo = {2, -7, 8, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);

    int x = 5;
    Solution sol;
    vector<int> res = sol.pathInATree(root, x);
    for (int e : res)
        cout << e << " ";
    return 0;
}