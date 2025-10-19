/*
    Bottom View of Binary Tree

    Given a binary tree, print the bottom view from left to right.
    A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \
                  10    14

    For the above tree, the bottom view is 5 10 3 14 25.
    If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal.
    For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \
                 10       14

    For the above tree the output should be 5 10 4 14 25.

    Note: The Input/Output format and Example given are used for the system's internal purpose, and should be used by a user
    for Expected Output only. As it is a function problem, hence a user should not read any input from the stdin/console.
    The task is to complete the function specified, and not to write the full code.
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

vector<int> bottomView(treeNode<int>* root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    // map <horizontal dist., node->data>
    map<int, int> botNode;

    // queue <pair<Node*, hd>>
    queue<pair<treeNode<int>*, int>> q;

    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<treeNode<int>*, int> curr = q.front();
        q.pop();

        treeNode<int>* frontNode = curr.first;
        int hd = curr.second;

        // update value at each horizontal distance
        botNode[hd] = frontNode->data;

        // push into queue
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    map<int, int>::iterator it = botNode.begin();
    while (it != botNode.end())
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
    vector<int> ans = bottomView(root);
    cout << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}