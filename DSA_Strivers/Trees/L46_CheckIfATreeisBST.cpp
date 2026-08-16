/*
Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

    The left of a node contains only nodes with keys strictly less than the node's key.
    The right subtree of a node contains only nodes with keys strictly greater than the node's key.
    Both the left and right subtrees must also be binary search trees.



Example 1:

Input: root = [2,1,3]
Output: true

Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.



Constraints:

    The number of nodes in the tree is in the range [1, {10}^{4}].
    -{2}^{31} <= Node.val <= {2}^{31} - 1

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
    bool isValidBSTUtil(TreeNode<int>* root, long long minVal, long long maxVal) {
        if (!root)
            return true;
        if (root->data <= minVal || root->data >= maxVal)
            return false;

        bool isLeft = isValidBSTUtil(root->left, minVal, root->data);
        bool isRight = isValidBSTUtil(root->right, root->data, maxVal);
        return isLeft && isRight;
    }
public:
    bool isValidBST(TreeNode<int>* root) {
        return isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    // root = [5,3,6,2,4,null,7], key = 3
    vector<int> lo = {5, 3, 6, 2, 4, -1, 7};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    if (sol.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }
}
