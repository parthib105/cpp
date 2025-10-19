/*
    Account Merge

    Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

    Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

    After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

    Example 1:

    Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
    Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
    Explanation:
    The first and second John's are the same person as they have the common email "johnsmith@mail.com".
    The third John and Mary are different people as none of their email addresses are used by other accounts.
    We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
    ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

    Example 2:

    Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
    Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

    Constraints:

        1 <= accounts.length <= 1000
        2 <= accounts[i].length <= 10
        1 <= accounts[i][j].length <= 30
        accounts[i][0] consists of English letters.
        accounts[i][j] (for j > 0) is a valid email.
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    int n;
    vector<int> rank, parent;

public:
    DisjointSet(int sz)
    {
        this->n = sz;
        this->rank.resize(this->n + 1, 0);
        this->parent.resize(this->n + 1);
        
        for (int i = 0; i < this->n; i++)
            this->parent[i] = i;
    }

    int findParent(int u)
    {
        if (u == this->parent[u])
            return u;

        this->parent[u] = findParent(this->parent[u]);
        return this->parent[u];
    }

    void unionByRank(int u, int v)
    {
        // find the ultimate parents
        int up_u = this->findParent(u);
        int up_v = this->findParent(v);

        if (up_u == up_v)   // same parent, return
            return;

        if (this->rank[up_u] < this->rank[up_v])
            this->parent[up_u] = up_v;
        else if (this->rank[up_v] < this->rank[up_u])
            this->parent[up_v] = up_u;
        else
        {
            this->parent[up_v] = up_u;
            this->rank[up_u] += 1;
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
{
    int E = accounts.size();
    DisjointSet ds(E);
    unordered_map<string, int> mailToNode;
    
    for (int i = 0; i < E; i++)
    {
        for (int j = 1; j < accounts[i].size(); j++)
        {
            string currMail = accounts[i][j];
            if (mailToNode.find(currMail) == mailToNode.end())
                mailToNode[currMail] = i;
            else
                ds.unionByRank(i, mailToNode[currMail]);
        }
    }

    vector<vector<string>> mergedMail(E);
    unordered_map<string, int>::iterator it = mailToNode.begin();
    while (it != mailToNode.end())
    {
        string mail = it->first;
        int u = ds.findParent(it->second);
        mergedMail[u].push_back(mail);
        it ++;
    }

    vector<vector<string>> ans;
    for (int u = 0; u < E; u++)
    {
        if (mergedMail[u].size() == 0)
            continue;
        
        sort(mergedMail[u].begin(), mergedMail[u].end());
        vector<string> temp;
        temp.push_back(accounts[u][0]);
        for (string str : mergedMail[u])
            temp.push_back(str);

        ans.push_back(temp);
    }
    return ans;
}

int main() 
{
    
    return 0;
}