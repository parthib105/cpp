/*
    Previous Smaller Element

    Given an array arr[ ] of n positive integers, the task is to find the greatest element on the left of every element in the array which is strictly smaller than itself, if this element does not exist for an index print "-1".

    Examples:

    Input: n = 5, arr[] = [2, 3, 4, 5, 1]
    Output: -1 2 3 4 -1
    Explanation:
    Greatest element on the left of 3 smaller 
    than itself is 2, for 4 it is 3 and for 5 
    it is 1. Since 2 is the first element and 
    no element on its left is present, so it's 
    greatest smaller element will be -1 and for 
    1 no element smaller than itself is present 
    on its left, so it's greatest smaller element 
    is -1.

    Input: n = 3, arr[] = [1, 2, 3] 
    Output: -1 1 2 

    Constraints:
    1 ≤ n ≤ 10^6
    1 ≤ arr[i] ≤ 10^8
*/


#include<bits/stdc++.h>
using namespace std;

// T.C. : O(N^2), S.C. : O(N) (ans)
vector<int> leftSmallerBrute(vector<int>& arr)
{
    int n = arr.size();
    vector<int> lse(n, -1);
    
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                lse[i] = arr[j];
                break;
            }
        }
    }
    return lse;
}

// T.C. : O(2N), S.C. : O(N) (stack) + O(N) (ans)
vector<int> leftSmallerOptimal(vector<int>& arr)
{
    int n = arr.size();
    vector<int> lse(n, -1);
    stack<int> st;
    
    for (int i = 0; i < n; i++)
    {
        int currElm = arr[i];
        while (!st.empty() && st.top() >= currElm)
            st.pop();
            
        if (!st.empty())
            lse[i] = st.top();
        
        st.push(currElm);
    }
    return lse;
}

vector<int> leftSmaller(vector<int> arr) 
{
    // Brute Force solution
    // return leftSmallerBrute(arr);
    
    // Optimal solution
    return leftSmallerOptimal(arr);
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 1};
    vector<int> ans = leftSmaller(arr);
    
    for (int i : ans)
        cout << i << " ";
    return 0;
}