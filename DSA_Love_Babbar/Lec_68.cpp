/*
    Morris Traversal
    T.C. O(n), S.C. O(n)

    1.  Initialize current as root 
    2.  While current is not NULL
        If the current does not have left child
            a)  Print current’s data
            b)  Go to the right, i.e., current = current->right
        Else
            a)  Find rightmost node in current left subtree OR node whose right child == current.
                If we found right child == current
                    a) Update the right child as NULL of that node whose right child is current
                    b) Print current’s data
                    c) Go to the right, i.e. current = current->right
                Else
                    a) Make current as the right child of that rightmost node we found; and 
                    b) Go to this left child, i.e., current = current->left
*/

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

void inOrder(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void morrisTraversal(treeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }

    // two pointers curr and pre , pre -> inorder predecessor
    treeNode<int>* curr;
    treeNode<int>* pre;

    // Initialize current as root 
    curr = root;

    while (curr != NULL)
    {
        // If the current does not have left child
        // Print current’s data.
        // Go to the right.
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of curr
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }

            // make curr as the right child of its inorder predecessor
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            /* 
                Revert the changes made in the 'if' part to
                restore the original tree i.e., fix the right
                child of predecessor 
            */
            else
            {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int> *root;
    root = buildTree(root);
    cout << endl << "Morris traversal : " << endl;
    morrisTraversal(root);
    cout << endl;

    cout << endl << "Inorder traversal : " << endl;
    inOrder(root);
    cout << endl;
    return 0;
}