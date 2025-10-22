/*
    Children Sum Property

    Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.

    A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).

    Note :
    1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
    2. You can not change the structure of the original binary tree.
    3. A binary tree is a tree in which each node has at most two children.
    4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints :
    1 <= T <= 10^2
    0 <= N <= 10^2
    1 <= node.Value <= 10^6

    Time Limit : 1 sec
    Sample Input 1 :
    1
    2 35 10 2 3 5 2 -1 -1 -1 -1 -1 -1 -1 -1
    Sample Output 1 :
    Valid ( One of the possible answers is : 45 35 10 32 3 8 2 -1 -1 -1 -1 -1, thus if the user modifies the given tree like this, the output printed will be valid).
    Explanation For Sample Input 1 :
    The tree can be represented as follows :

    The value at the root node is 2 which is less than the sum of its children’s values (35 + 10). So we simply increase the value at the root node to 45. The node with value  = 35 has children with values 2 and 3 so their sum i.s 2 + 3 = 5 < 35. As we can't decrement any value, so instead we have to increase the sum of children and thus we update 35's children (2 and 3) as 30 and 5 so that 30 + 5 = 35 and the same is done for the children of the node with value = 10.
    The final tree looks like this :

    Note that there can be many other valid solutions.
    Sample Input 2 :
    1
    10 5 5 -1 -1 -1 -1
    Sample Output 2 :
    Valid
*/

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
    void changeTree(TreeNode<int> *root)
    {
        if (!root)
            return;

        // collect children sum
        int childSum = 0;
        if (root->left)
            childSum += root->left->data;
        if (root->right)
            childSum += root->right->data;

        // modify according to the sum
        if (root->data <= childSum)
            root->data = childSum;
        else
        {
            if (root->left)
                root->left->data = root->data;
            if (root->right)
                root->right->data = root->data;
        }

        // go left and right
        changeTree(root->left);
        changeTree(root->right);

        // collect the sums
        int totSum = 0;
        if (root->left)
            totSum += root->left->data;
        if (root->right)
            totSum += root->right->data;

        // Update to non-leaf nodes
        if (root->left || root->right)
            root->data = totSum;
    }
};

int main()
{
    vector<int> lo = {2, 35, 10, 2, 3, 5, 2};
    TreeNode<int>* root = buildTree(lo);

    printLevelOrder(root);
    cout << endl;

    Solution sol;
    sol.changeTree(root);

    printLevelOrder(root);
    cout << endl;
    return 0;
}