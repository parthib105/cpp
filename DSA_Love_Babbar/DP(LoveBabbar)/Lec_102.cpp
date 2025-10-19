/*
    Dynamic Programming is a method used in mathematics and computer science to solve complex problems by breaking them down 
    into simpler subproblems. By solving each subproblem only once and storing the results, it avoids redundant computations, 
    leading to more efficient solutions for a wide range of problems.

    How Does Dynamic Programming (DP) Work?
        -> Identify Subproblems: Divide the main problem into smaller, independent subproblems.
        -> Store Solutions: Solve each subproblem and store the solution in a table or array.
        -> Build Up Solutions: Use the stored solutions to build up the solution to the main problem.
        -> Avoid Redundancy: By storing solutions, DP ensures that each subproblem is solved only once, reducing computation 
           time.

    When to Use Dynamic Programming (DP)?
        # Dynamic programming is an optimization technique used when solving problems that consists of the following 
          characteristics:

        1. Optimal Substructure: Optimal substructure means that we combine the optimal results of subproblems to achieve 
           the optimal result of the bigger problem.

        Example:
           Consider the problem of finding the minimum cost path in a weighted graph from a source node to a destination node. 
           We can break this problem down into smaller subproblems:

           -> Find the minimum cost path from the source node to each intermediate node.
           -> Find the minimum cost path from each intermediate node to the destination node.

           The solution to the larger problem (finding the minimum cost path from the source node to the destination node) can 
           be constructed from the solutions to these smaller subproblems.

        2. Overlapping Subproblems: The same subproblems are solved repeatedly in different parts of the problem.

        Example:
           Consider the problem of computing the Fibonacci series. To compute the Fibonacci number at index n, we need to 
           compute the Fibonacci numbers at indices n-1 and n-2. This means that the subproblem of computing the Fibonacci 
           number at index n-1 is used twice in the solution to the larger problem of computing the Fibonacci number at index 
           n.
    
    Approaches of Dynamic Programming (DP)
        # Dynamic programming can be achieved using two approaches:

        1. Top-Down Approach (Memoization):
            -> In the top-down approach, also known as memoization, we start with the final solution and recursively break it 
               down into smaller subproblems. To avoid redundant calculations, we store the results of solved subproblems in a 
               memoization table.

            -> Let’s breakdown Top down approach:
               => Starts with the final solution and recursively breaks it down into smaller subproblems.
               => Stores the solutions to subproblems in a table to avoid redundant calculations.
               => Suitable when the number of subproblems is large and many of them are reused.
    
        2. Bottom-Up Approach (Tabulation):
            -> In the bottom-up approach, also known as tabulation, we start with the smallest subproblems and gradually 
               build up to the final solution. We store the results of solved subproblems in a table to avoid redundant 
               calculations.

            -> Let’s breakdown Bottom-up approach:
               => Starts with the smallest subproblems and gradually builds up to the final solution.
               => Fills a table with solutions to subproblems in a bottom-up manner.
               => Suitable when the number of subproblems is small and the optimal solution can be directly computed from the 
                  solutions to smaller subproblems.
*/

/*
    Nth Fibonacci Number

    The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -

    F(n) = F(n - 1) + F(n - 2), 
    Where, F(1) = 1, F(2) = 1

    Provided 'n' you have to find out the n-th Fibonacci Number. Handle edges cases like when 'n' = 1 or 'n' = 2 by using 
    conditionals like if else and return what's expected.

    "Indexing is start from 1"

    Example :
    Input: 6

    Output: 8

    Explanation: The number is ‘6’ so we have to find the “6th” Fibonacci number.
    So by using the given formula of the Fibonacci series, we get the series:    
    [ 1, 1, 2, 3, 5, 8, 13, 21]
    So the “6th” element is “8” hence we get the output.
*/

#include<bits/stdc++.h>
using namespace std;

// Memoization : T.C. -> O(n), S.C. -> O(n) + O(n)
int fibMemo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
    return dp[n];
}

// Tabulation : T.C. -> O(n), S.C. -> O(n)
int fibTab(int n)
{
    vector<int> dp(n+1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Space Optimization : T.C. -> O(n), S.C. -> O(1)
int fibSO(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1, -1);

    cout << "Nth fibonacci number : " << fibSO(n) << endl;
    return 0;
}