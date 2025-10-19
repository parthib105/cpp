/*
    Sum Tree

    Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of
    its left subtree's value and its right subtree's value. Else return false.

    An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a
    Sum Tree.
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

// returns a pair (is Sum tree, sum)
pair<bool, int> isSumTreeFast(treeNode<int>* root)
{
    // base case
    if (root == NULL)
    {
        return {true, 0};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {true, root->data};
    }

    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    bool curr = (left.second + right.second == root->data);

    pair<bool, int> ans;
    if (left.first && right.first && curr)
    {
        ans.first = true;
        // left.second + right.second + root->data
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
        ans.second = left.second + right.second + root->data;
    }
    return ans;
}
bool isSumTree(treeNode<int>* root)
{
    return isSumTreeFast(root).first;
}

int main()
{
    treeNode<int> *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 9 8 -1 -1 -1 -1

    if (isSumTree(root))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}