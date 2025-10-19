/*
    Insert An Element At Its Bottom In A Given Stack

    Problem statement :
    You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of
    ‘MY-STACK’ and return the updated stack/deque.

    Note :
    If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last
    element represents the element at the top of the stack.

    For Example :
    Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].
*/

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &myStack, int x)
{
    // base case
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int topElm = myStack.top();
    myStack.pop();

    // Recursive call
    solve(myStack, x);

    myStack.push(topElm);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    // Write your code here.
    solve(myStack, x);

    return myStack;
}

int main()
{
    stack<int> myStack;
    myStack.push(7);
    myStack.push(1);
    myStack.push(4);
    myStack.push(5);

    int x = 9;

    myStack = pushAtBottom(myStack, x);

    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    return 0;
}