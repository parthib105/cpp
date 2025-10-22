/*
    Amount of Time for Binary Tree to Be Infected

    You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

    Each minute, a node becomes infected if:

    The node is currently uninfected.
    The node is adjacent to an infected node.
    Return the number of minutes needed for the entire tree to be infected.

    Example 1:


    Input: root = [1,5,3,null,4,10,6,9,2], start = 3
    Output: 4
    Explanation: The following nodes are infected during:
    - Minute 0: Node 3
    - Minute 1: Nodes 1, 10 and 6
    - Minute 2: Node 5
    - Minute 3: Node 4
    - Minute 4: Nodes 9 and 2
    It takes 4 minutes for the whole tree to be infected so we return 4.
    Example 2:


    Input: root = [1], start = 1
    Output: 0
    Explanation: At minute 0, the only node in the tree is infected so we return 0.
    

    Constraints:

    The number of nodes in the tree is in the range [1, 10^5].
    1 <= Node.val <= 10^5
    Each node has a unique value.
    A node with a value of start exists in the tree.
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
    unordered_map<TreeNode<int>*, TreeNode<int>*> parentMap;

    TreeNode<int>* getParent(int start, TreeNode<int>* root)
    {
        TreeNode<int>* src = nullptr;
        queue<TreeNode<int>*> q;

        q.push(root);
        this->parentMap[root] = nullptr;
        while (!q.empty())
        {
            TreeNode<int>* cur = q.front();
            q.pop();

            if (cur->data == start)
                src = cur;

            if (cur->left) {
                q.push(cur->left);
                this->parentMap[cur->left] = cur;
            }
            if (cur->right) {
                q.push(cur->right);
                this->parentMap[cur->right] = cur;
            }
        }
        return src;
    }
public:
    int amountOfTime(TreeNode<int>* root, int start) 
    {
        this->parentMap.clear();
        TreeNode<int>* src = getParent(start, root);

        int time = 0;
        queue<TreeNode<int>*> q;
        unordered_map<TreeNode<int>*, bool> vis;

        q.push(src);
        vis[src] = true;
        while (!q.empty())
        {
            time ++;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode<int>* cur = q.front();
                TreeNode<int>* par = this->parentMap[cur];
                q.pop();

                if (cur->left && !vis[cur->left]) {
                    vis[cur->left] = true;
                    q.push(cur->left);
                }
                if (cur->right && !vis[cur->right]) {
                    vis[cur->right] = true;
                    q.push(cur->right);
                }
                if (par && !vis[par]) {
                    vis[par] = true;
                    q.push(par);
                }
            }
        }
        return time - 1;
    }
};

int main()
{
    vector<int> lo = {1, 5, 3, -1, 4, 10, 6, 9, 2};
    TreeNode<int>* root = buildTree(lo);

    int start = 3;
    Solution sol;
    int t = sol.amountOfTime(root, start);
    cout << t << endl;
    return 0;
}