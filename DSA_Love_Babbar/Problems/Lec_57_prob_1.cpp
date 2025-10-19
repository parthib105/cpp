/*
    A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find
    if there is a celebrity in the party or not.
    A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set
    to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
    Return the index of the celebrity, if there is no celebrity return -1.
    Note: Follow 0 based indexing.

    Input:
    N = 3
    M[][] = {{0 1 0},
            {0 0 0},
            {0 1 0}}
    Output: 1
    Explanation: 0th and 2nd person both
    know 1. Therefore, 1 is the celebrity.
*/

#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    // step 1 : push all candidates into stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // step 2 : pick top two elements and check if a knows b or b knows a
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (M[a][b] == 1)
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    // step 3 : element left in the stack is a potential candidate
    // verify it
    bool rowCheck = true;
    bool colCheck = true;

    // check row
    for (int j = 0; j < n; j++)
    {
        if (j != st.top() && M[st.top()][j] == 1)
        {
            rowCheck = false;
            break;
        }
    }

    // check column
    for (int i = 0; i < n; i++)
    {
        if (i != st.top() && M[i][st.top()] == 0)
        {
            colCheck = false;
            break;
        }
    }

    if (rowCheck == true && colCheck == true)
    {
        return st.top();
    }
    return -1;
}

int main()
{
    vector<vector<int>> M = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int n = 3;
    cout << "Celebrity : " << celebrity(M, n) << endl;
    return 0;
}