/*
    Given an array 'nums', return true if the array was originally sorted in non-decreasing order,
    then rotated some number of positions (including 0). Otherwise, return false.

    There may be duplications in the original array.

    Ex. 
        nums = [3, 4, 5, 1, 2]
        true

        nums = [2, 1, 3, 4]
        false
*/

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums)
{
    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count ++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count ++;
    }
    return (count <= 1);
}   

int main()
{
    vector<int> nums = {2, 1, 3, 4};

    if (check(nums))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}