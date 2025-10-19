/*
    Maximal Rectangle

    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example 1:

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

#include<bits/stdc++.h>
using namespace std;


// largest area in histogram
int largestRectangle(int n, vector<int>& arr)
{
    stack<int> st;
    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int h = arr[st.top()];
            st.pop();

            int nsi = i;
            int psi = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, h*(nsi - psi - 1));
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int h = arr[st.top()];
        st.pop();

        int nsi = n;
        int psi = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, h*(nsi - psi - 1));
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& mat) 
{
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> pSum(m, vector<int>(n, 0));

    // fill the prefix sum matrix
    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += (int)(mat[i][j] - '0');
            if (mat[i][j] == '0')
                sum = 0;
            pSum[i][j] = sum;
        }
    }

    int maxArea = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        int lr = largestRectangle(n, pSum[i]);
        maxArea = max(maxArea, lr);
    }
    return maxArea;
}

int main()
{
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << maximalRectangle(matrix) << endl;
    return 0;
}