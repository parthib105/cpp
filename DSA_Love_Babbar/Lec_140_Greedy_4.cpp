/*
    Chocolate Distribution Problem

    Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet.
    Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets
    among M students such that :
    1. Each student gets exactly one packet.
    2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a
       student is minimum.

    Example 1:

    Input:
    N = 8, M = 5
    A = {3, 4, 1, 9, 56, 7, 9, 12}
    Output: 6
    Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following
                 M packets :{3, 4, 9, 7, 9}.

    Example 2:

    Input:
    N = 7, M = 3
    A = {7, 3, 2, 4, 9, 12, 56}
    Output: 2
    Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following
                 M packets :{3, 2, 4}.


    Expected Time Complexity: O(N*Log(N))
    Expected Auxiliary Space: O(1)

    Constraints:
    1 <= T <= 100
    1 <= N <= 10^5
    1 <= Ai <= 10^9
    1 <= M <= N
*/

#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long long minElm = 100000000005;
    for (int i = m - 1; i < n; i++)
    {
        long long diff = a[i] - a[i - m + 1];
        minElm = min(minElm, diff);
    }
    return minElm;
}

int main()
{
    long long N = 8, M = 5;
    vector<long long> A = {3, 4, 1, 9, 56, 7, 9, 12};
    cout << findMinDiff(A, N, M) << endl;
    return 0;
}