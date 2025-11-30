/*
    Max Consecutive Ones III

    Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

    Example 1:

    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    Output: 6
    Explanation: [1,1,1,0,0,1,1,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
    Example 2:

    Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
    Output: 10
    Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
    

    Constraints:

    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.
    0 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // T.C. : O(N^2), S.C. : O(1)
    int longestOnesBrute(vector<int> &nums, int k)
    {
        int maxLen = 0, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int zeros = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    zeros++;

                if (zeros > k)
                    break;

                // Update max length if this subarray is valid
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    int longestOnesBetter(vector<int> &nums, int k)
    {
        int zeros = 0, maxLen = 0;
        int l = 0, n = nums.size();

        for (int r = 0; r < n; r++)
        {
            if (nums[r] == 0)
                zeros++;

            // if zeros are greater than k, move the left pointer
            while (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;

                l++;
            }

            if (zeros <= k)
                maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }

    int longestOnesOpt(vector<int> &nums, int k)
    {
        int zeros = 0, maxLen = 0;
        int l = 0, n = nums.size();

        for (int r = 0; r < n; r++)
        {
            // If current element is 0, increment zerocount
            if (nums[r] == 0)
                zeros++;

            // If zero count exceeds k, move left pointer and adjust zerocount
            if (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            // Update the maximum window size
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }

public:
    int longestOnes(vector<int> &nums, int k)
    {
        // Brute Force
        // return longestOnesBrute(nums, k);

        // Better Appraoch
        // return longestOnesBetter(nums, k);

        // Optimal Approach
        return longestOnesOpt(nums, k);
    }
};

int main()
{
    int k = 2;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

    Solution sol;
    cout << sol.longestOnes(nums, k) << endl;
    return 0;
}