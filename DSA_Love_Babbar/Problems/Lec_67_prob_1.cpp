/*
    Burning Tree

    Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the
    target is set on fire. It is known that in 1 second all nodes connected to a given node get burned.
    That is its left child, right child, and parent.
    Note: The tree contains unique values.

    Input:
          1
        /   \
       2     3
      / \     \
     4   5     6
        / \     \
       7   8     9
                  \
                  10
    Target Node = 8
    Output: 7
    Explanation: If leaf with the value
    8 is set on fire.
    After 1 sec: 5 is set on fire.
    After 2 sec: 2, 7 are set to fire.
    After 3 sec: 4, 1 are set to fire.
    After 4 sec: 3 is set to fire.
    After 5 sec: 6 is set to fire.
    After 6 sec: 9 is set to fire.
    After 7 sec: 10 is set to fire.
    It takes 7s to burn the complete tree.
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

// create mapping
// return target node
treeNode<int> *createParentMapping(treeNode<int> *root, int target, map<treeNode<int> *, treeNode<int> *> &nodeToParent)
{
    // Node to point target element
    treeNode<int> *res = NULL;

    // queue to traverse level wise
    queue<treeNode<int> *> q;

    // push root
    q.push(root);

    // parent of root = NULL
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        // front node
        treeNode<int> *curr = q.front();
        q.pop();

        // identify target node
        if (curr->data == target)
        {
            res = curr;
        }

        // store parent and continue
        if (curr->left != NULL)
        {
            nodeToParent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            nodeToParent[curr->right] = curr;
            q.push(curr->right);
        }
    }
    return res;
}

void burnTree(treeNode<int> *root, map<treeNode<int> *, treeNode<int> *> &nodeToParent, int &ans)
{
    // map to store visited nodes
    map<treeNode<int> *, bool> visited;
    queue<treeNode<int> *> q;

    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        bool incSize = false;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            treeNode<int> *curr = q.front();
            q.pop();

            // check left
            if (curr->left && !visited[curr->left])
            {
                incSize = true;
                q.push(curr->left);
                visited[curr->left] = true;
            }
            // check right
            if (curr->right && !visited[curr->right])
            {
                incSize = true;
                q.push(curr->right);
                visited[curr->right] = true;
            }
            // check parent
            if (nodeToParent[curr] && !visited[nodeToParent[curr]])
            {
                incSize = true;
                q.push(nodeToParent[curr]);
                visited[nodeToParent[curr]] = true;
            }
        }

        if (incSize)
        {
            ans += 1;
        }
    }
}

int minTime(treeNode<int>* root, int target)
{
    // Algorithm
    // step 1 : Create nodeToParent mapping
    // step 2 : Find target node
    // step 3 : burn the tree in min time
    map<treeNode<int>*, treeNode<int>*> nodeToParent;
    int ans = 0;
    treeNode<int>* res = createParentMapping(root, target, nodeToParent);
    burnTree(res, nodeToParent, ans);
    return ans;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int> *root;
    root = buildTree(root);

    cout << endl << "Minimum time to burn the tree : " << minTime(root, 10) << endl;
    return 0;
}