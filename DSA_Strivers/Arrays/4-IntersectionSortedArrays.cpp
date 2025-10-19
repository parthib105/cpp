/*
    Intersection of two sorted arrays

    Given two sorted arrays arr1[] and arr2[]. Your task is to return the intersection of both arrays.

    Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not count
    duplicate elements.

    Note: If the intersection is empty then the list should contain -1.

    Examples:

    Input: arr1[] = [1, 2, 3, 4], arr2[] = [2, 4, 6, 7, 8]
    Output: [2, 4]
    Explanation: 2 and 4 are only common elements in both the arrays.
    Input: arr1[] = [1, 2, 2, 3, 4], arr2[] = [2, 2, 4, 6, 7, 8]
    Output: [2, 4]
    Explanation: 2 and 4 are the only common elements.
    Input: arr1[] = [1, 2], arr2[] = [3, 4]
    Output: -1
    Explanation: No common elements.

    Expected Time Complexity: O(n + m)
    Expected Auxiliary Space: O(min(n,m))

    Constraints:
    1 <= arr1.size(),arr2.size() <= 10^5
    1 <= arr1[i], arr2[i] <= 10^6

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bruteForce(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    vector<int> ans;
    vector<bool> vis(m, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j] && (ans.size() == 0 || arr1[i] != ans.back()) && vis[j] == false)
            {
                ans.push_back(arr1[i]);
                vis[j] = true;
                break;
            }
            if (arr2[j] > arr1[i])
            {
                break;
            }
        }
    }

    if (ans.empty())
    {
        return {-1};
    }
    return ans;
}

vector<int> optimal(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);

            // It should not contain duplicate elements
            int temp = arr1[i];
            while (i < n && arr1[i] == temp)
            {
                i++;
            }
            while (j < m && arr2[j] == temp)
            {
                j++;
            }
        }
    }
    if (ans.empty())
    {
        return {-1};
    }
    return ans;
}

// Function to return a list containing the intersection of two arrays.
vector<int> printIntersection(vector<int> &arr1, vector<int> &arr2)
{
    // Brute Force
    // return bruteForce(arr1, arr2);

    // Optimal
    return optimal(arr1, arr2);
}

int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 4, 6, 7, 8};
    vector<int> ans = printIntersection(arr1, arr2);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}