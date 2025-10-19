#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int* ptr;
};

void createArray(struct myArray * a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int*) malloc(tSize * sizeof(int));

    a -> total_size = tSize;
    a -> used_size = uSize;
    a -> ptr = (int*) malloc(tSize * sizeof(int));
}

void setVal(struct myArray * a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &(a->ptr)[i]);
    }
}

int insertion(struct myArray * a, int pos, int val)
{
    int count = 0;
    int i = a->used_size - 1;
    while (1)
    {
        (a->ptr)[i+1] = (a->ptr)[i];
        if (i == pos - 1)
        {
            (a->ptr)[i] = val;
            count +=1;
            break;
        }
        i--; 
    }
    if (count == 0)
    {
        return 0;
    }
    a->used_size += 1;
    return 1;
}

int deletion(struct myArray * a, int pos)
{
    int count = 0;
    for (int i = 0; i < a->used_size - 1; i++)
    {
        if (i >= pos - 1)
        {
            (a->ptr)[i] = (a->ptr)[i+1];
            count ++;
        }
    }
    if (count == 0)
    {
        return 0;
    }
    a->used_size -= 1;
    return 1;                                                                                    
}

void show(struct myArray * a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
    puts("");
}


int main()
{
    struct myArray arr;
    createArray(&arr, 8, 5);
    setVal(&arr);
    printf("Showing array before insertion\n");
    show(&arr);
    if(insertion(&arr, 2, 8) == 1)
    {
        printf("Insertion successfull\n");
        printf("Showing array after insertion\n");
        show(&arr);
    }
    else
    {
        printf("Insertion unsuccessfull\n");
    }
    
    if(deletion(&arr, 3) == 1)
    {
        printf("Deletion successfull\n");
        printf("Showing array after deletion\n");
        show(&arr);
    }
    else
    {
        printf("Deletion unsuccessfull\n");
    }
    return 0;
}