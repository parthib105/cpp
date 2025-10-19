/*
    Partial BST

    Given a binary tree with N number of nodes, check if that input tree is Partial BST (Binary Search Tree) or not. If yes, 
    return true, return false otherwise.

    A binary search tree (BST) is said to be a Partial BST if it follows the following properties.

    • The left subtree of a node contains only nodes with data less than and equal to the node’s data.
    • The right subtree of a node contains only nodes with data greater than and equal to the node’s data.
    • Both the left and right subtrees must also be partial binary search trees.
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

bool isBST(treeNode<int>* root, int minVal, int maxVal)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    if (root->data >= minVal && root->data <= maxVal)
    {
        bool leftSubtree = isBST(root->left, minVal, root->data);
        bool rightSubtree = isBST(root->right, root->data, maxVal);
        return leftSubtree && rightSubtree;
    }
    return false;
}

bool validateBST(treeNode<int>* root) {
    int minVal = INT_MIN;
    int maxVal = INT_MAX;
    return isBST(root, minVal, maxVal);
}

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    treeNode<int> *root = NULL;
    takeInput(root);

    if (validateBST(root))
    {
        cout << endl << "Valid BST" << endl;
    }
    else
    {
        cout << endl << "Not valid BST" << endl;
    }
    return 0;
}