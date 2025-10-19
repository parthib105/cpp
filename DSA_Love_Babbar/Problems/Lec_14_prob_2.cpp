/*
    Find the square root of a given number using binary search
*/

#include<bits/stdc++.h>
using namespace std;

long long int squareRoot(int n)
{
    int i = 0;
    int j = n;
    long long int ans;

    while (i <= j)
    {
        long long int mid = i + (j - i) / 2;
        long long int sq = mid * mid;

        if (sq > n)
        {
            j = mid - 1;
        }
        else if (sq < n)
        {
            ans = mid;
            i = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j*j < n; j = j + factor)
        {
            ans = j;
        } 
    }
    return ans;
}

int main()
{//9814072356
    long long int n, p;
    cout << "Enter the number : ";
    cin >> n;

    cout << "Enter precision : ";
    cin >> p;    

    int tempSol = squareRoot(n);
    cout << "Solution lies in between " << tempSol << " and " << tempSol + 1 << endl;

    cout << "More precise solution : " << morePrecision(n, p, tempSol) << endl;
    return 0;
}