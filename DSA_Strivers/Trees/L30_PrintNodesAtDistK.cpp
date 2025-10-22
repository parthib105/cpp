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

void findTarget(int tar, TreeNode<int>* root, TreeNode<int>** target)
{
    if (!root)
        return;

    if (root->data == tar)
    {
        *target = root;
        return;
    }

    findTarget(tar, root->left, target);
    findTarget(tar, root->right, target);
}

class Solution 
{
private:
    void getParent(TreeNode<int>* root, unordered_map<TreeNode<int>*, TreeNode<int>*>& parentMap)
    {
        queue<TreeNode<int>*> q;

        q.push(root);
        parentMap[root] = nullptr;
        while (!q.empty())
        {
            TreeNode<int>* u = q.front();
            q.pop();

            if (u->left) {
                parentMap[u->left] = u;
                q.push(u->left);
            }
            if (u->right) {
                parentMap[u->right] = u;
                q.push(u->right);
            }
        }
    }

    vector<int> distanceKUtil(TreeNode<int>* root, TreeNode<int>* target, int k)
    {
        unordered_map<TreeNode<int>*, TreeNode<int>*> parentMap;

        // mark the parents using bfs
        getParent(root, parentMap);

        // 2nd bfs to go upto k level
        int dist = 0;
        queue<TreeNode<int>*> q;
        unordered_map<TreeNode<int>*, bool> vis;

        q.push(target);
        vis[target] = true;
        while (!q.empty())
        {
            if (dist++ == k)
                break;

            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode<int>* cur = q.front();
                TreeNode<int>* par = parentMap[cur];
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

        vector<int> ans;
        while (!q.empty())
        {
            TreeNode<int>* cur = q.front();
            q.pop();
            ans.push_back(cur->data);
        }
        return ans;
    }
public:
    vector<int> distanceK(TreeNode<int>* root, TreeNode<int>* target, int k) {
        // Using 2 bfs calls
        return distanceKUtil(root, target, k);
    }
};

int main()
{
    vector<int> lo = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode<int>* root = buildTree(lo);

    int tar = 5, k = 2;
    TreeNode<int>* target;
    findTarget(tar, root, &target);

    Solution sol;
    vector<int> nodes = sol.distanceK(root, target, k);

    for (int n : nodes)
        cout << n << " ";
    return 0;
}