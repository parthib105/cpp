/*
    Count Number of Nice Subarrays

    Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

    Return the number of nice sub-arrays.

    Example 1:

    Input: nums = [1,1,2,1,1], k = 3
    Output: 2
    Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
    Example 2:

    Input: nums = [2,4,6], k = 1
    Output: 0
    Explanation: There are no odd numbers in the array.
    Example 3:

    Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    Output: 16


    Constraints:

    1 <= nums.length <= 50000
    1 <= nums[i] <= 10^5
    1 <= k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int previousApproach(vector<int> &nums, int k)
    {
        // make zero for even and 1 for odd
        for (int i = 0; i < nums.size(); i++)
            nums[i] = nums[i] % 2;

        // queue to store index of 1 (odd numbers)
        queue<int> q;
        int j = 0, ans = 0, oddCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // count the odd numbers and push its index
            if (nums[i] == 1)
            {
                oddCount += 1;
                q.push(i);
            }

            // if odd number count is greater than k, remove the odd numbers
            while (oddCount > k)
            {
                if (nums[j] == 1)
                    oddCount--;

                j++;
                if (q.front() < j)
                    q.pop();
            }

            if (oddCount == k)
                ans += q.front() - j + 1;
        }

        return ans;
    }

    int optimal(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;

        int curSum = 0, count = 0;
        int l = 0, n = nums.size();
        for (int r = 0; r < n; r++)
        {
            curSum += (nums[r] % 2);

            while (curSum > k)
            {
                curSum -= (nums[l] % 2);
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        // optimal appraoch
        return optimal(nums, k) - optimal(nums, k - 1);
    }
};

int main()
{
    int k = 3;
    vector<int> nums = {1, 1, 2, 1, 1}; 

    Solution sol;
    cout << sol.numberOfSubarrays(nums, k) << endl;
    return 0;
}