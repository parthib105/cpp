/*
    Deletion in BST
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

treeNode<int>* deleteFromBST(treeNode<int>* root, int val)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child : left child
        if (root->left != NULL && root->right == NULL)
        {
            treeNode<int>* temp = root->left;
            delete root;
            return temp;
        }

        // 1 child : right child
        if (root->left == NULL && root->right != NULL)
        {
            treeNode<int>* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int minVal = getMin(root->right);
            root->data = minVal;
            root->right = deleteFromBST(root->right, minVal);
            return root;
        }
    }
    else if (val < root->data)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
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

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    treeNode<int> *root = NULL;
    takeInput(root);

    cout << endl << "Inorder traversal (before deletion) : ";
    inOrder(root);
    cout << endl;

    root = deleteFromBST(root, 3);

    cout << endl << "Inorder traversal (after deletion) : ";
    inOrder(root);
    cout << endl;

    return 0;
}