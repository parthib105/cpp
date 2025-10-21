/*
    Symmetric Tree

    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    Example 1:


    Input: root = [1,2,2,3,4,4,3]
    Output: true
    Example 2:


    Input: root = [1,2,2,null,3,null,3]
    Output: false


    Constraints:

    The number of nodes in the tree is in the range [1, 1000].
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
    bool isSame(TreeNode<int>* p, TreeNode<int>* q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;

        if (p->data != q->data)
            return false;

        bool leftAns = isSame(p->left, q->right);
        bool rightAns = isSame(p->right, q->left);

        if (!leftAns || !rightAns)
            return false;

        return true;
    }

    bool isSymmetricHelper(TreeNode<int>* root1, TreeNode<int>* root2)
    {
        if (!root1 || !root2)
            return root1 == root2;

        if (root1->data != root2->data)
            return false;

        bool lSub = isSymmetricHelper(root1->left, root2->right);
        bool rSub = isSymmetricHelper(root1->right, root2->left);
        return lSub && rSub;
    }

public:
    bool isSymmetric(TreeNode<int>* root)
    {
        // Approach 1
        // return isSame(root->left, root->right);

        // Approach 2
        return !root || isSymmetricHelper(root->left, root->right);
    }
};

int main()
{
    vector<int> lo = {2, -7, 5, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    bool res = sol.isSymmetric(root);

    if (res)
        cout << "The Tree is symmetric" << endl;
    else 
        cout << "The Tree is not symmetric" << endl;
    return 0;
}