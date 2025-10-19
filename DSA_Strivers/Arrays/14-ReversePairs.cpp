/*
    Team Contest

    School is organizing a team contest. You are given an array ‘SKILL’ containing the skill level of ‘N’ candidates.
    Two candidates(having index ‘i’ and ‘j’) can pair up to form a team if for index i < j, SKILL[i] > 2*SKILL[j].

    Your task is the return the count of all the possible pairs to take part in the contest.

    Example:
    Input: ‘N’ = 5
    ‘SKILL’ = [4, 1, 2, 3, 1] 

    Output: 3
    Explanation:
    Possible pairs are (4,1), (4,1), (3,1).
    
    Sample Input 1:
    5
    4 1 2 3 1
    Sample Output 1 :
    3
    Explanation Of Sample Input 1:
    Possible pairs are (4,1), (4,1), and (3,1).
    
    Sample Input 2:
    4 
    100 49 201 100
    Sample Output 2 :
    2
    Constraints:
    1 <= N <= 10^5
    1 <= SKILL[i] <= 10^6
    Time Limit: 1 sec
*/

#include<bits/stdc++.h>
using namespace std;


// T.C. : O(n^2), S.C. : O(1)
int brute(vector<int> &skill, int n)
{
    int pairs = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (skill[i] > 2 * skill[j])
            {
                pairs ++;
            }
        }
    }
    return pairs;
}

void merge(vector<int> &skill, int st, int m, int ed)
{
    int l = st;
    int r = m + 1;
    vector<int> temp;

    // merge both the sorted subarrays
    while (l <= m && r <= ed)
    {
        if (skill[l] <= skill[r])
        {
            temp.push_back(skill[l]);
            l++;
        }
        else
        {
            temp.push_back(skill[r]);
            r++;
        }
    }
    while (l <= m)
    {
        temp.push_back(skill[l]);
        l++;
    }
    while (r <= ed)
    {
        temp.push_back(skill[r]);
        r++;
    }

    for (int i = st; i <= ed; i++)
    {
        skill[i] = temp[i - st];
    }
}

int countPairs(vector<int> &skill, int st, int m, int ed)
{
    int cnt = 0;
    int r = m + 1;
    for (int l = st; l <= m; l++)
    {
        while (r <= ed && skill[l] > 2 * skill[r])
        {
            r ++;
        }

        cnt += (r - (m + 1));
    }
    return cnt;
}

// T.C. : O(n log(n)), S.C. : O(n)
int optimal(vector<int> &skill, int st, int ed)
{
    if (st >= ed)
    {
        return 0;
    }

    int m = st + (ed - st)/2;

    int cnt = 0;
    cnt += optimal(skill, st, m);
    cnt += optimal(skill, m + 1, ed);
    cnt += countPairs(skill, st, m, ed);
    merge(skill, st, m, ed);

    return cnt;
}

int team(vector <int> & skill, int n)
{
    // Brute
    // return brute(skill, n);

    // Optimal
    return optimal(skill, 0, n - 1);
}

int main()
{
    int n = 5;
    vector<int> skill = {4, 1, 2, 3, 1};

    cout << team(skill, n) << endl;
    return 0;
}