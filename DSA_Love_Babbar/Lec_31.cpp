// Recursion : When a function calls itself

/*
    When we encounter a big problem whose solution depend on the same type of smaller problem
    we use recursion.

    Ex : 2^6 = 2 * 2^5 => 2^n = 2 * 2^(n-1) 
        => f(n) = 2 * f(n-1)

    Required : 
        -> base case (where to stop)
        -> recurrence relation
*/ 

#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

// fibonacci numbers up to n terms
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 2) + fibonacci(n - 1);
} 

// fibonacci numbers up to n
void printfib(int a, int b, int n)
{
    if (a > n)
    {
        return;
    }
    cout << a << " ";
    printfib(b, a + b, n);
}

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    // cout << "factorial of " << n << " , is : " << factorial(n) << endl;

    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }

    printfib(0, 1, n);

    return 0;
}