/*
    Reverse a stack

    You are given a stack St. You have to reverse the stack using recursion.

    Example 1:

    Input: St = [3,2,1,7,6]
    Output: [6,7,1,2,3]
    Explanation: Input stack after reversing will look like the stack in the output.
    Example 2:

    Input: St = [4,3,9,6]
    Output: [6,9,3,4]
    Explanation: Input stack after reversing will look like the stack in the output.
    Constraints:
    1 ≤ stack.size ≤ 10^4
    0 ≤ stack.element ≤ 10^3
*/

#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& st, int x) 
{
    if (st.empty()) 
    {
        st.push(x);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(temp);
}

void reverse(stack<int> &st) 
{
    if (st.empty())
        return;
        
    int currTop = st.top();
    st.pop();
    
    reverse(st);
    
    insertAtBottom(st, currTop);
}

int main()
{
    vector<int> arr = {11, 2, 32, 3, 41};
    stack<int> st(deque<int>(arr.begin(), arr.end()));

    reverse(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}