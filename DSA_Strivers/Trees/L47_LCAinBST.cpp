/*
Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2



Constraints:

    The number of nodes in the tree is in the range [2, 105].
    -10^9 <= Node.val <= 10^9
    All Node.val are unique.
    p != q
    p and q will exist in the BST.
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
public:
    TreeNode<int> *lowestCommonAncestor(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
    {
        if (!root)
            return nullptr;

        if (p->data < root->data && q->data < root->data)
            return lowestCommonAncestor(root->left, p, q);

        if (p->data > root->data && q->data > root->data)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

int main() {
    // root = [5,3,6,2,4,null,7], key = 3
    vector<int> lo = {5, 3, 6, 2, 4, -1, 7};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    TreeNode<int>* p = root->left; // Node with value 3
    TreeNode<int>* q = root->right; // Node with value 6
    TreeNode<int>* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "The LCA of " << p->data << " and " << q->data << " is " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }
}
