/*
    Missing And Repeating Numbers

    You are given an array of ‘N’ integers where each integer value is between ‘1’ and ‘N’. Each integer appears exactly once
    except for ‘P’, which appears exactly twice, and ‘Q’, which is missing.

    Your task is to find ‘P’ and ‘Q’ and return them respectively.

    Constraints:
    2 <= N <= 5 * 10^4
    1 <= data <= N

    Where ‘N’ is the size of the array and ‘data’ denotes the value of the elements of the array. 
    
    Sample Input 1:
    4
    1 2 3 2
    Sample Output 1:
    2 4
    Explanation Of Sample Input 1:
    Input: ‘N’ = 4
    ‘A’ = [1, 2, 3, 2]
    Output: {2, 4} - The integer appearing twice is ‘2’, and the integer missing is ‘4’.
    
    Sample Input 2:
    3
    1 2 1
    Sample Output 2:
    1 3
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(n^2), S.C. : O(1)
vector<int> brute(vector<int> &a)
{
    int n = a.size();
    int missing = -1, repeating = -1;

    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                count ++;
            }
        }

        if (count == 2)
        {
            repeating = i;
        }
        else if (count == 0)
        {
            missing = i;
        }

        if (missing != -1 && repeating != -1)
        {
            break;
        }
    }

    return {repeating, missing};
}

// T.C. : O(n) + O(n), S.C. : O(n)
vector<int> better(vector<int> &a)
{
    int n = a.size();
    int missing = -1, repeating = -1;

    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
        {
            repeating = i;
        }
        else if (hash[i] == 0)
        {
            missing = i;
        }

        if (missing != -1 && repeating != -1)
        {
            break;
        }
    }

    return {repeating, missing};
}

// T.C. : O(n), S.C. : O(1)
vector<int> optimal(vector<int> &a)
{
    long long n = a.size();

    // x = repeating, y = missing
    // s - sn = x - y
    // s2 - s2n = x^2 - y^2
    long long sn = (n * (n + 1))/2;
    long long s2n = (n * (n + 1) * (2*n + 1))/6;
    long long s = 0, s2 = 0;
    for (int i = 0; i < (int)n; i++)
    {
        s += (long long)a[i];
        s2 += (long long)a[i] * (long long)a[i]; 
    }

    long long val1 = s - sn;    // x - y
    long long val2 = s2 - s2n;  // x^2 - y^2
    val2 = val2 / val1; // x + y

    long long repeating = (val1 + val2)/2;
    long long missing = repeating - val1;
    return {(int)repeating, (int)missing};
}

vector<int> findMissingRepeatingNumbers(vector < int > a) 
{
    // Brute Force
    // return brute(a);

    // Better
    // return better(a);

    // optimal
    return optimal(a);
}

int main()
{
    
    return 0;
}