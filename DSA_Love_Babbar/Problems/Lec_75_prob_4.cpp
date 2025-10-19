/*
    Minimum Cost of ropes

    There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes
    is equal to sum of their lengths.
    The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes.

    Input:

    n = 5
    arr[] = {4, 2, 7, 6, 9}

    Output: 
    62 

    Explanation:

    First, connect ropes 4 and 2, which makes the array {6,7,6,9}. Cost of this operation 4+2 = 6. 
    Next, add ropes 6 and 6, which results in {12,7,9}. Cost of this operation 6+6 = 12.
    Then, add 7 and 9, which makes the array {12,16}. Cost of this operation 7+9 = 16. 
    And finally, add these two which gives {28}.
    
    Hence, the total cost is 6 + 12 + 16 + 
    28 = 62.
*/

#include <bits/stdc++.h>
using namespace std;

long long int minCost(vector<long long int> arr, long long int n)
{
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    long long ans = 0;
    while (pq.size() > 1)
    {
        long long n1 = pq.top();
        pq.pop();

        long long n2 = pq.top();
        pq.pop();

        ans += (n1 + n2);
        pq.push(n1 + n2);
    }
    return ans;
}

int main()
{
    long long int n = 5;
    vector<long long int> arr = {4, 2, 7, 6, 9};

    cout << "Minimum cose : " << minCost(arr, n) << endl;

    return 0;
}