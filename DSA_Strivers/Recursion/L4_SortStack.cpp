/*
    Sort a Stack

    Given a stack, the task is to sort it such that the top of the stack has the greatest element.

    Example 1:

    Input:
    Stack: 3 2 1
    Output: 3 2 1
    Example 2:

    Input:
    Stack: 11 2 32 3 41
    Output: 41 32 11 3 2
    
    Expected Time Complexity: O(N*N)
    Expected Auxilliary Space: O(N) recursive.

    Constraints:
    1<=N<=100
*/

#include<bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>& st, int x)
{
    if (st.empty() || st.top() <= x)
    {
        st.push(x);
        return;
    }
    
    int temp = st.top();
    st.pop();
    
    insertSorted(st, x);
    st.push(temp);
}

void sortedStack(stack<int> &st)
{
    if (st.empty())
        return;
    
    int currTop = st.top();
    st.pop();
    
    sortedStack(st);
    
    insertSorted(st, currTop);
}

int main()
{
    vector<int> arr = {11, 2, 32, 3, 41};
    stack<int> st(deque<int>(arr.begin(), arr.end()));

    sortedStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}