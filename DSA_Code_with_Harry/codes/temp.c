#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void display(struct node * head)
{
    struct node * temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

struct node * insertAtHead(struct node * head, int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node)); 
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

void insertAtPos(struct node * head, int data, int pos)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    int count = 0;
    struct node * temp = head;
    while (count != pos - 2)
    {
        count++;
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

int main()
{
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 23;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = NULL;

    printf("Before insertion: \n");
    display(head);

    printf("\nAfter insertion: \n");
    head = insertAtHead(head, 9);
    display(head);

    printf("\nAfter insertion: \n");
    insertAtPos(head, 12, 3);
    display(head);
    return 0;
}