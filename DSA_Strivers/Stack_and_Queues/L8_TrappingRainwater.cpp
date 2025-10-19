/*
    Trapping Rain Water

    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

    Example 1:


    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
    Example 2:

    Input: height = [4,2,0,3,2,5]
    Output: 9
    

    Constraints:

    n == height.length
    1 <= n <= 2 * 10^4
    0 <= height[i] <= 10^5

*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(2N), S.C. : O(N) 
int trapBrute(vector<int>& height)
{
    int n = height.size();
    vector<int> suffixMax(n);
    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i --)
    {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }

    int totalWater = 0;
    int leftMax = height[0];
    for (int i = 0; i < n; i++)
    {
        leftMax = max(leftMax, height[i]);
        int rightMax = suffixMax[i];
        if (height[i] < leftMax && height[i] < rightMax)
            totalWater += min(leftMax, rightMax) - height[i];
    }
    return totalWater;
}

// T.C. : O(N), S.C. : O(N)
int trapStack(vector<int>& height)
{
    int n = height.size();
    stack<int> st; // stores indices
    int totalWater = 0;

    for (int i = 0; i < n; i++) 
    {
        // If current bar is taller than the bar at stack top, process trapped water
        while (!st.empty() && height[i] > height[st.top()]) 
        {
            int bottom = st.top();
            st.pop();

            if (st.empty()) 
                break; // no left boundary

            int left = st.top();
            int width = i - left - 1;
            int waterHeight = min(height[left], height[i]) - height[bottom];

            totalWater += width * waterHeight;
        }
        st.push(i);
    }

    return totalWater;
}

// T.C. : O(N), S.C. : O(1)
int trapOptimal(vector<int>& height)
{
    int n = height.size();
    int lMax = 0, rMax = 0, totalWater = 0;
    int l = 0, r = n - 1;

    while (l < r)
    {
        if (height[l] <= height[r])
        {
            if (lMax > height[l])
                totalWater += lMax - height[l];
            else
                lMax = height[l];
            l += 1;
        }
        else
        {
            if (rMax > height[r])
                totalWater += rMax - height[r];
            else
                rMax = height[r];
            r -= 1; 
        }
    }
    return totalWater;
}

int trap(vector<int>& height) {
    // Brute Force solution
    // return trapBrute(height);

    // Optimal Solution
    return trapOptimal(height);
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << endl; 
    return 0;
}