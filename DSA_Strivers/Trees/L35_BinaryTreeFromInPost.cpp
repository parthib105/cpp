/*
    Construct Binary Tree from Inorder and Postorder Traversal

    Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

    Example 1:


    Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    Output: [3,9,20,null,null,15,7]
    Example 2:

    Input: inorder = [-1], postorder = [-1]
    Output: [-1]
    

    Constraints:

    1 <= inorder.length <= 3000
    postorder.length == inorder.length
    -3000 <= inorder[i], postorder[i] <= 3000
    inorder and postorder consist of unique values.
    Each value of postorder also appears in inorder.
    inorder is guaranteed to be the inorder traversal of the tree.
    postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode<int>* constructTree(int& pi, int ist, int ied, vector<int>& post, vector<int>& ino) 
    {
        if (pi < 0 || ist > ied)
            return nullptr;

        int rootVal = post[pi];
        int pos = this->inMap[rootVal];
        pi = pi - 1;

        TreeNode<int>* root = new TreeNode<int>(rootVal);
        root->right = constructTree(pi, pos + 1, ied, post, ino);
        root->left = constructTree(pi, ist, pos - 1, post, ino);
        return root;
    }
public:
    TreeNode<int>* buildTree(vector<int>& post, vector<int>& ino) 
    {
        int n = ino.size();
        this->inMap.clear();
        for (int i = 0; i < ino.size(); i++)
            this->inMap[ino[i]] = i;
        
        int pi = n - 1;
        TreeNode<int>* root = constructTree(pi, 0, n - 1, post, ino);
        return root;
    }
};

int main()
{
    vector<int> post = {9, 15, 7, 20, 3}, ino = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode<int>* root = sol.buildTree(post, ino);

    printLevelOrder(root);
    return 0;
}