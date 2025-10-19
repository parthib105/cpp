#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct circularQueue * q)
{
    if (((q->r + 1) % q->size == q->f + 1) && (q->r != q->f))
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue * q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue * q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue * q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This queue is empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct circularQueue * q)
{
    int i = q->f + 1;
    while (i != q->r + 1)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    puts("");
}

int main()
{
    struct circularQueue * q;
    q->size = 9;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // Enqueue few elements
    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 2);
    enqueue(q, 1);
    enqueue(q, 8);
    enqueue(q, 7);
    enqueue(q, 3);
    enqueue(q, 4);
    printf("Original queue:\n");
    display(q);

    // Dequeue elements
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);
    // dequeue(q);

    // printf("After dequeue:\n");
    // printf("Queue is empty : %d\n", isEmpty(q));
    // printf("Queue is full : %d\n", isFull(q));
    return 0;
}