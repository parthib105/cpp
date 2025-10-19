/*
    Top View of Binary Tree

    Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of
    nodes visible when the tree is viewed from the top. For the given below tree

        1
     /    \
    2      3
   / \    / \
  4   5  6   7

    Top view will be: 4 2 1 3 7
    Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at
    same position then consider the left ones only(i.e. leftmost).

    For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9
    will get shadowed.
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

vector<int> topView(treeNode<int>* root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // map <horizontal dist, node->data>
    map<int, int> topNode;

    // queue <pair<node*, hd>>
    queue<pair<treeNode<int>*, int>> q;

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<treeNode<int>*, int> curr = q.front();
        q.pop();

        treeNode<int>* frontNode = curr.first;
        int hd = curr.second;

        if (topNode.count(hd) == 0) // topNode.find(hd) == topNode.end()
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    map<int, int>::iterator it = topNode.begin();
    while (it != topNode.end())
    {
        ans.push_back(it->second);
        it++;
    }
    return ans;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int>* root;
    root = buildTree(root);
    vector<int> ans = topView(root);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}