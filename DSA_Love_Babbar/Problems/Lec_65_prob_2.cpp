/*
    Lowest Common Ancestor in a Binary Tree

    Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor 
    of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

    LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

    Input:
    n1 = 3 , n2 = 4
           5    
          /    
         2  
        / \  
       3   4
    Output: 2
    Explanation:
    LCA of 3 and 4 is 2. 
*/

#include<bits/stdc++.h>
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

treeNode<int>* lca(treeNode<int>* root, int n1, int n2)
{
    // base case
    if (root == NULL || root->data == n1 || root->data == n2)
    {
        return root;
    }

    treeNode<int>* leftAns = lca(root->left, n1, n2);
    treeNode<int>* rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    int n1 = 6;
    int n2 = 11;
    treeNode<int>* root;
    root = buildTree(root);
    treeNode<int>* LCA = lca(root, n1, n2);
    cout << endl << "Lowest common ancester of " << n1 << " and " << n2 << " : " << LCA->data << endl;
    return 0;
}