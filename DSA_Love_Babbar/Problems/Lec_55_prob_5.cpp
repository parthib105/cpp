#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &myStack, int x)
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
    insertAtBottom(myStack, x);

    myStack.push(topElm);
}

void reverseStack(stack<int> &myStack)
{
    // base case
    if (myStack.empty())
    {
        return;
    }

    int topElm = myStack.top();
    myStack.pop();

    // Recursive call
    reverseStack(myStack);

    insertAtBottom(myStack, topElm);
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

    reverseStack(myStack);

    cout << "Reversed stack : ";
    printStack(myStack);
    cout << endl;


    return 0;
}