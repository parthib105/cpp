/*
    Union of Two Sorted Arrays

    Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the
    common and distinct elements in the two arrays. Return the elements in sorted order.

    Example 1:

    Input:
    n = 5, arr1[] = {1, 2, 3, 4, 5}
    m = 5, arr2 [] = {1, 2, 3, 6, 7}
    Output:
    1 2 3 4 5 6 7
    Explanation:
    Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

    Example 2:

    Input:
    n = 5, arr1[] = {2, 2, 3, 4, 5}
    m = 5, arr2[] = {1, 1, 2, 3, 4}
    Output:
    1 2 3 4 5
    Explanation:
    Distinct elements including both the arrays are: 1 2 3 4 5.

    Example 3:

    Input:
    n = 5, arr1[] = {1, 1, 1, 1, 1}
    m = 5, arr2[] = {2, 2, 2, 2, 2}
    Output:
    1 2
    Explanation:
    Distinct elements including both the arrays are: 1 2.

    Expected Time Complexity: O(n+m).
    Expected Auxiliary Space: O(n+m).

    Constraints:
    1 <= n, m <= 10^5
    -10^9 <= arr1[i], arr2[i] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force TC : O(n log(n) + m log(m) + n + m), SC : O(m + n)
vector<int> bruteForce(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }

    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }

    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        ans.push_back(*it);
        it++;
    }
    return ans;
}

// Optimal TC : O(n + m), SC : O(m + n)
vector<int> optimal(int arr1[], int arr2[], int n, int m)
{
    vector<int> uni;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (uni.size() == 0 || uni.back() != arr1[i])
            {
                uni.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (uni.size() == 0 || uni.back() != arr2[j])
            {
                uni.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (uni.size() == 0 || uni.back() != arr1[i])
        {
            uni.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (uni.size() == 0 || uni.back() != arr2[j])
        {
            uni.push_back(arr2[j]);
        }
        j++;
    }

    return uni;
}

// arr1,arr2 : the arrays
//  n, m: size of arrays
// Function to return a list containing the union of the two arrays.
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    // Brute Force solution
    // return bruteForce(arr1, arr2, n, m);

    // Optimal
    return optimal(arr1, arr2, n, m);
}

int main()
{
    int n = 5, m = 5;
    int arr1[] = {2, 2, 3, 4, 5}; 
    int arr2[] = {1, 1, 2, 3, 4};

    vector<int> ans = findUnion(arr1, arr2, n, m);

    for (int elm : ans)
    {
        cout << elm << " ";
    }
    return 0;
}