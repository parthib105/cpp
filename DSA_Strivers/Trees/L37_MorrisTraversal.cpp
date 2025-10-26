/*
    Morris Traversal (inorder)

    Given the root of a binary tree, return the inorder traversal of its nodes' values.

    Example 1:

    Input: root = [1,null,2,3]

    Output: [1,3,2]

    Explanation:



    Example 2:

    Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

    Output: [4,2,6,5,7,1,3,9,8]

    Explanation:



    Example 3:

    Input: root = []

    Output: []

    Example 4:

    Input: root = [1]

    Output: [1]

    

    Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
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

class Solution {
public:
    vector<int> morrisInorderTraversal(TreeNode<int>* root) 
    {
        vector<int> inO;

        TreeNode<int>* curr = root;
        while (curr != nullptr)
        {
            if (!curr->left) 
            {
                inO.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                TreeNode<int>* prev = curr->left;
                // go to right and connect
                while (prev->right && prev->right != curr)
                    prev = prev->right;

                if (!prev->right)   // connect and go left
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = nullptr;
                    inO.push_back(curr->data);
                    curr = curr->right;
                }
            }
        } 
        return inO;   
    }
};

int main()
{
    vector<int> lo = {1, 5, 3, -1, 4, 10, 6, 9, 2};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    vector<int> morrisIno = sol.morrisInorderTraversal(root);

    for (int node : morrisIno)
        cout << node << " ";
    return 0;
}