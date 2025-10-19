/*
    Next Greater Element II

    Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

    The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

    Example 1:

    Input: nums = [1,2,1]
    Output: [2,-1,2]
    Explanation: The first 1's next greater number is 2; 
    The number 2 can't find next greater number. 
    The second 1's next greater number needs to search circularly, which is also 2.
    Example 2:

    Input: nums = [1,2,3,4,3]
    Output: [2,3,4,-1,4]
    

    Constraints:

    1 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
*/


#include<bits/stdc++.h>
using namespace std;

// T.C. : O(N^2), S.C. : O(N) (ans)
vector<int> nextGreaterElementBrute(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> nge(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < i + n; j++)
        {
            int ind = j % n;
            if (nums[ind] > nums[i])
            {
                nge[i] = nums[ind];
                break;
            }
        }
    }

    return nge;
}

// T.C. : O(4N), S.C. : O(2N) (stack) + O(N) (ans)
vector<int> nextGreaterElementOptimal(vector<int>& nums) 
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for (int i = 2*n - 1; i >= 0; i--)
    {
        int idx = i % n;
        
        while (!st.empty() && nums[st.top()] <= nums[idx])
        {
            st.pop();
        }
        
        if (!st.empty())
            ans[idx] = nums[st.top()];
        st.push(idx);
    }

    return ans;
}

vector<int> nextGreaterElement(vector<int> &nums)
{
    // Brute Force
    // return nextGreaterElementBrute(nums);


    // Optimal Approach
    return nextGreaterElementOptimal(nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> ans = nextGreaterElement(nums);
    
    for (int i : ans)
        cout << i << " ";
    return 0;
}