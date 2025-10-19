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

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char * exp, int length)
{
    // create and initialize stack
    struct stack * sp;
    sp->size = length;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }
    return isEmpty(sp);
}

int main()
{
    char * exp = "((8)[(9-8))";
    int length = 11;

    if(parenthesisMatch(exp, length))
    {
        printf("The parenthesis are balanced\n");
    }
    else
    {
        printf("The parenthesis are not balanced\n");
    }
    return 0;
}