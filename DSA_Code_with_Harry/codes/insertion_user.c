#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void insertion(struct node ** head, int data)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
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

void display(struct node ** head)
{
    struct node * temp = *head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct node * head = NULL;
    
    // insertion(&head, 3);
    // insertion(&head, 6);
    // insertion(&head, 4);
    // display(&head);
    
    int no;
    printf("Enter the no. of nodes: ");
    scanf("%d", &no);
    for (int i = 0; i < no; i++)
    {
        int val;
        scanf("%d", &val);
        insertion(&head, val);
    }
    display(&head);
    return 0;
}