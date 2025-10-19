/*
    Search in BST

    There is a Binary Search Tree (BST) consisting of ‘N’ nodes. Each node of this BST has some integer data.
    You are given the root node of this BST, and an integer ‘X’. Return true if there is a node in BST having data equal to
    ‘X’, otherwise return false.

    A binary search tree (BST) is a binary tree data structure that has the following properties:

    1. The left subtree of a node contains only nodes with data less than the node’s data.
    2. The right subtree of a node contains only nodes with data greater than the node’s data.
    3. The left and right subtrees must also be binary search trees.

    Note:
    It is guaranteed that all nodes have distinct data.
*/

#include <bits/stdc++.h>
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

bool searchInBST(treeNode<int>* root, int x)
{
    // Write your code here
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }
    else if (x < root->data)
    {
        return searchInBST(root->left, x);
    }
    return searchInBST(root->right, x);
}

// To find the min and max value in bst
int getMin(treeNode<int>* root)
{
    // base case
    if (root->left == NULL)
    {
        return root->data;
    }

    return getMin(root->left);
}

int getMax(treeNode<int>* root)
{
    // base case
    if (root->right == NULL)
    {
        return root->data;
    }

    return getMax(root->right);
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

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    treeNode<int> *root = NULL;
    int x = 15;
    takeInput(root);

    cout << endl << "Minimum value : " << getMin(root) << endl;
    cout << endl << "Maximum value : " << getMax(root) << endl;

    if (searchInBST(root, x))
    {
        cout << endl << x << " is present" << endl;
    }
    else
    {
        cout << endl << x << " is not present" << endl;
    }
    return 0;
}