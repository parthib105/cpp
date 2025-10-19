/*
    Maximum sum of Non-adjacent nodes

    Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of
    chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we
    have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

    Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
    Output: 16
    Explanation: The maximum sum is sum of
    nodes 1 4 5 6 , i.e 16. These nodes are
    non adjacent.
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

pair<int, int> solve(treeNode<int>* root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }

    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> ans;
    ans.first = root->data + leftAns.second + rightAns.second;
    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return ans;
}

// Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(treeNode<int>* root)
{
    // pair<including curr node, excluding curr node>
    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int> *root;
    root = buildTree(root);
    cout << endl << "Max sum : " << getMaxSum(root) << endl;
    return 0;
}