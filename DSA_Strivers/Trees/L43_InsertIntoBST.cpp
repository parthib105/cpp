/*
    Insert into a Binary Search Tree

    You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

    Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

    Example 1:

    Input: root = [4,2,7,1,3], val = 5
    Output: [4,2,7,1,3,5]
    Explanation: Another accepted tree is:

    Example 2:

    Input: root = [40,20,60,10,30,50,70], val = 25
    Output: [40,20,60,10,30,50,70,null,null,25]
    Example 3:

    Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
    Output: [4,2,7,1,3,5]
    

    Constraints:

    The number of nodes in the tree will be in the range [0, 10^4].
    -10^8 <= Node.val <= 10^8
    All the values Node.val are unique.
    -10^8 <= val <= 10^8
    It's guaranteed that val does not exist in the original BST.
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

class Solution 
{
private:
    TreeNode<int>* insertIntoBSTIter(TreeNode<int>* root, int val) 
    {
        if (!root)
            return new TreeNode<int>(val);

        TreeNode<int>* curr = root;
        while (curr)
        {
            int curVal = curr->data;
            if (val > curVal)
            {
                if (curr->right)
                    curr = curr->right;
                else
                {
                    TreeNode<int>* node = new TreeNode<int>(val);
                    curr->right = node;
                    break;
                }
            }
            else
            {
                if (curr->left)
                    curr = curr->left;
                else
                {
                    TreeNode<int>* node = new TreeNode<int>(val);
                    curr->left = node;
                    break;
                }
            }
        }
        return root;
    }

    TreeNode<int>* insertIntoBSTRecur(TreeNode<int>* root, int val) 
    {
        if (!root)
            return new TreeNode<int>(val);

        if (val < root->data)
            root->left = insertIntoBSTRecur(root->left, val);
        else
            root->right = insertIntoBSTRecur(root->right, val);
        return root;
    }
public:
    TreeNode<int>* insertIntoBST(TreeNode<int>* root, int val) 
    {
        // Iterative solution
        // return insertIntoBSTIter(root, val);

        // Recursive solution
        return insertIntoBSTRecur(root, val); 
    }
};

int main()
{
    vector<int> lo = {4,2,7,1,3};
    TreeNode<int>* root = buildTree(lo);

    int val = 5;
    Solution sol;
    root = sol.insertIntoBST(root, val);

    printLevelOrder(root);
    return 0;
}