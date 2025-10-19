/*
    Find Kth Rotation

    Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
    Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
    After 1st Rotation : [9, 2, 4, 6]
    After 2nd Rotation : [6, 9, 2, 4]

    Examples:

    Input: arr = [5, 1, 2, 3, 4]
    Output: 1
    Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was
                 rotated 1 times to the right.

    Input: arr = [1, 2, 3, 4, 5]
    Output: 0
    Explanation: The given array is not rotated.

    Expected Time Complexity: O(log(n))
    Expected Auxiliary Space: O(1)

    Constraints:
    1 <= n <=10^5
    1 <= arri <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    // Find the minimum
    int l = 0, r = arr.size() - 1, minIdx = 0;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[l] <= arr[r] && arr[l] < arr[minIdx])
        {
            minIdx = l;
            break;
        }

        if (arr[l] <= arr[m])
        {
            if (arr[l] < arr[minIdx])
            {
                minIdx = l;
            }
            l = m + 1;
        }
        else
        {
            if (arr[m] < arr[minIdx])
            {
                minIdx = m;
            }
            r = m - 1;
        }
    }

    return minIdx;
}

int main()
{
    vector<int> arr = {5, 6, 7, 1, 3, 4};

    cout << "Right rotated : " << findKRotation(arr) << " times." << endl;
    return 0;
}