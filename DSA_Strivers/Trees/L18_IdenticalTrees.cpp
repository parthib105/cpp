/*
    Identical Trees

    You are given two binary trees with 'n' and 'm' nodes respectively.

    You need to return true if the two trees are identical. Otherwise, return false.

    Example:
    For the trees given below:- 

    The given trees are identical as:-
    1. The number of nodes in both trees is the same. 
    2. The number of edges in both trees is the same. 
    3. The data for root for both the trees is the same i.e 5. 
    4. The data of root -> left (root’s left child) for both the trees is the same i.e 2.
    5. The data of root -> right (root’s right child) for both the trees is the same i.e 3.
    6. The data of root -> right -> left ( left child of root’s right child) for both the trees is the same i.e 6.
    7. Nodes with data 2 and 6 are the leaf nodes for both the binary trees. 
    Detailed explanation ( Input/output format, Notes, Images )
    Sample input 1 :
    5 2 3 -1 6 -1 -1 -1 -1
    5 2 3 -1 6 -1 -1 -1 -1
    Sample output 1 :
    True
    Explanation for Sample Input 1 :
    Refer to the example given above in the problem description.
    Sample input 2 :
    1 -1 2 -1 -1
    1 2 -1 -1 -1  
    Sample output 2 :
    False
    Explanation for Sample Input 2 :

    Although the following conditions satisfy:

    The number of nodes in both trees is the same.
    The number of edges in both trees is the same. 
    The data for root for both the trees is the same i.e 1.

    It’s visible from the pictorial representation that the trees are not identical. Reason being:
    In Binary tree 1, root’s right is NULL but it’s not true for Binary tree 2. 
    In Binary tree 1, root’s left is not NULL but it’s not true for Binary tree 2. 
    Expected time complexity:
    The expected time complexity is O(min(n,m)).
    Constraints :
    0 <= 'n' <= 10^6
    0 <= 'm' <= 10^6
    1 <= Node Data <= 10^9 

    Time limit: 1 sec
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
            this->left = NULL;
        if (this->right)
            this->right = NULL;
    }
};

TreeNode<int> *buildTree(vector<int> &lo)
{
    int i = 1, n = lo.size();
    if (n == 0) 
        return nullptr;

    TreeNode<int>* root = new TreeNode<int>(lo[0]);
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty() && i < n)
    {
        TreeNode<int>* curr = q.front();
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

bool identicalTrees(TreeNode<int>* root1, TreeNode<int>* root2) 
{
    if (!root1 || !root2)
        return root1 == root2;

    bool lSub = identicalTrees(root1->left, root2->left);
    bool rSub = identicalTrees(root1->right, root2->right);
    return root1->data == root2->data && lSub && rSub;
}

int main()
{
    vector<int> lo1 = {28, 4, 10, 15, -1, 30, 1, 17, 33, -1, -1, 22, -1, 5, -1, -1, -1, -1, -1, 6, -1, -1, -1}; 
    vector<int> lo2 = {28, 4, 10, 15, -1, 30, 1, 17, 33, -1, -1, 22, -1, 5, -1, -1, -1, -1, -1, 6, -1, -1, -1}; 

    TreeNode<int>* root1 = buildTree(lo1);
    TreeNode<int>* root2 = buildTree(lo2);

    bool ans = identicalTrees(root1, root2);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}