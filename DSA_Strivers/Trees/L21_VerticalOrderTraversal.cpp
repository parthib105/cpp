/*
    Vertical Order Traversal of a Binary Tree

    Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

    For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

    The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

    Return the vertical order traversal of the binary tree.



    Example 1:


    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    Explanation:
    Column -1: Only node 9 is in this column.
    Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
    Column 1: Only node 20 is in this column.
    Column 2: Only node 7 is in this column.
    Example 2:


    Input: root = [1,2,3,4,5,6,7]
    Output: [[4],[2],[1,5,6],[3],[7]]
    Explanation:
    Column -2: Only node 4 is in this column.
    Column -1: Only node 2 is in this column.
    Column 0: Nodes 1, 5, and 6 are in this column.
            1 is at the top, so it comes first.
            5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
    Column 1: Only node 3 is in this column.
    Column 2: Only node 7 is in this column.
    Example 3:


    Input: root = [1,2,3,4,6,5,7]
    Output: [[4],[2],[1,5,6],[3],[7]]
    Explanation:
    This case is the exact same as example 2, but with nodes 5 and 6 swapped.
    Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.


    Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    0 <= Node.val <= 1000
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
    vector<vector<int>> verticalTraversal(TreeNode<int> *root)
    {
        // {hd, {lvl, node}}
        map<int, map<int, multiset<int>>> nodeMap;
        queue<pair<TreeNode<int> *, pair<int, int>>> q; // {node, {hd, lvl}}

        q.push({root, {0, 0}});
        while (!q.empty())
        {
            pair<TreeNode<int> *, pair<int, int>> p = q.front();
            q.pop();

            TreeNode<int> *cur = p.first;
            int hd = p.second.first;
            int lvl = p.second.second;

            nodeMap[hd][lvl].insert(cur->data);
            if (cur->left)
                q.push({cur->left, {hd - 1, lvl + 1}});
            if (cur->right)
                q.push({cur->right, {hd + 1, lvl + 1}});
        }

        vector<vector<int>> res;
        map<int, map<int, multiset<int>>>::iterator it1 = nodeMap.begin();
        while (it1 != nodeMap.end())
        {
            vector<int> col;
            map<int, multiset<int>>::iterator it2 = it1->second.begin();
            while (it2 != it1->second.end())
            {
                multiset<int> levelNodes = it2->second;
                multiset<int>::iterator it3 = levelNodes.begin();
                while (it3 != levelNodes.end())
                {
                    col.push_back(*it3);
                    it3 ++;
                }
                it2++;
            }
            res.push_back(col);
            it1++;
        }
        return res;
    }
};

int main()
{
    vector<int> lo = {2, -7, 5, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    vector<vector<int>> res = sol.verticalTraversal(root);

    for (vector<int>& row : res)
    {
        for (int e : row)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}