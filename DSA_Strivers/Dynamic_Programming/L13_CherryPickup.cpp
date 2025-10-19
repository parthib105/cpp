/*
    Chocolate Pickup

    Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

    Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

    If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

    Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

    Example:
    Input: ‘R’ = 3, ‘C’ = 4
        ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
    Output: 21

    Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.

    Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.

    Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.
    Detailed explanation ( Input/output format, Notes, Images )
    Constraints :
    1 <= ‘T’ <= 10
    2 <= 'R', 'C' <= 50
    0 <= 'GRID[i][j]'<= 10^2
    Time Limit: 1sec
    Sample Input 1 :
    2
    3 4
    2 3 1 2
    3 4 2 2
    5 6 3 5
    2 2
    1 1
    1 2
    Sample Output 1 :
    21
    5
    Explanation Of Sample Input 1 :
    For the first test case, Initially Alice is at the position (0, 0) he can follow the path (0, 0) -> (1, 1) -> (2, 1) and will collect 2 + 4 + 6 = 12 chocolates.

    Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1, 3) -> (2, 3) and will collect 2 + 2 + 5 = 9 chocolates.

    Hence the total number of chocolates collected will be 12 + 9 = 21.

    For the second test case, Alice will follow the path (0, 0) -> (1, 0) and Bob will follow the path (0, 1) -> (1, 1). total number of chocolates collected will be 1 + 1 + 1 + 2 = 5
    Sample Input 2 :
    2
    2 2
    3 7
    7 6
    3 2
    4 5
    3 7
    4 2
    Sample Output 2 :
    23
    25
*/

#include<bits/stdc++.h>
using namespace std;

/* 
    Alice and bob are changing row simultaneously i.e., if alice is in ith row, 
    then bob has to be on that row
*/
int solveRecur(int i, int ja, int jb, int r, int c, vector<vector<int>> &grid)
{
    if (ja < 0 || ja >= c || jb < 0 || jb >= c)
        return -1e8;
    if (i == r - 1)
    {
        if (ja == jb)
            return grid[i][ja];
        else
            return grid[i][ja] + grid[i][jb];
    }

    // all possible movements
    int maxChoco = INT_MIN;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int currChoco = 0;
            if (ja == jb)
                int currChoco = grid[i][ja];
            else
                currChoco = grid[i][ja] + grid[i][jb];
            
            currChoco += solveRecur(i + 1, ja + dj1, jb + dj2, r, c, grid);
            maxChoco = max(maxChoco, currChoco);
        }
    }
    return maxChoco;
}

int solveRM(int i, int ja, int jb, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp)
{
    if (ja < 0 || ja >= c || jb < 0 || jb >= c)
        return -1e8;
    if (i == r - 1)
    {
        if (ja == jb)
            return grid[i][ja];
        else
            return grid[i][ja] + grid[i][jb];
    }

    if (dp[i][ja][jb] != -1)
        return dp[i][ja][jb];

    // all possible movements
    int maxChoco = INT_MIN;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int currChoco = 0;
            if (ja == jb)
                int currChoco = grid[i][ja];
            else
                currChoco = grid[i][ja] + grid[i][jb];
            
            currChoco += solveRM(i + 1, ja + dj1, jb + dj2, r, c, grid, dp);
            maxChoco = max(maxChoco, currChoco);
        }
    }

    dp[i][ja][jb] = maxChoco;
    return dp[i][ja][jb];
}

int solveTab(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    // base case
    for (int ja = 0; ja < c; ja++)
    {
        for (int jb = 0; jb < c; jb++)
        {
            if (ja == jb)
                dp[r - 1][ja][jb] = grid[r - 1][ja];
            else
                dp[r - 1][ja][jb] = grid[r - 1][ja] + grid[r - 1][jb];
        }
    }

    for (int i = r - 2; i >= 0; i--)
    {
        for (int ja = 0; ja < c; ja++)
        {
            for (int jb = 0; jb < c; jb++)
            {
                int maxChoco = INT_MIN;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int currChoco = 0;
                        if (ja == jb)
                            int currChoco = grid[i][ja];
                        else
                            currChoco = grid[i][ja] + grid[i][jb];
                        
                        if (ja + dj1 >= 0 && ja + dj1 < c && jb + dj2 >= 0 && jb + dj2 < c)
                            currChoco += dp[i + 1][ja + dj1][jb + dj2];
                        else   
                            currChoco += -1e8;

                        maxChoco = max(maxChoco, currChoco);
                    }
                }
                dp[i][ja][jb] = maxChoco;
            }
        }
    }

    return dp[0][0][c - 1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    // Recursion
    // return solveRecur(0, 0, c - 1, r, c, grid);

    // Recursion + Memoization
    // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    // return solveRM(0, 0, c - 1, r, c, grid, dp);

    // Tabulation
    return solveTab(r, c, grid);
}

int main()
{
    
    return 0;
}