#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue * q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue * q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full\n");
    }
    else
    {
        q->r ++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue * q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This queue is empty\n");
    }
    else
    {
        q->f ++;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct queue * q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    puts("");
}

int main()
{
    struct queue * q;
    q->size = 100;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 89);
    enqueue(q, 21);
    enqueue(q, 14);
    printf("Before dequeing\n");
    display(q);
    printf("After dequeing\n");
    dequeue(q);
    display(q);
    return 0;
}