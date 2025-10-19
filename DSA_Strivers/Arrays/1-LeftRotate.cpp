/*
    Left rotate by 1 place
*/

#include<bits/stdc++.h>
using namespace std;

void leftRotate(vector<int> &nums)
{
    int n = nums.size();
    int to_place = nums[0];
    for (int i = 1; i < n; i++)
    {
        nums[i - 1] = nums[i];
    }
    nums[n - 1] = to_place;
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    cout << "Before rotation : " << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    leftRotate(nums);

    cout << endl << "After rotation : " << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}