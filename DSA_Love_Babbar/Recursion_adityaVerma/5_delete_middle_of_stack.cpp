#include<bits/stdc++.h>
using namespace std;

// definition of middle element : n/2 + 1, n is integer
void deleteMiddle(int n, stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    if (st.size() == (n/2 + 1))
    {
        st.pop();
        return;
    }

    int t = st.top();
    st.pop();

    deleteMiddle(n, st);

    st.push(t);
}

int main()
{
    stack<int> st;

    st.push(0);
    st.push(-1);
    st.push(9);
    st.push(3);
    st.push(2);

    deleteMiddle(st.size(), st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}