#include<stdio.h>
#include<stdlib.h>

struct node 
{   
    int data;
    struct node * next;
};

struct node * f = NULL;
struct node * r = NULL;

int isEmpty(struct node * f)
{
    if(f == NULL)
    {
        return 1;
    }
    return 0;
}



void enqueue(int val)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;

        if(r == NULL && f == NULL)
        {
            f = n;
            r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    if (!isEmpty(f))
    {
        struct node * n = f;
        f = f->next;
        val = n->data;
        free(n);
        return val;
    }
    return val;
}

void display()
{
    struct node * n = f;
    while(n != NULL)
    {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL");
}
int main()
{
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Displaying original queue:\n");
    display();
    printf("\nDequeued element: %d\n", dequeue());
    printf("\nDequeued element: %d\n", dequeue());
    printf("\nDequeued element: %d\n", dequeue());
    printf("Displaying queue after dequeing:\n");
    display();

}