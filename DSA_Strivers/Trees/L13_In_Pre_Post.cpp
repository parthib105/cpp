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

void inPrePostOrder(treeNode<int> *root, vector<int> &ino, vector<int> &pre, vector<int>& post)
{
    if (root == NULL)
    {
        return;
    }

    stack<pair<treeNode<int>*, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        treeNode<int> *node = st.top().first;
        int flag = st.top().second;
        st.pop();

        if (flag == 1)
        {
            pre.push_back(node->data);
            flag += 1;
            st.push({node, flag});

            if (node->left != NULL)
            {
                st.push({node->left, 1});
            }
        }
        else if (flag == 2)
        {
            ino.push_back(node->data);
            flag += 1;
            st.push({node, flag});

            if (node->right != NULL)
            {
                st.push({node->right, 1});
            }
        }
        else
        {
            post.push_back(node->data);
        }
    }
}

int main()
{
    // 1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 -1 7 9 -1 -1 10 -1 -1
    treeNode<int> *root = buildTree(root);

    vector<int> ino, pre, post;
    inPrePostOrder(root, ino, pre, post);

    cout << endl << "Pre-order : ";
    for (int node : pre)
    {
        cout << node << " ";
    }
    cout << endl;

    cout << endl << "In-order : ";
    for (int node : ino)
    {
        cout << node << " ";
    }
    cout << endl;

    cout << endl << "Post-order : ";
    for (int node : post)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}