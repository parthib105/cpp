/*
    Sum of minimum and maximum elements of all subarrays of size k.

    Input : 

    arr[] = {2, 5, -1, 7, -3, -1, -2}  
    K = 4

    Output : 18
    Explanation : Subarrays of size 4 are : 
    {2, 5, -1, 7},   min + max = -1 + 7 = 6
    {5, -1, 7, -3},  min + max = -3 + 7 = 4      
    {-1, 7, -3, -1}, min + max = -3 + 7 = 4
    {7, -3, -1, -2}, min + max = -3 + 7 = 4   
    
    Missing sub arrays - 
    
    {2, -1, 7, -3}
    {2, 7, -3, -1}
    {2, -3, -1, -2}
    {5, 7, -3, -1}
    {5, -3, -1, -2}
    and few more -- why these were not considered??
    Considering missing arrays result coming as 27
    
    Sum of all min & max = 6 + 4 + 4 + 4 = 18
*/

#include<bits/stdc++.h>
using namespace std;

int MaxMinSum(vector<int>& arr, int k)
{
    // maintain a deque for min and max elements
    deque<int> mini(k);
    deque<int> maxi(k);

    // for first window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        mini.push_back(i);
        maxi.push_back(i);
    }

    // rest of the windows
    int ans = 0;
    for (int i = k; i < arr.size(); i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];

        // remove
        while (!maxi.empty() && (i - maxi.front()) >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && (i - mini.front()) >= k)
        {
            mini.pop_front();
        }

        // add
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        mini.push_back(i);
        maxi.push_back(i);
    }

    // consider the last window
    ans += arr[maxi.front()] + arr[mini.front()];

    return ans;
}

int main()
{
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << "Required sum : " << MaxMinSum(arr, k) << endl;
    return 0;
}