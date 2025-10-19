/*
    Is Binary Tree Heap

    Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
    Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

    Input:
          5
         / \
        2   3
    Output: 1
    Explanation: The given tree follows max-heap property since 5,
    is root and it is greater than both its children
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

void buildTreeFromLevelOrder(treeNode<int> *&root)
{
    queue<treeNode<int>*> q;
    int rootData;
    cout << "Enter data for root : ";
    cin >> rootData;

    root = new treeNode<int>(rootData);
    q.push(root);

    while (!q.empty())
    {
        treeNode<int> *curr = q.front();
        q.pop();

        int leftData;
        cout << "Enter left node for " << curr->data << " : ";
        cin >> leftData;

        if (leftData != -1)
        {
            curr->left = new treeNode<int>(leftData);
            q.push(curr->left);
        }

        int rightData;
        cout << "Enter right node for " << curr->data << " : ";
        cin >> rightData;

        if (rightData != -1)
        {
            curr->right = new treeNode<int>(rightData);
            q.push(curr->right);
        }
    }
}

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

void levelOrderTraversal(treeNode<int> *root)
{
    queue<treeNode<int> *> q;
    q.push(root);
    q.push(NULL); // separator

    while (!q.empty())
    {
        treeNode<int> *frontNode = q.front();
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

// function to count no. of nodes
int countNode(treeNode<int>* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (1 + countNode(root->left) + countNode(root->right));
}

// function to check if the binary tree is a complete binary tree
bool isCBT(treeNode<int>* root, int idx, int nodeCount)
{
    if (root == NULL)
    {
        return true;
    }
    if (idx >= nodeCount)
    {
        return false;
    }

    bool leftAns = isCBT(root->left, 2 * idx + 1, nodeCount);
    bool rightAns = isCBT(root->right, 2 * idx + 2, nodeCount);
    return (leftAns && rightAns);
}

// function to check if complete binary tree follows max order
bool isMaxOrder(treeNode<int>* root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }

    bool ans1 = root->data > root->left->data;
    bool ans2 = root->data > root->right->data;
    if (ans1 && ans2 && isMaxOrder(root->left) && isMaxOrder(root->right))
    {
        return true;
    }
    return false;
}

bool isHeap(treeNode<int>* tree) 
{
    // code here
    int idx = 0;
    int nodeCount = countNode(tree);
    
    if (isCBT(tree, idx, nodeCount) && isMaxOrder(tree))
    {
        return true;
    }
    return false;
}

int main()
{

    return 0;
}