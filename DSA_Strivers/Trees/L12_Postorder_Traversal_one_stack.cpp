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

    treeNode<int> *curr = root;
    stack<treeNode<int>*> st;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            treeNode<int> *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                post.push_back(temp->data);

                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return post;
}

int main()
{
    // 1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 -1 7 9 -1 -1 10 -1 -1
    treeNode<int> *root = buildTree(root);

    vector<int> postIter, postRecur;

    // Iterative traversal
    postIter = postOrderIter(root);

    // Recursive traversal
    postOrderRecur(root, postRecur);

    cout << endl << "Postorder traversal (Iterative) : ";
    for (auto it : postIter)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << endl << "Postorder traversal (Recursive) : ";
    for (auto it : postRecur)
    {
        cout << it << " ";
    }
    return 0;
}