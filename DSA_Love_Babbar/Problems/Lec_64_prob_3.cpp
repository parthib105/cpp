/*
    Vertical Traversal of Binary Tree

    Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.

    If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order
    traversal of the tree.

    Example 1 :

    Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
             \      \
              8      9
    Output:
    4 2 1 5 6 3 8 7 9
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

vector<int> verticalOrder(treeNode<int>* root)
{
    // map <horizontal dist, map <level, data>>>
    map<int, map<int, vector<int>>> nodes;

    // queue < pair< Node*, map<hd, lvl>>>
    queue<pair<treeNode<int>*, pair<int, int>>> q;

    // vector to store ans
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<treeNode<int>*, pair<int, int>> curr = q.front();
        q.pop();

        // extract values
        treeNode<int>* fNode = curr.first;
        int hd = curr.second.first;
        int lvl = curr.second.second;

        // store into map
        nodes[hd][lvl].push_back(fNode->data);

        if (fNode->left)
        {
            treeNode<int>* nodeToInsert = fNode->left;
            pair<int, int> HDLvL = make_pair(hd - 1, lvl + 1);
            q.push(make_pair(nodeToInsert, HDLvL));
        }
        if (fNode->right)
        {
            treeNode<int>* nodeToInsert = fNode->right;
            pair<int, int> HDLvL = make_pair(hd + 1, lvl + 1);
            q.push(make_pair(nodeToInsert, HDLvL));
        }
    }

    for (auto hd : nodes)
    {
        for (auto lvl : hd.second)
        {
            for (auto i : lvl.second)
            {
                ans.push_back(i);
            }
        }
    }

    return ans;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int>* root;
    root = buildTree(root);
    vector<int> ans = verticalOrder(root);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}