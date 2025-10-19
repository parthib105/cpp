/*
    Binary tree
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

// level order traversal
void levelOrderTraversal(treeNode<int>* root)
{
    queue<treeNode<int>*> q;
    q.push(root);
    q.push(NULL);    // separator

    while (!q.empty())
    {
        treeNode<int>* frontNode = q.front();
        q.pop();

        // add the separator
        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
    }
}

void inorderTraversal(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    postorderTraversal(root->left);
    postorderTraversal(root->right);
}

int main()
{
    treeNode<int>* root = NULL;
    root = buildTree(root);

    // tree : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout << "Level order traversal : " << endl;
    inorderTraversal(root);
    return 0;
}