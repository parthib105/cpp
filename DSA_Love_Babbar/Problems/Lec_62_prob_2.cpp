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

int main()
{
    treeNode<int>* root = NULL;
    
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    buildTreeFromLevelOrder(root);
    cout << endl;
    levelOrderTraversal(root);
    return 0;
}