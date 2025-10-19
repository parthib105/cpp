/*
    Normal BST To Balanced BST

    You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert it into a balanced BST with
    the minimum height possible.

    A binary search tree (BST) is a binary tree data structure that has the following properties.

    • The left subtree of a node contains only nodes with data less than the node’s data.
    • The right subtree of a node contains only nodes with data greater than the node’s data.
    • Both the left and right subtrees must also be binary search trees.
    A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs no more than 1.

    Example :

    For the given BST :

                        10
                       /  \
                      8    12
                     /      \
                    4        16
                   /          \
                  2            20

    Modefied BST will be :

                        10
                       /  \
                      4    16
                     / \   / \
                    2   8 12  20
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

void levelOrder(treeNode<int>* root)
{
    queue<treeNode<int>*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        treeNode<int>* curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

// Approach 1 : store the inorder, and make tree out of it
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

treeNode<int>* inorderToBST(int s, int e, vector<int> &inorder)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    int m = s + (e - s) / 2;
    treeNode<int>* root = new treeNode<int>(inorder[m]);
    root->left = inorderToBST(s, m - 1, inorder);
    root->right = inorderToBST(m + 1, e, inorder);
    return root;
}

treeNode<int>* balancedBst1(treeNode<int>* root)
{
    // Write your code here.
    vector<int> inorder;
    inorderTraverse(root, inorder);
    return inorderToBST(0, inorder.size() - 1, inorder);
}

int main()
{
    // 10 8 4 2 12 16 20 -1
    treeNode<int> *root = NULL;
    takeInput(root);

    cout << endl << "Level order traversal of the tree (before balancing) : " << endl;
    levelOrder(root);
    cout << endl;

    treeNode<int>* newRoot = balancedBst1(root);

    cout << endl << "Level order traversal of the tree (after balancing) : " << endl;
    levelOrder(newRoot);
    cout << endl;
    return 0;
}