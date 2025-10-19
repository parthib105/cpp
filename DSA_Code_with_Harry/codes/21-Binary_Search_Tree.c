#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int val) 
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
}

void inOrder(struct node* root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            printf("[");
            inOrder(root->left);
            printf("]");
        }
        printf("%d", root->data);
        if (root->right != NULL)
        {
            printf("[");
            inOrder(root->right);
            printf("]");
        }
    }
}

int isBST(struct node* root)
{
    static struct node* prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

bool validBST(struct node* root, struct node* min, struct node* max)
{
    if (root == NULL) // base case
    {
        return true;
    }


    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }  

    bool leftValid = validBST(root->left, min, root);
    bool rightValid = validBST(root->right, root, max);

    return (leftValid && rightValid); 
}

int main()
{
    // constructing the root node
    struct node* p = createnode(4);
    struct node* p1 = createnode(2);
    struct node* p2 = createnode(5);
    struct node* p3 = createnode(0);
    struct node* p4 = createnode(3);
    struct node* p5 = createnode(7);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    // printf("Format of printing => [left] root [right]\n");
    // inOrder(p);

    printf("%d\n", validBST(p, NULL, NULL));
    return 0;
}