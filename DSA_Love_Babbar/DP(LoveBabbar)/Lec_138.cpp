/*
    Maximal Rectangle

    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example 1:

            1 0 1 0 0
            1 0 1 1 1
            1 1 1 1 1
            1 0 0 1 0

    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.
    Example 2:

    Input: matrix = [["0"]]
    Output: 0
    Example 3:

    Input: matrix = [["1"]]
    Output: 1

    Constraints:

    rows == matrix.length
    cols == matrix[i].length
    1 <= row, cols <= 200
    matrix[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

// store the indices of next smaller element
vector<int> nextSmallerIndex(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        if (st.top() == -1)
        {
            ans[i] = n;
        }
        st.push(i);
    }
    return ans;
}

// store the indices of previous smaller element
vector<int> prevSmallerIndex(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// largest area in histogram
int largestRectangle(vector<int> height)
{
    int n = height.size();
    vector<int> prev = prevSmallerIndex(height);
    vector<int> next = nextSmallerIndex(height);

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = height[i];
        int b = next[i] - prev[i] - 1;
        maxArea = max(maxArea, l * b);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(n, 0);
    int maxArea = INT_MIN;
    for (int r = 0; r < m; r++)
    {
        // add prev heights
        for (int c = 0; c < n; c++)
        {
            row[c]++;
            if (matrix[r][c] == '0')
            {
                row[c] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangle(row));
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};
    cout << maximalRectangle(matrix) << endl;
    return 0;
}