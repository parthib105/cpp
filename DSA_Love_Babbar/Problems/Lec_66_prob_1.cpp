/*
    Construct Tree from Inorder & Preorder

    Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print 
    the Postorder traversal. 

    Input:
    N = 4
    inorder[] = {1 6 8 7}
    preorder[] = {1 6 7 8}
    Output: 8 7 6 1

    Input:
    N = 6
    inorder[] = {3 1 4 0 5 2}
    preorder[] = {0 1 3 4 2 5}
    Output: 3 4 1 5 2 0
    Explanation: The tree will look like
          0
        /   \
       1     2
      / \   /
     3   4 5
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

treeNode<int>* buildTreeFromInPre(int preorder[], int inorder[], map<int, int>& mp, int st, int ed)  // st->start of inorder, ed->end of inorder
{
    static int idx = 0;
    if (st > ed)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    treeNode<int>* n = new treeNode<int>(curr);
    if (st == ed)
    {
        return n;
    }

    int pos = mp[curr];
    n->left = buildTreeFromInPre(preorder, inorder, mp, st, pos - 1);
    n->right = buildTreeFromInPre(preorder, inorder, mp, pos + 1, ed);

    return n;
}

/******************** If duplicate element present in inorder sequence ********************/
treeNode<int>* solve(int in[], int pre[], int n, int& preIdx, map<int, queue<int>>& mp, int inSt, int inEd)
{
    // base case
    if (preIdx >= n || inSt > inEd)
    {
        return NULL;
    }

    // take the element from preOrder sequence
    int elm = pre[preIdx++];

    // create node with curr element
    treeNode<int>* node = new treeNode<int>(elm);

    // fetch the position of curr element in inorder sequence
    int pos = mp[elm].front();
    mp[elm].pop();

    node->left = solve(in, pre, n, preIdx, mp, inSt, pos - 1);
    node->right = solve(in, pre, n, preIdx, mp, pos + 1, inEd);
    return node;
}

treeNode<int>* buildTreeInPre(int in[], int pre[], int n)
{
    int preIdx = 0;
    map<int, queue<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]].push(i);
    }
    return solve(in, pre, n, preIdx, mp, 0, n - 1);
}
/******************************************************************************************/


void inOrder(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    // 5
    int in[] = {10, 1, 30, 40, 20};
    int pre[] = {1, 10, 20, 30, 40};
    // int in[] = {3, 1, 4, 0, 5, 2};
    // int pre[] = {0, 1, 3, 4, 2, 5};
    int n = 5;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[in[i]] = i;
    }
    treeNode<int>* root = buildTreeFromInPre(pre, in, mp, 0, n - 1);
    inOrder(root);
    cout << endl;
    preOrder(root);
    return 0;
}