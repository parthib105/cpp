/*
    Given an integer array nums, move all 0's to end while maintaining the relative order of non-zero elements
*/

#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &nums)
{
    int countNonZero = 0;
    for (auto i : nums)
    {
        if (i != 0)
        {
            countNonZero ++;
        }
    }

    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[k] = nums[i];
            k ++;
        }
    }

    for (int i = countNonZero; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

void moveZeros_2(vector<int> &nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    } 
}

int main()
{
    vector<int> nums = {2, 0, 1, 3, 0, 0, 0};
    moveZeros_2(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    return 0;
}