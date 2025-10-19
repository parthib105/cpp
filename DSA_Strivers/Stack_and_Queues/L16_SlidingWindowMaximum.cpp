/*
    Sliding Window Maximum

    You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

    Return the max sliding window.

    Example 1:

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]
    Explanation: 
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
    Example 2:

    Input: nums = [1], k = 1
    Output: [1]
    

    Constraints:

    1 <= nums.length <= 10^5
    -10^4 <= nums[i] <= 10^4
    1 <= k <= nums.length
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O((n - k)*k), S.C. : O(n - k)
vector<int> maxSlidingWindowBrute(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i <= n - k; i++)
    {
        int currMax = INT_MIN;
        for (int j = i; j < i + k; j++)
            currMax = max(currMax, nums[j]);
        ans.push_back(currMax);
    }
    return ans;
}

// T.C. : O(n log(k)), S.C. : O(k)
vector<int> maxSlidingWindowPQ(vector<int>& nums, int k)
{
    int n = nums.size();
    if (n == 0)
        return {};

    vector<int> ans;
    priority_queue<pair<int, int>> pq;

    // put first k values in heap
    for (int i = 0; i < k; i++)
        pq.push({nums[i], i});

    ans.push_back(pq.top().first);
    for (int i = k; i < n; i++)
    {
        while (!pq.empty() && pq.top().second <= (i - k))
            pq.pop();

        pq.push({nums[i], i});
        ans.push_back(pq.top().first);
    }
    return ans;
}

// T.C. : O(2n), S.C. : O(k) + O(n - k)
vector<int> maxSlidingWindowDeque(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= (i - k))
            dq.pop_front();
        
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    // Brute Force
    // return maxSlidingWindowBrute(nums, k);

    // Using priority queue
    return maxSlidingWindowPQ(nums, k);

    // Using Deque
    // return maxSlidingWindowDeque(nums, k);

}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);
    for (auto elm : ans)
        cout << elm << " ";
    return 0;
}