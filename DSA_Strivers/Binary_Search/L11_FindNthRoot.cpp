/*
    You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

    Examples :

    Input: n = 2, m = 9
    Output: 3
    Explanation: 32 = 9
    Input: n = 3, m = 9
    Output: -1
    Explanation: 3rd root of 9 is not integer.
    Input: n = 1, m = 14
    Output: 14
    Constraints:
    1 <= n <= 30
    1 <= m <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

// returns 0 < m
// returns 1 == m
// returns 2 > m
int mult(int num, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * num;
        if (ans > m)
        {
            return 2;
        }
    }

    if (ans == m)
    {
        return 1;
    }
    return 0;
}

int nthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int check = mult(mid, n, m);
        if (check == 1)
        {
            return mid;
        }
        else if (check == 0)
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

int main()
{
    int n = 9, m = 262144;
    cout << nthRoot(n, m) << endl;
    return 0;
}