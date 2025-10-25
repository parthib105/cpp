/*
    Count Complete Tree Nodes

    Given the root of a complete binary tree, return the number of the nodes in the tree.

    According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

    Design an algorithm that runs in less than O(n) time complexity.

    Example 1:


    Input: root = [1,2,3,4,5,6]
    Output: 6
    Example 2:

    Input: root = []
    Output: 0
    Example 3:

    Input: root = [1]
    Output: 1


    Constraints:

    The number of nodes in the tree is in the range [0, 5 * 10^4].
    0 <= Node.val <= 5 * 10^4
    The tree is guaranteed to be complete.
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
private:
    // T.C. : O(n), S.C. : O(h)
    void bruteForce(int &count, TreeNode<int>* root)
    {
        if (!root)
            return;

        count += 1;
        bruteForce(count, root->left);
        bruteForce(count, root->right);
    }

    int findHeight(char ch, TreeNode<int>* node)
    {
        int hght = 0;
        while (node)
        {
            hght++;
            node = (ch == 'l') ? node->left : node->right;
        }
        return hght;
    }

    // T.C. : O((log(n))^2), S.C. : O(log(n))
    int countNodesOptimal(TreeNode<int>* root)
    {
        if (!root)
            return 0;

        int lh = findHeight('l', root);
        int rh = findHeight('r', root);

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodesOptimal(root->left) + countNodesOptimal(root->right);
    }

public:
    int countNodes(TreeNode<int>* root)
    {
        // Using Brute Force solution
        // int count = 0;
        // bruteForce(count, root);
        // return count;

        // using Optimal Solution
        return countNodesOptimal(root);
    }
};

int main()
{
    vector<int> lo = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    int nodes = sol.countNodes(root);
    cout << nodes << endl;
    return 0;
}