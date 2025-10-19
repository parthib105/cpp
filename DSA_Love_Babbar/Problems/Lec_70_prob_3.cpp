/*
    Inorder predecessor : maximum element in left subtree
    Inorder successor : minimum element in right subtree

    Find Inorder successor and Inorder predecessor of an element of a tree
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

pair<int, int> PredecessorSuccessor(treeNode<int>* root, int key)
{
    // base case
    if (root == NULL)
    {
        return make_pair(-1, -1);
    }

    int pred = -1;
    int succ = -1;

    treeNode<int>* curr = root;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            break;
        }
        else if (key < curr->data)
        {
            succ = curr->data;
            curr = curr->left;
        }
        else
        {
            pred = curr->data;
            curr = curr->right;
        }
    }

    if (curr == NULL)
    {
        return make_pair(pred, succ);
    }

    // find predecessor
    treeNode<int>* leftTree = curr->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // find successor
    treeNode<int>* rightTree = curr->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return make_pair(pred, succ);
}

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    treeNode<int> *root = NULL;
    int key = 7;
    takeInput(root);
    pair<int, int> ans = PredecessorSuccessor(root, key);

    cout << endl << "Inorder traverse :" << endl;
    inOrder(root);
    cout << endl;

    cout << endl << "Inorder predecessor of " << key << " is : " << ans.first << endl;
    cout << endl << "Inorder successor of " << key << " is : " << ans.second<< endl;

    return 0;
}