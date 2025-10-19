/*
    Word Ladder II

    A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord
    Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].



    Example 1:

    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
    Explanation: There are 2 shortest transformation sequences:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
    "hit" -> "hot" -> "lot" -> "log" -> "cog"
    Example 2:

    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
    Output: []
    Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


    Constraints:

    1 <= beginWord.length <= 5
    endWord.length == beginWord.length
    1 <= wordList.length <= 500
    wordList[i].length == beginWord.length
    beginWord, endWord, and wordList[i] consist of lowercase English letters.
    beginWord != endWord
    All the words in wordList are unique.
    The sum of all shortest transformation sequences does not exceed 10^5.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> findLaddersMLE(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<string> usedOnLevel;
    queue<vector<string>> q;

    int level = 0;
    q.push({beginWord});
    usedOnLevel.push_back(beginWord);

    vector<vector<string>> ans;
    while (!q.empty())
    {
        vector<string> curr = q.front();
        q.pop();

        // erase used words in prev level
        if (curr.size() > level)
        {
            level++;
            for (string word : usedOnLevel)
                st.erase(word);
            usedOnLevel.clear();
        }

        string currWord = curr.back();
        if (currWord == endWord)
            ans.push_back(curr);

        for (int i = 0; i < currWord.length(); i++)
        {
            char org = currWord[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                currWord[i] = c;
                if (st.count(currWord))
                {
                    curr.push_back(currWord);
                    q.push(curr);

                    // mark as vis on the level
                    usedOnLevel.push_back(currWord);
                    curr.pop_back();
                }
            }
            currWord[i] = org;
        }
    }
    return ans;
}

void dfsBacktrack(string currWord, string beginWord, vector<string> &seq, unordered_map<string, int> &dist, vector<vector<string>> &ans)
{
    if (currWord == beginWord)
    {
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }

    int currStep = dist[currWord];
    for (int i = 0; i < currWord.size(); i++)
    {
        char org = currWord[i];
        for (char c = 'a'; c <= 'z'; c++)
        {
            currWord[i] = c;
            if (dist.find(currWord) != dist.end() && dist[currWord] + 1 == currStep)
            {
                seq.push_back(currWord);
                dfsBacktrack(currWord, beginWord, seq, dist, ans);
                seq.pop_back();
            }
        }
        currWord[i] = org;
    }
}

vector<vector<string>> findLaddersOpt(string beginWord, string endWord, vector<string> &wordList)
{
    queue<string> q;
    unordered_map<string, int> dist;
    unordered_set<string> st(wordList.begin(), wordList.end());

    q.push(beginWord);
    dist[beginWord] = 1;
    st.erase(beginWord);
    while (!q.empty())
    {
        string currWord = q.front();
        int currStep = dist[currWord];
        q.pop();

        if (currWord == endWord)
            break;

        for (int i = 0; i < currWord.size(); i++)
        {
            char org = currWord[i];
            for (char c = 'a'; c <= 'z'; c++)
            {
                currWord[i] = c;
                if (st.count(currWord))
                {
                    q.push(currWord);
                    st.erase(currWord);
                    dist[currWord] = currStep + 1;
                }
            }
            currWord[i] = org;
        }
    }

    vector<vector<string>> ans;
    if (dist.find(endWord) != dist.end())
    {
        vector<string> seq = {endWord};
        dfsBacktrack(endWord, beginWord, seq, dist, ans);
    }
    return ans;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    // Shows MLE
    // return findLaddersMLE(beginWord, endWord, wordList);

    // Optimized
    return findLaddersOpt(beginWord, endWord, wordList);
}

int main()
{
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> res = findLadders(beginWord, endWord, wordList);

    for (int i = 0; i < res.size(); i++)
    {
        cout << "[";
        int n = res[i].size();
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
                cout << res[i][j];
            else
                cout << res[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}