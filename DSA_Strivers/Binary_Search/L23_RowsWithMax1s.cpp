/*
    Row with max 1s

    You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

    Note:

    The array follows 0-based indexing.
    The number of rows and columns in the array are denoted by n and m respectively.
    Examples:

    Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
    Output: 2
    Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.
    Input: arr[][] = [[0,0], [1,1]]
    Output: 1
    Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
    Input: arr[][] = [[0,0], [0,0]]
    Output: -1
    Explanation: No row contains any 1s, so the output is -1.
    Constraints:
    1 ≤ arr.size(), arr[i].size() ≤ 10^3
    0 ≤ arr[i][j] ≤ 1
*/

#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<vector<int>> &mat)
{
    int idx = 0, maxOnes = 0;
    int m = mat.size(), n = mat[0].size();

    for (int i = 0; i < m; i++)
    {
        int currOnes = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
                currOnes += 1;
        }

        if (currOnes > maxOnes)
        {
            maxOnes = currOnes;
            idx = i;
        }
    }
    return idx;
}

int lowerBound(int x, int n, vector<int> &arr)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int binarySearch(vector<vector<int>> &mat)
{
    int idx = -1, maxOnes = 0;
    int m = mat.size();

    for (int i = 0; i < m; i++)
    {
        int n = mat[i].size();
        int currOnes = n - lowerBound(1, n, mat[i]);

        if (currOnes > maxOnes)
        {
            maxOnes = currOnes;
            idx = i;
        }
    }
    return idx;
}

int rowWithMax1s(vector<vector<int>> &arr)
{
    // Brute force soiution
    // return bruteForce(mat);

    // Binary search solution
    return binarySearch(arr);
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    cout << rowWithMax1s(arr) << endl;
    return 0;
}