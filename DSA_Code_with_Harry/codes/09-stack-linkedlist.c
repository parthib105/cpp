#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

int isEmpty(struct node * top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct node * top)
{
    struct node * p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

struct node * push(struct node * top, int data)
{
    if (isFull(top))
    {
        printf("Stack underflow\n");
    }
    else
    {
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = top;
        top = newnode;
        return top;
    }
}

int pop(struct node ** top)
{
    if (isEmpty(*top))
    {
        return 0;
    }
    else
    {
        struct node * newnode = *top;
        *top = (*top)->next;
        int x = newnode->data;
        free(newnode);
        return x;
    }
}

int peek(struct node ** top, int pos)
{
    struct node * ptr = * top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    return -1;
    
}

void linkedlistTraversal(struct node * ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main()
{
    struct node * top = NULL;
    top = push(top, 28);
    top = push(top, 18);
    top = push(top, 15);
    top = push(top, 7);
    printf("Linked list is:\n");
    linkedlistTraversal(top);
    puts("");

    // printf("\nPopped element is: %d\n", pop(&top));
    // linkedlistTraversal(top);

    // printf("\nValue of position 1 is %d\n", peek(&top, 1));
    for (int i = 1; i <= 4; i++)
    {
        printf("value at position %d is : %d\n", i, peek(&top, i));
    }
    
    return 0;
}