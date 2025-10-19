/*
    Find Peak Element

    A peak element is an element that is strictly greater than its neighbors.

    Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

    You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

    You must write an algorithm that runs in O(log n) time.

    Example 1:

    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.
    Example 2:

    Input: nums = [1,2,1,3,5,6,4]
    Output: 5
    Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
    

    Constraints:

    1 <= nums.length <= 1000
    -2^31 <= nums[i] <= 2^31 - 1
    nums[i] != nums[i + 1] for all valid i.
*/

#include <bits/stdc++.h>
using namespace std;

// brute force - O(n)
int bruteForce(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || nums[i - 1] < nums[i]) && (i == n - 1 || nums[i] > nums[i + 1]))
        {
            return i;
        }
    }
    return -1; // no peak element found
}

// optimal approach using binary search - O(log(n))
int optimalApproach(vector<int>& nums)
{
    if (nums.size() == 1) return 0;

    // edge cases
    int n = nums.size();
    if (nums[0] > nums[1]) return 0;
    if (nums[n - 1] > nums[n - 2]) return n - 1;

    // perform binary search
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (nums[mid] > nums[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int findPeakElement(vector<int>& nums)
{
    // Brute Force approach
    // return bruteForce(nums);

    // optimal approach
    return optimalApproach(nums);
}

int main()
{
    vector<int> nums = {1, 10, 13, 7, 6, 5, 4, 2, 1, 0};
    int idx = findPeakElement(nums);
    if (idx == -1)
    {
        cout << "No peak element exists" << endl;
    }
    else
    {
        cout << "peak element is at index : " << idx << " , and the element is : " << nums[idx] << endl;
    }
    return 0;
}