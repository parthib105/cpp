#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    node(int d, node* l)
    {
        this->data = d;
        this->left = l;
        this->right = NULL;
    }

    node(int d, node* l, node* r)
    {
        this->data = d;
        this->left = l;
        this->right = r;
    }
};

node* buildTreeFromLevelOrder(vector<int> lo)
{
    node* root = new node(lo[0]);

    int i = 1;
    queue<node*> q;
    q.push(root);

    while (!q.empty() && i < lo.size())
    {
        node* n = q.front();
        q.pop();

        if (i < lo.size() && lo[i] != -1)
        {
            n->left = new node(lo[i]);
            q.push(n->left);
        }
        else
        {
            n->left = NULL;
        }
        i++;

        if (i < lo.size() && lo[i] != -1)
        {
            n->right = new node(lo[i]);
            q.push(n->right);
        }
        else
        {
            n->right = NULL;
        }
        i++;
    }

    return root;
}

int height(node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

void printInorder(node* root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> lo = {5, 7, 8, 1, 2, 10, 9, 3, 6, -1, -1, -1, 11, -1, -1};
    node* root = buildTreeFromLevelOrder(lo);
    printInorder(root);
    cout << endl << "Height : " << height(root) << endl;
    return 0;
}