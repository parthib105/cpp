#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void LinkedListTraversal(struct node * head)
{
    struct node * ptr = head;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
    printf("%d", head->data);
}

struct node * InsertAtFirst(struct node * head, int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node * temp = head->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}


int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    // allocate memeory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // link first and second nodes
    head->data = 4;
    head->next = second;

    // link second and third nodes
    second->data = 3;
    second->next = third;

    // link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;

    printf("Original List:\n");
    LinkedListTraversal(head);
    puts("");

    printf("After insertion:\n");
    LinkedListTraversal(InsertAtFirst(head, 80));
    puts("");
    return 0;
}