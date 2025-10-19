/*
    Check for Balanced Tree

    Given a binary tree, find if it is height balanced or not.  A tree is height balanced if difference between heights of
    left and right subtrees is not more than one for all nodes of tree.
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

int height(treeNode<int> *root)
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

// Approach 1 : T.C. O(n^2)
bool isBalanced1(treeNode<int> *root)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced1(root->left);
    bool right = isBalanced1(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if (left && right && diff)
    {
        return true;
    }
    return false;
}

// Approach 2 : T.C. O(n), faster
// function to calculate balanced and height
pair<bool, int> isBalancedFast(treeNode<int>* root)
{
    // base condition
    if (root == NULL)
    {
        return {true, 0};
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool heightDiff = abs(left.second - right.second) <= 1;     // check height difference

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;    // update height

    if (left.first && right.first && heightDiff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
// Function to check whether a binary tree is balanced or not.
bool isBalanced2(treeNode<int>* root)
{
    return isBalancedFast(root).first;
}

int main()
{
    treeNode<int> *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 9 8 -1 -1 -1 -1

    if (isBalanced2(root))
    {
        cout << "Tree is balanced" << endl;
    }
    else
    {
        cout << "Tree is not balanced" << endl;
    }
    return 0;
}