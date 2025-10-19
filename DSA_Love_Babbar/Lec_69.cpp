/*
    Binary Search tree
*/

#include<bits/stdc++.h>
using namespace std;

template <class T>
class treeNode
{
public:
    T data;
    treeNode<T>* left;
    treeNode<T>* right;

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
treeNode<int>* insertInBSTrecur(treeNode<int>* root, int val)
{
    // create a node with the given value
    treeNode<int>* node = new treeNode<int>(val);

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

// non recursive solution
void insertInBST(treeNode<int>* &root, int val)
{
    // create a node with the given value
    treeNode<int>* node = new treeNode<int>(val);

    // if root is NULL
    if (root == NULL)
    {
        root = node;
    }

    // if root is not NULL
    treeNode<int>* curr = root;
    treeNode<int>* prev = curr;
    bool present = false;
    while (curr != NULL)
    {
        if (val == curr->data)
        {
            present = true;
            break;
        }
        else if (val < curr->data)
        {
            prev = curr;
            curr = curr->left;
        }
        else
        {
            prev = curr;
            curr = curr->right;
        }
    }

    if (present == false)
    {
        if (val < prev->data)
        {
            prev->left = node;
            return;
        }
        if (val > prev->data)
        {
            prev->right = node;
            return;
        }
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

void takeInput(treeNode<int>* &root)
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
    takeInput(root);

    cout << endl << "Inorder traversal : ";
    inOrder(root);
    cout << endl;
    return 0;
}