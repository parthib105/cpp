/*
    Binary Tree Maximum Path Sum

    You are given a binary tree with ‘N’ nodes.

    Your task is to find the “Maximum Path Sum” for any path.

    Note : 
    1. A ‘path’ is a sequence of adjacent pair nodes with an edge between them in the binary tree.
    2. The ‘path’ doesn’t need to pass through the root.
    3. The ‘path sum’ is the sum of the node’s data in that path. 
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    1
    -4 -2 3 -1 -1 1 1 -1 -1 -1 -1
    Sample Output 1 :
    5
    Explanation For Sample Input 1 :
    The tree will be

    The path marked in yellow is the maximum sum path.
    Sample Input 2 :
    1
    -2 2 1 -1 -1 -1 -1
    Sample Output 2 :
    2
    Explanation For Sample Input 2 :
    The tree will be:

    The maximum sum path will only contain one node and marked in yellow.
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

// If the tree is given as a graph representation
class Solution2 {
private:
    int maxSum;
    
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& wgts) {
        int maxBranch1 = 0; // largest branch sum
        int maxBranch2 = 0; // second largest branch sum
        
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                int branchSum = max(0, dfs(neighbor, node, adj, wgts));
                
                // Update top two branches
                if (branchSum > maxBranch1) {
                    maxBranch2 = maxBranch1;
                    maxBranch1 = branchSum;
                } else if (branchSum > maxBranch2) {
                    maxBranch2 = branchSum;
                }
            }
        }
        
        // Path through current node using top two branches
        int pathThroughNode = wgts[node] + maxBranch1 + maxBranch2;
        maxSum = max(maxSum, pathThroughNode);
        
        // Return maximum single branch
        return wgts[node] + maxBranch1;
    }

public:
    int maxPathSum(int n, vector<vector<int>>& edges, vector<int>& wgts) {
        if (n == 0) return 0;
        
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        maxSum = INT_MIN;
        dfs(0, -1, adj, wgts);
        return maxSum;
    }
};

int dfsUtil(TreeNode<int>* root, int& maxPath)
{
    if (!root)
        return 0;

    int ls = max(0, dfsUtil(root->left, maxPath));
    int rs = max(0, dfsUtil(root->right, maxPath));

    maxPath = max(maxPath, root->data + ls + rs);
    return root->data + max(ls, rs);
}

int maxPathSum(TreeNode<int>* root)
{
	int maxPath = INT_MIN;
    int _null = dfsUtil(root, maxPath);
    return maxPath;
}

int main()
{
    vector<int> lo = {2, -7, 5, -2, 6, -1, -9, -1, -1, 5, -11, 4, -1};
    TreeNode<int>* root = buildTree(lo);
    
    int mps = maxPathSum(root);
    cout << mps << endl;
    return 0;
}