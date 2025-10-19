/*
    Median in a row-wise sorted Matrix

    Given a row-wise sorted matrix mat[][] where the number of rows and columns is always odd. Return the median of the matrix.

    Examples:

    Input: mat[][] = [[1, 3, 5], 
                    [2, 6, 9], 
                    [3, 6, 9]]
    Output: 5
    Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
    Input: mat[][] = [[2, 4, 9],
                    [3, 6, 7],
                    [4, 7, 10]]
    Output: 6
    Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
    Input: mat = [[3], [4], [8]]
    Output: 4
    Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
    Constraints:
    1 ≤ mat.size(), mat[0].size() ≤ 400
    1 ≤ mat[i][j] ≤ 2000
*/

#include<bits/stdc++.h>
using namespace std;

int upperBound(int x, int n, vector<int> &arr)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int countLessEqual(int x, int m, int n, vector<vector<int>> &mat)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += upperBound(x, n, mat[i]);
    }
    return cnt;
}


// T.C. : O(mn log(mn)), S.C.: O(mn)
int _matrixMedianBrute(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    int req = (m*n)/2 + 1;
    priority_queue<int> pq;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pq.push(mat[i][j]);
            if (pq.size() > req)
                pq.pop();
        }
    }

    return pq.top();
}

// T.C.: O(log(max - min)*m*log(n)), S.C. : O(1)
int _matrixMedianBS(vector<vector<int>> &mat)
{
    int low = INT_MAX, high = INT_MIN;
    int m = mat.size(), n = mat[0].size();

    // get the min and max element
    for (int i = 0; i < m; i++)
    {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][n - 1]);
    }

    // apply binary search
    int req = (m * n) / 2;
    while (low <= high)
    {
        int mid = low + (high - mid)/2;
        int lessEqual = countLessEqual(mid, m, n, mat);
        if (lessEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}


int matrixMedian(vector<vector<int>> &mat) 
{
    // Brute Force approach
    // return _matrixMedianBrute(mat);  

    // Optimal solution
    return _matrixMedianBS(mat);
}

int main()
{
    vector<vector<int>> mat = {{2, 4, 9}, {3, 6, 7}, {4, 7, 10}};
    cout << matrixMedian(mat) << endl;
    return 0;
}