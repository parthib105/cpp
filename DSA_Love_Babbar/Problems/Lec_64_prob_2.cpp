/*
    Boundary Traversal of binary tree

    Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

    Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.
    Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
    Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
    Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.
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

void printLeftPart(treeNode<int>* root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left != NULL)
    {
        printLeftPart(root->left, ans);
    }
    else
    {
        printLeftPart(root->right, ans);
    }
}

void printRightPart(treeNode<int>* root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        printRightPart(root->right, ans);
    }
    else
    {
        printRightPart(root->left, ans);
    }
    ans.push_back(root->data);
}

void printLeafNode(treeNode<int>* root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    printLeafNode(root->left, ans);
    printLeafNode(root->right, ans);
}

vector<int> boundary(treeNode<int>* root)
{
    // 4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // traverse left
    printLeftPart(root->left, ans);

    // traverse for leaf nodes
    printLeafNode(root->left, ans);
    printLeafNode(root->right, ans);

    // traverse right
    printRightPart(root->right, ans);

    return ans;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int>* root;
    root = buildTree(root);
    vector<int> ans = boundary(root);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}