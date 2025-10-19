/*
    Given an array of integers arr, return true if the no. of occurances
    of each values in the array is unique or false otherwise

    Ex. arr = [1, 2]         , arr = [-3, 0, 1 -3, 1, 1, 1, -3, 10, 0]
        1 occurs 1 time        1 occurs 4 times
        2 occurs 1 time        -3 occurs 3 times
        return false            0 occurs 2 times
                               10 occurs 1 times
                               return true
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool uniqueOccurance(vector<int> &arr)
{
    int i = 0;
    sort(arr.begin(), arr.end());
    vector<int> ans;
    while (i < arr.size())
    {
        int count = 1;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        ans.push_back(count);
        i = i + count;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] == ans[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    
    return 0;
}