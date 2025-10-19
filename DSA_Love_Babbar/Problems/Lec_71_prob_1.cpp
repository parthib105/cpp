/*
    Two Sum in a BST

    You have been given a Binary Search Tree and a target value. You need to find out whether there exists a pair of node
    values in the BST, such that their sum is equal to the target value.

    A binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree whose internal nodes
    each store a value greater than all the values keys in the node's left subtree and less than those in its right subtree.

    Can you solve this in O(N) time, and O(H) space complexity?

    Sample Input 1:

    10 6 12 2 8 11 15 -1 -1 -1 -1 -1 -1 -1 -1
    14

    Sample Output 1:
    True
    Explanation for sample 1:
    For the first test case, the sum of the nodes with values 2 and 12 equals the target value.
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

void inorderTraverse(treeNode<int>* root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraverse(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraverse(root->right, inorder);
}

bool twoSumInBST(treeNode<int>* root, int target)
{
    // Write your code here
    vector<int> inorder;
    inorderTraverse(root, inorder);

    int i = 0;
    int j = inorder.size() - 1;
    while (i < j)
    {
        int sumElm = inorder[i] + inorder[j];
        if (sumElm == target)
        {
            return true;
        }
        else if (sumElm > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
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

    if (twoSumInBST(root, target))
    {
        cout << "Sum is present " << endl;
    }
    else
    {
        cout << "Sum is not present " << endl;
    }
    return 0;
}