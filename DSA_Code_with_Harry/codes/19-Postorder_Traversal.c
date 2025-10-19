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

void postOrder(struct node* root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            printf("[");
            postOrder(root->left);
            printf("]");
        }
        
        if (root->right != NULL)
        {
            printf("[");
            postOrder(root->right);
            printf("]");
        }
        printf("%d", root->data);
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

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Format of printing => [left] [right] root\n");
    postOrder(p);
    return 0;
}