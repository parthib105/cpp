/*
    K Sum Paths

    Given a binary tree and an integer K. Find the number of paths in the tree which have their sum equal to K.
    A path may start from any node and end at any node in the downward direction.

    Example 1:

    Input:
    Tree =
              1
            /   \
           2     3
    K = 3
    Output:
    2
    Explanation:
    Path 1 : 1 + 2 = 3
    Path 2 : only leaf node 3
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

// Approach 1 :  TC O(n^2)
void solve1(treeNode<int> *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    // left subtree
    solve1(root->left, k, count, path);

    // right subtree
    solve1(root->right, k, count, path);

    // check if sum is equal to k
    int n = path.size();
    int nodeSum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        nodeSum += path[i];
        if (nodeSum == k)
        {
            count += 1;
        }
    }

    // remove the visited node (backtracking)
    path.pop_back();
}

int sumK1(treeNode<int> *root, int k)
{
    vector<int> path;
    int count = 0;
    solve1(root, k, count, path);
    return count;
}

// Approach 2 : TC O(n)
void solve2(treeNode<int>* root, int k, unordered_map<int, int> &mp, int sum, int& ans)
{
    if (root == NULL)
    {
        return;
    }
    sum += root->data;
    if (mp.find(sum - k) != mp.end())
    {
        ans += mp[sum - k];
    }
    mp[sum]++;
    solve2(root->left, k, mp, sum, ans);
    solve2(root->right, k, mp, sum, ans);
    mp[sum]--;
}

int sumK2(treeNode<int>* root, int k)
{
    // code here
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0;
    int ans = 0;
    solve2(root, k, mp, sum, ans);
    return ans;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    int k = 10;
    treeNode<int> *root;
    root = buildTree(root);
    cout << endl << "No. of nodes that sum up to " << k << " is : " << sumK1(root, k) << endl;
    return 0;
}