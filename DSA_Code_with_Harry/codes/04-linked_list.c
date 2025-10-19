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
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node * insertAtFirst(struct node *  head, int val)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = head;
    return ptr;
}

struct node * insertAtIndex(struct node * head, int val, int index)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * temp = head;
    int count = 1;
    while (count != index)
    {
        temp = temp->next;
        count ++;
    }
    ptr->data = val;
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}

struct node * insertAtEnd(struct node * head, int val)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    ptr->data = val;
    temp->next = ptr;
    ptr->next = NULL;
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
    head->data = 7;
    head->next = second;

    // link second and third nodes
    second->data = 11;
    second->next = third;

    // link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    // without inseriton
    printf("Before insertion: \n");
    LinkedListTraversal(head);
    puts("");

    // After insertion at head
    printf("After insertion: \n");
    struct node * newhead1 = insertAtFirst(head, 56);
    LinkedListTraversal(newhead1);
    puts("");

    // After insertion at index = 1
    printf("After insertion: \n");
    struct node * newhead2 = insertAtIndex(head, 46, 1);
    LinkedListTraversal(newhead2);
    puts("");

    // After insertion at end
    printf("After insertion: \n");
    struct node * newhead3 = insertAtEnd(head, 76);
    LinkedListTraversal(newhead3);
    puts("");

    // After deletion
    printf("After deletion: \n");
    struct node * newhead4 = deletion(head, 5);
    LinkedListTraversal(newhead4);
    puts("");

    free(head);
    free(second);
    free(third);
    free(fourth);
    return 0;
}