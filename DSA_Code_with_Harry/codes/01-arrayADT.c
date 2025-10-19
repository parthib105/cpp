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

void show(struct myArray * a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
    puts("");
}

void setVal(struct myArray * a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &(a->ptr)[i]);
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2); // will create an array(dynamically allocated) 
    printf("We are running setVal function\n");
    setVal(&marks);
    printf("We are running show function\n");
    show(&marks);
    free(marks.ptr);

    return 0;
}