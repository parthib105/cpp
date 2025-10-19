/*
    Kth Ancestor in a Tree

    Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
    Note:
    1. It is guaranteed that the node exists in the tree.
    2. All the nodes of the tree have distinct values.

    Example 1:
                   1
                  / \
                 2   3
                / \
               4   5
    Input:
    K = 2 Node = 4
    Output: 1
    Explanation:
    Since, K is 2 and node is 4, so we
    first need to locate the node and
    look k times its ancestors.
    Here in this Case node 4 has 1 as his
    2nd Ancestor aka the Root of the tree.
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class treeNode
{
public:
    T data;
    treeNode *left;
    treeNode *right;

    treeNode(T d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    ~treeNode()
    {
        if (this->left != NULL)
        {
            this->left = NULL;
        }
        if (this->right != NULL)
        {
            this->right = NULL;
        }
    }
};

treeNode<int> *buildTree(treeNode<int> *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new treeNode<int>(data);

    cout << "To insert on the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "To insert on the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// Approach 1 : TC O(n), SC O(n)
void findPath1(treeNode<int> *root, int k, int node, int &ans, vector<int> &path)
{
    if (root == NULL)
    {
        return;
    }

    // push root data into path
    path.push_back(root->data);

    if (root->data == node)
    {
        if (path.size() > k)
        {
            ans = path[path.size() - 1 - k];
        }
        else
        {
            ans = -1;
        }
        return;
    }

    // traverse left
    findPath1(root->left, k, node, ans, path);

    // traverse right
    findPath1(root->right, k, node, ans, path);

    path.pop_back();
}

int kthAncestor1(treeNode<int> *root, int k, int node)
{
    vector<int> path;
    int ans = -1;
    findPath1(root, k, node, ans, path);
    return ans;
}

// Approach 2 : TC O(n), SC O(h)
treeNode<int>* findPath2(treeNode<int>* root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }

    treeNode<int>* leftAns = findPath2(root->left, k, node);
    treeNode<int>* rightAns = findPath2(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // to lock the answer
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // to lock the answer
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

// your task is to complete this function
int kthAncestor2(treeNode<int>* root, int k, int node)
{
    treeNode<int>* ans = findPath2(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    return ans->data;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int> *root;
    root = buildTree(root);
    int k = 3;
    int node = 8;
    cout << endl
         << "kth ancestor : " << kthAncestor2(root, k, node) << endl;
    return 0;
}