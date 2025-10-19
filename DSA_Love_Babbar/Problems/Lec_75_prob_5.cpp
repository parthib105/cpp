/*
    BST to max heap

    Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left 
    subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the 
    nodes in the so converted Max Heap.

    Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7  

    Output : 1 2 3 4 5 6 7 
    Exaplanation :
                  7
                /   \
               3     6
              / \   / \
             1   2 4   5
    The given BST has been transformed into a
    Max Heap and it's postorder traversal is
    1 2 3 4 5 6 7.
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

treeNode<int>* insertInBSTrecur(treeNode<int>* root, int val)
{
    // create a node with the given value
    treeNode<int>* node = new treeNode<int>(val);

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

void takeInput(treeNode<int>* &root)
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

void preOrder(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
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

void postOrder(treeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// To convert BST to MaxOrder Heap
void getInorder(treeNode<int>* root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    getInorder(root->left, arr);
    arr.push_back(root->data);
    getInorder(root->right, arr);
}

void _toMaxHeap(treeNode<int>* root, vector<int> &arr, int &idx)
{
    if (root == NULL)
    {
        return;
    }

    _toMaxHeap(root->left, arr, idx);
    _toMaxHeap(root->right, arr, idx);
    root->data = arr[idx++];
}

void convertToMaxHeapUtil(treeNode<int>* root)
{
    vector<int> inorder;
    int idx = 0;
    getInorder(root, inorder);
    _toMaxHeap(root, inorder, idx);
}

// To convert BST to MinOrder Heap
void _toMinHeap(treeNode<int>* root, vector<int> &arr, int &idx)
{
    if (root == NULL)
    {
        return;
    }

    root->data = arr[idx++];
    _toMinHeap(root->left, arr, idx);
    _toMinHeap(root->right, arr, idx);
}

void convertToMinHeapUtil(treeNode<int>* root)
{
    vector<int> inorder;
    int idx = 0;
    getInorder(root, inorder);
    _toMinHeap(root, inorder, idx);
}


int main()
{
    // 5 1 2 4 7 3 10 11 6 9 8 -1
    treeNode<int> *root = NULL;
    takeInput(root);

    cout << endl << "Inorder traversal of the tree : " << endl;
    inOrder(root);
    cout << endl;

    // BST to maxHeap : postorder will be a sorted array
    // convertToMaxHeapUtil(root);
    // cout << "After converting into maxHeap : " << endl;
    // postOrder(root);
    // cout << endl;

    // BST to minHeap : preorder will be a sorted array
    convertToMinHeapUtil(root);
    cout << "After converting into minHeap : " << endl;
    preOrder(root);
    return 0;
}