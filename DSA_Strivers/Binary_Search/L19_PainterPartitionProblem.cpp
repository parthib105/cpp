/*
    Painter's Partition Problem

    Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

    You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

    Example :
    Input: arr = [2, 1, 5, 6, 2, 3], k = 2

    Output: 11

    Explanation:
    First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.

    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1 :
    4 2
    10 20 30 40

    Sample Output 1 :
    60

    Explanation For Sample Input 1 :
    In this test case, we can divide the first 3 boards for one painter and the last board for the second painter.

    Sample Input 2 :
    2 2
    48 90

    Sample Output 2 :
    90

    Expected Time Complexity:
    Try to do this in O(n*log(n)).

    Constraints :
    1 <= n <= 10^5
    1 <= k <= n
    1 <= arr[i] <= 10^9

    Time Limit: 1 sec.
*/

#include<bits/stdc++.h>
using namespace std;

bool canPaint(int cost, int k, vector<int> &boards)
{
    int painters = 1, currCost = 0;
    for (auto board : boards)
    {
        if (currCost + board > cost) {
            painters += 1;
            if (painters > k || board > cost) {
                return false;
            }
            currCost = board;
        }
        else {
            currCost += board;
        }
    }

    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canPaint(mid, k, boards))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int k = 2;
    vector<int> boards = {10, 20, 30, 40};
    cout << findLargestMinDistance(boards, k) << endl;
    return 0;
}