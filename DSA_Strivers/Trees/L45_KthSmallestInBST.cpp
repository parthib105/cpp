/*
Kth smallest/largest element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 10^4
0 <= Node.val <= 10^4
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
    void inorderTraversal(TreeNode<int>* root, vector<int>& elements) {
        if (!root)
            return;
        inorderTraversal(root->left, elements);
        elements.push_back(root->data);
        inorderTraversal(root->right, elements);
    }

    // T.C. : O(N), S.C. : O(N) + O(N) (recursive stack)
    int kthSmallestUsingInorder(TreeNode<int>* root, int k) {
        vector<int> elements;
        this->inorderTraversal(root, elements);
        return elements[k - 1]; // k is 1-indexed
    }

    int kthSmallestCounter(TreeNode<int>* root, int k, int& count) {
        if (!root)
            return -1;

        // Traverse the left subtree
        int left = this->kthSmallestCounter(root->left, k, count);
        if (left != -1)
            return left; // If we found the kth smallest in the left subtree

        // Visit the current node
        count++;
        if (count == k)
            return root->data; // Found the kth smallest element

        // Traverse the right subtree
        return this->kthSmallestCounter(root->right, k, count);
    }
public:
    int kthSmallest(TreeNode<int>* root, int k) {
        // Using inorder traversal
        // return this->kthSmallestUsingInorder(root, k);

        // Using inorder traversal with counter
        int count = 0;
        return this->kthSmallestCounter(root, k, count);
    }
};

int main() {
    // root = [5,3,6,2,4,null,7], key = 3
    vector<int> lo = {5, 3, 6, 2, 4, -1, 7};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;

    int k = 3;
    int result = sol.kthSmallest(root, k);
    cout << "The " << k << "th smallest element in the BST is: "<< result << endl;
}
