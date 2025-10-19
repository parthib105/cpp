/*
    Minimize Max Distance to Gas Station

    We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
    Note: stations is in a strictly increasing order.

    Example 1:

    Input:
    n = 10
    stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    k = 9
    Output: 0.50
    Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.

    Example 2:

    Input:
    n = 10
    stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95]
    k = 2
    Output: 14.00
    Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.

    Your Task:
    You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer k as inputs and returns the smallest possible value of d. Find the answer exactly to 2 decimal places.

    Constraint:
    10 <= n <= 10000
    0 <= stations[i] <= 10^9
    0 <= k <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

long double bruteForce(vector<int> &stations, int k)
{
    int n = stations.size();
    vector<int> howMany(n - 1, 0); // how many sections (n - 1)

    for (int gs = 1; gs <= k; gs++)
    {
        long double maxSection = -1;
        int maxIdx = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = stations[i + 1] - stations[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxIdx = i;
            }
        }
        howMany[maxIdx] += 1;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = stations[i + 1] - stations[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

long double optimal(vector<int> &stations, int k)
{
    int n = stations.size();
    vector<int> howMany(n - 1, 0);             // how many sections (n - 1)
    priority_queue<pair<long double, int>> pq; // stores (section length, section index)

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = (long double)(stations[i + 1] - stations[i]);
        pq.push({diff, i});
    }

    for (int gs = 1; gs <= k; gs++)
    {
        int secIdx = pq.top().second;
        pq.pop();

        howMany[secIdx] += 1;
        long double initDiff = stations[secIdx + 1] - stations[secIdx];
        long double newSecLen = initDiff / (long double)(howMany[secIdx] + 1);
        pq.push({newSecLen, secIdx});
    }

    return round(pq.top().first * 100.0) / 100.0;
}

int noOfGasStationsReq(long double dist, vector<int> &arr)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int noInBet = (arr[i] - arr[i - 1]) / dist;
        if ((arr[i] - arr[i - 1]) / dist == noInBet * dist)
        {
            noInBet--;
        }
        cnt += noInBet;
    }
    return cnt;
}

long double binarySearch(vector<int> &stations, int k)
{
    int n = stations.size();
    long double low = 0, high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(stations[i + 1] - stations[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / (2.0);
        int cnt = noOfGasStationsReq(mid, stations);
        if (cnt > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}

long double minimiseMaxDistance(vector<int> &stations, int k)
{
    // Brute Force solution
    // return bruteForce(stations, k);

    // Binary search Solution
    return binarySearch(stations, k);
}

int main()
{
    vector<int> stations = {3, 6, 12, 19, 33, 44, 67, 72, 89, 95};
    int k = 7;
    cout << minimiseMaxDistance(stations, k) << endl;
    return 0;
}