/*
    Height of Binary Tree
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

treeNode<int>* buildTree(treeNode<int>* root)
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

int height(treeNode<int>* root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (max(leftHeight, rightHeight) + 1);
}

int main()
{
    treeNode<int>* root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 9 8 -1 -1 -1 -1
    cout << "Height of the tree : " << height(root) << endl;
    return 0;
}