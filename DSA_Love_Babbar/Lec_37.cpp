/*
    Power Set using recursion
*/

#include<bits/stdc++.h>
using namespace std;

/******************* Subset of an array *******************/
void subsets(vector<int>& nums, int idx, vector<int> output, vector<vector<int>>& ans)
{           
    // base case
    if (idx >= nums.size())
    {
        ans.push_back(output);      // before return, store the subset
        return;
    }

    // exclusion
    subsets(nums, idx + 1, output, ans);

    // inclusion
    output.push_back(nums[idx]);
    subsets(nums, idx + 1, output, ans);
}

vector<vector<int>> powerSet(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int idx = 0;
    subsets(nums, idx, output, ans);

    return ans;
}
/**********************************************************/


/******************* Subsequence of a string *******************/
void subSequence(string& str, int idx, string output, vector<string>& ans)
{
	// base case
	if (idx >= str.length())
	{
		if (!output.empty())
		{
			ans.push_back(output);
		}
		return;
	}

	// exclusion
	subSequence(str, idx + 1, output, ans);

	// inclusion
	output += str[idx];
	subSequence(str, idx + 1, output, ans);
}

vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> ans;
	string output;
	int idx = 0;
	subSequence(str, idx, output, ans);
	return ans;
}
/***************************************************************/

int main()
{
    /******************* Subset of an array *******************/
    // int n;
    // cout << "Enter the size of the set : ";
    // cin >> n;

    // vector<int> nums(n, 0);
    // cout << "Enter elements of the set : " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> nums[i];
    // }

    // sort(nums.begin(), nums.end(), greater<int>());
    // vector<vector<int>> powerset;
    // powerset = powerSet(nums);

    // for (int i = 0; i < (1 << n); i++)
    // {
    //     cout << "subset " << i + 1 << " : ";
    //     for (int j = 0; j < powerset[i].size(); j++)
    //     {
    //         cout << powerset[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    /**********************************************************/



    /******************* Subsequence of a string *******************/
    string str;
    cout << "Enter the string : ";
    getline(cin, str);

    vector<string> ans;
    ans = subsequences(str);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "subsequence " << i + 1 << " : " << ans[i] << endl;
    }
    /***************************************************************/

    return 0;
}