/*
    Alien Dictionary

    A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

    Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

    However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

    A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

    Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

    Examples:

    Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
    Output: true
    Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
    The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
    The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
    The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
    The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
    So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
    Input: words[] = ["caa", "aaa", "aab"]
    Output: true
    Explanation: A possible corrct order of letters in the alien dictionary is "cab".
    The pair "caa" and "aaa" suggests 'c' appears before 'a'.
    The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary.
    So, 'c' → 'a' → 'b' is a valid ordering.
    Input: words[] = ["ab", "cd", "ef", "ad"]
    Output: ""
    Explanation: No valid ordering of letters is possible.
    The pair "ab" and "ef" suggests "a" appears before "e".
    The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
    Constraints:
    1 ≤ words.length ≤ 500
    1 ≤ words[i].length ≤ 100
    words[i] consists only of lowercase English letters.
*/

#include <bits/stdc++.h>
using namespace std;

void getAdj(int n, vector<vector<int>> &adj, vector<string> &words)
{
    for (int i = 1; i < words.size(); i++)
    {
        string s1 = words[i - 1];
        string s2 = words[i];

        int j = 0;
        int len = min(s1.length(), s2.length());
        while (j < len && s1[j] == s2[j])
            j++;

        if (j < len)
            adj[s1[j] - 'a'].push_back(s2[j] - 'a');
        else if (s1.size() > s2.size())
        {
            // invalid prefix case
            adj.clear();
            return;
        }
    }
}

bool dfsUtil(int u, vector<bool> &vis, vector<bool> &pathVis, stack<int> &st, vector<vector<int>> &adj)
{
    vis[u] = true;
    pathVis[u] = true;
    for (int v : adj[u])
    {
        if (!vis[v])
        {
            bool cycle = dfsUtil(v, vis, pathVis, st, adj);
            if (cycle)
                return true;
        }
        else if (pathVis[v])
            return true;
    }
    st.push(u);
    pathVis[u] = false;
    return false;
}

string topoDFS(int n, vector<bool> &present, vector<vector<int>> &adj)
{
    stack<int> st;
    vector<bool> vis(n, false);
    vector<bool> pathVis(n, false);

    for (int i = 0; i < n; i++)
    {
        if (present[i] && !vis[i])
        {
            bool cycle = dfsUtil(i, vis, pathVis, st, adj);
            if (cycle)
                return "";
        }
    }

    string ans = "";
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (present[node])
            ans.push_back('a' + node);
    }
    return ans;
}

string topoBFS(int n, vector<bool> &present, vector<vector<int>> &adj)
{
    queue<int> q;
    vector<int> indegree(n, 0);

    // get the indegrees
    for (int u = 0; u < n; u++)
    {
        for (int v : adj[u])
            indegree[v]++;
    }

    // push nodes present & inderee = 0
    for (int u = 0; u < n; u++)
    {
        if (present[u] && indegree[u] == 0)
            q.push(u);
    }

    string ans = "";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        ans.push_back('a' + u);
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // count the present
    int countPresent = 0;
    for (int u = 0; u < n; u++)
    {
        if (present[u])
            countPresent++;
    }

    if (countPresent != ans.length())
        return "";
    return ans;
}

string findOrder(vector<string> &words)
{
    // mark all present characters
    vector<bool> present(26, false);
    for (string word : words)
    {
        for (char c : word)
            present[c - 'a'] = true;
    }

    // fill the adj list
    vector<vector<int>> adj(26);
    getAdj(26, adj, words);
    if (adj.empty())
        return "";

    // Using DFS
    // return topoDFS(26, present, adj);

    // Using BFS
    return topoBFS(26, present, adj);
}

int main()
{
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << findOrder(words) << endl;
    return 0;
}