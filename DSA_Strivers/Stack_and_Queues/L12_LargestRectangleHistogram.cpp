/*
    Largest Rectangle in Histogram

    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

    Example 1:


    Input: heights = [2,1,5,6,2,3]
    Output: 10
    Explanation: The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.
    Example 2:


    Input: heights = [2,4]
    Output: 4


    Constraints:

    1 <= heights.length <= 10^5
    0 <= heights[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(2N), S.C. : O(2N)
vector<int> prevSmallElement(int n, vector<int> &arr)
{
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            pse[i] = st.top();
        st.push(i);
    }
    return pse;
}

// T.C. : O(2N), S.C. : O(2N)
vector<int> nextSmallElement(int n, vector<int> &arr)
{
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();

        if (!st.empty())
            nse[i] = st.top();
        st.push(i);
    }
    return nse;
}

// T.C. : O(5N), S.C. : O(4N)
int bruteForce(vector<int>& heights)
{
    int n = heights.size();

    // get the nse and pse
    vector<int> pse = prevSmallElement(n, heights);
    vector<int> nse = nextSmallElement(n, heights);

    int maxArea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int h = heights[i];
        int b = nse[i] - pse[i] - 1;
        maxArea = max(maxArea, b*h);
    }
    return maxArea;
}

// T.C. : O(2N), S.C. : O(N)
int optimalSol(vector<int>& heights)
{
    int n = heights.size();
    int maxArea = INT_MIN;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int h = heights[st.top()];
            st.pop();

            int nsi = i;
            int psi = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nsi - psi - 1)*h);
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int h = heights[st.top()];
        st.pop();

        int nsi = n;
        int psi = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, h*(nsi - psi - 1));
    }
    return maxArea;
}

int largestRectangleArea(vector<int> &heights)
{
    // Brute force
    // return bruteForce(heights);

    // Optimal Solution
    return optimalSol(heights);
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "The area of the largest reactangle is " << largestRectangleArea(heights) << endl;
    return 0;
}