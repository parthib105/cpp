#include <bits/stdc++.h>
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

class Solution
{
private:
    int height(TreeNode<int>* root)
    {
        if (!root)
            return 0;

        int lst = height(root->left);
        int rst = height(root->right);
        return 1 + max(lst, rst);
    }

    void bruteForce(TreeNode<int>* root, int &dia)
    {
        if (!root)
            return;

        int lh = height(root->left);
        int rh = height(root->right);

        int curDia = lh + rh;
        dia = max(dia, curDia);

        bruteForce(root->left, dia);
        bruteForce(root->right, dia);
    }

    int dfsUtil(TreeNode<int>* root, int &dia)
    {
        if (!root)
            return 0;

        int lh = dfsUtil(root->left, dia);
        int rh = dfsUtil(root->right, dia);

        dia = max(dia, lh + rh);
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode<int>* root)
    {
        int dia = 0;

        // brute force
        // bruteForce(root, dia);

        // Optimized solution
        int _null = dfsUtil(root, dia);

        return dia;
    }
};

int main()
{
    vector<int> lo = {7, 4, 9, 2, 5, 8, 10, 1, 3, -1, 6};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    int dia = sol.diameterOfBinaryTree(root);
    cout << dia << endl;
    return 0;
}