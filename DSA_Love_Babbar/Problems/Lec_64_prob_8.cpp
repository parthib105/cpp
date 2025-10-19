/*
    Diagonal Traversal of Binary Tree

    Given a Binary Tree, print the diagonal traversal of the binary tree.

    Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
    If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree.

    Example 1:

    Input :
           8
         /   \
        3     10
       / \      \
      1   6     14
         / \    /
        4   7  13
    Output : 8 10 14 3 6 7 13 1 4
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

vector<int> diagonal(treeNode<int>* root)
{
   vector<int> ans;
   if (root == NULL)
   {
       return ans;
   }
   
   queue<treeNode<int>*> q;
   q.push(root);
   while(!q.empty())
   {
       treeNode<int>* curr = q.front();
       q.pop();
       while (curr != NULL)
       {
           ans.push_back(curr->data);
           if (curr->left != NULL)
           {
               q.push(curr->left);
           }
           curr = curr->right;
       }
   }
   
   return ans;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int>* root;
    root = buildTree(root);
    vector<int> ans = diagonal(root);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}