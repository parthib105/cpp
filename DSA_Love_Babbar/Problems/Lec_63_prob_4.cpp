/*
    Determine if Two Trees are Identical

    Given two binary trees, the task is to find if both of them are identical or not.
    Note: You need to return true or false, the printing is done by the driver code.
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

bool isIdentical(treeNode<int>* r1, treeNode<int>* r2)
{
    // base cases
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    else if (r1 == NULL || r2 == NULL)
    {
        return false;
    }

    // check left and right of each tree
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool curr = (r1->data == r2->data);

    if (left && right && curr)
    {
        return true;
    }
    return false;
}

int main()
{

    return 0;
}