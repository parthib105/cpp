/*
    Prime Number Algorithms and Sieve Techniques

    A prime number is a natural number greater than 1 that has exactly two distinct positive divisors — 1 and itself.

    Basic Primality Check: To check if a number n is prime, try dividing it by numbers from 2 to n-1. If any number divides it, then n is not prime; otherwise, it is.

    Optimized Method (Square Root Check): We only need to check up to √n because if n has a factor larger than √n, the corresponding smaller factor must be less than √n.So, if no number from 2 to √n divides n, then n is prime.

    Sieve of Eratosthenes: The Sieve of Eratosthenes is an efficient algorithm to find all prime numbers up to a given number n.

    Note: It is much faster than checking each number individually using the basic method.
*/

#include<bits/stdc++.h>
using namespace std;

// Optimized method
bool isPrime(int n) 
{
    if (n <= 1)     // Check if n is 1 or 0
        return false;

    if (n == 2 || n == 3)      // Check if n is 2 or 3
        return true;

    if (n % 2 == 0 || n % 3 == 0)   // Check whether n is divisible by 2 or 3
        return false;
    
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(n); i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    int n = 7;  
  	if(isPrime(n)) 
        cout << "true";
  	else 
        cout<<"false";
    return 0;
}