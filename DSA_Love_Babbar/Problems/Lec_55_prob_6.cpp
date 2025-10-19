/*
    Sort a Stack

    Problem statement :

    You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending 
    order using recursion.

    We can only use the following functions on this stack S.

    is_empty(S) : Tests whether stack is empty or not.
    push(S) : Adds a new element to the stack.
    pop(S) : Removes top element from the stack.
    top(S) : Returns value of the top element. Note that this function does not remove elements from 
             the stack.
    Note :
    1) Use of any loop constructs like while, for..etc is not allowed. 
    2) The stack may contain duplicate integers.
    3) The stack may contain any integer i.e it may either be negative, positive or zero.
*/

#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int x)
{
    // base case
    if (s.empty() || (!s.empty() && s.top() < x))
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    
    sortedInsert(s, x);

    s.push(num);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int topElm = stack.top();
    stack.pop();

    sortStack(stack);

    sortedInsert(stack, topElm);
}

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " -> ";
        st.pop();
    }
}

int main()
{
    stack<int> myStack;
    myStack.push(9);
    myStack.push(1);
    myStack.push(4);
    myStack.push(7);
    myStack.push(3);
    
    cout << "Original stack : ";
    printStack(myStack);
    cout << endl;

    sortStack(myStack);

    cout << "Sorted stack : ";
    printStack(myStack);
    cout << endl;
    return 0;
}