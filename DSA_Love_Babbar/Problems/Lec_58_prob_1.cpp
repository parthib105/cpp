/*
    Question link : 
    https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0%3Fsource%3Dyoutube&campaign=Lovebabbarcodestudio11thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio11thfeb

    Implement N stacks in a single array

    Problem statement
    Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

    push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

    pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
*/

#include <bits/stdc++.h>
using namespace std;

class NStack
{
private:
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        this->n = N;
        this->s = S;
        this->arr = new int[this->s];
        this->next = new int[this->s];
        this->top = new int[this->n];

        // initialize top
        for (int i = 0; i < this->n; i++)
        {
            this->top[i] = -1;
        }

        // initialize next
        for (int i = 0; i < this->s; i++)
        {
            this->next[i] = i + 1;
        }
        this->next[this->s - 1] = -1;

        // initialize free spot
        this->freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // condition for stack overflow
        if (this->freeSpot == -1)
        {
            return false;
        }

        // find index
        int idx = this->freeSpot;

        // insert element into array
        this->arr[idx] = x;

        // update freeSpot
        this->freeSpot = this->next[idx];

        // update next
        this->next[idx] = this->top[m - 1];

        // update top
        this->top[m - 1] = idx;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow condition
        if (this->top[m - 1] == -1)
        {
            return -1;
        }

        // store the index of top elm
        int idx = this->top[m - 1];

        // update top
        this->top[m - 1] = this->next[idx];

        // update next
        this->next[idx] = this->freeSpot;

        // update freeSpot
        this->freeSpot = idx;

        return this->arr[idx];
    }
};

int main()
{

    return 0;
}