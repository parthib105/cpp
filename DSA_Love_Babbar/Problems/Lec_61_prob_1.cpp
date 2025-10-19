/*
    Queue Reversal

    Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(),
    that reverses the N elements of the queue.

    Input:
    4 3 1 10 2 6

    Output:
    6 2 10 1 3 4

    Explanation:
    After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4.
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : using stack
queue<int> revQueue(queue<int> q)
{
    stack<int> st;
    while (!q.empty())
    {
        int elm = q.front();
        q.pop();
        st.push(elm);
    }

    while (!st.empty())
    {
        int elm = st.top();
        st.pop();
        q.push(elm);
    }
    return q;
}

// Approach 2 : using recursion
void revQueue2(queue<int>& q)
{
    if (q.empty())
    {
        return;
    }

    int elm = q.front();
    q.pop();

    revQueue2(q);
    q.push(elm);
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    // q.push(2);
    // q.push(6);

    cout << "Before revarsal : ";
    printQueue(q);

    revQueue2(q);

    cout << "After revarsal : ";
    printQueue(q);
    return 0;
}