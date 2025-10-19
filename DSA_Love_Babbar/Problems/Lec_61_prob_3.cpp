 /*
    Reverse First K elements of Queue

    Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving
    the other elements in the same relative order.

    Input:
    N = 5, K = 3
    queue = 1 2 3 4 5
    Output:
    3 2 1 4 5
    Explanation:
    After reversing the given
    input from the 3rd position the resultant
    output will be 3 2 1 4 5.
*/

#include <bits/stdc++.h>
using namespace std;

/********** Approch 1 : using stacks ( O(n) space ) **********/
queue<int> modifyQueue(queue<int> q, int k)
{
    // reverse the queue
    stack<int> st;

    // step 1 : pop first k element from queue to stack
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    // step 2 : fetch from stack and push into queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // step 3 : fetch n - k elements from queue and push into queue
    for (int i = 0; i < (q.size() - k); i++)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
}
/**********************************************/

/********** Approch 2 : using recursion ( O(1) space ) **********/

// function to reverse queue
void revQueue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int elm = q.front();
    q.pop();

    revQueue(q);
    q.push(elm);
}

// function to take remaimining (n - k) elements into it's correct position
void comeFront(queue<int> &q, int cnt, int k, int n)
{
    if (cnt == (n - k))
    {
        return;
    }

    int elm = q.front();
    q.pop();

    comeFront(q, cnt + 1, k, n);
    q.push(elm);
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueueRecur(queue<int> q, int k)
{
    // reverse the queue
    revQueue(q);
    comeFront(q, 0, k, q.size());
    return q;
}

/****************************************************************/
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
    int k = 3;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Before modification : ";
    printQueue(q);

    q = modifyQueueRecur(q, k);

    cout << "After modification : ";
    printQueue(q);
    return 0;
}