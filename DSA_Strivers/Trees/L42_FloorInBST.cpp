/*
    floor in bst

    You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. Your task is to find the greatest value node of the BST which is smaller than or equal to ‘X’.

    Note :‘X’ is not smaller than the smallest node of BST .

    For example:


    In the above example, For the given BST  and X = 7, the greatest value node of the BST  which is smaller than or equal to  7 is 6.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints:
    1 <= T <= 5
    1 <= N <= 5 * 10 ^ 3
    1 <= nodeVal[i] <= 10 ^ 9

    Time Limit: 1 sec.
    Sample Input 1:
    2
    10 5 15 2 6 -1 -1 -1 -1 -1 -1
    7
    2 1 3 -1 -1 -1 -1
    2
    Sample Output 1:
    6
    2
    Explanation of Sample Input 1:
    In the first test case, the BST looks like as below:

    The greatest value node of the BST which is smaller than or equal to  7 is 6.

    In the second test case, the BST looks like as below:

    The greatest value node of the BST which is smaller than or equal to  2 is 2.
    Sample Input 2:
    2
    5 3 10 2 4 6 15 -1 -1 -1 -1 -1 -1 -1 -1
    15
    5 3 10 2 4 6 15 -1 -1 -1 -1 -1 -1 -1 -1
    8
    Sample Output 2:
    15
    6
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
public:
    int findFloor(TreeNode<int>* root, int x)
    {
        int floor = -1;
        while (root) 
        {
            if (root->data == x)
            {
                floor = root->data;
                return floor;
            }

            if (x > root->data)
            {
                floor = root->data;
                root = root->right;
            }
            else
                root = root->left;
        }
        return floor;
    }
};

int main()
{
    vector<int> lo = {18, 5, 10, 2, 6, -1, -1, -1, -1, -1, 7};
    TreeNode<int>* root = buildTree(lo);
    int x = 4;

    Solution sol;
    cout << sol.findFloor(root, x) << endl;
    return 0;
}