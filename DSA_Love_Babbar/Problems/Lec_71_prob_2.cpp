/*
    Flatten BST To A Sorted List

    You have been given a Binary Search Tree (BST). Your task is to flatten the given BST to a sorted list. More formally,
    you have to make a right-skewed BST from the given BST, i.e., the left child of all the nodes must be NULL, and the value
    at the right child must be greater than the current node.

    A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes each
    store a value greater than all the values in the node's left subtree and less than those in its right subtree.
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

// Approach 1 : store inorder of bst, make right skewed tree out of it
void inorderTraverse(treeNode<int> *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraverse(root->right, inorder);
}

treeNode<int> *flatten1(treeNode<int> *root)
{
    // Write your code here
    vector<int> inorder;
    inorderTraverse(root, inorder);

    treeNode<int> *newRoot = new treeNode<int>(inorder[0]);
    treeNode<int> *temp = newRoot;
    for (int i = 1; i < inorder.size(); i++)
    {
        temp->right = new treeNode<int>(inorder[i]);
        temp = temp->right;
    }

    temp->left = NULL;
    return newRoot;
}

// Approach 2 : without using any space
void makelist(treeNode<int>* root, treeNode<int>* &head)
{
    if (root == NULL)
    {
        return;
    }

    // move to right child
    makelist(root->right, head);
    root->right = head;
    head = root;

    // move to left child
    makelist(root->left, head);
    root->left = NULL;

    return;
}

treeNode<int>* flatten2(treeNode<int>* root)
{
    // initilize head of the linked list
    treeNode<int>* head = NULL;
    makelist(root, head);
    return head;
}

void printFlatten(treeNode<int>* root)
{
    while (root != NULL)
    {
        cout << root->data << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
}

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    treeNode<int> *root = NULL;
    int target = 120;
    takeInput(root);

    cout << endl << "Inorder traversal of the tree : ";
    inOrder(root);
    cout << endl;

    treeNode<int>* flattenHead = flatten2(root);

    cout << endl << "Flatten List : ";
    printFlatten(flattenHead);
    cout << endl;
    return 0;
}