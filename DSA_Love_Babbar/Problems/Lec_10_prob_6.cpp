/*
    You are given an integer array 'ARR' of size 'N' and and integer 'S'.
    Your task is to return the list of all pairs of elements such that each sum
    of elements of each pair equals 'S'

    ex.    2 -3 3 3 -2
    sort -> -2 -3 2 3 3
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> arr, int s)
{
    int n = arr.size();

    // sort the array
    sort(arr.begin(), arr.end());

    // define a answer vector of type vector
    vector<vector<int>> ans;

    int i = 0;
    int j = n - 1;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if ((arr[i] + arr[j]) == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, -3, 3, 3, -2};
    int s = 0;

    vector<vector<int>> ans = pairSum(arr, s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "(" << ans[i][0] << ", " << ans[i][1] << ") ";
    }
    
    return 0;
}