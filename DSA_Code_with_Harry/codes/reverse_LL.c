#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void insert(struct node ** head, int val)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;

    if (*head == NULL)
    {
        *head = n;
    }
    else
    {
        struct node * temp = * head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void display(struct node * head)
{
    struct node * temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node * reverseLL(struct node * head)
{
    struct node * prevPtr = NULL;
    struct node * currPtr = head;
    struct node * nextPtr;

    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

int main()
{
    struct node * head = NULL;
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 1);
    insert(&head, 5);
    insert(&head, 9);
    insert(&head, 2);
    printf("Original linkedlist:\n");
    display(head);
    struct node * newhead = reverseLL(head);
    printf("After reverse:\n");
    display(newhead);
    return 0;
}