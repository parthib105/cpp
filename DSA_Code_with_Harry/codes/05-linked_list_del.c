#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next; 
};

void LinkedListTraversal(struct node * ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

// case 1: deleting the first element from the linked list
struct node * deleteFirst(struct node * head)
{
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node * deletionAtIndex(struct node * head, int index)
{
    struct node * ptr;
    int count = 0;
    struct node * temp = head;
    while (count != index - 1)
    {
        temp = temp->next;
        count ++;
    }
    ptr = temp->next;
    temp->next = temp->next->next;
    free(ptr);
    return head;
}

struct node * deleteAtLast(struct node * head)
{
    struct node * p = head;
    struct node * q = head->next;
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;
    struct node * fifth;

    // allocate memeory for nodes in the linked list in heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    // link first and second nodes
    head->data = 4;
    head->next = second;

    // link second and third nodes
    second->data = 3;
    second->next = third;

    // link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // link fourth and fifth nodes
    fourth->data = 9;
    fourth->next = fifth;

    // terminate the list at the fifth node
    fifth->data = 1;
    fifth->next = NULL;

    // without inseriton
    printf("Original Linkedlist: \n");
    LinkedListTraversal(head);
    puts("");

    // after deleting first node
    printf("After deletion:\n");
    struct node * newhead1 = deleteFirst(head);
    LinkedListTraversal(newhead1);
    puts("");

    // after deleting node at the index = 2  
    printf("After deletion:\n");
    struct node * newhead2 = deletionAtIndex(newhead1, 2);
    LinkedListTraversal(newhead2);
    puts("");

    // after deleting node at the last  
    printf("After deletion:\n");
    struct node * newhead3 = deleteAtLast(newhead1);
    LinkedListTraversal(newhead3);
    puts("");

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
    return 0;
}