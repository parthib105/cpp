/*
    Matrix Chain Multiplication

    Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices. The cost of matrix multiplication is defined as the number of scalar multiplications. A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.

    For example:
    For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]

    Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.
    Detailed explanation ( Input/output format, Notes, Images )
    Sample Input 1:
    2
    4
    4 5 3 2
    4
    10 15 20 25
    Sample Output 1:
    70
    8000
    Sample Output Explanation 1:
    In the first test case, there are three matrices of dimensions A = [4 5], B = [5 3] and C = [3 2]. The most efficient order of multiplication is A * ( B * C).
    Cost of ( B * C ) = 5 * 3 * 2 = 30  and (B * C) = [5 2] and A * (B * C) = [ 4 5] * [5 2] = 4 * 5 * 2 = 40. So the overall cost is equal to 30 + 40 =70.

    In the second test case, there are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.

    If we multiply in order- A1*(A2*A3), then the number of multiplications required is 11250.

    If we multiply in order- (A1*A2)*A3, then the number of multiplications required is 8000.

    Thus a minimum number of multiplications required is 8000. 
    Sample Input 2:
    1
    4
    1 4 3 2
    Sample Output 2:
    18
    Explanation of Sample Output 2:
    In the first test case, there are three matrices of dimensions A = [1 4], B = [4 3] and C = [3 2]. The most efficient order of multiplication is (A *  B) * C .
*/

#include<bits/stdc++.h>
using namespace std;

int solveRecur(int i, int j, vector<int>& arr)
{
    if (i == j)
        return 0;
    
    int minSteps = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int part1 = solveRecur(i, k, arr);
        int part2 = solveRecur(k + 1, j, arr);
        int currSteps = arr[i - 1] * arr[k] * arr[j] + part1 + part2;
        minSteps = min(minSteps, currSteps);
    }
    return minSteps;
}

int solveRM(int i, int j, vector<int>& arr, vector<vector<int>>& dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int minSteps = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int part1 = solveRM(i, k, arr, dp);
        int part2 = solveRM(k + 1, j, arr, dp);
        int currSteps = arr[i - 1] * arr[k] * arr[j] + part1 + part2;
        minSteps = min(minSteps, currSteps);
    }
    dp[i][j] = minSteps;
    return dp[i][j];
}

int solveTab(int N, vector<int>& arr)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int minSteps = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int currSteps = arr[i - 1]*arr[k]*arr[j] + dp[i][k] + dp[k + 1][j];
                minSteps = min(minSteps, currSteps);
            }
            dp[i][j] = minSteps;
        }
    }
    return dp[1][N - 1];
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Using Recursion
    // return solveRecur(1, N - 1, arr);

    // Using Recursion + Memoization
    // vector<vector<int>> dp(N, vector<int>(N, -1));
    // return solveRM(1, N - 1, arr, dp);

    // Tabulation
    return solveTab(N, arr);
}

int main()
{
    int n = 10;
    vector<int> arr = {40, 32, 40, 39, 38, 40, 29, 43, 21, 47};
    cout << matrixMultiplication(arr, n) << endl; 
    return 0;
}