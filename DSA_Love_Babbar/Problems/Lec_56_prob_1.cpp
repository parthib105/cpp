/*
    Next Smaller Element

    Problem statement :
    You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array
    elements.

    Next Smaller Element for an array element is the first element to the right of that element which has a value strictly
    smaller than that element. If for any array element the next smaller element does not exist, you should print -1 for that
    array element.

    For Example:

    If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element.
    For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    /********** Approach 1 **********/
    vector<int> ans(n, 0);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int currElm = arr[i];
        while (st.top() >= currElm)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(currElm);
    }
    return ans;

    /********** Approach 2 **********/
    // stack<int> st;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (st.empty())
    //     {
    //         st.push(arr[i]);
    //         arr[i] = -1;
    //     }
    //     else
    //     {
    //         int curr = arr[i];
    //         while (!st.empty() && st.top() >= curr)
    //         {
    //             st.pop();
    //         }
    //         if (st.empty())
    //         {
    //             arr[i] = -1;
    //             st.push(curr);
    //         }
    //         else
    //         {
    //             arr[i] = st.top();
    //             st.push(curr);
    //         }
    //     }
    // }
    // return arr;
}

int main()
{
    int n = 3;
    vector<int> arr = {2, 3, 1};

    vector<int> ans = nextSmallerElement(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}