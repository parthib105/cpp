/*
    Maximum Meetings in One Room

    There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of
    meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be
    accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than
    the finish time of the previous meeting. Print all meeting numbers.

    Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.

    Example 1:

    Input:
    N = 6
    S = {1,3,0,5,8,5}
    F = {2,4,6,7,9,9}
    Output:
    {1,2,4,5}
    Explanation:
    We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.

    Example 2:

    Input:
    N = 1
    S = {3}
    F = {7}
    Output:
    {1}
    Explanation:
    Since there is only one meeting, we can attend the meeting.

    Expected Time Complexity: O(N*log(N))
    Expected Auxiliary Space: O(N)

    Constraints:
    1 <= N <= 10^5
    0 <= S[i] <= F[i] <= 10^9
    Sum of N over all test cases doesn't exceeds 10^6
*/

#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.first.second < b.first.second;
}

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    if (N == 1)
    {
        return {1};
    }

    vector<pair<pair<int, int>, int>> meet;
    for (int i = 0; i < N; i++)
    {
        meet.push_back({{S[i], F[i]}, i + 1});
    }

    sort(meet.begin(), meet.end(), cmp);

    vector<int> ans;
    ans.push_back(meet[0].second);
    int lastMeet = meet[0].first.second;
    for (int i = 1; i < N; i++)
    {
        if (meet[i].first.first > lastMeet)
        {
            ans.push_back(meet[i].second);
            lastMeet = meet[i].first.second;
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int N = 6;
    vector<int> S = {1, 3, 0, 5, 8, 5};
    vector<int> F = {2, 4, 6, 7, 9, 9}; 
    vector<int> arr = maxMeetings(N, S, F);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}