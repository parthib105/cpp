/*
    Permutations of a string
*/

#include<bits/stdc++.h>
using namespace std;

void permutation(string str, int idx, vector<string>& ans)
{
    if (idx >= str.length())
    {
        ans.push_back(str);
        return;
    }

    for (int i = idx; i < str.length(); i++)
    {
        swap(str[idx], str[i]);
        permutation(str, idx + 1, ans);
        // backtrack
        swap(str[idx], str[i]);
    }
    
}

vector<string> permute(string str)
{
    vector<string> ans;
    int idx = 0;

    if (str.length() == 0)
    {
        return ans;
    }

    permutation(str, idx, ans);

    return ans;
}

int main()
{
    string str;
    cout << "Enter the string : ";
    getline(cin, str);

    vector<string> ans = permute(str);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}