/*
    Inorder traversal using iteration
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

void inOrderRecur(treeNode<int>*root, vector<int> &inO)
{
    if (root == NULL)
    {
        return;
    }

    inOrderRecur(root->left, inO);
    inO.push_back(root->data);
    inOrderRecur(root->right, inO);
}

vector<int> inOrderIter(treeNode<int> *root)
{
    vector<int> inO;
    if (root == NULL)
    {
        return inO;
    }

    stack<treeNode<int> *> st;
    treeNode<int> *node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
    return inO;
}

int main()
{
    // 1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 -1 7 9 -1 -1 10 -1 -1
    treeNode<int> *root = buildTree(root);

    vector<int> inO;

    // Iterative traversal
    inO = inOrderIter(root);

    // Recursive traversal
    // inOrderRecur(root, inO);

    cout << endl << "Inorder traversal : ";
    for (auto it : inO)
    {
        cout << it << " ";
    }
    return 0;
}