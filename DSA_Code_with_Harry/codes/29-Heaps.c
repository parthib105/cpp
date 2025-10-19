#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int* arr;
    int size;
} heap;

void swap (heap* H, int a, int b)
{
    int temp = H->arr[a];
    H->arr[a] = H->arr[b];
    H->arr[b] = temp;
}

void insert(heap* H, int val)
{
    H->size = H->size + 1;
    int index = H->size;
    H->arr[index] = val;

    while (index > 1)
    {
        int parent = index / 2;

        if (H->arr[parent] < H->arr[index])
        {
            swap(H, parent, index);
            index = parent;
        }
        else
        {
            break;
        }
    }
    return;
}

void Deletion(heap* H, int idx)
{
    if (H->size == 0)
    {
        printf("Nothing to delete\n");
        return;
    }

    // step 1 : put last element into idx
    H->arr[idx] = H->arr[H->size];

    // step 2 : remove the last element
    H->size--;

    // step 3 : take root node to its correct position
    int i = idx;
    while(i < H->size)
    {
        int leftidx = 2 * i;
        int rightidx = 2 * i + 1;

        if (leftidx < H->size && H->arr[i] < H->arr[leftidx])
        {
            swap(H, i, leftidx);
            i = leftidx;
        }
        else if (rightidx < H->size && H->arr[i] < H->arr[rightidx])
        {
            swap(H, i, rightidx);
            i = rightidx;
        }
        else
        {
            return;
        }
    }
}



void printHeap(heap* H)
{
    for (int i = 1; i <= H->size; i++)
    {
        printf("%d ", H->arr[i]);
    }
    puts(" ");
}

int main()
{
    heap* H = (heap *)malloc(sizeof(heap));
    H->arr = (int*)malloc(100 * sizeof(int));
    H->size = 0;
    H->arr[0] = -1;

    insert(H, 55);
    insert(H, 53);
    insert(H, 54);
    insert(H, 40);
    insert(H, 52);
    insert(H, 45);
    insert(H, 47);
    insert(H, 35);
    insert(H, 39);
    insert(H, 50);

    printf("Before deletion\n");
    printHeap(H);

    printf("\nAfter deletion of 40\n");
    Deletion(H, 4);
    printHeap(H);

    printf("\nAfter deletion of 45\n");
    Deletion(H, 6);
    printHeap(H);

    return 0;
}