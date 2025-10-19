/*
    Sum of nodes on the longest path from root to leaf node

    Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. 
    If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

    Input: 
         4        
       /   \       
      2     5      
     / \   / \     
    7   1 2   3    
       /
      6
    Output: 
    13
*/

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

void solve(treeNode<int>* root, pair<int, int> nodeLen, pair<int, int>& nodeMax)
{
    // base case
    if (root == NULL)
    {
        if (nodeLen.second > nodeMax.second)
        {
            nodeMax.second = nodeLen.second;
            nodeMax.first = nodeLen.first;
        }
        else if (nodeLen.second == nodeMax.second)
        {
            nodeMax.first = max(nodeLen.first, nodeMax.first);
        }
        return;
    }

    nodeLen.first = nodeLen.first + root->data;
    nodeLen.second = nodeLen.second + 1;

    solve(root->left, nodeLen, nodeMax);
    solve(root->right, nodeLen, nodeMax);
}

int sumOfLongRootToLeafPath(treeNode<int>* root)
{
    // pair <sum, len>
    pair<int, int> nodeLen = make_pair(0, 0);

    // pair <maxSum, maxLen>
    pair<int, int> nodeMax = make_pair(INT32_MIN, 0);

    solve(root, nodeLen, nodeMax);

    return nodeMax.first;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int>* root;
    root = buildTree(root);
    cout << endl << "Sum of longest root : " << sumOfLongRootToLeafPath(root) << endl;
    return 0;
}