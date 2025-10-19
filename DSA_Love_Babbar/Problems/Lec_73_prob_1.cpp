/*
    Size of Largest BST in Binary Tree

    You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to return the size of 
    the largest subtree of the binary tree which is also a BST.

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

class nodeInfo
{
public:
    int maxElm;
    int minElm;
    bool isBst;
    int size;

    nodeInfo(int M, int m, bool bst, int sz)
    {
        this->maxElm = M;
        this->minElm = m;
        this->isBst = bst;
        this->size = sz;
    }
};

nodeInfo solve(treeNode<int>* root, int &ans)
{
    // base case
    if (root == NULL)
    {
        return nodeInfo(INT_MIN, INT_MAX, true, 0);
    }
    
    // call for left subtree
    nodeInfo leftSub = solve(root->left, ans);

    // call for right subtree
    nodeInfo rightSub = solve(root->right, ans);

    int currSize = leftSub.size + rightSub.size + 1;
    int currMax = max(root->data, rightSub.maxElm);
    int currMin = min(root->data, leftSub.minElm);
    bool currBst = false;

    // update value if the current binary tree is BST  
    if (leftSub.isBst && rightSub.isBst && (root->data > leftSub.maxElm && root->data < rightSub.minElm))
    {
        currBst = true;
    }
    
    // update answer is current binary tree is BST
    if (currBst)
    {
        ans = max(ans, currSize);
    }

    return nodeInfo(currMax, currMin, currBst, currSize);
}

int largestBST(treeNode<int>* root){
    // to store answer
    int ans = 0;

    nodeInfo Nde = solve(root, ans);
    return ans;
}

int main()
{
    
    return 0;
}