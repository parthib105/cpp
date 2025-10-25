/*
    Construct Binary Tree from Preorder and Inorder Traversal

    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

    Example 1:


    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]
    Example 2:

    Input: preorder = [-1], inorder = [-1]
    Output: [-1]
    

    Constraints:

    1 <= preorder.length <= 3000
    inorder.length == preorder.length
    -3000 <= preorder[i], inorder[i] <= 3000
    preorder and inorder consist of unique values.
    Each value of inorder also appears in preorder.
    preorder is guaranteed to be the preorder traversal of the tree.
    inorder is guaranteed to be the inorder traversal of the tree.
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
    unordered_map<int, int> inMap;
    TreeNode<int>* constructTree(int& pi, int ist, int ied, vector<int>& pre, vector<int>& ino) 
    {
        if (ist > ied)
            return nullptr;

        int rootVal = pre[pi];
        int pos = this->inMap[rootVal];
        pi = pi + 1;

        TreeNode<int>* root = new TreeNode<int>(rootVal);
        root->left = constructTree(pi, ist, pos - 1, pre, ino);
        root->right = constructTree(pi, pos + 1, ied, pre, ino);
        return root;
    }
public:
    TreeNode<int>* buildTree(vector<int>& pre, vector<int>& ino) 
    {
        int pi = 0;
        int n = ino.size();
        this->inMap.clear();
        for (int i = 0; i < ino.size(); i++)
            this->inMap[ino[i]] = i;

        TreeNode<int>* root = constructTree(pi, 0, n - 1, pre, ino);
        return root;
    }
};

int main()
{
    vector<int> pre = {3, 9, 20, 15, 7}, ino = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode<int>* root = sol.buildTree(pre, ino);

    printLevelOrder(root);
    return 0;
}