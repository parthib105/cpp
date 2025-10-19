/*
    Aggressive Cow Problem
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount ++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int maxim = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxim = max(stalls[i], maxim);
    }
    
    int i = 0;
    int j = maxim;
    int ans;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (isValid(stalls, k, mid))
        {
            i = mid + 1;
            ans = mid;
        }
        else
        {
            j = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> stalls = {4, 2, 1, 3, 6};
    int k = 2;
    cout << aggressiveCows(stalls, k) << endl;
    return 0;
}