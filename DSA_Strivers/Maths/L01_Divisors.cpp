/*
    Print all the divisors of a number N
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(n), S.C. : O(1)
vector<int> brute(int N)
{
    vector<int> div;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            div.push_back(i);
        }
    }
    return div;
}

// T.C. : O(sqrt(N)), S.C. : O(1)
vector<int> better(int N)
{
    vector<int> div;
    for (int i = 1; i <= sqrt(N); i++)
    {
        if (N % i == 0)
        {
            div.push_back(i);
            if (N / i != i)
            {
                div.push_back(N/i);
            }
        }
    }
    return div;
}

vector<int> numberOfDivisors(int N)
{
    // brute force
    // return brute(N);

    // better
    return better(N);
}

int main()
{
    int N = 99;
    vector<int> divs = numberOfDivisors(N);

    for (auto it : divs)
    {
        cout << it << " ";
    }
    return 0;
}