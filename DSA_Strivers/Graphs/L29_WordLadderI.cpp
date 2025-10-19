/*
    Word Ladder I

    Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find
    the length of the shortest transformation sequence from startWord to targetWord.

    Keep the following conditions in mind:

    A word can only consist of lowercase characters.
    Only one letter can be changed in each transformation.
    Each transformed word must exist in the wordList including the targetWord.
    startWord may or may not be part of the wordList
    The second part of this problem can be found here.

    Note: If no possible way to transform sequence from startWord to targetWord return 0

    Example 1:

    Input:
    wordList = {"des","der","dfr","dgt","dfs"}
    startWord = "der", targetWord= "dfs",
    Output:
    3
    Explanation:
    The length of the smallest transformation
    sequence from "der" to "dfs" is 3
    i,e "der" -> "dfr" -> "dfs".

    Example 2:

    Input:
    wordList = {"geek", "gefk"}
    startWord = "gedk", targetWord= "geek",
    Output:
    2
    Explanation:
    gedk -> geek

    Example 3:

    Input:
    wordList = {"poon", "plee", "same", "poie","plea","plie","poin"}
    startWord = "toon", targetWord= "plea",
    Output: 7
    Explanation:
    toon -> poon -> poin -> poie -> plie -> plee -> plea

    Expected Time Compelxity: O(N^2 * M)
    Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|

    Constraints:
    1 ≤ N ≤ 100
    1 ≤ M ≤ 10
*/

#include <bits/stdc++.h>
using namespace std;

// T.C. : O(N^2 * M), S.C. : O(N * M)
// where N = length of wordList and M = |wordListi|
bool isAdjacent(const string &word1, const string &word2)
{
    int count = 0;
    for (int i = 0; i < word1.length(); i++)
    {
        if (word1[i] != word2[i])
        {
            count++;
        }
        if (count > 1)
            return false;
    }
    return count == 1;
}

int wordLadderLengthBrute(string startWord, string targetWord, vector<string> &wordList)
{
    int N = wordList.size();

    // Add startWord to the wordList if it's not already present
    bool startPresent = false;
    for (const string &word : wordList)
    {
        if (word == startWord)
        {
            startPresent = true;
            break;
        }
    }
    if (!startPresent)
    {
        wordList.push_back(startWord);
        N++;
    }

    // Create the adjacency list for the graph
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (isAdjacent(wordList[i], wordList[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // BFS to find the shortest path
    queue<pair<int, int>> q;
    vector<bool> visited(N, false);

    int startIdx = find(wordList.begin(), wordList.end(), startWord) - wordList.begin();
    int targetIdx = find(wordList.begin(), wordList.end(), targetWord) - wordList.begin();

    if (startIdx == N || targetIdx == N)
        return 0;

    q.push({startIdx, 1});
    visited[startIdx] = true;

    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (node == targetIdx)
        {
            return steps;
        }

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push({neighbor, steps + 1});
            }
        }
    }

    return 0;
}

// T.C. : O(N * M), S.C. : O(N)
// where N = length of wordList and M = |wordListi|
int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    // BFS
    queue<pair<string, int>> q;
    unordered_set<string> s(wordList.begin(), wordList.end());

    s.erase(startWord);
    q.push({startWord, 1});
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == targetWord)
        {
            return steps;
        }

        for (int i = 0; i < word.size(); i++)
        {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (s.find(word) != s.end())
                {
                    s.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = org;
        }
    }
    return 0;
}

int main()
{
    vector<string> wordList = {"poon", "plee", "same", "poie", "plea", "plie", "poin"};
    string startWord = "toon", targetWord = "plea";

    cout << wordLadderLength(startWord, targetWord, wordList) << endl;
    return 0;
}