/*
    Delete Node in a BST

    Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

    Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.
    

    Example 1:


    Input: root = [5,3,6,2,4,null,7], key = 3
    Output: [5,4,6,2,null,null,7]
    Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
    One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
    Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

    Example 2:

    Input: root = [5,3,6,2,4,null,7], key = 0
    Output: [5,3,6,2,4,null,7]
    Explanation: The tree does not contain a node with value = 0.
    Example 3:

    Input: root = [], key = 0
    Output: []
*/

#include<bits/stdc++.h>
using namespace std;

template <class T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    ~TreeNode()
    {
        if (this->left)
            delete this->left;
        if (this->right)
            delete this->right;
    }
};

TreeNode<int> *buildTree(vector<int> &lo)
{
    int i = 1, n = lo.size();
    if (n == 0)
        return nullptr;

    TreeNode<int> *root = new TreeNode<int>(lo[0]);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty() && i < n)
    {
        TreeNode<int> *curr = q.front();
        q.pop();

        if (i < n && lo[i] != -1)
        {
            curr->left = new TreeNode<int>(lo[i]);
            q.push(curr->left);
        }
        i++;

        if (i < n && lo[i] != -1)
        {
            curr->right = new TreeNode<int>(lo[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void printLevelOrder(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();

        if (!curr)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

TreeNode<int>* findLastRight(TreeNode<int>* root)
{
    if (!root->right)
        return root;
    return findLastRight(root->right);
}

TreeNode<int>* reconnect(TreeNode<int>* root)
{
    if (!root->left)
        return root->right;
    else if (!root->right)
        return root->left;
    
    TreeNode<int>* rightChild = root->right;
    TreeNode<int>* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode<int>* deleteNode(TreeNode<int>* root, int key)
{
    if (!root)
        return nullptr;
    if (root->data == key)
        return reconnect(root);
    
    TreeNode<int>* dummy = root;
    while (root)
    {
        if (root->data > key)
        {
            if (root->left && root->left->data == key)
            {
                root->left = reconnect(root->left);
                break;
            }
            else
                root = root->left;
        }
        else
        {
            if (root->right && root->right->data == key)
            {
                root->right = reconnect(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}

int main()
{
    // root = [5,3,6,2,4,null,7], key = 3
    vector<int> lo = {5,3,6,2,4,-1,7};
    TreeNode<int>* root = buildTree(lo);

    int key = 3;
    printf("Level order before deletion: \n");
    printLevelOrder(root);

    root = deleteNode(root, key);

    printf("\nLevel order after deletion: \n");
    printLevelOrder(root);
    return 0;
}