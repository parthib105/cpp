/*
    Right View of Binary Tree

    Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

    Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /  \     /   \
  4    5   6     7
   \
    8
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

void solve(treeNode<int>* root, vector<int> &ans, int lvl)
{
    if (root == NULL)
    {
        return;
    }

    if (lvl == ans.size())
    {
        ans.push_back(root->data);
    }

    solve(root->right, ans, lvl + 1);
    solve(root->left, ans, lvl + 1);
}
// Function to return list containing elements of right view of binary tree.
vector<int> rightView(treeNode<int>* root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    solve(root, ans, 0);
    return ans;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int>* root;
    root = buildTree(root);
    vector<int> ans = rightView(root);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}