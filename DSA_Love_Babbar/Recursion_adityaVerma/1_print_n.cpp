/*
    Print numbers 1 to n using recursion
*/

#include<bits/stdc++.h>
using namespace std;

void printNum(int n)
{
    if (n == 0)
    {
        return;
    }
    printNum(n - 1);
    cout << n << " ";
}

int main()
{
    int n = 7;
    printNum(n);
    return 0;
}