/*
    Subarrays with XOR ‘K’

    Given an array ‘A’ consisting of ‘N’ integers and an integer ‘B’, find the number of subarrays of array ‘A’ whose bitwise
    XOR( ⊕ ) of all elements is equal to ‘B’.
    A subarray of an array is obtained by removing some(zero or more) elements from the front and back of the array.

    Example:
    Input: ‘N’ = 4 ‘B’ = 2
    ‘A’ = [1, 2, 3, 2]

    Output: 3

    Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
    
    Sample Input 1:
    4 2
    1 2 3 2
    Sample Output 1 :
    3
    Explanation Of Sample Input 1:
    Input: ‘N’ = 4 ‘B’ = 2
    ‘A’ = [1, 2, 3, 2]

    Explanation: Subarrays have bitwise xor equal to ‘2’ are: [1, 2, 3, 2], [2], [2].
    Sample Input 2:
    4 3
    1 2 3 3
    Sample Output 2:
    4

    Sample Input 3:
    5 6
    1 3 3 3 5 
    Sample Output 3:
    2

    Constraints:
    1 <= N <= 10^3
    1 <= A[i], B <= 10^9

    Time Limit: 1-sec
*/

#include<bits/stdc++.h>
using namespace std;

// T.C. : O(n^3), S.C. : O(1)
int brute(vector<int> &a, int b)
{
    int n = a.size();
    int subArr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int elmXor = 0;
            for (int k = i; k <= j; k++)
            {
                elmXor = elmXor^a[k];
            }
            if (elmXor == b)
            {
                subArr += 1;
            }
        }
    }
    return subArr;
}

// T.C. : O(n^2), S.C. : O(1)
int better(vector<int> &a, int b)
{
    int n = a.size();
    int subArr = 0;
    for (int i = 0; i < n; i++)
    {
        int elmXor = 0;
        for (int j = i; j < n; j++)
        {
            elmXor = elmXor^a[j];
            if (elmXor == b)
            {
                subArr += 1;
            }
        }
    }
    return subArr;
}

//T.C. : O(n), S.C. : O(n)
int optimal(vector<int> &a, int b)
{
    unordered_map<int, int> xorMap;
    xorMap[0] = 1;

    int subArr = 0, preXor = 0;
    for (int i = 0; i < a.size(); i++)
    {
        // prefix xor
        preXor = preXor^a[i];

        // count remaining sub
        int rem = preXor^b;
        subArr += xorMap[rem];

        xorMap[preXor] += 1;
    }
    return subArr;
}

int subarraysWithSumK(vector < int > a, int b) 
{
    // Brute force
    // return brute(a, b);

    // Better approach
    // return better(a, b);

    // Optimal
    return optimal(a, b);
}

int main()
{
    vector<int> a = {1, 2, 3, 3};
    int b = 3;

    cout << subarraysWithSumK(a, b) << endl;
    return 0;
}