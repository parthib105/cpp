/*
    Max rectangle

    Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

    Input:
    n = 4, m = 4
    M[][] = {{0 1 1 0},
            {1 1 1 1},
            {1 1 1 1},
            {1 1 0 0}}
    Output: 8
    Explanation: For the above test case the
    matrix will look like
    0 1 1 0
    1 1 1 1
    1 1 1 1
    1 1 0 0
    the max size rectangle is
    1 1 1 1
    1 1 1 1
    and area is 4 *2 = 8.
*/

#include <bits/stdc++.h>
using namespace std;

// store the indices of next smaller element
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, 0);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// store the indices of prev smaller element
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n, 0);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights, int n)
{
    vector<int> prev;
    prev = prevSmallerElement(heights, n);

    vector<int> next;
    next = nextSmallerElement(heights, n);

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        if (l * b > maxArea)
        {
            maxArea = l * b;
        }
    }
    return maxArea;
}

int maxArea(vector<vector<int>>& M, int n, int m)
{
    // To handle empty matrix case
    if (n == 0 || m == 0)
    {
        return 0;
    }

    // Compute the area for first row
    int currArea = largestRectangleArea(M[0], m);

    for (int i = 1; i < n; i++)
    {
        // update row by adding values from prev rows
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] != 0)
            {
                M[i][j] += M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
        }

        currArea = max(currArea, largestRectangleArea(M[i], m));
    }
    return currArea;
}

int main()
{
    vector<vector<int>> M = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    int n = 4;
    int m = 4;

    cout << "largest rectangle area : " << maxArea(M, n, m) << endl;
    return 0;
}