/*
    Given an integer array 'nums' of length 'n' where all the integers of nums are in the range [1, n] and 
    each integer appears once or twice, return an array of all the integers that appears twice.
    
    You must write an algorithm that runs in O(n) time and uses only constant extra space.

    Example 1 :

    Input  : nums = [4,3,2,7,8,2,3,1]
    Output : [2,3]

    Example 2 : 

    Input  : nums = [1,1,2]
    Output : [1]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) 
{
    int n = nums.size();
    int prime = 100003;
    vector<int> ans;

    for(int i=0; i<n; i++)
    {
        int next = (nums[i] % prime) - 1;
        if (nums[next] > prime)
        { 
            ans.push_back(next + 1);
        }
        nums[next] += prime;
    }
    return ans;
}

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> ans = findDuplicates(nums);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}