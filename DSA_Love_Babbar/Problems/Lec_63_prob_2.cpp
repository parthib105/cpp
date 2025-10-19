/*
    Diameter of a Binary Tree

    The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
    The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded
    (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
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

int height(treeNode<int> *root)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (max(leftHeight, rightHeight) + 1);
}

// approach 1 : T.C. O(n^2)
int diameter1(treeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftDiameter = diameter1(root->left);
    int rightDiameter = diameter1(root->right);
    int heightOfLeftRight = height(root->left) + height(root->right) + 1;

    return max(leftDiameter, max(rightDiameter, heightOfLeftRight));
}

// Approach 2 : T.C. O(n)
// function to return a pair (diameter, height)
pair<int, int> diameterOptimal(treeNode<int>* root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> LD = diameterOptimal(root->left);
    pair<int, int> RD = diameterOptimal(root->right);

    int op1 = LD.first;
    int op2 = RD.first;
    int op3 = LD.second + RD.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(LD.second, RD.second) + 1;

    return ans;
}

// Function to return the diameter of a Binary Tree.
int diameter2(treeNode<int>* root)
{
    pair<int, int> ans = diameterOptimal(root);
    return ans.first;
}

int main()
{
    treeNode<int> *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 9 8 -1 -1 -1 -1

    cout << endl << "Diameter of the tree : " << diameter2(root) << endl;
    return 0;
}