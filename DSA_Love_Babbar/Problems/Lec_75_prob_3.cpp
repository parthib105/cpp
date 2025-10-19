/*
    Merge two binary Max heaps

    Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

    Input  :
    n = 4 m = 3
    a[] = {10, 5, 6, 2},
    b[] = {12, 7, 9}
    Output :
    {12, 10, 9, 2, 5, 7, 6}
    Explanation :

                        10                    12
                       /  \                  /  \
                      5    6                7    9
                     /
                    2


                                   12
                                 /    \
                                10     9
                               /  \   / \
                              2    5 7   6

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

void buildTreeFromLevelOrder(treeNode<int>* &root, vector<int> levelOrder)
{
    queue<treeNode<int>*> q;

    root = new treeNode<int>(levelOrder[0]);
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrder.size())
    {
        treeNode<int> *curr = q.front();
        q.pop();

        int leftData = levelOrder[i++];
        if (leftData != -1)
        {
            curr->left = new treeNode<int>(leftData);
            q.push(curr->left);
        }

        int rightData = levelOrder[i++];
        if (rightData != -1)
        {
            curr->right = new treeNode<int>(rightData);
            q.push(curr->right);
        }
    }
}

void inOrder(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void levelOrderTraversal(treeNode<int> *root)
{
    queue<treeNode<int> *> q;
    q.push(root);
    q.push(NULL); // separator

    while (!q.empty())
    {
        treeNode<int> *frontNode = q.front();
        q.pop();

        // add the separator
        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
    }
}

// function to count no. of nodes
int countNode(treeNode<int>* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return (1 + countNode(root->left) + countNode(root->right));
}

// function to check if the binary tree is a complete binary tree
bool isCBT(treeNode<int>* root, int idx, int nodeCount)
{
    if (root == NULL)
    {
        return true;
    }
    if (idx >= nodeCount)
    {
        return false;
    }

    bool leftAns = isCBT(root->left, 2 * idx + 1, nodeCount);
    bool rightAns = isCBT(root->right, 2 * idx + 2, nodeCount);
    return (leftAns && rightAns);
}

// function to check if complete binary tree follows max order
bool isMaxOrder(treeNode<int>* root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }

    bool ans1 = root->data > root->left->data;
    bool ans2 = root->data > root->right->data;
    if (ans1 && ans2 && isMaxOrder(root->left) && isMaxOrder(root->right))
    {
        return true;
    }
    return false;
}

bool isHeap(treeNode<int>* tree) 
{
    // code here
    int idx = 0;
    int nodeCount = countNode(tree);
    
    if (isCBT(tree, idx, nodeCount) && isMaxOrder(tree))
    {
        return true;
    }
    return false;
}

// using 0-based indexing
void heapify(vector<int> &arr, int idx, int n)
{
    int p = idx;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;

    if (lc < n && arr[lc] > arr[p])
    {
        p = lc;
    }
    if (rc < n && arr[rc] > arr[p])
    {
        p = rc;
    }

    if (p != idx)
    {
        swap(arr[p], arr[idx]);
        heapify(arr, p, n);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;

    // merge both arrays
    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }

    // Heapify
    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(ans, i, ans.size());
    }

    return ans;
}

int main()
{
    int n = 4, m = 3;
    vector<int> a = {10, 5, 6, 2}; 
    vector<int> b = {12, 7, 9};

    vector<int> mergedHeap = mergeHeaps(a, b, n, m);

    for (int i = 0; i < mergedHeap.size(); i++)
    {
        cout << mergedHeap[i] << " ";
    }
    cout << endl;

    treeNode<int>* root;
    buildTreeFromLevelOrder(root, mergedHeap);

    cout << endl << isHeap(root) << endl << endl;

    levelOrderTraversal(root);
    return 0;
}