#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int getHeight(struct node* n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int getBalancedFactor(struct node* n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

struct node* createNode(int data)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left == NULL;
    n->right == NULL;
    n->height = 1;

    return n;
}

struct node* rightRotate(struct node* y)
{
    struct node* x = y->left;
    struct node* T2 = x->right;
    x->right = y;
    y->left = T2;

    // updating heights
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y = x->right;
    struct node* T2 = y->left;
    y->left =x ;
    x->right = T2;

    // updating heights
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    return y;
}

struct node* insert(struct node* node, int val)
{
    if (node == NULL)
    {
        return createNode(val);
    }
    if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = insert(node->right, val);
    }
    return node;
    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalancedFactor(node);

    // Left-Left case
    if (bf > 1 && val < node->left->data)
    {
        return rightRotate(node);
    }

    //Right-Right case
    if (bf < -1 && val > node->right->data)
    {
        return leftRotate(node);
    }

    // Left-Right case
    if (bf > 1 && val > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left case
    if (bf < -1 && val < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        if (root->left != NULL)
        {
            printf("[");
            preOrder(root->left);
            printf("]");
        }
        if (root->right != NULL)
        {
            printf("[");
            preOrder(root->right);
            printf("]");
        }
    }
}

int main()
{
    struct node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}