/*
    ZigZag Tree Traversal

    Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

    In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for
    even-numbered levels.

    Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7

    Output:
    1 3 2 4 5 6 7
    Explanation:
    For level 1 going left to right, we get traversal as {1}.
    For level 2 going right to left, we get traversal as {3,2}.
    For level 3 going left to right, we get traversal as {4,5,6,7}.
    Merging  all this traversals in single array we get {1,3,2,4,5,6,7}
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

void buildTreeFromLevelOrder(treeNode<int> *&root)
{
    queue<treeNode<int> *> q;
    int rootData;
    cout << "Enter data for root : ";
    cin >> rootData;

    root = new treeNode<int>(rootData);
    q.push(root);

    while (!q.empty())
    {
        treeNode<int> *curr = q.front();
        q.pop();

        int leftData;
        cout << "Enter left node for " << curr->data << " : ";
        cin >> leftData;

        if (leftData != -1)
        {
            curr->left = new treeNode<int>(leftData);
            q.push(curr->left);
        }

        int rightData;
        cout << "Enter left node for " << curr->data << " : ";
        cin >> rightData;

        if (rightData != -1)
        {
            curr->right = new treeNode<int>(rightData);
            q.push(curr->right);
        }
    }
}

vector<int> zigZagTraversal(treeNode<int>* root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<treeNode<int>*> q;
    q.push(root);
    bool LeftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            treeNode<int>* curr = q.front();
            q.pop();

            int idx = LeftToRight ? i : size - i - 1;
            temp[idx] = curr->data;

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }

        // change direction
        LeftToRight = !LeftToRight;

        for (int i = 0; i < size; i++)
        {
            ans.push_back(temp[i]);
        }
    }

    return ans;
}

int main()
{
    treeNode<int>* root = NULL;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    buildTreeFromLevelOrder(root);
    cout << endl;
    vector<int> ans = zigZagTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}