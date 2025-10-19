#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}l_node;

typedef struct linked_list
{
    l_node* head;
    l_node* tail;

    // to add a node
    void (*add_node) (l_node**, int);

    // to remove a node
    void (*remove_node) (l_node**, int);

    // display the list
    void (*display_list) (l_node**);
} ll;

// create a linked list node 
l_node* create_node(int val)
{
    l_node* new_node = (l_node*) malloc(sizeof(l_node));
    if (!new_node)
    {
        printf("Memory allocation error\n");
        exit(1);
    }

    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

// add a node
void add_node_util(l_node** head, int val)
{
    l_node* newNode = create_node(val);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    l_node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// remove a node
void remove_node_util(l_node** head, int val)
{
    if (*head == NULL)
    {
        printf("The Linked list is empty\n");
        return;
    }

    l_node* temp = *head;
    l_node* prev = NULL;

    if (temp != NULL && temp->data == val)
    {
        *head = temp->next;
        temp->next = NULL;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    temp->next = NULL;
    free(temp);
}

int length(l_node** head)
{
    int count = 0;
    l_node* temp = *head;
    while (temp!= NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display_list_util(l_node** head)
{
    l_node* temp = *head;
    if (temp == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct hashMap
{
    int* arr;
} Map;

int main()
{
    int m = 997;
    int* 
}