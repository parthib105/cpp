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

int height(treeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// Brute Force Solution
bool brute(treeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }

    bool checkLeft = brute(root->left);
    bool checkRight = brute(root->right);
    if (checkLeft || checkRight)
    {
        return true;
    }
    return false;
}

// Optimized Solution
int dfsHeight(treeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }

    // call for left subtree
    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
    {
        return -1;
    }

    // call for right subtree
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
    {
        return -1;
    }

    // not a valid BST
    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

bool checkBalancedTree(treeNode<int> *root)
{
    // Brute Force
    // return brute(root);

    // Optimal Approach O(n)
    return dfsHeight(root)!= -1;
}

int main()
{
    // 1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 -1 7 9 -1 -1 10 -1 -1
    treeNode<int> *root = buildTree(root);

    bool isBalanced = checkBalancedTree(root);
    if (isBalanced)
    {
        cout << endl << "The tree is balanced." << endl;
    }
    else
    {
        cout << endl << "The tree is not balanced." << endl;
    }
    return 0;
}