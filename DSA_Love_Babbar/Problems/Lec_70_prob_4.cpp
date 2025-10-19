/*
    LCA of Two Nodes In A BST

    You are given a binary search tree of integers with N nodes. You are also given references to two nodes 'P' and 'Q' from this BST.

    Your task is to find the lowest common ancestor(LCA) of these two given nodes.

    The lowest common ancestor for two nodes P and Q is defined as the lowest node that has both P and Q as descendants 
    (where we allow a node to be a descendant of itself)

    A binary search tree (BST) is a binary tree data structure which has the following properties.

    • The left subtree of a node contains only nodes with data less than the node’s data.
    • The right subtree of a node contains only nodes with data greater than the node’s data.
    • Both the left and right subtrees must also be binary search trees.
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

void inOrder(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

treeNode<int>* LCAInBST(treeNode<int>* root, int P, int Q)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data < P && root->data < Q)
    {
        return LCAInBST(root->right, P, Q);
    }
    else if (root->data > P && root->data > Q)
    {
        return LCAInBST(root->left, P, Q);
    }
    return root;
}

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    treeNode<int> *root = NULL;
    int P = 8, Q = 4;
    takeInput(root);
    treeNode<int>* lca = LCAInBST(root, P, Q);
    cout << "LCA of " << P << " and " << Q << " : " << lca->data << endl;
    return 0;
}