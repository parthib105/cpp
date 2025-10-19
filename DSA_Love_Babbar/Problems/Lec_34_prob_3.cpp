/*
    power of 2 using recursion
*/

#include<bits/stdc++.h>
using namespace std;

long long int power(int a, int b)
{
    // base case
    if (b == 0)
    {
        return 1LL * 1;
    }

    if (b&1)
    {
        return 1LL * a * power(a, b/2) * power(a, b/2);
    }
    else
    {
        return 1LL * power(a, b/2) * power(a, b/2);
    }
}

long long int powerRecur(int a, int n, long long int mod) 
{

    if (n == 0) 
    {
        return 1;
    }

    long long int temp = power(a, n/2) % mod;

    if (n & 1) 
    {
        return (((temp * temp) % mod) * (a % mod)) % mod;
    }
    
    return (temp * temp) % mod;
}


int main()
{
    int a, b;
    cout << "Enter the numbers a and b : ";
    cin >> a >> b;
    
    cout << "Power : " << power(a, b) << endl;

    return 0;
}