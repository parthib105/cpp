/*
    Flatten Binary Tree to Linked List

    Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.
    

    Example 1:

    Input: root = [1,2,5,3,4,null,6]
    Output: [1,null,2,null,3,null,4,null,5,null,6]
    Example 2:

    Input: root = []
    Output: []
    Example 3:

    Input: root = [0]
    Output: [0]
    

    Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100
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
    TreeNode<int>* nextRight;

    // T.C. : O(N), S.C. : O(N)
    void flattenRecur(TreeNode<int>* root) 
    {
        if(!root)
            return;
        
        //call the right subtree
        flattenRecur(root->right);

        //calling the left subtree
        flattenRecur(root->left);

        //make left point to null 
        root->left = NULL;
        //make the right point to the head of existing list that is nextright
        root->right = nextRight;
        //update the next right value for every new node added
        nextRight=root;
    }

    // T.C. : O(N), S.C. : O(N)
    void flattenIter(TreeNode<int>* root)
    {
        if (!root)
            return;

        stack<TreeNode<int>*> st;

        st.push(root);
        while (!st.empty())
        {
            TreeNode<int>* curr = st.top();
            st.pop();

            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);

            if (!st.empty())
                curr->right = st.top();
            curr->left = nullptr;
        }
    }
public:
    void flatten(TreeNode<int>* root) 
    {
        // using recursion
        // this->nextRight = nullptr;
        // flattenRecur(root);

        // Using stack
        flattenIter(root);
    }
};

int main()
{
    vector<int> lo = {1, 5, 3, -1, 4, 10, 6, 9, 2};
    TreeNode<int>* root = buildTree(lo);

    Solution sol;
    sol.flatten(root);

    printLevelOrder(root);
    return 0;
}