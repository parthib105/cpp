/*
    AVL tree (Height Balanced Binary tree)
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class treeNode
{
public:
    T data;
    treeNode<T>* left;
    treeNode<T>* right;
    int height;  

    treeNode(T val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int getHeight(treeNode<int>* n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int getBalanceFactor(treeNode<int>* n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

// right rotate w.r.t node y
treeNode<int>* rightRotate(treeNode<int>* y)
{
    treeNode<int>* x = y->left;     // left subtree of y
    treeNode<int>* T2 = x->right;   // right subtree of x

    // change links
    x->right = y;
    y->left = T2;

    // update height of x and y
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

// left rotate w.r.t node y
treeNode<int>* leftRotate(treeNode<int>* x)
{
    treeNode<int>* y = x->right;     // right subtree of x
    treeNode<int>* T2 = y->left;     // left subtree of y

    // change links
    y->left = x;
    x->right = T2;

    // update height of x and y
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

// Insertion
treeNode<int>* insertInAVL(treeNode<int>* root, int val)
{
    // insert in desired position
    if (root == NULL)
    {
        return new treeNode<int>(val);
    }
    else if (val < root->data)
    {
        root->left = insertInAVL(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insertInAVL(root->right, val);
    }
    else
    {
        return root;
    }

    // update the height after insertion
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // get the balance factor
    int bf = getBalanceFactor(root);

    // left-left case
    if (bf > 1 && val < root->left->data)
    {
        return rightRotate(root);
    }

    // left-right case
    if (bf > 1 && val > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // right-right case
    if (bf < -1 && val > root->right->data)
    {
        return leftRotate(root);
    }

    // right-left case
    if (bf < -1 && val < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void leveOrderTraversal(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
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
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    treeNode<int>* root = NULL;
    root = insertInAVL(root, 1);
    root = insertInAVL(root, 2);
    root = insertInAVL(root, 3);
    root = insertInAVL(root, 4);
    root = insertInAVL(root, 5);

    leveOrderTraversal(root);
    return 0;
}