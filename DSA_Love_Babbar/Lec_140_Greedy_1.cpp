/*
    N meetings in one room

    You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and
    end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single
    meeting room, when only one meeting can be held in the meeting room at a particular time.

    Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

    Examples :

    Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
    Output: 4
    Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7)
    and (8,9)

    Input: n = 3, start[] = [10, 12, 20], end[] = [20, 25, 30]
    Output: 1
    Explanation: Only one meetings can be held with given start and end timings.

    Expected Time Complexity: O(n*logn)
    Expected Auxilliary Space: O(n)

    Constraints:
    1 <= n <= 10^5
    0 <= start[i] < end[i] <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxMeetings(int n, int start[], int end[])
{
    vector<pair<int, int>> meet;
    for (int i = 0; i < n; i++)
    {
        meet.push_back({start[i], end[i]});
    }

    // sort according to ending time
    sort(meet.begin(), meet.end(), cmp);

    int meetings = 1;
    int lastMeet = meet[0].second;
    for (int i = 1; i < n; i++)
    {
        if (meet[i].first > lastMeet)
        {
            meetings++;
            lastMeet = meet[i].second;
        }
    }
    return meetings;
}

int main()
{
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] =  {2, 4, 6, 7, 9, 9};

    cout << maxMeetings(n, start, end) << endl;
    return 0;
}