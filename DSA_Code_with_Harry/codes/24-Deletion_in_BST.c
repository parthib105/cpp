#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* createnode(int val) 
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
}

struct node* inOrderPredecessor(struct node* root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node* deletion(struct node* root, int val)
{
    struct node* iPre;

    // base condititon
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // search for the node to be deleted
    if (val < root->data)
    {
        root->left = deletion(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deletion(root->right, val);
    }
    // deletion strategy
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletion(root->left, iPre->data);
    }
    return root;
}

struct node* DELETE(struct node* root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    
    struct node* temp = root;
    struct node* prev = NULL;
    while (temp != NULL)
    {
        prev = temp;

        if (temp->data == val)
        {
            break;
        }
        if (val > temp->data)
        {
            temp = temp->right;
        }
        else if (val < temp->data)
        {
            temp = temp->left;
        }
    }

    if (temp->left == NULL && temp->right == NULL)
    {
        if (prev->right == temp)
        {
            prev->right = NULL;
        }
        if (prev->left == temp)
        {
            prev->left = NULL;
        }

        free(temp);
    }

    if (temp->left == NULL && temp->right != NULL)
    {
        if (temp->right->data > prev->data)
        {
            prev->right = temp->right;
            temp->right->parent = prev;
        }
        
        if (temp->right->data < prev->data)
        {
            prev->left = temp->right;
            temp->right->parent = prev;
        }
        free(temp);
    }

    if (temp->right == NULL && temp->left != NULL)
    {
        if (temp->left->data < prev->data)
        {
            prev->left = temp->left;
            temp->left->parent = prev;
        }
        else
        {
            prev->right = temp->left;
            temp->left->parent = prev;
        }
        free(temp);
    }

    if (temp->left != NULL && temp->right != NULL)
    {
        struct node* inPre = inOrderPredecessor(temp);
        temp->data = inPre->data;
        free(inPre);
    }
    return root;
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
    // node construction
    struct node* p = createnode(8);
    struct node* p1 = createnode(3);
    struct node* p2 = createnode(10);
    struct node* p3 = createnode(1);
    struct node* p4 = createnode(6);
    struct node* p5 = createnode(4);
    struct node* p6 = createnode(7);
    struct node* p7 = createnode(14);
    struct node* p8 = createnode(13);

    // linking nodes
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p4->left = p5;
    p4->right = p6;
    p2->right = p7;
    p7->left = p8;

    inOrder(p);

    struct node* root = deletion(p, 6);
    printf("\nAfter deleting\n");
    inOrder(root);

    return 0;
}