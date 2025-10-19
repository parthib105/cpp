/*
    -> Count Ways To Reach The N-th Stairs

    -> Problem statement
    
    You have been given a number of stairs. 
    Initially, you are at the 0th stair, and you need to reach the Nth stair.
    Each time, you can climb either one step or two steps.
    You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

    Example :
        N = 3

            We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or 
            we can climb the first two-step and then one step i.e. {(0,2),(1, 3)} or 
            we can climb first one step and then two step i.e. {(0,1), (1,3)}.

        output = 3
*/


#include<bits/stdc++.h>
using namespace std;

// using dp, we can find optimal solution, till now let's solve using recursion
int countDistinctWays(int nStairs)
{
    // base case
    if (nStairs < 0)
    {
        return 0;
    }

    if (nStairs == 0)
    {
        return 1;
    }

    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    cout << "No. of ways : " << countDistinctWays(n) << endl;
    return 0;
}