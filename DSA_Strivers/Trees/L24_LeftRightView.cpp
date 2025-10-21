/*
    Left/Right view of a binary tree

    You have been given a binary tree of integers. You are supposed to find the left view of the binary tree. The left view of a binary tree is the set of all nodes that are visible when the binary tree is viewed from the left side.

    Example:

    The left view of the above binary tree is  {5, 7, 14, 25}.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 100
    0 <= N <= 3000
    1 <= data <= 10^5 and data!=-1

    Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, and “data” is the value of the binary tree node

    Time Limit: 1 sec
    Sample Input 1:
    2
    3 4 -1 -1 -1
    2 8 7 -1 5 -1 -1 1 -1 -1 -1
    Sample Output 1:
    3 4
    2 8 5 1
    Explanation of Sample Input 1:
    For the first test case, node 3 and node 4 are visible when the binary tree is viewed from the left.

    For the second test case, nodes 2, 8, 5, 1 are visible when the binary tree is viewed from the left.
    Sample Input 2:
    2
    1 3 5 12 -1 8 -1 -1 -1 -1 -1
    9 6 3 -1 -1 4 8 -1 -1 -1 -1
    Sample Output 2:
    1 3 12
    9 6 4
    Explanation of Sample Input 2:
    For the first test case, nodes 1, 3, 12 are visible when the binary tree is viewed from the left.

    For the second test case, nodes 9, 6, 4 are visible when the binary tree is viewed from the left.
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
    void dfsUtil(int l, TreeNode<int>* root, vector<int> &rv)
    {
        if (!root)
            return;

        if (l == rv.size())
            rv.push_back(root->data);

        dfsUtil(l + 1, root->right, rv);
        dfsUtil(l + 1, root->left, rv);
    }

public:
    vector<int> printRightView(TreeNode<int>* root)
    {
        vector<int> rv;
        dfsUtil(0, root, rv);
        return rv;
    }
};

int main()
{
    vector<int> lo = {2, -7, 5, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    vector<int> res = sol.printRightView(root);

    for (int& e : res)
        cout << e << " ";
    return 0;
}