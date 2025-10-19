/*
    Given an array, rotate the array to the right by k steps, where k is non-negative.
    Ex. 
        nums = [1, 2, 3, 4, 5, 6, 7], k = 3
        output = [5, 6, 7, 1, 2, 3, 4]

        nums = [-1, -100, 3, 99], k = 2
        output = [3, 99, -1, -100]
*/
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<int> temp(n, 0);
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    
    return 0;
}