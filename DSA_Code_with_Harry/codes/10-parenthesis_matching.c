#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char * arr;
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

void push(struct stack * ptr, char val)
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

char pop(struct stack * ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow!");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top --;
        return val;
    }
}

int parenthesisMatch(char * exp, int length)
{
    // create and initialize stack
    struct stack * sp;
    sp->size = length;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    return isEmpty(sp);
}

int main()
{
    char * exp = "8)*9(";
    int length = 5;

    if(parenthesisMatch(exp, length))
    {
        printf("The parenthesis is matching\n");
    }
    else
    {
        printf("The parenthesis is not matching\n");
    }

    return 0;
}