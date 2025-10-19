/*
    Binary Tree from Inorder and Postorder

    Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays in[] and post[] respectively.
    The task is to construct a unique binary tree from these traversals.

    Driver code will print the preorder traversal of the constructed tree.

    Note :- The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is
    also found in the inorder traversal.

    Input: n = 8, in[] = {4, 8, 2, 5, 1, 6, 3, 7}, post[] = {8, 4, 5, 2, 6, 7, 3, 1}
    Output: 1 2 4 8 5 3 6 7
    Explanation: For the given postorder and inorder traversal of tree the  resultant binary tree will be
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
       \
        8
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

treeNode<int> *solve(int in[], int post[], int n, int &postIdx, map<int, int> &mp, int inSt, int inEd)
{
    if (postIdx < 0 || inSt > inEd)
    {
        return NULL;
    }

    int elm = post[postIdx--];
    treeNode<int> *node = new treeNode<int>(elm);
    int pos = mp[elm];

    node->right = solve(in, post, n, postIdx, mp, pos + 1, inEd);
    node->left = solve(in, post, n, postIdx, mp, inSt, pos - 1);

    return node;
}

treeNode<int>* buildTree(int n, int in[], int post[])
{
    int postIdx = n - 1;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    return solve(in, post, n, postIdx, mp, 0, n - 1);
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

void postOrder(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int n = 8;
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    treeNode<int>* root = buildTree(n, in, post);
    inOrder(root);
    cout << endl;
    postOrder(root);
    return 0;
}