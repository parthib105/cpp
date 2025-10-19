#include<bits/stdc++.h>
using namespace std;

void insertLast(stack<int> &st, int elm)
{
    if (st.size() == 0 || st.top() >= elm)
    {
        st.push(elm);
        return;
    }

    int t = st.top();
    st.pop();

    insertLast(st, elm);

    st.push(t);
}

void sortStack(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }

    int topElm = st.top();
    st.pop();

    sortStack(st);

    insertLast(st, topElm);
}

int main()
{
    stack<int> st;
    st.push(0);
    st.push(5);
    st.push(1);
    st.push(2);
    st.push(-1);

    sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}