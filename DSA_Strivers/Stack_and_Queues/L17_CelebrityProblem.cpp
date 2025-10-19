/*
    The Celebrity Problem

    A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

    Note: Follow 0-based indexing.

    Examples:

    Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
    Output: 1
    Explanation: 0th and 2nd person both know 1st person. Therefore, 1 is the celebrity person. 
    Input: mat[][] = [[1, 1], [1, 1]]
    Output: -1
    Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
    Input: mat[][] = [[1]]
    Output: 0
    Constraints:
    1 ≤ mat.size() ≤ 1000
    0 ≤ mat[i][j] ≤ 1
    mat[i][i] == 1
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(n^2) + O(n), S.C. : O(2n)
int celebrityBrute(vector<vector<int>>& mat)
{
    int n = mat.size();
    vector<int> knowMe(n), iKnow(n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                knowMe[j] += 1;
                iKnow[i] += 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (knowMe[i] == n - 1 && iKnow[i] == 0)
            return i;
    }
    return -1;
}

// T.C. : O(n), S.C. : O(n)
int celebrityUsingStack(vector<vector<int>>& mat)
{
    int n = mat.size();
    stack<int> st;

    // Push everyone into stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // Eliminate non-celebrities
    while (st.size() > 1) 
    {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        
        if (mat[a][b] == 1) // a knows b -> a cannot be celeb
            st.push(b);
        else                 // a does not know b -> b cannot be celeb
            st.push(a);
    }

    // Possible candidate
    int candidate = st.top();

    // Verify candidate
    for (int i = 0; i < n; i++) 
    {
        if (i == candidate) 
            continue;
        // Candidate should not know i, and i should know candidate
        if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
            return -1;
    }

    return candidate;
}

// T.C. : O(2n), S.C. : O(1)
int celebrityOptimal(vector<vector<int>>& mat)
{
    int n = mat.size();
    int top = 0, down = n - 1;
    
    while (top < down)
    {
        if (mat[top][down] == 1)
            top += 1;
        else if (mat[down][top] == 1)
            down -= 1;
        else
        {
            top += 1;
            down -= 1;
        }
    }
    
    // Both pointers should point to the same
    if (top > down)
        return -1;
        
    for (int i = 0; i < n; i++)
    {
        if (i == top)
            continue;
        
        if (mat[top][i] != 0 || mat[i][top] != 1)
            return -1;
    }
    
    return top;
}

int celebrity(vector<vector<int> >& mat) 
{
    // Brute Force approach
    // return celebrityBrute(mat);
    
    // Using stack
    return celebrityUsingStack(mat);
    
    // OptimalApproch
    // return celebrityOptimal(mat);
}

int main()
{
    
    return 0;
}