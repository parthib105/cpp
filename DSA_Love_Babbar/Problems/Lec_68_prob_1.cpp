/*
    Flatten binary tree to linked list

    Given the root of a binary tree, flatten the tree into a "lLinked list":

    ->  The "linked list" should use the same Node class where the right child pointer points to the next node in the list and
        the left child pointer is always null.
    ->  The "linked list" should be in the same order as a pre-order traversal of the binary tree.

    Input :
          1
        /   \
       2     5
      / \     \
     3   4     6
    Output :
    1 2 3 4 5 6
    Explanation:
    After flattening, the tree looks
    like this
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
    Here, left of each node points
    to NULL and right contains the
    next node in preorder.The inorder
    traversal of this flattened tree
    is 1 2 3 4 5 6.
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

void flatten(treeNode<int>* &root)
{
    treeNode<int>* curr = root;
    treeNode<int>* pre;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            pre = curr->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }

            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void printFlatten(treeNode<int>* root)
{
    treeNode<int>* curr = root;
    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        curr = curr->right;
    }
    cout << "NULL" << endl;
}

int main()
{
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 10 11 -1 -1 -1 6 9 8 -1 -1 -1 -1
    treeNode<int> *root;
    root = buildTree(root);
    flatten(root);
    cout << "Flattened tree : " << endl;
    printFlatten(root);
    return 0;
}