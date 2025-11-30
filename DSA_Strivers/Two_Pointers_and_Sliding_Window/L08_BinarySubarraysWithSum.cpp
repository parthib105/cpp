/*
    Binary Subarrays With Sum

    Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
    A subarray is a contiguous part of the array.

    Example 1:

    Input: nums = [1,0,1,0,1], goal = 2
    Output: 4
    Explanation: The 4 subarrays are bolded and underlined below:
    [1,0,1,0,1]
    [1,0,1,0,1]
    [1,0,1,0,1]
    [1,0,1,0,1]
    Example 2:

    Input: nums = [0,0,0,0,0], goal = 0
    Output: 15


    Constraints:

    1 <= nums.length <= 3 * 10^4
    nums[i] is either 0 or 1.
    0 <= goal <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // T.C. : O(N^2), S.C. : O(1)
    int brute(vector<int> &nums, int goal)
    {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int curSum = 0;
            for (int j = i; j < n; j++)
            {
                curSum += nums[j];
                if (curSum == goal)
                    count++;
            }
        }
        return count;
    }

    // T.C. : O(N), S.C. : O(N)
    int better(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int curSum = 0, count = 0;
        unordered_map<int, int> seen;

        seen[0] = 1;
        for (int i = 0; i < n; i++)
        {
            curSum += nums[i];

            int rem = curSum - goal;
            if (seen.find(rem) != seen.end())
                count += seen[rem];

            seen[curSum] += 1;
        }
        return count;
    }

    // T.C. : O(N), S.C. : O(1)
    // calculates subarrays whose sum is <= goal
    int optimal(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;

        int curSum = 0, count = 0;
        int l = 0, n = nums.size();
        for (int r = 0; r < n; r++)
        {
            curSum += nums[r];

            while (curSum > goal)
            {
                curSum -= nums[l];
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }

public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // Brute force
        // return brute(nums, goal);

        // Better approach (map)
        // return better(nums, goal);

        // Optimal approach
        // f(goal) - f(goal - 1)
        return optimal(nums, goal) - optimal(nums, goal - 1);
    }
};

int main()
{
    int goal = 2;
    vector<int> nums = {1, 0, 1, 0, 1};

    Solution sol;
    cout << sol.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}