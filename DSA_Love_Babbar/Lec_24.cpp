// Sieve of Eratosthenes
/*
    Count Primes

    Given an integer n, return the number of prime numbers that are strictly less than n
*/
#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n)
{
    vector<int> prime (n + 1, true);
    prime[0] = prime[1] = false;
    int count = 0;

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            count ++;
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return count;
}

// Modular Exponentiation

// You are given a three integers 'X', 'N', and 'M'. 
// Your task is to find ('X' ^ 'N') % 'M'. 
// A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
int modularExponentiation(int x, int n, int m)
{
    long long int res = 1;

    while (n > 0)
    {
        if (n&1)    // check if odd
        {
            res = (res * (x%m)) % m;
        }
        x = (1LL * (x%m) * (x%m)) % m;
        n = n >> 1;             // divide by 2
    }
    return res;
}

int main()
{
    int n = 40;
    cout << countPrimes(n) << endl;
    return 0;
}