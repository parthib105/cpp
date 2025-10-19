/*
    Merge Two BSTs

    You are given two binary search trees of integers having ‘N’ and ‘M’ nodes. Return an array that contains elements of
    both BST in sorted order.

    A binary search tree (BST) is a binary tree data structure with the following properties.

    • The left subtree of a node contains only nodes with data less than the node’s data.
    • The right subtree of a node contains only nodes with data greater than the node’s data.
    • Both the left and right subtrees must also be binary search trees.
*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class treeNode
{
public:
    T data;
    treeNode<T> *left;
    treeNode<T> *right;

    treeNode(T val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

    ~treeNode()
    {
        if (this->left)
        {
            this->left = NULL;
        }
        if (this->right)
        {
            this->right = NULL;
        }
    }
};

// recursive solution
treeNode<int> *insertInBSTrecur(treeNode<int> *root, int val)
{
    // create a node with the given value
    treeNode<int> *node = new treeNode<int>(val);

    // if root is NULL
    if (root == NULL)
    {
        return node;
    }

    // if root is not NULL
    if (val < root->data)
    {
        root->left = insertInBSTrecur(root->left, val);
    }
    else
    {
        root->right = insertInBSTrecur(root->right, val);
    }

    return root;
}

void takeInput(treeNode<int> *&root)
{
    cout << "Enter strem of data to construct BST, (-1 to end stream) : " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBSTrecur(root, data);
        cin >> data;
    }
}

void inOrder(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

/******************** Approach 2 : T.C. O(m + n)  S.C. O(m + n) ********************/

/***********************************************************************************/


/******************** Approach 2 : T.C. O(m + n)  S.C. O(h1 + h2) ********************/

// function to convert BST to DLL
void BST_to_DLL(treeNode<int>* root, treeNode<int>* &head)
{
    if (root == NULL)
    {
        return;
    }

    // call for right subtree
    BST_to_DLL(root->right, head);

    // change links
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    // call for left subtree
    BST_to_DLL(root->left, head);
}

// function to merge two doubly linked list
treeNode<int>* merge_DLLs(treeNode<int>* head1, treeNode<int>* head2)
{
    treeNode<int>* prev = head1;
    treeNode<int>* curr = head1->right;
    treeNode<int>* temp = head2;
    treeNode<int>* newHead = head1;

    if (head2->data < head1->data)
    {
        prev = head2;
        curr = head2->right;
        temp = head1;
        newHead = head2;
    }

    while (curr != NULL && temp != NULL)
    {
        if (temp->data >= prev->data && temp->data <= curr->data)
        {
            treeNode<int>* tempNext = temp->right;
            prev->right = temp;
            temp->left = prev;
            temp->right = curr;
            curr->left = temp;

            prev = temp;
            temp = tempNext;
        }
        else
        {
            prev = curr;
            curr = curr->right;
        }
    }

    if (curr == NULL)
    {
        prev->right = temp;
        temp->left = prev;
    }

    return newHead;
}

// function to calculate length
int getLength(treeNode<int>* head)
{
    if (head == NULL)
    {
        return 0;
    }
    return (getLength(head->right) + 1);
}

// make BST from sorted list
treeNode<int>* sortedLL_to_BST(treeNode<int>* &head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    treeNode<int>* leftSub = sortedLL_to_BST(head, n/2);

    treeNode<int>* root = head;
    root->left = leftSub;
    head = head->right;

    root->right = sortedLL_to_BST(head, n - (n/2) - 1);

    return root;
}

treeNode<int>* mergeBST(treeNode<int>* root1, treeNode<int>* root2)
{
    // step 1 :  convert BST to DLL
    treeNode<int>* head1 = NULL;
    BST_to_DLL(root1, head1);
    head1->left = NULL;

    treeNode<int>* head2 = NULL;
    BST_to_DLL(root2, head2);
    head2->left = NULL;

    // step 2 : Merge two sorted DLLS
    treeNode<int>* head = merge_DLLs(head1, head2);

    // step 3 : DLL to BST
    return sortedLL_to_BST(head, getLength(head));
}

/*************************************************************************************/

int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    // 16 14 12 15 23 17 -1
    treeNode<int>* root1 = NULL;
    treeNode<int>* root2 = NULL;
    takeInput(root1);
    takeInput(root2);

    treeNode<int>* newRoot = mergeBST(root1, root2);

    cout << endl << "Inorder Traversal : " << endl;
    inOrder(newRoot);
    cout << endl;

    return 0;
}