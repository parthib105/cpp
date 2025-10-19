#include <bits/stdc++.h>
using namespace std;

// Brute Force
int brute(int dividend, int divisor)
{
    if (abs(dividend) < abs(divisor))
    {
        return 0;
    }
    long long int n = abs(divisor);
    long long int cnt = 0;
    while (n + abs(divisor) <= abs(dividend))
    {
        n += abs(divisor);
        cnt += 1;
    }

    if ((divisor < 0 && dividend > 0) || (divisor > 0 && dividend < 0))
    {
        return (-cnt - 1);
    }
    return (cnt + 1);
}

// Better approach
int better(int dividend, int divisor)
{
    if (dividend == divisor)
    {
        return 1;
    }

    // deal the signs
    bool sign = true; // +ve
    if ((divisor < 0 && dividend >= 0) || (divisor > 0 && dividend <= 0))
    {
        sign = false;
    }

    long n = abs(dividend);
    long d = abs(divisor);
    divisor = abs(divisor);
    long quotient = 0;
    while (n >= d)
    {
        int cnt = 0;
        while (n >= (d << (cnt + 1)))
        {
            cnt += 1;
        }
        quotient += (1 << cnt);
        n = n - (d << cnt);
    }

    if (quotient == (1 << 31) && sign)
    {
        return INT_MAX;
    }
    if (quotient == (1 << 31) && !sign)
    {
        return INT_MIN;
    }
    return sign ? quotient : -quotient;
}

int divide(int dividend, int divisor)
{
    // Brute Force
    // return brute(dividend, divisor);

    // Better approach
    return better(dividend, divisor);
}

int main()
{

    return 0;
}