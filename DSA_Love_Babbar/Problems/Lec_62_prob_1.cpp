#include<bits/stdc++.h>
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

treeNode<int>* buildTree(treeNode<int>* root)
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

// reverse level order traversal
void reverseLevelOrder(treeNode<int>* root)
{
    queue<treeNode<int>*> q;
    stack<treeNode<int>*> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        treeNode<int>* curr = q.front();
        s.push(curr);
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }

    while (!s.empty())
    {
        treeNode<int>* curr = s.top();
        s.pop();

        if (curr == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << curr->data << " ";
        }
    }
    
}

int main()
{
    treeNode<int>* root = NULL;
    root = buildTree(root);

    // tree : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Level order traversal : " << endl;
    reverseLevelOrder(root);
    return 0;
}