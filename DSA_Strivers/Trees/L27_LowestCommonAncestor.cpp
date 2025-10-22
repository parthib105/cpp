/*
    Lowest Common Ancestor of a Binary Tree

    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

    
    Example 1:


    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    Explanation: The LCA of nodes 5 and 1 is 3.
    Example 2:


    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    Output: 5
    Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
    Example 3:

    Input: root = [1,2], p = 1, q = 2
    Output: 1
    

    Constraints:

    The number of nodes in the tree is in the range [2, 10^5].
    -10^9 <= Node.val <= 10^9
    All Node.val are unique.
    p != q
    p and q will exist in the tree.
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
private:
    bool getPath(TreeNode<int>* root, TreeNode<int>* x, vector<TreeNode<int>*>& path)
    {
        if (!root)
            return false;

        path.push_back(root);
        if (root == x)
            return true;

        bool lSub = getPath(root->left, x, path);
        bool rSub = getPath(root->right, x, path);

        if (lSub || rSub)
            return true;

        path.pop_back();
        return false;
    }

    // T.C. : O(n), S.C. : O(h)
    TreeNode<int>* lowestCommonAncestorBrute(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
    {
        bool _null;
        vector<TreeNode<int>*> path1, path2;
        _null = getPath(root, p, path1);
        _null = getPath(root, q, path2);

        int n = min(path1.size(), path2.size());
        for (int i = 0; i < n; i++)
        {
            if (path1[i] != path2[i])
                return path1[i - 1];
        }
        return path1[n - 1];
    }

    // T.C. : O(n)
    TreeNode<int>* lowestCommonAncestorOptimal(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
    {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode<int>* lSub = lowestCommonAncestorOptimal(root->left, p, q);
        TreeNode<int>* rSub = lowestCommonAncestorOptimal(root->right, p, q);

        if (lSub && rSub) {   // both returned not null values
            return root;
        }
        else if (!lSub && rSub) {   // return not null values
            return rSub;
        }
        else if (lSub && !rSub) {
            return lSub;
        }
        return NULL;
    }
public:
    TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) 
    {
        // brute force solution
        // return lowestCommonAncestorBrute(root, p, q);

        // Optimal Solution
        return lowestCommonAncestorOptimal(root, p, q);
    }
};

int main()
{
    vector<int> lo = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode<int>* root = buildTree(lo);
    return 0;
}