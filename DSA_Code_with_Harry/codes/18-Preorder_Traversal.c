#include<stdio.h>
#include<stdlib.h>

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

void preOrder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d", root->data);

        if (root->left != NULL && root->right == NULL)
        {
            printf("[]");
        }
        if (root->right != NULL && root->left == NULL)
        {
            printf("[]");
        }
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
    // constructing the root node
    struct node* p = createnode(7);
    struct node* p1 = createnode(2);
    struct node* p2 = createnode(1);
    struct node* p3 = createnode(0);
    struct node* p4 = createnode(4);
    struct node* p5 = createnode(5);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;

    printf("Format of printing => root [left] [right]\n");
    preOrder(p);
    return 0;
}