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

struct node* recur_search(struct node* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return recur_search(root->left, key);
    }
    else
    {
        return recur_search(root->right, key);
    }
}

bool iter_search(struct node* root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return true;
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
    return false;
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

    // recursive search

    // struct node* n = recur_search(p, 8);
    // if (n != NULL)
    // {
    //     printf("Element found: %d\n", n->data);
    // }
    // else
    // {
    //     printf("Element not found\n");
    // }

    // iterative search

    struct node* n = iter_search(p, 8);
    if (n != NULL)
    {
        printf("Element found: %d\n", n->data);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}