/*
    Find K-th smallest Element in BST

    Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element in the given BST( binary search tree).

    BST ( binary search tree) -

    If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.

    Example 1 : 

                          5
                        /   \
                       4     8
                      /     / \
                     2     6   10
                      \     \
                       3     7
    

    Order of elements in increasing order in the given BST is - { 2, 3, 4, 5, 6, 7, 8, 10 }

    Suppose given ‘K = 3’ then 3rd smallest element is ‘4’.

    Suppose given ‘K = 8’ then 8th smallest element is ‘10’.

    Note:
    1. You are not required to print the output explicitly, it has already been taken care of. Just implement the function and return the ‘K-th’ smallest element of BST.
    2. You don’t need to return ‘K-th’ smallest node, return just value of that node. 
    3. If ‘K-th’ smallest element is not present in BST then return -1.
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

int solve(treeNode<int>* root, int& i, int k)
{
    // base case
    if (root == NULL)
    {
        return -1;
    }

    // left
    int L = solve(root->left, i, k);

    if (L != -1)
    {
        return L;
    }

    i++;
    if (i == k)
    {
        return root->data;
    }

    return solve(root->right, i, k);
}

int kthSmallest(treeNode<int>* root, int k) {
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    treeNode<int> *root = NULL;
    int k = 4;
    takeInput(root);

    cout << endl << "Inorder traverse :" << endl;
    inOrder(root);
    cout << endl;

    cout << endl << k << "th smallest element : " << kthSmallest(root, k) << endl;
    return 0;
}