/*
    Combination Sum IV

    You are given an array of distinct integers and you have to tell how many different ways of selecting the elements from 
    the array are there such that the sum of chosen elements is equal to the target number tar.

    Note: Two ways are considered the same if for every index the contents of both the ways are equal example way1=[1,2,3,1] 
    and way2= [1,2,3,1] both way1 and way 2 are the same.

    But if way1 =[1,2,3,4] and way2= [4,3,2,1] then both ways are different.

    Input is given such that the answer will fit in a 32-bit integer. 
    For Example:
        If N = 3 and tar = 5 and array elements are [1,2,5] then the number of possible ways of making sum = 5 are:
        (1,1,1,1,1)
        (1,1,1,2)
        (1,2,1,1)
        (2,1,1,1)
        (1,1,2,1)
        (2,2,1)
        (1,2,2)
        (2,1,2)
        (5)
    Hence the output will be 9.
    
    Constraints:
    1 <= N <= 200
    1 <= nums[i] <= 1000
    All the elements will be unique
    1 <= tar <= 1000

    Time limit: 1 sec

    Sample Input 1 :
    3 5
    1 2 5

    2 3
    1 2

    Sample output 1 :
    9
    3

    Explanation For Sample Output 1:
    For the first test case, the number of possible ways will be
    (1,1,1,1,1)
    (1,1,1,2)
    (1,2,1,1)
    (2,1,1,1)
    (1,1,2,1)
    (2,2,1)
    (1,2,2)
    (2,1,2)
    (5)

    For the second test case, the number of ways will be
    (1,1,1)
    (1,2)
    (2,1)
    Here you can see we have considered (1,2) and (2,1) in 2 different ways.

    Sample Input 2 :
    3 4
    12 1 3
    2 41
    2 34
    Sample output 2 :
    3
    0
*/

#include<bits/stdc++.h>
using namespace std;

// Recursive way
int solveRecur(vector<int> &num, int tar)
{
    if (tar < 0)
    {
        return 0;
    }
    if (tar == 0)
    {
        return 1;
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveRecur(num, tar - num[i]);
    }
    return ans;
}

// Recursion + Memoization
int solveRM(vector<int> &num, vector<int> &dp, int tar)
{
    if (tar < 0)
    {
        return 0;
    }
    if (tar == 0)
    {
        return 1;
    }

    if (dp[tar] != -1)
    {
        return dp[tar];
    }

    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveRM(num, dp, tar - num[i]);
    }
    dp[tar] = ans;
    return dp[tar];
}

// Tabulation
int solveTab(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0)
            {
                dp[i] += dp[i - num[j]];
            }
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // Recursive Approach
    // return solveRecur(num, tar);

    // Recursion + Memoization
    vector<int> dp(tar + 1, -1);
    return solveRM(num, dp, tar);

    // Tabulation
    return solveTab(num, tar);
}

int main()
{
    int tar = 5;
    vector<int> num = {1, 2, 5};
    cout << "No. of ways : " << findWays(num, tar) << endl;
    return 0;
}