/*
    Search in a Binary Search Tree

    You are given the root of a binary search tree (BST) and an integer val.

    Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

    Example 1:


    Input: root = [4,2,7,1,3], val = 2
    Output: [2,1,3]
    Example 2:


    Input: root = [4,2,7,1,3], val = 5
    Output: []
    

    Constraints:

    The number of nodes in the tree is in the range [1, 5000].
    1 <= Node.val <= 10^7
    root is a binary search tree.
    1 <= val <= 10^7
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

class Solution {
public:
    TreeNode<int>* searchBST(TreeNode<int>* root, int val) 
    {
        TreeNode<int>* curr = root;
        while (curr)
        {
            if (curr->data == val)
                return curr;
            if (val > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }
        return nullptr;
    }
};

int main()
{
    vector<int> lo = {10, 5, 13, 3, 6, 11, 14, 2, 4, -1, 9};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    int val = 1;
    TreeNode<int>* node = sol.searchBST(root, val);

    if (node)
        cout << "Value found : " << node->data << endl;
    else    
        cout << "value not found" << endl;
    return 0;
}