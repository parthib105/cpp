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

void insert(struct node* root, int key)
{
    struct node* prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Already present in the tree, can't insert\n");
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct node* new = createnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

void inOrder(struct node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    // constructing the root node
    struct node* p = createnode(6);
    struct node* p1 = createnode(1);
    struct node* p2 = createnode(7);
    struct node* p3 = createnode(0);
    struct node* p4 = createnode(4);
    struct node* p5 = createnode(8);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    printf("Before insertion\n");
    inOrder(p);

    insert(p, 2);
    printf("\nAfter insertion\n");
    inOrder(p);

    insert(p, 10);
    printf("\nAfter insertion\n");
    inOrder(p);
    return 0;
}