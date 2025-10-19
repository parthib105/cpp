#include<stdio.h>
#include<stdlib.h>

static int top = -1;

struct node
{
    int data;
    struct node * next;
};

int isFull(int size)
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct node ** ptr, int data, int size)
{
    if (isFull(size))
    {
        printf("Stack overflow! Can't add %d to the stack\n", data);
    }
    else
    {
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;

        if (*ptr == NULL)
        {
            *ptr = newnode;
            top ++;
        }
        else
        {
            struct node * temp = *ptr;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            top ++;
        }
    }
}

int pop(struct node ** ptr)
{
    if (isEmpty())
    {
        printf("Stack underflow! Can't pop element\n");
    }
    else
    {
        struct node * p = (struct node *)malloc(sizeof(struct node));
        struct node * temp = *ptr;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        p = temp->next;
        temp->next = NULL;
        free(p);
        top --;
    }
}

int peek(struct node ** ptr, int pos)
{
    int i = 0;
    struct node * temp = *ptr;
    while(i != pos - 1)
    {
        temp = temp->next;
        i++;
    }
    return temp->data;
}

void display(struct node ** head)
{
    struct node * temp = *head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node * head = NULL;
    printf("Implementing Stacks:\n");
    push(&head, 4, 5);
    push(&head, 3, 5);
    push(&head, 6, 5);
    push(&head, 5, 5);
    push(&head, 1, 5);
    printf("Printing Stacks:\n");
    display(&head);

    printf("\n%d\n", peek(&head, 3));

    // printf("\nAfter popping:\n");
    // pop(&head);
    // display(&head);
    
    return 0;
}