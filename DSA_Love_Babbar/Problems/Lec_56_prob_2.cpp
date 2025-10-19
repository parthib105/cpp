/*
    Largest Rectangle in Histogram

    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
    return the area of the largest rectangle in the histogram.

    Input: heights = [2,1,5,6,2,3]
    Output: 10
    Explanation: The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.
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

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

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

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle area : " << largestRectangleArea(heights) << endl;
    return 0;
}