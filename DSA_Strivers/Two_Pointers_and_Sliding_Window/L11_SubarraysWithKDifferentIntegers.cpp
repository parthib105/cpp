/*
    Subarrays with K Different Integers

    Given an integer array nums and an integer k, return the number of good subarrays of nums.

    A good array is an array where the number of different integers in that array is exactly k.

    For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
    A subarray is a contiguous part of an array.



    Example 1:

    Input: nums = [1,2,1,2,3], k = 2
    Output: 7
    Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
    Example 2:

    Input: nums = [1,2,1,3,4], k = 3
    Output: 3
    Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].


    Constraints:

    1 <= nums.length <= 2 * 10^4
    1 <= nums[i], k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // T.C. : O(N^2), S.C. : O(N)
    int brute(vector<int> &nums, int k)
    {
        int cnt = 0, n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq.clear();
            for (int j = i; j < n; j++)
            {
                freq[nums[j]]++;
                if (freq.size() == k)
                    cnt += 1;
                else if (freq.size() > k)
                    break;
            }
        }
        return cnt;
    }

    // T.C. : O(2*N), S.C. : O(N)
    int optimal(vector<int> &nums, int k)
    {
        int cnt = 0, n = nums.size();
        unordered_map<int, int> freq;

        int l = 0;
        for (int r = 0; r < n; r++)
        {
            freq[nums[r]]++;

            while (freq.size() > k)
            {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                l++;
            }

            if (freq.size() <= k)
                cnt += (r - l + 1);
        }
        return cnt;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // brute force
        // return brute(nums, k);

        // Optimal
        return optimal(nums, k) - optimal(nums, k - 1);
    }
};

int main()
{
    int k = 2;
    vector<int> nums = {1, 2, 1, 2, 3};

    Solution sol;
    cout << sol.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}