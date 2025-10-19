/*
    Preorder traversal of a BST

    You have been given an array/list 'PREORDER' representing the preorder traversal of a BST with 'N' nodes. All the elements 
    in the given array have distinct values.

    Your task is to construct a binary search tree that matches the given preorder traversal.

    A binary search tree (BST) is a binary tree data structure that has the following properties:

    • The left subtree of a node contains only nodes with data less than the node’s data.
    • The right subtree of a node contains only nodes with data greater than the node’s data.
    • Both the left and right subtrees must also be binary search trees.

    It is guaranteed that a BST can be always constructed from the given preorder traversal. Hence, the answer will always exist.
*/

#include<bits/stdc++.h>
using namespace std;

template <class T>
class treeNode
{
public:
    T data;
    treeNode<T> *left;
    treeNode<T> *right;

    treeNode(T val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

    ~treeNode()
    {
        if (this->left)
        {
            this->left = NULL;
        }
        if (this->right)
        {
            this->right = NULL;
        }
    }
};

// recursive solution
treeNode<int> *insertInBSTrecur(treeNode<int> *root, int val)
{
    // create a node with the given value
    treeNode<int> *node = new treeNode<int>(val);

    // if root is NULL
    if (root == NULL)
    {
        return node;
    }

    // if root is not NULL
    if (val < root->data)
    {
        root->left = insertInBSTrecur(root->left, val);
    }
    else
    {
        root->right = insertInBSTrecur(root->right, val);
    }

    return root;
}

void takeInput(treeNode<int> *&root)
{
    cout << "Enter strem of data to construct BST, (-1 to end stream) : " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBSTrecur(root, data);
        cin >> data;
    }
}

void inOrder(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Approach 1 : store inorder , and make tree out of it
treeNode<int>* buildTree(vector<int> &preorder, int m, int M, int &i)
{
    if (i >= preorder.size())
    {
        return NULL;
    }

    if (preorder[i] >= m && preorder[i] <= M)
    {
        treeNode<int>* root = new treeNode<int>(preorder[i++]);
        root->left = buildTree(preorder, m, root->data, i);
        root->right = buildTree(preorder, root->data, M, i);
        return root;
    }

    return NULL;
}

treeNode<int>* preorderToBST(vector<int> &preorder)
{
    // Write your code here.
    int m = INT_MIN;
    int M = INT_MAX;
    int i = 0;
    return buildTree(preorder, m, M, i);
} 

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    vector<int> preorder = {5, 1, 2, 4, 3, 7, 6, 10, 9, 8, 11};
    treeNode<int>* root = preorderToBST(preorder);

    cout << endl << "Inorder traversal of the tree : ";
    inOrder(root);
    cout << endl;

    return 0;
}