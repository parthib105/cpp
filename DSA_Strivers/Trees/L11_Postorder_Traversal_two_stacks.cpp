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

void postOrderRecur(treeNode<int> *root, vector<int>& post)
{
    if (root == NULL)
    {
        return;
    }

    postOrderRecur(root->left, post);
    postOrderRecur(root->right, post);
    post.push_back(root->data);
}

vector<int> postOrderIter(treeNode<int> *root)
{
    vector<int> post;
    if (root == NULL)
    {
        return post;
    }

    stack<treeNode<int>*> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();

        st2.push(root);
        if (root->left)
        {
            st1.push(root->left);
        }
        if (root->right)
        {
            st1.push(root->right);
        }
    }

    while (!st2.empty())
    {
        post.push_back(st2.top()->data);
        st2.pop();
    }
    return post;
}

int main()
{
    // 1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 -1 7 9 -1 -1 10 -1 -1
    treeNode<int> *root = buildTree(root);

    vector<int> post;

    // Iterative traversal
    // post = postOrderIter(root);

    // Recursive traversal
    postOrderRecur(root, post);

    cout << endl << "Postorder traversal : ";
    for (auto it : post)
    {
        cout << it << " ";
    }
    return 0;
}