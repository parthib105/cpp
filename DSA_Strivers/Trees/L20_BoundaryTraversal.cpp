/*
    Tree Boundary Traversal

    Given a root of a Binary Tree, return its boundary traversal in the following order:

    Left Boundary: Nodes from the root to the leftmost leaf (prefer left child over right). Exclude leaf nodes.

    Leaf Nodes: All leaf nodes from left to right, excluding those already in the left or right boundary.

    Reverse Right Boundary: Nodes from the rightmost leaf to the root (prefer right child over left). Exclude the root if already included in the left boundary.

    Note: If the root has no left or right subtree, consider the root itself as part of the respective boundary.

    Examples:

    Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
    Output: [1, 2, 4, 8, 9, 6, 7, 3]
    Explanation:

    Input: root = [1, N, 2, N, 3, N, 4, N, N] 
    Output: [1, 4, 3, 2]
    Explanation:

    Left boundary: [1] (as there is no left subtree)
    Leaf nodes: [4]
    Right boundary: [3, 2] (in reverse order)
    Final traversal: [1, 4, 3, 2]
    Constraints:
    1 ≤ number of nodes ≤ 10^5
    1 ≤ node->data ≤ 10^5


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
    bool isLeaf(TreeNode<int>* root) {
        return !root->left && !root->right;
    }
    
    void addLeftBoundary(TreeNode<int>* root, vector<int>& bt)
    {
        TreeNode<int>* cur = root->left;
        while (cur)
        {
            if (!this->isLeaf(cur))
                bt.push_back(cur->data);
                
            if (cur->left)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
    
    void addRightBoundary(TreeNode<int>* root, vector<int>& bt)
    {
        vector<int> tmp;
        TreeNode<int>* cur = root->right;
        while (cur)
        {
            if (!this->isLeaf(cur))
                tmp.push_back(cur->data);
                
            if (cur->right)
                cur = cur->right;
            else
                cur = cur->left;
        }
        
        for (int i = tmp.size() - 1; i >= 0; i--)
            bt.push_back(tmp[i]);
    }
    
    void addLeaves(TreeNode<int>* root, vector<int>& bt)
    {
        if (this->isLeaf(root))
        {
            bt.push_back(root->data);
            return;
        }
        
        if (root->left)
            addLeaves(root->left, bt);
        if (root->right)
            addLeaves(root->right, bt);
    }
public:
    vector<int> boundaryTraversal(TreeNode<int>* root) 
    {
        vector<int> bt;
        if (!root)
            return bt;
            
        if (!this->isLeaf(root))
            bt.push_back(root->data);
        
        this->addLeftBoundary(root, bt);
        this->addLeaves(root, bt);
        this->addRightBoundary(root, bt);
        return bt;
    }
};

int main()
{
    vector<int> lo = {2, -7, 5, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    vector<int> res = sol.boundaryTraversal(root);
    for (int e : res)
        cout << e << " ";
        
    return 0;
}