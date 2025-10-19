#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack * ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0; 
}

void push(struct stack * ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow! Can't push %d to the stack\n", val);
        return;
    }
    else
    {
        ptr->top ++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack * ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow!");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top --;
        return val;
    }
}

int peek(struct stack * ptr, int i)
{
    int arr_ind = ptr->top - i ;
    if (arr_ind < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return ptr->arr[arr_ind];
    }
}

int stackTop(struct stack * ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack * ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1; // initially no elements are there in stack
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("Before pushing: \n");
    printf("Is it empty? : %d\n", isEmpty(sp));
    printf("Is it full? : %d\n", isFull(sp));
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6); // ---> pushes 10 values
    // push(sp, 46); // stack overflow since the size of the stack is 10
    
    printf("Topmost value is: %d\n", stackTop(sp));
    printf("Bottommost value is: %d\n", stackBottom(sp));

    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));

    for (int j = 0; j < sp->top + 1; j++)
    {
        printf("The value at index %d is %d\n", j, peek(sp, j));
    }
    

    
    printf("\nAfter pushing: \n");
    printf("Is it empty? : %d\n", isEmpty(sp));
    printf("Is it full? : %d\n", isFull(sp));
}