/*
    Sum of Two Arrays

    You are given two numbers 'A' and 'B' in the form of arrays (A[] and B[]) of length 'N' and
    'M' respectively, where each array element represents a digit. You need to find the sum of these
    two numbers and return this sum in the form of an array.

    Ex. A[] = {4, 5, 1} and B[] = {3, 4, 5}
    sum = 451 + 345 = 796
    you need to return {7, 9, 6}
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m)
{
    int size = max(m, n);
    vector<int> ans(size, 0);

    int i = n - 1;
    int j = m - 1;
    int k = size - 1;

    int carry = 0;
    int sum;
    while (i >= 0 || j >= 0)
    {
        if (i >= 0 && j >= 0)
        {
            sum = a[i] + b[j] + carry;
        }
        else if (i >= 0 && j < 0)
        {
            sum = a[i] + carry;
        }
        else if (j >= 0 && i < 0)
        {
            sum = b[j] + carry;
        }

        if (sum >= 10)
        {
            ans[k] = sum % 10;
            k --;
            carry = 1;
        }
        else
        {
            ans[k] = sum;
            k --;
            carry = 0;
        }
        i --;
        j --;
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 1};
    vector<int> b = {1, 2};
    int n = 2;
    int m = 2;

    vector<int> ans = findArraySum(a, n, b, m);
    for (int i = 0; i < max(n, m); i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}