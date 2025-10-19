#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

void insert(struct node ** head, int data)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL)
    {
        newnode->prev = NULL;
        *head = newnode;
    }
    else
    {
        struct node * temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void display(struct node ** head)
{
    struct node * temp = *head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    temp = *head;
    while(temp != NULL)
    {
        printf("%p -> ", temp->prev);
        temp = temp->next;
    }
}

int main()
{
    struct node * head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 7);
    insert(&head, 5);
    insert(&head, 3);
    display(&head);

    return 0;
}