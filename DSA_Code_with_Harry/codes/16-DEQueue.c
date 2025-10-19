// In Double-Ended Queue, we can
// Insert element from rear + front
// Delete element from rear + front
// Two types of DEQueue:
// 1. Restricted input DEQueue -> Insertion from front is not allowed
// 2. Restricted output DEQueue -> Deletion from rear is not allowed

#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int * arr;
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
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueueR(struct queue * q, int val)
{
    if (isFull(q))
    {
        printf("Queue is full! Can't enqueue element %d\n", val);
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

void enqueueF(struct queue * q, int val)
{
    if (q->f == -1)
    {
        printf("Can't enqueue element %d from front\n", val);
    }
    else
    {
        q->arr[q->f] = val;
        q->f = q->f - 1;
    }
}

int dequeueF(struct queue * q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! Can't dequeue element\n");
    }
    else
    {
        int n = q->f;
        q->f++;
        return q->arr[n+1];
    }
}

int dequeueR(struct queue * q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty! Can't dequeue element\n");
    }
    else
    {
        int n = q->r;
        q->r--;
        return q->arr[n];
    }
}

void display(struct queue * q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
}

int main()
{
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));
    q->f = q->r = -1;
    q->size = 5;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueueR(q, 4);
    enqueueR(q, 1);
    enqueueR(q, 3);
    enqueueR(q, 7);
    enqueueR(q, 5);
    printf("Original queue:\n");
    display(q);
    printf("\nDequeue from front: %d\n", dequeueF(q));
    printf("Modified queue:\n");
    display(q);
    printf("\nDequeue from front: %d\n", dequeueF(q));
    printf("Modified queue:\n");
    display(q);
    printf("\nEnqueue from front:\n");
    enqueueF(q, 9);
    printf("Modified queue:\n");
    display(q);
    printf("\nDequeue from rear: %d\n", dequeueR(q));
    printf("Modified queue:\n");
    display(q);
    return 0;
}