#include<stdio.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* createnode(int val)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));  
    n->data  = val; 
    n->left = NULL; 
    n->right = NULL; 
    n->height = 1;
    return n; 
}

int searchNode(struct node* root, int val)
{
    struct node* temp = root;
    while (temp != NULL)
    {
        if (val > temp->data)
        {
            temp = temp->right;
        }
        else if (val < temp->data)
        {
            temp = temp->left;
        }
        if (temp->data == val)
        {
            return 1;
        }
    }
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int TreeHeight(struct node* root)
{
    if (root == NULL)
    {
        return -1;
    }
    return (1 + max(TreeHeight(root->left), TreeHeight(root->right)));
}

// inserting elements 
struct node* insert(void)
{
    int elm;
    struct node* newnode;
    printf("Enter the node of the tree(-1 for no element): ");
    scanf("%d", &elm);

    if (elm == -1)
    {
        return NULL;
    }

    newnode = createnode(elm);

    printf("Enter the left child of %d\n", elm);
    newnode->left = insert();

    printf("Enter the right child of %d\n", elm);
    newnode->right = insert();
}

//inorder traversal
void inOrder(struct node* root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            printf("[ ");
            inOrder(root->left);
            printf(" ]");
        }
        printf("%d", root->data);
        if (root->right != NULL)
        {
            printf("[ ");
            inOrder(root->right);
            printf(" ]");
        }
    }
}

int main()
{
    // constructting nodes using function    

    // struct node* p = createnode(2);
    // struct node* p1 = createnode(1);
    // struct node* p2 = createnode(4);
    // struct node* p3 = createnode(5);
    
    // p->left = p1;
    // p->right = p2;
    // p2->right = p3;

    // printf("%d\n", TreeHeight(p));

    struct node* root = insert();
    inOrder(root);

    return 0;
}